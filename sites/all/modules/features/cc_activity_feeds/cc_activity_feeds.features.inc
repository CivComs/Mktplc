<?php
/**
 * @file
 * cc_activity_feeds.features.inc
 */

/**
 * Implementation of hook_ctools_plugin_api().
 */
function cc_activity_feeds_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => "1");
  }
}

/**
 * Implementation of hook_node_info().
 */
function cc_activity_feeds_node_info() {
  $items = array(
    'activity_feeds' => array(
      'name' => t('Activity Feeds'),
      'base' => 'node_content',
      'description' => t('Activity Feeds used to aggregate data from around the internet about Civic Commons.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
