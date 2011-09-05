// $Id: openlayers_behavior_zoomtomaxextent.js,v 1.1.2.3.2.2 2010/11/29 16:39:19 tmcw Exp $

/**
 * @file
 * JS Implementation of OpenLayers behavior.
 */

/**
 * Zoom Max Extent Behavior
 */
(function($) {
  Drupal.behaviors.openlayers_behavior_zoomtomaxextent = {
    'attach': function(context, settings) {
      var data = $(context).data('openlayers');
      if (data && data.map.behaviors['openlayers_behavior_zoomtomaxextent']) {
        var panel = new OpenLayers.Control.Panel({
          allowSelection: true
        });

        data.openlayers.addControl(panel);
        panel.activate();

        var button = new OpenLayers.Control.ZoomToMaxExtent();
        panel.addControls(button);
      }
    }
  };
})(jQuery);
