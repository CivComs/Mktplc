/**
 * @file
 * JS Implementation of OpenLayers behavior.
 */

/**
 * OpenLayers Zoom to Layer Behavior
 */
Drupal.openlayers.addBehavior('openlayers_behavior_zoomtolayer', function (data, options) {
  var map = data.openlayers;
  var layers = map.getLayersBy('drupalID', options.zoomtolayer);

  // Go through selected layers to get full extent.
  for (var i in layers) {
    if (layers[i].features !== undefined) {
      // For KML layers, we need to wait until layer is loaded.  Ideally
      // we could check for any layer that is loading from an external
      // source, but for now, just check KML
      if (layers[i].layer_handler == 'kml') {
        layers[i].events.register('loadend', layers[i], function() {
          layerextent = layers[i].getDataExtent();
          map.zoomToExtent(layerextent);
        });
      }
      else {
        layerextent = layers[i].getDataExtent();
        // Check for valid layer extent
        if (layerextent != null) {
          map.zoomToExtent(layerextent);

          // If unable to find width due to single point,
          // zoom in with point_zoom_level option.
          if (layerextent.getWidth() == 0.0) {
            map.zoomTo(options.point_zoom_level);
          }
        }
      }
    }
  }
});
