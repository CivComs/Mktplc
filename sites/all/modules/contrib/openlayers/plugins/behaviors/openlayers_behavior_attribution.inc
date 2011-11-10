<?php
/**
 * @file
 * Implementation of OpenLayers behavior.
 */

/**
 * Ctools plugin definition.
 */
$plugin = array(
  'title' => t('Attribution'),
  'description' => t('Allows layers to provide attribution to the map if it exists.'),
  'type' => 'layer',
  'behavior' => array(
    'file' => 'openlayers_behavior_attribution.inc',
    'class' => 'openlayers_behavior_attribution',
    'parent' => 'openlayers_behavior',
  ),
);

/**
 * Attribution Behavior
 */
class openlayers_behavior_attribution extends openlayers_behavior {
  /**
   * Provide initial values for options.
   */
  function options_init() {
    return array(
      'attribution' => '',
    );
  }

  function js_dependency() {
    return array('OpenLayers.Control.Attribution');
  }

  function options_form($defaults) {
    return array(
    );
  }

  /**
   * Render.
   */
  function render(&$map) {
    drupal_add_js(drupal_get_path('module', 'openlayers') . 
      '/plugins/behaviors/openlayers_behavior_attribution.js');
    return $this->options;
  }
}
