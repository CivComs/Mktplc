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
  'title' => t("WKT Geocoder"),
  'description' => t('Get the geomtry of a WKT string'),
  'callback' => 'geocode_wkt',
  'field_types' => array('text','text_long','file','geofield','computed'),
  'field_callback' => 'geocode_wkt_field',
);

/**
 * Process WKT
 */
function geocode_wkt($wkt) {
  geocode_load_geophp();
  return geoPHP::load($wkt,'wkt');
}

function geocode_wkt_field($field, $field_item) {
	if ($field['type'] == 'text' || $field['type'] == 'text_long' || $field['type'] == 'computed') {
		return geocode_wkt($field_item['value']);
	}
	if ($field['type'] == 'geofield') {
		return geocode_wkt($field_item['wkt']);
	}
  if ($field['type'] == 'file') {
  	$file = file_load($field_item['fid']);
  	$wkt = file_get_contents($file->uri);
  	return geocode_wkt($wkt);
  }
}
