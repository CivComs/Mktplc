// $Id: openlayers_behavior_navigation.js,v 1.1.2.4.2.2 2010/11/29 16:39:19 tmcw Exp $

/**
 * @file
 * JS Implementation of OpenLayers behavior.
 */

/**
 * Navigation Behavior
 */
(function($) {
Drupal.behaviors.openlayers_behavior_navigation = {
  'attach': function(context, settings) {
    var data = $(context).data('openlayers');
    if (data && data.map.behaviors['openlayers_behavior_navigation']) {
      // Add control
      var options = {
        'zoomWheelEnabled': data.map.behaviors['openlayers_behavior_navigation'].zoomWheelEnabled
      };
      var control = new OpenLayers.Control.Navigation(options);
      data.openlayers.addControl(control);
      control.activate();
    }
  }
};
})(jQuery);
