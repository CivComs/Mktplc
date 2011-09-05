// $Id: openlayers_behavior_argparser.js,v 1.1.2.1.2.2 2010/11/29 16:39:19 tmcw Exp $

/**
 * @file
 * JS Implementation of OpenLayers behavior.
 */


(function($) {
/**
 * ArgParser Behavior
 */
Drupal.behaviors.openlayers_behavior_argparser = {
  'attach': function(context, settings) {
    var data = $(context).data('openlayers');
    if (data && data.map.behaviors['openlayers_behavior_argparser']) {
      // Add control
      var control = new OpenLayers.Control.ArgParser();
      data.openlayers.addControl(control);
      control.activate();
    }
  }
};
})(jQuery);
