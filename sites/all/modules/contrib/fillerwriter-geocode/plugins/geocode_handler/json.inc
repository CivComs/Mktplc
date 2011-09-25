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
  'title' => t("GeoJSON"),
  'description' => t('Get the geometry of a GeoJSON string, file, or URL'),
  'callback' => 'geocode_json',
  'field_types' => array('text','text_long','file','computed'),
  'field_callback' => 'geocode_json_field',
);

/**
 * Process Markup
 */
function geocode_json($json_string) {
  geocode_load_geophp();
  return geoPHP::load($json_string,'json');
}

function geocode_json_field($field, $field_item) {
  if ($field['type'] == 'text' || $field['type'] == 'text_long' || $field['type'] == 'computed') {
  	return geocode_json($field_item['value']);
  }
  if ($field['type'] == 'file') {
  	$file = file_load($field_item['fid']);
  	$json = file_get_contents($file->uri);
  	return geocode_json($json);
  }
}
