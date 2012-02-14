<?php
/**
 * @file
 * cc_user_actions.features.inc
 */

/**
 * Implementation of hook_ctools_plugin_api().
 */
function cc_user_actions_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
}
