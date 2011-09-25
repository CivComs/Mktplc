<?php
// $Id$

/**
 * @file
 * Plugin to provide a google geocoder.
 */

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'title' => t("KML"),
  'description' => t('Get the geometry out of a KML string, file, or URL'),
  'callback' => 'geocode_kml',
  'field_types' => array('text','text_long','file','computed'),
  'field_callback' => 'geocode_kml_field',
);

/**
 * Process Markup
 */
function geocode_kml($kml_string) {
  geocode_load_geophp();
  return geoPHP::load($kml_string,'kml');
}

function geocode_kml_field($field, $field_item) {
  if ($field['type'] == 'text' || $field['type'] == 'text_long' || $field['type'] == 'computed') {
  	return geocode_kml($field_item['value']);
  }
  if ($field['type'] == 'file') {
  	$file = file_load($field_item['fid']);
  	$kml = file_get_contents($file->uri);
  	return geocode_kml($kml);
  }
}