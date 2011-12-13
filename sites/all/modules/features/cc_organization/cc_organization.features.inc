<?php
/**
 * @file
 * cc_organization.features.inc
 */

/**
 * Implementation of hook_ctools_plugin_api().
 */
function cc_organization_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implementation of hook_views_api().
 */
function cc_organization_views_api() {
  list($module, $api) = func_get_args();
  if ($module == "views" && $api == "views_default") {
    return array("version" => "3.0");
  }
}

/**
 * Implementation of hook_node_info().
 */
function cc_organization_node_info() {
  $items = array(
    'organization' => array(
      'name' => t('Organization'),
      'base' => 'node_content',
      'description' => t('An Organization is an operating entity, of type = government, nonprofit/ngo, company.  Organizations can play a number of roles, including technology user, service provider, etc.  And they interact with technologies ("Apps" in our nomenclature) in a number of ways, via "Interactions." The Organization data type deprecates the Agency and Vendor types.'),
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
  );
  return $items;
}
