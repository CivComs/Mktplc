<?php
/**
 * @file
 * Implementation of OpenLayers behavior.
 */

/**
 * Ctools plugin definition.
 */
$plugin = array(
  'title' => t('Permalink'),
  'description' =>  t('Provides a URL that will link to a specific map position.'),
  'type' => 'map',
  'behavior' => array(
    'file' => 'openlayers_behavior_permalink.inc',
    'class' => 'openlayers_behavior_permalink',
    'parent' => 'openlayers_behavior',
  ),
);

/**
 * PermaLink Behavior
 */
class openlayers_behavior_permalink extends openlayers_behavior {
  /**
   * Provide initial values for options.
   */
  function options_init() {
    return array(
      'permalink' => '',
    );
  }

  function js_dependency() {
    return array('OpenLayers.Control.Permalink');
  }

  function options_form($defaults) {
    return array();
  }

  /**
   * Render.
   */
  function render(&$map) {
    drupal_add_js(drupal_get_path('module', 'openlayers') . 
      '/plugins/behaviors/openlayers_behavior_permalink.js');
    return $this->options;
  }
}
