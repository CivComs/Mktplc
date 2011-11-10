/**
 * @file
 * JS for interaction usability improvements.
 */


// Scope $ for jQuery
(function($){

/**
 * Drupal behavior for cc_interactions
 */
Drupal.behaviors.cc_interactions = {
  attach: function(context, settings) {
    
    // Check if user has any orgs.
    if (Drupal.settings.hasOwnProperty('cc_interactions') && Drupal.settings.cc_interactions.hasOwnProperty('user_orgs')) {
      
      // Create drop down
      var userOrgs = Drupal.settings.cc_interactions.user_orgs;
      var $dropdown = Drupal.behaviors.cc_interactions.orgDropdown(userOrgs);
      var $wrapper = $('.field-name-field-interaction-organization');
      var $input = $('#edit-field-interaction-organization-und-0-nid');
      var $innerWrapper = $('#edit-field-interaction-organization');
      var $dialogLinks = $wrapper.find('.dialog-links');
      
      // Add title and custom dropdown
      $wrapper.before('<h3>Which Organization</h3>');
      $wrapper.before($dropdown);
      $innerWrapper.hide();
      
      // Create chang event and fill in the first organization.
      $dropdown.change(function(e) {
        var id = $(this).find('option:selected').val();
        if (id != 'search') {
          $input.val(userOrgs[id] + ' [nid: ' + id + ']');
        }
        else {
          $input.val('');
          $innerWrapper.slideDown();
          $dropdown.slideUp();
        }
      })
      .trigger('change');
      
      
      // TODO
      // MAke input red until something found!  then green;
      
      // Make the automcplete search more usable;
      //$input.css('border-color', 'red').css('border-width', '10px');
      $dialogLinks.prepend('<strong>' + Drupal.t('We cant find your organization.') + '</strong>');
      $dialogLinks.hide();
      $input.keyup(function(e) {
        Drupal.behaviors.cc_interactions.checkValue($(this), $dialogLinks);
      });
      $input.blur(function(e) {
        Drupal.behaviors.cc_interactions.checkValue($(this), $dialogLinks);
      });
    }
  },
  
  orgDropdown: function(orgs) {
    var dropdown =
      '<div class="field-widget-options-select form-wrapper" id="edit-cc-interaction-user-orgs-id">' +
        '<div class="form-item form-type-select">' +
          '<label for="cc-interaction-user-orgs-id">' + Drupal.t('Your Organizations') + '</label>' +
            '<select id="cc-interaction-user-orgs-id class="cc-interactions-user-orgs form-select">';
    for (var o in orgs) {
      dropdown += '<option value="' + o + '">' + orgs[o] + '</option>'
    }
    dropdown += '<option value="search">' + Drupal.t('-Search for other Organizations-') + '</option>'
    dropdown += '</div></div></select>';
    
    return $(dropdown);
  },
  
  checkValue: function($input, $links) {
    if ($input.val().indexOf('[nid:') <= 0) {
      $links.slideDown();
      $input.css('border-color', 'red');
    }
    else {
      $links.slideUp();
      $input.css('border-color', 'green');
    }
  }
};


})(jQuery);