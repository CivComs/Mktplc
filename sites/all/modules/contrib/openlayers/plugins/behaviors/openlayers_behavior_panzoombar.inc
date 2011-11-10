<?php
/**
 * @file
 * Implementation of OpenLayers behavior.
 */

/**
 * Ctools plugin definition.
 */
$plugin = array(
  'title' => t('PanZoomBar'),
  'description' => t('Gives user ability to pan and zoom, with a zoom bar, in the map interface.'),
  'type' => 'map',
  'behavior' => array(
    'file' => 'openlayers_behavior_panzoombar.inc',
    'class' => 'openlayers_behavior_panzoombar',
    'parent' => 'openlayers_behavior',
  ),
);

/**
 * Pan Zoom Bar Behavior
 */
class openlayers_behavior_panzoombar extends openlayers_behavior {
  /**
   * Provide initial values for options.
   */
  function options_init() {
    return array(
      'panzoombar' => '',
    );
  }

  function js_dependency() {
    return array('OpenLayers.Control.PanZoomBar');
  }

  function options_form($defaults) {
    return array();
  }

  /**
   * Render.
   */
  function render(&$map) {
    drupal_add_js(drupal_get_path('module', 'openlayers') . 
      '/plugins/behaviors/openlayers_behavior_panzoombar.js');
    return $this->options;
  }
}
