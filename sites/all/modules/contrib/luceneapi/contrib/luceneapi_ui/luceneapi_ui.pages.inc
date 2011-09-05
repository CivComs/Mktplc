<?php

/**
 * @file
 *
 */

/**
 * Displays the label, machine readable name, and description in the "Name"
 * column of the list tables.
 *
 * @param $variables
 *   An array containing the variables required for theming.
 * @return
 *   A string containing the markup.
 */
function theme_luceneapi_ui_setting_overview(array $variables) {
  $output = '<strong>' . check_plain($variables['label']) . '</strong>';
  $output .= ' <small>(Machine name: ' . check_plain($variables['name']) . ')</small>';
  $output .= '<div class="description">' . filter_xss_admin($variables['description']) . '</div>';
  return $output;
}

/**
 * Gets the href attribute for the link to the search path.
 *
 * @param $path
 *   A string containing the raw path to the search page.
 * @return
 *   A string containing the root path of the search page.
 */
function luceneapi_ui_get_search_path($path) {
  return str_replace('/%keys', '', parse_url($path, PHP_URL_PATH));
}

/**
 *
 */
function luceneapi_ui_searcher_list_page() {
  $build = array();

  // Build the sortable table header.
  $header = array(
    'label' => array('data' => t('Name'), 'field' => 's.label'),
    'path' => array('data' => t('Path'), 'field' => 's.search_path'),
    'index' => array('data' => t('Index'), 'field' => 'i.label'),
    'operations' => array('data' => t('Operations'), 'colspan' => '3'),
  );

  // Initializes the searcher query.
  $query = db_select('luceneapi_searcher', 's')
    ->fields('s', array('label', 'name', 'description', 'search_path'))
    ->extend('PagerDefault')
    ->extend('TableSort')
    ->limit(20)
    ->orderByHeader($header);

  // Adds alias to the label of the index.
  $query->addField('i', 'name', 'index_name');
  $query->addField('i', 'label', 'index_label');

  // Joins on the index table.
  $query->leftJoin('luceneapi_index', 'i', 'i.name = s.index_name');

  $rows = array();
  foreach ($query->execute() as $record) {
    $row = array();

    $row['name'] = array(
      'data' => array(
        '#theme' => 'luceneapi_ui_setting_overview',
        '#label' => $record->label,
        '#name' => $record->name,
        '#description' => $record->description,
      ),
    );

    // Parses path information, calculates the link's href.
    $path_info = luceneapi_parse_search_path($record->search_path);
    $href = (!empty($path_info['parent'])) ? $path_info['parent'] : $path_info['path'];
    $row['path'] = array(
      'data' => array(
        '#type' => 'link',
        '#title' => $record->search_path,
        '#href' => $href,
      ),
    );

    $row['index'] = check_plain($record->index_label);

    $row[] = array('data' => array(
      '#type' => 'link',
      '#title' => t('Edit'),
      '#href' => 'admin/config/search/luceneapi/search-pages/' . $record->name . '/edit',
    ));

    $row[] = array('data' => array(
      '#type' => 'link',
      '#title' => t('Export'),
      '#href' => 'admin/config/search/luceneapi/search-pages/' . $record->name . '/export',
    ));

    // @todo Check if it is delete or revert.
    $row[] = array('data' => array(
      '#type' => 'link',
      '#title' => t('Delete'),
      '#href' => 'admin/config/search/luceneapi/search-pages/' . $record->name . '/delete',
    ));

    $rows[] = $row;
  }

  $build['list'] = array(
    '#theme' => 'table',
    '#header' => $header,
    '#rows' => $rows,
    '#empty' => t('No available search pages.'),
  );

  return $build;
}

/**
 *
 */
