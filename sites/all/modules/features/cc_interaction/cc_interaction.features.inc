<?php
/**
 * @file
 * cc_interaction.features.inc
 */

/**
 * Implementation of hook_ctools_plugin_api().
 */
function cc_interaction_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implementation of hook_views_api().
 */
function cc_interaction_views_api() {
  list($module, $api) = func_get_args();
  if ($module == "views" && $api == "views_default") {
    return array("version" => "3.0");
  }
}

/**
 * Implementation of hook_node_info().
 */
function cc_interaction_node_info() {
  $items = array(
    'interaction' => array(
      'name' => t('Interaction'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
