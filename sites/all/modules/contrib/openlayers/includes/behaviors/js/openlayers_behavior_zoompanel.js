// $Id: openlayers_behavior_zoompanel.js,v 1.1.2.1.2.3 2010/12/06 22:27:11 tmcw Exp $

/**
 * @file
 * JS Implementation of OpenLayers behavior.
 */

/**
 * ZoomPanel Behavior
 */
(function($) {
Drupal.behaviors.openlayers_behavior_zoompanel = {
  'attach': function(context, settings) {
    var data = $(context).data('openlayers');
    if (data && data.map.behaviors['openlayers_behavior_zoompanel']) {
      // Add control
      var control = new OpenLayers.Control.ZoomPanel();
      data.openlayers.addControl(control);
      control.activate();
    }
  }
};
})(jQuery);
