/**
 * @file
 * Main JS file for the CC API documentation page.
 */

// Namespace $ for jQuery
(function($) {

/**
 * Drupal behavior for the documentation page.
 */
Drupal.behaviors.ccAPIDocPageTOC = {
  attach: function(context, settings) {
    $('body').once('cc-api-toc', function() {
      $('.api-toc-container').tableOfContents($('.api-container'), {
        topLinks: true,
        depth: 5,
        startLevel: 2
      });
    });
  }
};
	
})(jQuery);