function luceneapi_ui_index_list_page() {
  $build = array();

  // Loads settings from CTools API function, gets additional information.
  $indexer_options = luceneapi_ui_get_plugin_options('indexers');
  $backend_options = luceneapi_ui_get_plugin_options('backends');

  // Build the sortable table header.
  $header = array(
    'label' => array('data' => t('Name'), 'field' => 'i.label'),
    'backend' => array('data' => t('Backend')),
    'indexer' => array('data' => t('Indexer')),
    'operations' => array('data' => t('Operations'), 'colspan' => '3'),
  );

  $result = db_select('luceneapi_index', 'i')
    ->fields('i', array('label', 'name', 'description', 'backend', 'indexer'))
    ->extend('PagerDefault')
    ->extend('TableSort')
    ->limit(20)
    ->orderByHeader($header)
    ->execute();

  $rows = array();
  foreach ($result as $record) {
    $row = array();

    $row['name'] = array(
      'data' => array(
        '#theme' => 'luceneapi_ui_setting_overview',
        '#label' => $record->label,
        '#name' => $record->name,
        '#description' => $record->description,
      ),
    );

    $row['backend'] = check_plain($backend_options[$record->backend]);

    $row['indexer'] = check_plain($indexer_options[$record->indexer]);

    $row[] = array('data' => array(
      '#type' => 'link',
      '#title' => t('Edit'),
      '#href' => 'admin/config/search/luceneapi/indexes/' . $record->name .'/edit',
    ));

    $row[] = array('data' => array(
      '#type' => 'link',
      '#title' => t('Export'),
      '#href' => 'admin/config/search/luceneapi/indexes/' . $record->name .'/export',
    ));

    // @todo Check if it is delete or revert.
    $row[] = array('data' => array(
      '#type' => 'link',
      '#title' => t('Delete'),
      '#href' => 'admin/config/search/luceneapi/indexes/' . $record->name .'/delete',
    ));

    $rows[] = $row;
  }

  $build['list'] = array(
    '#theme' => 'table',
    '#header' => $header,
    '#rows' => $rows,
    '#empty' => t('No available indexes.'),
  );

  return $build;
}

/**
 * Deletes a single index configuration.
 */
function luceneapi_ui_delete_searcher_confirm($form, &$form_state, LuceneapiSearcher $searcher) {

  // Sets values required for deletion.
  $form['name'] = array('#type' => 'value', '#value' => $searcher->getName());
  $form['label'] = array('#type' => 'value', '#value' => $searcher->getLabel());
  $form['table'] = array('#type' => 'value', '#value' => $searcher->getTable());

  // Sets the message, or the title of the page.
  $message = t(
    'Are you sure you want to delete the %label search page configuration?',
    array('%label' => $form['label']['#value'])
  );

  // Builds caption.
  $caption = '<p>';
  $caption .= t(
    'The %label search page configuration will be deleted.',
    array('%label' => $form['label']['#value'])
  );
  $caption .= '</p>';
  $caption .= '<p><strong>' . t('This action cannot be undone.') . '</strong></p>';

  // Finalizes and returns the confirmation form.
  $return_path = 'admin/config/search/luceneapi/search-pages';
  $button_text = t('Delete configuration');
  return confirm_form($form, $message, $return_path, $caption, $button_text);
}

/**
 * Process content type delete confirm submissions.
 */
function luceneapi_ui_delete_searcher_confirm_submit($form, &$form_state) {

  // Deletes the index configuration settings.
  // @todo Invoke a hook that allows backends and indexers to delete their stuff.
  ctools_export_crud_delete('luceneapi_searcher', $form_state['values']['name']);

  // Sets message, logs action.
  drupal_set_message(t(
    'The %label search page configuration has been deleted.',
    array('%label' => $form_state['values']['label'])
  ));
  watchdog('luceneapi', 'Deleted search page configuration "@name".', array('@name' => $form_state['values']['name']), WATCHDOG_NOTICE);

  // Rebuilds the menu cache.
  ctools_export_load_object_reset('luceneapi_searcher');
  menu_rebuild();

  // Returns back to search page list page.
  $form_state['redirect'] = 'admin/config/search/luceneapi/searchers';
}

/**
 * Deletes a single index configuration.
 */
