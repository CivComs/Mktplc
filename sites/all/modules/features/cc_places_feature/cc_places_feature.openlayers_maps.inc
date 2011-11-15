<?php
/**
 * @file
 * cc_places_feature.openlayers_maps.inc
 */

/**
 * Implementation of hook_openlayers_maps().
 */
function cc_places_feature_openlayers_maps() {
  $export = array();

  $openlayers_maps = new stdClass;
  $openlayers_maps->disabled = FALSE; /* Edit this to true to make a default openlayers_maps disabled initially */
  $openlayers_maps->api_version = 1;
  $openlayers_maps->name = 'cc_interactions_map';
  $openlayers_maps->title = 'CC recent Activity Map';
  $openlayers_maps->description = 'CC map to output recent activity';
  $openlayers_maps->data = array(
    'width' => 'auto',
    'height' => '400px',
    'image_path' => '',
    'css_path' => '',
    'proxy_host' => '',
    'hide_empty_map' => 0,
    'center' => array(
      'initial' => array(
        'centerpoint' => '-104.1503906209, 47.279229001113',
        'zoom' => '3',
      ),
      'restrict' => array(
        'restrictextent' => 0,
        'restrictedExtent' => '',
      ),
    ),
    'behaviors' => array(
      'openlayers_behavior_zoomtolayer' => array(
        'zoomtolayer' => 'interactions_openlayers_1',
        'point_zoom_level' => '5',
      ),
      'openlayers_behavior_navigation' => array(
        'zoomWheelEnabled' => 0,
        'documentDrag' => 0,
      ),
      'openlayers_behavior_panzoombar' => array(),
      'openlayers_behavior_permalink' => array(),
      'openlayers_behavior_keyboarddefaults' => array(),
      'openlayers_behavior_popup' => array(
        'layers' => array(
          'interactions_openlayers_1' => 'interactions_openlayers_1',
        ),
      ),
    ),
    'default_layer' => 'google_normal',
    'layers' => array(
      'google_normal' => 'google_normal',
      'interactions_openlayers_1' => 'interactions_openlayers_1',
    ),
    'layer_weight' => array(
      'test_deployed_places_openlayers_2' => '-1',
      'places_openlayers_1' => '0',
      'places_openlayers_2' => '0',
      'places_bac_openlayers_2' => '0',
      'interactions_openlayers_1' => '0',
      'places_bac_openlayers_1' => '0',
      'test_deployed_places_openlayers_1' => '0',
      'cc_organizations_openlayers_1' => '0',
      'geofield_formatter' => '0',
    ),
    'layer_styles' => array(
      'geofield_formatter' => 'default',
      'test_deployed_places_openlayers_1' => 'default',
      'test_deployed_places_openlayers_2' => 'default',
      'cc_organizations_openlayers_1' => '0',
      'places_bac_openlayers_1' => '0',
      'places_bac_openlayers_2' => '0',
      'places_openlayers_1' => 'default',
      'places_openlayers_2' => '0',
      'interactions_openlayers_1' => 'default',
    ),
    'layer_styles_select' => array(
      'geofield_formatter' => 'default',
      'test_deployed_places_openlayers_1' => 'default',
      'test_deployed_places_openlayers_2' => 'default',
      'cc_organizations_openlayers_1' => 'default',
      'places_bac_openlayers_1' => 'default',
      'places_bac_openlayers_2' => 'default',
      'places_openlayers_1' => 'default',
      'places_openlayers_2' => 'default',
      'interactions_openlayers_1' => 'default',
    ),
    'layer_activated' => array(
      'interactions_openlayers_1' => 'interactions_openlayers_1',
      'geofield_formatter' => 0,
      'test_deployed_places_openlayers_1' => 0,
      'test_deployed_places_openlayers_2' => 0,
      'cc_organizations_openlayers_1' => 0,
      'places_bac_openlayers_1' => 0,
      'places_bac_openlayers_2' => 0,
      'places_openlayers_1' => 0,
      'places_openlayers_2' => 0,
    ),
    'layer_switcher' => array(
      'interactions_openlayers_1' => 0,
      'geofield_formatter' => 0,
      'test_deployed_places_openlayers_1' => 0,
      'test_deployed_places_openlayers_2' => 0,
      'cc_organizations_openlayers_1' => 0,
      'places_bac_openlayers_1' => 0,
      'places_bac_openlayers_2' => 0,
      'places_openlayers_1' => 0,
      'places_openlayers_2' => 0,
    ),
    'projection' => '900913',
    'displayProjection' => '4326',
    'styles' => array(
      'default' => 'default',
      'select' => 'default',
      'temporary' => 'default',
    ),
  );
  $export['cc_interactions_map'] = $openlayers_maps;

  $openlayers_maps = new stdClass;
  $openlayers_maps->disabled = FALSE; /* Edit this to true to make a default openlayers_maps disabled initially */
  $openlayers_maps->api_version = 1;
  $openlayers_maps->name = 'cc_organizations_map';
  $openlayers_maps->title = 'CC Organizations Map';
  $openlayers_maps->description = 'A Map Used for Organizations output';
  $openlayers_maps->data = array(
    'width' => 'auto',
    'height' => '300px',
    'image_path' => '',
    'css_path' => '',
    'proxy_host' => '',
    'hide_empty_map' => 1,
    'center' => array(
      'initial' => array(
        'centerpoint' => '-102.39257812096, 37.996162678431',
        'zoom' => '4',
      ),
      'restrict' => array(
        'restrictextent' => 0,
        'restrictedExtent' => '',
      ),
    ),
    'behaviors' => array(
      'openlayers_behavior_popup' => array(
        'layers' => array(
          'cc_organizations_openlayers_1' => 'cc_organizations_openlayers_1',
        ),
      ),
      'openlayers_behavior_keyboarddefaults' => array(),
      'openlayers_behavior_navigation' => array(
        'zoomWheelEnabled' => 0,
        'documentDrag' => 0,
      ),
      'openlayers_behavior_panzoombar' => array(),
      'openlayers_behavior_permalink' => array(),
      'openlayers_behavior_zoomtolayer' => array(
        'zoomtolayer' => 'cc_organizations_openlayers_1',
        'point_zoom_level' => '5',
      ),
    ),
    'default_layer' => 'google_normal',
    'layers' => array(
      'google_normal' => 'google_normal',
      'cc_organizations_openlayers_1' => 'cc_organizations_openlayers_1',
    ),
    'layer_weight' => array(
      'test_deployed_places_openlayers_2' => '-1',
      'places_openlayers_1' => '0',
      'places_openlayers_2' => '0',
      'places_bac_openlayers_2' => '0',
      'cc_organizations_openlayers_1' => '0',
      'places_bac_openlayers_1' => '0',
      'test_deployed_places_openlayers_1' => '0',
      'interactions_openlayers_1' => '0',
      'geofield_formatter' => '0',
    ),
    'layer_styles' => array(
      'geofield_formatter' => '0',
      'test_deployed_places_openlayers_1' => 'default',
      'test_deployed_places_openlayers_2' => 'default',
      'interactions_openlayers_1' => '0',
      'places_bac_openlayers_1' => '0',
      'places_bac_openlayers_2' => '0',
      'places_openlayers_1' => '0',
      'places_openlayers_2' => '0',
      'cc_organizations_openlayers_1' => 'default',
    ),
    'layer_activated' => array(
      'cc_organizations_openlayers_1' => 'cc_organizations_openlayers_1',
      'geofield_formatter' => 0,
      'test_deployed_places_openlayers_1' => 0,
      'test_deployed_places_openlayers_2' => 0,
      'interactions_openlayers_1' => 0,
      'places_bac_openlayers_1' => 0,
      'places_bac_openlayers_2' => 0,
      'places_openlayers_1' => 0,
      'places_openlayers_2' => 0,
    ),
    'layer_switcher' => array(
      'geofield_formatter' => 0,
      'test_deployed_places_openlayers_1' => 0,
      'test_deployed_places_openlayers_2' => 0,
      'cc_organizations_openlayers_1' => 0,
      'interactions_openlayers_1' => 0,
      'places_bac_openlayers_1' => 0,
      'places_bac_openlayers_2' => 0,
      'places_openlayers_1' => 0,
      'places_openlayers_2' => 0,
    ),
    'projection' => '900913',
    'displayProjection' => '4326',
    'styles' => array(
      'default' => 'default',
      'select' => 'default',
      'temporary' => 'default',
    ),
  );
  $export['cc_organizations_map'] = $openlayers_maps;

  $openlayers_maps = new stdClass;
  $openlayers_maps->disabled = FALSE; /* Edit this to true to make a default openlayers_maps disabled initially */
  $openlayers_maps->api_version = 1;
  $openlayers_maps->name = 'cc_places_map';
  $openlayers_maps->title = 'CC Places Map';
  $openlayers_maps->description = 'CC Map for Places output';
  $openlayers_maps->data = array(
    'width' => 'auto',
    'height' => '200px',
    'image_path' => '',
    'css_path' => '',
    'proxy_host' => '',
    'hide_empty_map' => 0,
    'center' => array(
      'initial' => array(
        'centerpoint' => '-104.1503906209, 47.279229001113',
        'zoom' => '3',
      ),
      'restrict' => array(
        'restrictextent' => 0,
        'restrictedExtent' => '',
      ),
    ),
    'behaviors' => array(
      'openlayers_behavior_popup' => array(
        'layers' => array(
          'places_openlayers_1' => 'places_openlayers_1',
        ),
      ),
      'openlayers_behavior_keyboarddefaults' => array(),
      'openlayers_behavior_navigation' => array(
        'zoomWheelEnabled' => 0,
        'documentDrag' => 0,
      ),
      'openlayers_behavior_panzoom' => array(),
      'openlayers_behavior_permalink' => array(),
      'openlayers_behavior_zoomtolayer' => array(
        'zoomtolayer' => 'places_openlayers_1',
        'point_zoom_level' => '5',
      ),
    ),
    'default_layer' => 'google_normal',
    'layers' => array(
      'google_normal' => 'google_normal',
      'places_openlayers_1' => 'places_openlayers_1',
    ),
    'layer_weight' => array(
      'test_deployed_places_openlayers_2' => '-1',
      'places_bac_openlayers_2' => '0',
      'places_openlayers_2' => '0',
      'places_bac_openlayers_1' => '0',
      'places_openlayers_1' => '0',
      'interactions_openlayers_1' => '0',
      'test_deployed_places_openlayers_1' => '0',
      'cc_organizations_openlayers_1' => '0',
      'geofield_formatter' => '0',
    ),
    'layer_styles' => array(
      'geofield_formatter' => 'default',
      'test_deployed_places_openlayers_1' => 'default',
      'test_deployed_places_openlayers_2' => 'default',
      'cc_organizations_openlayers_1' => '0',
      'interactions_openlayers_1' => '0',
      'places_bac_openlayers_1' => '0',
      'places_bac_openlayers_2' => '0',
      'places_openlayers_2' => '0',
      'places_openlayers_1' => 'default',
    ),
    'layer_activated' => array(
      'places_openlayers_1' => 'places_openlayers_1',
      'geofield_formatter' => 0,
      'test_deployed_places_openlayers_1' => 0,
      'test_deployed_places_openlayers_2' => 0,
      'cc_organizations_openlayers_1' => 0,
      'interactions_openlayers_1' => 0,
      'places_bac_openlayers_1' => 0,
      'places_bac_openlayers_2' => 0,
      'places_openlayers_2' => 0,
    ),
    'layer_switcher' => array(
      'places_openlayers_1' => 'places_openlayers_1',
      'geofield_formatter' => 0,
      'test_deployed_places_openlayers_1' => 0,
      'test_deployed_places_openlayers_2' => 0,
      'cc_organizations_openlayers_1' => 0,
      'interactions_openlayers_1' => 0,
      'places_bac_openlayers_1' => 0,
      'places_bac_openlayers_2' => 0,
      'places_openlayers_2' => 0,
    ),
    'projection' => '900913',
    'displayProjection' => '4326',
    'styles' => array(
      'default' => 'default',
      'select' => 'default',
      'temporary' => 'default',
    ),
  );
  $export['cc_places_map'] = $openlayers_maps;

  $openlayers_maps = new stdClass;
  $openlayers_maps->disabled = FALSE; /* Edit this to true to make a default openlayers_maps disabled initially */
  $openlayers_maps->api_version = 1;
  $openlayers_maps->name = 'cc_single_place_map';
  $openlayers_maps->title = 'CC Single Place Map';
  $openlayers_maps->description = 'CC map to output single place';
  $openlayers_maps->data = array(
    'width' => 'auto',
    'height' => '140px',
    'image_path' => '',
    'css_path' => '',
    'proxy_host' => '',
    'hide_empty_map' => 0,
    'center' => array(
      'initial' => array(
        'centerpoint' => '-102.91992187095, 45.089035563403',
        'zoom' => '3',
      ),
      'restrict' => array(
        'restrictextent' => 0,
        'restrictedExtent' => '',
      ),
    ),
    'behaviors' => array(
      'openlayers_behavior_popup' => array(
        'layers' => array(
          'places_openlayers_2' => 'places_openlayers_2',
        ),
      ),
      'openlayers_behavior_keyboarddefaults' => array(),
      'openlayers_behavior_navigation' => array(
        'zoomWheelEnabled' => 0,
        'documentDrag' => 0,
      ),
      'openlayers_behavior_permalink' => array(),
      'openlayers_behavior_zoomtolayer' => array(
        'zoomtolayer' => 'places_openlayers_2',
        'point_zoom_level' => '6',
      ),
    ),
    'default_layer' => 'google_normal',
    'layers' => array(
      'google_normal' => 'google_normal',
      'places_openlayers_2' => 'places_openlayers_2',
    ),
    'layer_weight' => array(
      'test_deployed_places_openlayers_2' => '-1',
      'interactions_openlayers_1' => '0',
      'places_openlayers_2' => '0',
      'cc_organizations_openlayers_1' => '0',
      'places_openlayers_1' => '0',
      'test_deployed_places_openlayers_1' => '0',
      'geofield_formatter' => '0',
    ),
    'layer_styles' => array(
      'geofield_formatter' => 'default',
      'test_deployed_places_openlayers_1' => 'default',
      'test_deployed_places_openlayers_2' => 'default',
      'places_openlayers_1' => 'default',
      'cc_organizations_openlayers_1' => '0',
      'interactions_openlayers_1' => '0',
      'places_openlayers_2' => 'default',
    ),
    'layer_activated' => array(
      'places_openlayers_2' => 'places_openlayers_2',
      'geofield_formatter' => 0,
      'test_deployed_places_openlayers_1' => 0,
      'test_deployed_places_openlayers_2' => 0,
      'places_openlayers_1' => 0,
      'cc_organizations_openlayers_1' => 0,
      'interactions_openlayers_1' => 0,
    ),
    'layer_switcher' => array(
      'geofield_formatter' => 0,
      'test_deployed_places_openlayers_1' => 0,
      'test_deployed_places_openlayers_2' => 0,
      'places_openlayers_1' => 0,
      'places_openlayers_2' => 0,
      'cc_organizations_openlayers_1' => 0,
      'interactions_openlayers_1' => 0,
    ),
    'projection' => '900913',
    'displayProjection' => '4326',
    'styles' => array(
      'default' => 'default',
      'select' => 'default',
      'temporary' => 'default',
    ),
  );
  $export['cc_single_place_map'] = $openlayers_maps;

  return $export;
}
