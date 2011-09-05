// $Id: openlayers_behavior_panzoombar.js,v 1.1.2.3.2.2 2010/11/29 16:39:19 tmcw Exp $

/**
 * @file
 * JS Implementation of OpenLayers behavior.
 */

/**
 * Pan Zoom Bar Behavior
 */
(function($) {
    Drupal.behaviors.openlayers_behavior_panzoombar = {
    'attach': function(context, settings) {
      var data = $(context).data('openlayers');
      if (data && data.map.behaviors['openlayers_behavior_panzoombar']) {
        // Add control
        var control = new OpenLayers.Control.PanZoomBar();
        data.openlayers.addControl(control);
        control.activate();
      }
    }
  };
})(jQuery);
