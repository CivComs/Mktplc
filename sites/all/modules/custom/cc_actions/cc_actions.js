/**
 * @file
 * JS file for CC ACtions module.
 */

// Namespace jQuery
(function($) {

/**
 * Drupal behavior for the CC Actions block.
 */
Drupal.behaviors.CCActionsBlock = {
  attach: function(context, settings) {
    $('#block-cc-actions-cc-actions .content').once('block-cc-actions-cc-actions-processed', function() {
      var $list = $(this);
      var $expanding = $list.find('li:not(.cc-actions-my-account)');
      
      $list.find('li.cc-actions-my-account div.top-level-item').click(function() {
        var $clicker = $(this);
        $clicker.toggleClass('cc-actions-expanded');
        $expanding.toggle($clicker.hasClass('cc-actions-expanded'));
      });
    });
  }
};

})(jQuery);