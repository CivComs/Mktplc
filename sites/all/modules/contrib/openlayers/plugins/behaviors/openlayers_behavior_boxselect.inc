<?php
/**
 * @file
 * Implementation of OpenLayers behavior.
 */

/**
 * Ctools plugin definition.
 */
$plugin = array(
  'title' => t('Boxselect'),
  'description' => t('Allows the selection and display of a box.'),
  'type' => 'map',
  'behavior' => array(
    'file' => 'openlayers_behavior_boxselect.inc',
    'class' => 'openlayers_behavior_boxselect',
    'parent' => 'openlayers_behavior',
  ),
);

/**
 * BoxSelect Behavior
 */
class openlayers_behavior_boxselect extends openlayers_behavior {
  /**
   * Provide initial values for options.
   */
  function options_init() {
    return array(
      'input_fields' => '',
    );
  }

  function js_dependency() {
    return array(
      'OpenLayers.Control.DrawFeature',
      'OpenLayers.Layer.Vector',
      'OpenLayers.Handler.RegularPolygon'
    );
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
      '/plugins/behaviors/openlayers_behavior_boxselect.js');
    return $this->options;
  }
}
