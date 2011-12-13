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
