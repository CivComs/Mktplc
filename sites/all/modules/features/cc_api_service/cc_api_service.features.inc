<?php
/**
 * @file
 * cc_api_service.features.inc
 */

/**
 * Implementation of hook_ctools_plugin_api().
 */
function cc_api_service_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "services" && $api == "services") {
    return array("version" => "3");
  }
}
