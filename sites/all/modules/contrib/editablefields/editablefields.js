(function ($) {
Drupal.behaviors.editablefields_submit = {
  attach: function (context) {
    $('.editablefield-item').once('editablefield', function() {
      var $this = $(this);

      // There is only one editable field in that form, we can hide the submit
      // button.
      if ($this.find('input[type=text],textarea,select').length == 1) {
        $this.find('input.form-submit').hide();
        $this.find('input[type=text],textarea,select').change(function() {
          $this.find('input.form-submit').triggerHandler('click');
        });
      }
    });
  }
};

/**
 * Overridden from Drupal core autocomplete.js
 * Hides the autocomplete suggestions.
 */
Drupal.jsAC.prototype.hidePopup = function (keycode) {
  // Select item if the right key or mousebutton was pressed.
  if (this.selected && ((keycode && keycode != 46 && keycode != 8 && keycode != 27) || !keycode)) {
    this.input.value = $(this.selected).data('autocompleteValue');
    $(this.input).trigger('change');
  }
  // Hide popup.
  var popup = this.popup;
  if (popup) {
    this.popup = null;
    $(popup).fadeOut('fast', function () { $(popup).remove(); });
  }
  this.selected = false;
  $(this.ariaLive).empty();
};

})(jQuery);
