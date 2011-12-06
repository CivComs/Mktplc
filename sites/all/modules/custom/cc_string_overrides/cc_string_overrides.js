(function($) {

/**
 * String Overrides behavior to load in JavaScript-based translations.
 */
Drupal.behaviors.cc_string_overrides = {
  attach: function (context, settings) {
    $('body').once('', function() {
      if (settings.cc_string_overrides || false) {
        // Make sure the strings array is initialized.
        Drupal.locale.strings = Drupal.locale.strings || {};
        // Add the string overrides translations to the strings array.
        jQuery.extend(Drupal.locale.strings, settings.cc_string_overrides);
      }
    });
  }
};

})(jQuery);