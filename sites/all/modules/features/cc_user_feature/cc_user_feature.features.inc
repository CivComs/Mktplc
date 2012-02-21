<?php
/**
 * @file
 * cc_user_feature.features.inc
 */

/**
 * Implementation of hook_views_api().
 */
function cc_user_feature_views_api() {
  list($module, $api) = func_get_args();
  if ($module == "views" && $api == "views_default") {
    return array("version" => "3.0");
  }
}
