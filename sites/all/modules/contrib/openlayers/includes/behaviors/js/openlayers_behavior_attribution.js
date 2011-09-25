
/**
 * @file
 * JS Implementation of OpenLayers behavior.
 */

/**
 * Attribution Behavior
 */
(function($) {
Drupal.behaviors.openlayers_behavior_attribution = {
  'attach': function(context, settings) {
    var data = $(context).data('openlayers');
    if (data && data.map.behaviors['openlayers_behavior_attribution']) {
      // Add control
      var control = new OpenLayers.Control.Attribution();
      data.openlayers.addControl(control);
      control.activate();
    }
  }
};
})(jQuery);
