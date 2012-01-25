<?php
/**
 * @file
 * engagement_commons.features.inc
 */

/**
 * Implementation of hook_views_api().
 */
function engagement_commons_views_api() {
  list($module, $api) = func_get_args();
  if ($module == "views" && $api == "views_default") {
    return array("version" => "3.0");
  }
}
