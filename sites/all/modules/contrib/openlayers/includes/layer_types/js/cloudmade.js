// $Id: cloudmade.js,v 1.1.2.2 2010/09/15 21:28:21 tmcw Exp $

/**
 * Process CloudMade Layers
 *
 * @param layerOptions
 *   Object of options.
 * @param map
 *   Reference to OpenLayers object.
 * @return
 *   Valid OpenLayers layer.
 */
Drupal.openlayers.layer.cloudmade = function(title, map, options) {
  var styleMap = Drupal.openlayers.getStyleMap(map, options.drupalID);

  // options.sphericalMercator = true;
  options.maxExtent = new OpenLayers.Bounds(-20037508, -20037508, 20037508, 20037508);
  options.projection = 'EPSG:' + options.projection;

  var layer = new OpenLayers.Layer.CloudMade(title, options);
  layer.styleMap = styleMap;
  return layer;
};
