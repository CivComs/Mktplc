<?php

/**
 * @file
 * Default theme implementation to configure blocks.
 */

  $element_regions = array(
    'block' => array('title' => t('Block'), 'count' => 0),
    'popup' => array('title' => t('Popup'), 'count' => 0),
  );
  foreach (element_children($form) as $element) $element_regions[$form[$element]['region']['#value']]['count']++;

  // Add table javascript.
  drupal_add_js('misc/tableheader.js');
  drupal_add_js(drupal_get_path('module', 'custom_search') . '/custom_search_sort.js');
  foreach ($element_regions as $region => $title) {
    drupal_add_tabledrag('elements', 'match', 'sibling', 'region-select', 'region-select-' . $region, NULL, FALSE);
    drupal_add_tabledrag('elements', 'order', 'sibling', 'sort-select', 'sort-select-' . $region);
  }
?>
<table id="elements" class="sticky-enabled">
  <thead>
    <tr>
      <th><?php print t('Element'); ?></th>
      <th><?php print t('Region'); ?></th>
      <th><?php print t('Weight'); ?></th>
    </tr>
  </thead>
  <tbody>
    <?php $row = 0; ?>
    <?php foreach ($element_regions as $region => $region_data): ?>
      <tr class="region-title region-title-<?php print $region?>">
        <td colspan="3"><?php print $region_data['title']; ?></td>
      </tr>
      <tr class="region-message region-<?php print $region?>-message <?php print((!$region_data['count']) ? 'region-empty' : 'region-populated'); ?>">
        <td colspan="3"><em><?php print t('No elements in this region'); ?></em></td>
      </tr>
      <?php foreach (element_children($form) as $element):
        $data = $form[$element];
        if ($data['region']['#value'] == $region): ?>
          <tr class="draggable <?php print $row % 2 == 0 ? 'odd' : 'even'; ?>">
            <td class="element"><?php print $data['#title']; ?></td>
            <td><?php print drupal_render($data['region']); ?></td>
            <td><?php print drupal_render($data['sort']); ?></td>
          </tr>
          <?php $row++;
        endif;
      endforeach;
    endforeach; ?>
  </tbody>
</table>