function luceneapi_ui_delete_index_confirm($form, &$form_state, LuceneapiIndex $index) {

  $form['name'] = array('#type' => 'value', '#value' => $index->getName());
  $form['label'] = array('#type' => 'value', '#value' => $index->getLabel());
  $form['table'] = array('#type' => 'value', '#value' => $index->getTable());

  $message = t(
    'Are you sure you want to delete the %label index configuration?',
    array('%label' => $form['label']['#value'])
  );

  $caption = '<p>';
  $caption .= t(
    'The %label index configuration will be deleted.',
    array('%label' => $form['label']['#value'])
  );
  $caption .= '</p>';

  $num_searchers = db_select('luceneapi_searcher', 's')
    ->condition('s.index_name', $form['name']['#value'])
    ->countQuery()
    ->execute()
    ->fetchField();

  if ($num_searchers) {
    $caption .= '<p>';
    $caption .= format_plural(
      $num_searchers,
      '1 search page uses the %label index and will also be deleted.',
      '@count search pages use the %label index and will also be deleted.',
      array('%label' => $index->getLabel())
    );
    $caption .= '</p>';
  }

  $caption .= '<p><strong>' . t('This action cannot be undone.') . '</strong></p>';

  $button_text = t('Delete configuration options');
  $return_path = 'admin/config/search/luceneapi/indexes';
  return confirm_form($form, $message, $return_path, $caption, $button_text);
}

/**
 * Process content type delete confirm submissions.
 */
function luceneapi_ui_delete_index_confirm_submit($form, &$form_state) {
  $searchers_deleted = 0;

  // Iterates over all configurations, deletes one at a time for logging.
  foreach (ctools_export_crud_load_all('luceneapi_searcher') as $searcher_name => $searcher_settings) {
    if ($form_state['values']['name'] == $searcher_settings->index_name) {
      $searchers_deleted++;
      ctools_export_crud_delete('luceneapi_searcher', $searcher_settings);
      drupal_set_message(t(
        'The %label search page configuration has been deleted.',
        array('%label' => $searcher_settings->label)
      ));
      watchdog('luceneapi', 'Deleted search page configuration %name.', array('%name' => $searcher_name), WATCHDOG_NOTICE);
    }
  }

  // Deletes the index configuration settings.
  // @todo Invoke a hook that allows backends and indexers to delete their stuff.
  ctools_export_crud_delete('luceneapi_index', $form_state['values']['name']);
  ctools_export_load_object_reset('luceneapi_index');

  // Sets message, logs action.
  drupal_set_message(t(
    'The %label index configuration has been deleted.',
    array('%label' => $form_state['values']['label'])
  ));
  watchdog('luceneapi', 'Deleted index configuration %name.', array('%name' => $form_state['values']['name']), WATCHDOG_NOTICE);

  // Rebuilds the menu cache if any search page configuration were deleted.
  if ($searchers_deleted) {
    ctools_export_load_object_reset('luceneapi_searcher');
    menu_rebuild();
  }

  // Returns back to index list page.
  $form_state['redirect'] = 'admin/config/search/luceneapi/indexes';
}

/**
 * Export form, wrapper around ctools_export_form().
 *
 * @param $form
 *
 * @param &$form_state
 *
 * @param $settings
 *
 * @see ctools_export_form()
 */
function luceneapi_ui_export_form($form, &$form_state, LuceneapiSettings $settings) {

  // Adds link to get back to list page.
  $form['back'] = array(
    '#type' => 'link',
    '#title' => t('Go back to list page'),
    '#href' => luceneapi_ui_calculate_settings_path($settings->getTable()),
  );

  // Gets export fieldset from ctools_export_form().
  $title = t('Export configuration');
  $form = ctools_export_form($form, $form_state, $settings->getExport(), $title);

  // Adds settings and returns form.
  $form['#settings'] = $settings;
  return $form;
}

/**
 * Export page.
 */
function luceneapi_ui_export_page(LuceneapiSettings $settings) {
  return drupal_get_form('luceneapi_ui_export_form', $settings);
}
