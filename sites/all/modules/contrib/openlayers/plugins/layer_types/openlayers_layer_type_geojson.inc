<?php
/**
 * @file
 * GeoJSON Layer Type
 */

/**
 * Define the Ctools plugin options.
 */
$plugin = array(
  'title' => t('GeoJSON'),
  'description' => t('Provides a vector layer based on <a href="!url">GeoJSON</a>.', 
    array('!url' => 'http://geojson.org/')),
  'layer_type' => array(
    'file' => 'openlayers_layer_type_geojson.inc',
    'class' => 'openlayers_layer_type_geojson',
    'parent' => 'openlayers_layer_type',
  ),
);

/**
 * OpenLayers GeoJSON Layer Type class
 */
class openlayers_layer_type_geojson extends openlayers_layer_type {
  function __construct($layer = array(), $map = array()) {
    parent::__construct($layer, $map);
    if (isset($this->data)) {
      $this->data += $this->options_init();
    }
    else {
      $this->data = $this->options_init();
    }
  }

  /**
   * Provide initial values for options.
   */
  function options_init() {
    return array(
      'layer_type' => 'openlayers_layer_type_geojson',
      'layer_handler' => 'geojson',
      'projection' => array('4326'),
      'baselayer' => FALSE,
      'vector' => TRUE,
      'geojson_data' => '',
    );
  }

  /**
   * Options form which generates layers
   */
  function options_form() {
    return array(
      'url' => array(
        '#type' => 'textfield',
        '#title' => t('URL'),
        '#description' => t('The URL of the GeoJSON file.  This can be a Drupal path as well, as it will get run through the Drupal <a href="!url">url()</a> function.', 
          array('!url' => 'http://api.drupal.org/api/drupal/includes--common.inc/function/url')),
        '#maxlength' => 1024,
        '#default_value' => isset($this->data['url']) ? $this->data['url'] : ''
      ),
      'geojson_data' => array(
        '#type' => 'textarea',
        '#title' => t('GeoJSON Data'),
        '#description' => t('Paste raw GeoJSON data here.  It is better to use a URL.  This is provided for very simple use cases like one or two features.  If there is data here, it will override the URL above.'),
        '#default_value' => isset($this->data['geojson_data']) ? $this->data['geojson_data'] : '',
      ),
      'layer_type' => array(
        '#type' => 'hidden',
        '#value' => 'openlayers_layer_type_geojson'
      ),
    );
  }

  /**
   * Render.
   */
  function render(&$map) {
    $this->options['url'] = !empty($this->options['url']) ? url($this->options['url']) : '';

    drupal_add_js(drupal_get_path('module', 'openlayers') 
      . '/plugins/layer_types/openlayers_layer_type_geojson.js');
    return $this->options;
  }
}
