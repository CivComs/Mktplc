// $Id: openlayers_behavior_dragpan.js,v 1.1.2.3.2.1 2010/11/29 16:39:19 tmcw Exp $

/**
 * @file
 * JS Implementation of OpenLayers behavior.
 */

(function($) {
/**
 * DragPan Behavior
 */
Drupal.behaviors.openlayers_behavior_dragpan = function(context) {
  var data = $(context).data('openlayers');
  if (data && data.map.behaviors['openlayers_behavior_dragpan']) {
    // Add control
    var control = new OpenLayers.Control.DragPan();
    data.openlayers.addControl(control);
    control.activate();
  }
}
})(jQuery);
