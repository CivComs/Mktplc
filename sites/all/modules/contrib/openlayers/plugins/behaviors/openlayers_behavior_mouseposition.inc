<?php
/**
 * @file
 * Implementation of OpenLayers behavior.
 */

/**
 * Ctools plugin definition.
 */
$plugin = array(
  'title' => t('Mouse Position'),
  'description' => t('Provides a visual indication of the mouse position to the user.'),
  'type' => 'map',
  'behavior' => array(
    'file' => 'openlayers_behavior_mouseposition.inc',
    'class' => 'openlayers_behavior_mouseposition',
    'parent' => 'openlayers_behavior',
  ),
);

/**
 * Mouse Position Behavior
 */
class openlayers_behavior_mouseposition extends openlayers_behavior {
  /**
   * Provide initial values for options.
   */
  function options_init() {
    return array(
      'mouseposition' => '',
    );
  }

  function js_dependency() {
    return array('OpenLayers.Control.MousePosition');
  }

  function options_form($defaults) {
    return array();
  }

  /**
   * Render.
   */
  function render(&$map) {
    drupal_add_js(drupal_get_path('module', 'openlayers') . 
      '/plugins/behaviors/openlayers_behavior_mouseposition.js');
    return $this->options;
  }
}
