/**
 * @file
 * Civic Common theme, general JS.
 */
 
// Namespace jQuery
(function($) {
  $(document).ready(function() {
    // Fire of row evenizers on page load
    evenizeRowHeights(".view-applications .views-row .views-field-field-application-sdesc");
    evenizeRowHeights(".view-places .views-row .field-content");
    evenizeRowHeights(".meta");
    // Make front page columns same height
    evenizeRowHeights(".front .region-content-main-left .view, .front .region-content-main-middle .view, .front .region-content-main-right .view");
  });

  /**
   * Makes all app listing rows the same height --
   * using the height of the tallest row for everything.
   */
  function evenizeRowHeights(selector) {
    var rowMaxHeight = 0;
    $(selector).each(function () {
      var elHeight = $(this).height();
      if (elHeight > rowMaxHeight) {
        rowMaxHeight = elHeight;
      }
    });
    $(selector).each(function () {
      $(this).height(rowMaxHeight);
    });  
  }
})(jQuery);