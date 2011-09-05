// $Id: openlayers_behavior_scaleline.js,v 1.1.2.3.2.1 2010/10/11 21:28:40 tmcw Exp $

/**
 * @file
 * JS Implementation of OpenLayers behavior.
 */

/**
 * Scale Line Behavior
 */
(function($) {
Drupal.behaviors.openlayers_behavior_scaleline = {
  'attach': function(context, settings) {
  var data = $(context).data('openlayers');
  if (data && data.map.behaviors['openlayers_behavior_scaleline']) {
    // Add control
    var control = new OpenLayers.Control.ScaleLine();
    data.openlayers.addControl(control);
    control.activate();
  }
}
})(jQuery);
