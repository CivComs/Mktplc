<?php
/**
 * @file
 * cc_places_feature.openlayers_styles.inc
 */

/**
 * Implementation of hook_openlayers_styles().
 */
function cc_places_feature_openlayers_styles() {
  $export = array();

  $openlayers_styles = new stdClass;
  $openlayers_styles->disabled = FALSE; /* Edit this to true to make a default openlayers_styles disabled initially */
  $openlayers_styles->api_version = 1;
  $openlayers_styles->name = 'cc_default';
  $openlayers_styles->title = 'CC Default style';
  $openlayers_styles->description = 'CC default style.';
  $openlayers_styles->data = array(
    'pointRadius' => 15,
    'fillColor' => '#FFCC66',
    'strokeColor' => '#FF9933',
    'strokeWidth' => 6,
    'fillOpacity' => 0.5,
    'strokeOpacity' => 1,
    'strokeLinecap' => 'round',
    'strokeDashstyle' => 'solid',
    'graphicWidth' => 300,
    'graphicHeight' => 200,
    'graphicOpacity' => 1,
    'labelAlign' => 'cm',
    'fontSize' => '24',
    'fontWeight' => 'bold',
  );
  $export['cc_default'] = $openlayers_styles;

  return $export;
}
