<?php
/**
 * @file
 * Implementation of OpenLayers behavior.
 */

/**
 * Ctools plugin definition.
 */
$plugin = array(
  'title' => t('Layer Switcher'),
  'description' => t('Provides the ability to switch layers in the map interface.'),
  'type' => 'map',
  'behavior' => array(
    'file' => 'openlayers_behavior_layerswitcher.inc',
    'class' => 'openlayers_behavior_layerswitcher',
    'parent' => 'openlayers_behavior',
  ),
);

/**
 * Layer Switcher Behavior
 */
class openlayers_behavior_layerswitcher extends openlayers_behavior {
  /**
   * Provide initial values for options.
   */
  function options_init() {
    return array(
      'layerswitcher' => '',
      'ascending' => TRUE,
      'roundedCorner' => TRUE,
      'roundedCornerColor' => '#222222',
    );
  }

  function js_dependency() {
    return array('OpenLayers.Control.LayerSwitcher');
  }

  function options_form($defaults) {
    return array(
      'ascending' => array(
        '#type' => 'checkbox',
        '#title' => t('Show layers in ascending order'),
        '#description' => t('Higher layers shown toward the bottom'),
        '#default_value' => isset($defaults['ascending']) ? $defaults['ascending'] : TRUE,
      ),
      'roundedCorner' => array(
        '#type' => 'checkbox',
        '#title' => t('Rounded corners'),
        '#description' => t('If true the Rico library is used for rounding the corners of the layer switcher box.'),
        '#default_value' => isset($defaults['roundedCorner']) ? $defaults['roundedCorner'] : TRUE,
      ),
      'roundedCornerColor' => array(
        '#type' => 'textfield',
        '#title' => t('Rounded corners color'),
        '#description' => t('For rounded corners, this is the CSS color to use for the corners.'),
        '#default_value' => isset($defaults['roundedCornerColor']) ? $defaults['roundedCornerColor'] : '#222222', 
      ),
    );
  }

  /**
   * Render.
   */
  function render(&$map) {
    // Legacy code for maps not using the default images now
    // provided with the code, or for maps that dont have images
    // set.  We have to set the rounded corner color and add a 
    // class for CSS to style
    if (empty($map['image_path'])) {
      $this->options['roundedCornerColor'] = 'darkblue';
      $this->options['displayClass'] = 'olControlLayerSwitcher legacy';
    }
  
    drupal_add_js(drupal_get_path('module', 'openlayers') . 
      '/plugins/behaviors/openlayers_behavior_layerswitcher.js');
    return $this->options;
  }
}
