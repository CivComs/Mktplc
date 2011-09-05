// $Id: google.js,v 1.1.2.2 2010/09/15 21:28:21 tmcw Exp $

/**
 * Process Google Layers
 *
 * @param layerOptions
 *   Object of options.
 * @param map
 *   Reference to OpenLayers object.
 * @return
 *   Valid OpenLayers layer.
 */
Drupal.openlayers.layer.google = function(title, map, options) {
  var styleMap = Drupal.openlayers.getStyleMap(map, options.drupalID);

  var google_type_map = {
    'normal': G_NORMAL_MAP,
    'satellite': G_SATELLITE_MAP,
    'hybrid': G_HYBRID_MAP,
    'physical': G_PHYSICAL_MAP
  };

  options.sphericalMercator = true;
  options.maxExtent = new OpenLayers.Bounds(-20037508.34, -20037508.34, 20037508.34, 20037508.34);
  options.type = google_type_map[options.type];

  var layer = new OpenLayers.Layer.Google(title, options);
  layer.styleMap = styleMap;
  return layer;
};
