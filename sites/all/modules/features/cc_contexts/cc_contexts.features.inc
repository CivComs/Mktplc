<?php
/**
 * @file
 * cc_contexts.features.inc
 */

/**
 * Implementation of hook_ctools_plugin_api().
 */
function cc_contexts_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
}
