/**
 * @file
 * JS Implementation of OpenLayers behavior.
 */

/**
 * Geolocate Control.  Implements the Geolocate OpenLayers
 * Control.
 */
Drupal.openlayers.addBehavior('openlayers_behavior_geolocate', function (data, options) {
  // Create Geolocate control
  var geolocate = new OpenLayers.Control.Geolocate(options);
  data.openlayers.addControl(geolocate);

  // Add some event handling
  geolocate.events.register('locationupdated', this, function(e) {
    data.openlayers.setCenter(new OpenLayers.Geometry.Point(e.point.x, e.point.y), options.zoom_level);
  });
  geolocate.events.register('locationfailed', this, function(e) {
    OpenLayers.Console.log(Drupal.t('Location detection failed'));
  });

  // Activiate!
  geolocate.activate();
});
