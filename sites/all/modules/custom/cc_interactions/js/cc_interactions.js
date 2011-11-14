/**
 * @file
 * JS for interaction usability improvements.
 *
 * We have to override Drupal.jsAC.prototype.found so that
 * it fires an event.
 */


// Scope $ for jQuery
(function($){


/**
 * Drupal behavior for cc_interactions, specifically
 * for organization reference.  This hides the node
 * reference field and allows user to choose from 
 * their own first.
 */
Drupal.behaviors.cc_interactions_organizations = {
  attach: function(context, settings) {
    
    // Check if user has any orgs.
    if (Drupal.settings.hasOwnProperty('cc_interactions') && 
      Drupal.settings.cc_interactions.hasOwnProperty('user_orgs')) {
      
      // Create drop down
      var userOrgs = Drupal.settings.cc_interactions.user_orgs;
      var $dropdown = Drupal.behaviors.cc_interactions_organizations.orgDropdown(userOrgs);
      var $wrapper = $('.field-name-field-interaction-organization');
      var $input = $('#edit-field-interaction-organization-und-0-nid');
      var $innerWrapper = $('#edit-field-interaction-organization');
      
      // Add title and custom dropdown
      $wrapper.before('<h3 class="organiation-input-improvement">Which Organization</h3>');
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
    }
  },
  
  /**
   * Create dropdown for choosing own organizations.
   */
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
}

/**
 * Drupal behavior for cc_interactions
 */
Drupal.behaviors.cc_interactions = {
  attach: function(context, settings) {
    
    $('input.form-autocomplete').each(function() {

      // Create drop down
      var $input = $(this);
      var $wrapper = $input.parent().parent();
      var $innerWrapper = $input.find('.form-item');
      var $dialogLinks = $wrapper.find('.dialog-links');
      var dialogHrefOrig = $dialogLinks.find('a').attr('href');
      
      // Hand dialog links
      if ($dialogLinks.size() > 0) {
        // Add container for input value and hide by default
        $dialogLinks.prepend('<div class="dialog-input-value"></div>');
        $dialogLinks.hide();
        $input.before($dialogLinks);
        
        // Events for autocomplete
        $input.bind('autocomplete_notfound', function() {
          $dialogLinks.fadeIn();
        });
        $input.bind('autocomplete_found', function() {
          $dialogLinks.fadeOut();
        });
        
        // Make the automcplete search more usable;
        //$dialogLinks.hide();
        $('body').bind('dialog_closed', function() {
          // Hack to get around the fact that this does not seem to
          // get fired at the right time.
          var t = setTimeout(function() {
            Drupal.behaviors.cc_interactions.checkValue($input, $dialogLinks, dialogHrefOrig);
          }, 1000);
        });
      }

      $input.keyup(function(e) {
        Drupal.behaviors.cc_interactions.checkValue($(this), $dialogLinks, dialogHrefOrig);
      });
      $input.blur(function(e) {
        Drupal.behaviors.cc_interactions.checkValue($(this), $dialogLinks, dialogHrefOrig);
      });
      
    });
  },
  
  /**
   * Checks input value for correct format for node references.
   */
  checkValue: function($input, $links, href) {
    if ($input.val() == '') {
      return;
    }
    
    // Check links
    if ($links.size() > 0) {
      $links.find('.dialog-input-value').html(Drupal.t('Could not find: ') + 
        '<span class="input-value">' + $input.val() + '</span>');
      $links.find('a').attr('href', Drupal.addQueryString(href, 'edit[title]', $input.val()));
    }
    
    // Did we choose something?
    if ($input.val().indexOf('[nid:') <= 0) {
      $input.addClass('error interaction-node-reference-notfound')
        .removeClass('interaction-node-reference-found');
    }
    else {
      $input.addClass('interaction-node-reference-found')
        .removeClass('error interaction-node-reference-notfound');
      $links.hide();
    }
    
  }
};

/**
 * Utility function for object length
 */
Drupal.objectLength = function(object) {
  var count = 0;
  for (i in object) {
    if (object.hasOwnProperty(i)) {
        count++;
    }
  }
};

/**
 * Add query string to url
 *
 */
Drupal.addQueryString = function(url, key, value) {
  url += ((url.indexOf('?') > 0) ? '&' : '?') + 
    key + '=' + value;
  return url;
};

/**
 * OVERRIDE Fills the suggestion popup with any matches received.
 */
Drupal.jsAC = Drupal.jsAC || {};
Drupal.jsAC.prototype.found = function (matches) {
  if ($.isArray(matches) || Drupal.objectLength(matches) > 0) {
    $(this.input).trigger('autocomplete_notfound');
  }
  else {
    $(this.input).trigger('autocomplete_found');
  }

  // If no value in the textfield, do not show the popup.
  if (!this.input.value.length) {
    return false;
  }

  // Prepare matches.
  var ul = $('<ul></ul>');
  var ac = this;
  for (key in matches) {
    $('<li></li>')
      .html($('<div></div>').html(matches[key]))
      .mousedown(function () { ac.select(this); })
      .mouseover(function () { ac.highlight(this); })
      .mouseout(function () { ac.unhighlight(this); })
      .data('autocompleteValue', key)
      .appendTo(ul);
  }

  // Show popup with matches, if any.
  if (this.popup) {
    if (ul.children().size()) {
      $(this.popup).empty().append(ul).show();
      $(this.ariaLive).html(Drupal.t('Autocomplete popup'));
    }
    else {
      $(this.popup).css({ visibility: 'hidden' });
      this.hidePopup();
    }
  }
};

/**
 * OVERRIDE! To add event trigger when closing.
 * 
 * Close the dialog and provide an entity id and a title
 * that we can use in various ways.
 */
Drupal.ReferencesDialog = Drupal.ReferencesDialog || {};
Drupal.ReferencesDialog.close = function(entity_id, title) {
  this.open_dialog.dialog('close');
  this.open_dialog.dialog('destroy');
  this.open_dialog = null;
  this.dialog_open = false;
  // Call our entityIdReceived function if we have one.
  // this is used as an event.
  
  $('body').trigger('dialog_closed');
  
  if (typeof this.entityIdReceived == "function") {
    this.entityIdReceived(entity_id, title);
  }
}


/**
 * OVERRIDE!  To better make HREF
 *
 * Open a dialog window.
 * @param string href the link to point to.
 */
Drupal.ReferencesDialog = Drupal.ReferencesDialog || {};
Drupal.ReferencesDialog.open = function(href, title) {
  if (!this.dialog_open) {
    // Add render references dialog, so that we know that we should be in a
    // dialog.
    href = Drupal.addQueryString(href, 'render', 'references-dialog');
    // Get the current window size and do 75% of the width and 90% of the height.
    // @todo Add settings for this so that users can configure this by themselves.
    var window_width = $(window).width() / 100*75;
    var window_height = $(window).height() / 100*90;
    this.open_dialog = $('<iframe class="references-dialog-iframe" src="' + href + '"></iframe>').dialog({
      width: window_width,
      height: window_height,
      modal: true,
      resizable: false,
      position: ["center", 50],
      title: title,
      close: function() { Drupal.ReferencesDialog.dialog_open = false; }
    }).width(window_width-10).height(window_height)
    $(window).bind("resize scroll", function() {
      // Move the dialog the main window moves.
      if (typeof Drupal.ReferencesDialog == "object") {
        Drupal.ReferencesDialog.open_dialog.
          dialog("option", "position", ["center", 10]);
        Drupal.ReferencesDialog.setDimensions();
      }
    });
    this.dialog_open = true;
  }
}


})(jQuery);