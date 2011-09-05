// $Id: openlayers_behavior_zoombox.js,v 1.1.2.3.2.2 2010/11/29 16:39:19 tmcw Exp $

/**
 * @file
 * JS Implementation of OpenLayers behavior.
 */

/**
 * Zoom Box Behavior
 */
(function($) {
Drupal.behaviors.openlayers_behavior_zoombox = {
  'attach': function(context, settings) {
    var data = $(context).data('openlayers');
    if (data && data.map.behaviors['openlayers_behavior_zoombox']) {
      // Add control
      var control = new OpenLayers.Control.ZoomBox();
      data.openlayers.addControl(control);
      control.activate();
    }
  }
};
})(jQuery);
