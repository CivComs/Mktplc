<?php
/**
 * @file
 * Implementation of OpenLayers behavior.
 */

/**
 * Ctools plugin definition.
 */
$plugin = array(
  'title' => t('DragPan'),
  'description' => t('Provides the ability to pan in the map interface.'),
  'type' => 'map',
  'behavior' => array(
    'file' => 'openlayers_behavior_dragpan.inc',
    'class' => 'openlayers_behavior_dragpan',
    'parent' => 'openlayers_behavior',
  ),
);

/**
 * DragPan Behavior
 */
class openlayers_behavior_dragpan extends openlayers_behavior {
  /**
   * Provide initial values for options.
   */
  function options_init() {
    return array(
      'navigation' => '',
    );
  }

  function js_dependency() {
    return array('OpenLayers.Control.DragPan');
  }

  function options_form($defaults) {
    return array();
  }

  /**
   * Render.
   */
  function render(&$map) {
    drupal_add_js(drupal_get_path('module', 'openlayers') . 
      '/plugins/behaviors/openlayers_behavior_dragpan.js');
    return $this->options;
  }
}
