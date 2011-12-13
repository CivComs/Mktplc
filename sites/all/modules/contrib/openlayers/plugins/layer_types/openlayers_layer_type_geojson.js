/**
 * @file
 * Layer handler for GeoJSON layers
 */

/**
 * Openlayer layer handler for KML layer
 */
(function($) {

Drupal.openlayers.layer.geojson = function(title, map, options) {
  var features = null;
  options.projection = 'EPSG:' + options.projection;
  options.styleMap = Drupal.openlayers.getStyleMap(map, options.drupalID);
  var layer = new OpenLayers.Layer.Vector(title, options);

  // GeoJSON Projection handling
  var geojson_options = {
    'internalProjection': new OpenLayers.Projection('EPSG:' + map.projection),
    'externalProjection': new OpenLayers.Projection(options.projection)
  };

  // If GeoJSON data is provided with the layer, use that
  if (options.geojson_data) {
    // Read data in.
    features = new OpenLayers.Format.GeoJSON(geojson_options).read(options.geojson_data);
    if (features) {
      // If not array (ie only one feature)
      if (features.constructor != Array) {
        features = [features];
      }
    }
    
    // Add features, if needed
    if (features) {
      layer.addFeatures(features);
    }
  }
  else {
    // Use an AJAX like call to get data from URL
    OpenLayers.loadURL(options.url, {}, null, function (response) {
      var format = new OpenLayers.Format.GeoJSON(geojson_options);
      var features = format.read(response.responseText);
      // Add features, if needed
      if (features) {
        layer.addFeatures(features);
      }
    });
    
    // Extend options with a Fixed strategy fo getting from URL.
    //
    // This seems a bit more natural but does not
    // seem to work.
    /*
    options = $.extend(options, {
      strategies: [ new OpenLayers.Strategy.Fixed() ],
      protocol: new OpenLayers.Protocol.HTTP({
        url: options.url,
        format: new OpenLayers.Format.GeoJSON()
      })
    });
    */
  }

  return layer;
};

})(jQuery);



