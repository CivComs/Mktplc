<?php
/**
 * @file
 * cc_content_creation.features.fe_block_boxes.inc
 */

/**
 * Implementation of hook_default_fe_block_boxes().
 */
function cc_content_creation_default_fe_block_boxes() {
  $export = array();

  $fe_block_boxes = new stdClass;
  $fe_block_boxes->info = 'Add to the Market Place';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'cc_add_to_marketplace';
  $fe_block_boxes->body = '<a class="add-button" href="node/add/application">Add an App</a>
<div class="example"><em>WordPress</em></div>
<a class="add-button" href="/node/add/interaction">tell us who did what</a>
<div class="example"><em>NY Senate deployed Drupal</em></div>
<p>The Marketplace is a wiki: <strong>you</strong> should improve it by <strong>adding civic software</strong> you know about, and where it’s being used.</p>';

  $export['cc_add_to_marketplace'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass;
  $fe_block_boxes->info = 'Add New content';
  $fe_block_boxes->format = 'php_code';
  $fe_block_boxes->machine_name = 'cc_jm_add_content';
  $fe_block_boxes->body = '<?php
// jump_menu($menu, $parent, $btn = false, $maxDepth = 0, $choose = \'Select Now\')
if (module_exists(\'jump_menu\')) {
  echo jump_menu(\'menu-add-content\', 2, false, 0, \'Add new...\');
}
?>';

  $export['cc_jm_add_content'] = $fe_block_boxes;

  return $export;
}
