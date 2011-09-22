(function ($) {
  Drupal.PhoneNumber = Drupal.PhoneNumber || {};

  /**
   * Filters checkboxes based on their label.
   * This code is shamelessly taken from checkbox_filter
   */
  Drupal.PhoneNumber.filter = function() {
    var field = $(this);
    var checkboxes = $('.form-checkboxes .form-item', field.parent().parent());
    var found = false;
    var label = "";
    var option = null;
    for (var i = 0; i < checkboxes.length; i++) {
      option = checkboxes.eq(i);
      label = Drupal.PhoneNumber.trim(option.text());
      if (label.toUpperCase().indexOf(field.val().toUpperCase()) < 0) {
        option.hide();
      } else {
        option.show();
      }
    }
  };

  /**
   * Trims whitespace from strings
   */
  Drupal.PhoneNumber.trim = function(str) {
	  var	str = str.replace(/^\s\s*/, ''),
		  ws = /\s/,
		  i = str.length;
	  while (ws.test(str.charAt(--i)));
	  return str.slice(0, i + 1);
  };

  /**
   * Check/Uncheck all checkboxes
   */
  Drupal.PhoneNumber.checkall = function(e) {
    var field = $(this);
    var checkboxes = $('.form-checkboxes .form-item:visible .form-checkbox', field.parent().parent());

    var checked = (field.text() == Drupal.t('Select all'));
    if (checked) {
      checkboxes.attr('checked', true);
      field.text(Drupal.t('Deselect all'));
    }
    else {
      checkboxes.attr('checked', false);
      Drupal.PhoneNumber.checkDefault();
      field.text(Drupal.t('Select all'));
    }
  };

  /**
   * Country selection should include default country code by default.
   */
  Drupal.PhoneNumber.checkDefault = function(e) {
    var defaultCC = $('#edit-default-country').val();
    var span = $('<span class="default-cc"></span>').append(Drupal.t('Default'));

    if ($('.cck-phone-default-country').find('.form-checkbox').val() == defaultCC) {
      $('#edit-country-selection-' + defaultCC)
        .attr('checked', 'checked');
    }
    else {
      $('.cck-phone-default-country')
        .removeClass('cck-phone-default-country')
        .find('span.default-cc').remove();


      $('#edit-country-selection-' + defaultCC)
        .attr('checked', 'checked')
        .parents('.form-item:first')
          .addClass('cck-phone-default-country')
          .append(span);
    }
  };

  /**
   * Attach a filtering textfield to checkboxes.
   */
  Drupal.behaviors.PhoneNumber = function (context) {
    // Toggle collapsible on selection
    $('#edit-all-country-codes').change(function() {
      if ($(this).attr('checked')) {
        $('fieldset.cck-phone-settings').addClass('collapsed');
      }
      else {
        $('fieldset.cck-phone-settings').removeClass('collapsed');
      }
    });
    $('#edit-all-country-codes').trigger('change');

    // Ensure the new default country is checked
    $('#edit-default-country, .cck-phone-settings .form-checkboxes').bind('change', Drupal.PhoneNumber.checkDefault);
    $('#edit-default-country').trigger('change');
    $('form#content-field-edit-form').submit(Drupal.PhoneNumber.checkDefault);


    // Filter for countries
    var form = '<div class="form-item">'
             + '  <label>' + Drupal.t('Filter') + ':</label> '
             + '  <input class="cck-phone-filter" type="text" size="16" />'
             + '</div>'
             + '<div class="form-item">'
             + '  <a class="cck-phone-check" href="javascript://">' + Drupal.t('Select all') + '</a>'
             + '</div>';
    $('.cck-phone-settings .form-checkboxes', context).before(form);
    $('input.cck-phone-filter').bind('keyup', Drupal.PhoneNumber.filter);
    $('a.cck-phone-check').bind('click', Drupal.PhoneNumber.checkall);
  };
})(jQuery);