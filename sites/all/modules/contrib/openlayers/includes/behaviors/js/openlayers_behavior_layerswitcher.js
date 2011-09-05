// $Id: openlayers_behavior_layerswitcher.js,v 1.1.2.5.2.2 2010/11/29 16:39:19 tmcw Exp $

/**
 * @file
 * JS Implementation of OpenLayers behavior.
 */

/**
 * Layer Switcher Behavior
 */
(function($) {
  Drupal.behaviors.openlayers_behavior_layerswitcher = {
    'attach': function(context, settings) {
      var data = $(context).data('openlayers');
      if (data && data.map.behaviors['openlayers_behavior_layerswitcher']) {
        // Add control
        var control = new OpenLayers.Control.LayerSwitcher({
          'ascending': !!data.map.behaviors['openlayers_behavior_layerswitcher'].ascending
        });
        data.openlayers.addControl(control);
        control.activate();
      }
    }
  };
})(jQuery);
