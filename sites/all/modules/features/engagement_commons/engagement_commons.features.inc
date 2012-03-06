<?php
/**
 * @file
 * engagement_commons.features.inc
 */

/**
 * Implementation of hook_ctools_plugin_api().
 */
function engagement_commons_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
}

/**
 * Implementation of hook_views_api().
 */
function engagement_commons_views_api() {
  list($module, $api) = func_get_args();
  if ($module == "views" && $api == "views_default") {
    return array("version" => "3.0");
  }
}

/**
 * Implementation of hook_image_default_styles().
 */
function engagement_commons_image_default_styles() {
  $styles = array();

  // Exported image style: engagement_commons_feature
  $styles['engagement_commons_feature'] = array(
    'name' => 'engagement_commons_feature',
    'effects' => array(
      18 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => '940',
          'height' => '300',
        ),
        'weight' => '1',
      ),
    ),
  );

  return $styles;
}
