// $Id: openlayers_behavior_permalink.js,v 1.1.2.3.2.1 2010/10/11 21:28:40 tmcw Exp $

/**
 * @file
 * JS Implementation of OpenLayers behavior.
 */

/**
 * Permalink Behavior
 */
(function($) {
  Drupal.behaviors.openlayers_behavior_permalink = {
    'attach': function(context, settings) {
    var data = $(context).data('openlayers');
    if (data && data.map.behaviors['openlayers_behavior_permalink']) {
      // Add control
      var control = new OpenLayers.Control.Permalink();
      data.openlayers.addControl(control);
      control.activate();
    }
  }
})(jQuery);
