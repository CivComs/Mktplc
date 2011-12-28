
/**
 * @file:
 * Converts textfield to a autocomplete deluxe widget.
 */

(function($) {
  Drupal.autocomplete_deluxe = Drupal.autocomplete_deluxe || {};

  Drupal.behaviors.autocomplete_deluxe = {
    attach: function(context) {
      var autocomplete_settings = Drupal.settings.autocomplete_deluxe;

      $('input.autocomplete-deluxe-form').once( function() {
        new Drupal.autocomplete_deluxe(this, autocomplete_settings[$(this).attr('id')]);
      });
    }
  };

  /**
   * Autocomplete deluxe object.
   */
  Drupal.autocomplete_deluxe = function(input, settings) {
    this.id = settings.input_id;
    this.jqObject = $('#' + this.id);
    this.jqObject.addClass('ui-corner-left');
    this.type = settings.type;
    this.minLength = settings.min_length;

    this.multiple = settings.multiple;

    this.opendByFocus = false;
    this.keyPress = false;

    if (settings.select_input !== undefined) {
      this.selectInput = $('#' + settings.select_input);
      this.selectInput.hide();
      this.jqObject.show();
    }

    this.button = $('<span>&nbsp;</span>');
    this.button.attr({
      'tabIndex': -1,
      'title': 'Show all items'
    });
    this.button.insertAfter(this.jqObject);

    this.button.button({
      icons: {
        primary: 'ui-icon-triangle-1-s'
      },
      text: false
    });

    // Don't round the left corners.
    this.button.removeClass('ui-corner-all');
    this.button.addClass('ui-corner-right ui-button-icon autocomplete-deluxe-button');

    this.jqObject.autocomplete();
    this.jqObject.autocomplete("option", "minLength", this.minLength);
    // Add a custom class, so we can style the autocomplete box without
    // interfering with other jquery autocomplete widgets.
    this.jqObject.autocomplete("widget").addClass('autocomplete-deluxe-widget');

    this.hasFocus = false;

    // Save the current autocomplete object, so it can be used in
    // handlers.
    var instance = this;

    // Override enter keypress for the form, but only when the input hasn't
    // the focus and it isn\t empty.
    $('form').keypress(function(event) {
      if (event.keyCode == 13 && instance.hasFocus && instance.jqObject.val() !== "") return false;
    });

    // Event handlers.
    this.jqObject.focus( function(eventObject) {
      // Overlay causes a second focus, wich has to be instance.catched.
      if (eventObject.originalEvent === undefined) {
        return false;
      }
      instance.open();
      instance.opendByFocus = true;
    });

    this.jqObject.focusin(function(){
      instance.hasFocus = true;
    })

    this.jqObject.focusout(function(){
      instance.hasFocus = false;
    })

    // Needed when the window is closed but the textfield has the focus.
    this.jqObject.click( function() {
      if (!instance.opendByFocus) {
        instance.toggle();
      }
      else {
        instance.opendByFocus = false;
      }
    });

    // Create the source item, set its options and elements and initialize it.
    switch (this.type) {
      case 'ajax':
        var uri = settings.uri;
        this.source = new Drupal.autocomplete_deluxe.ajaxSource(uri);
        break;
      case 'list':
        this.source = new Drupal.autocomplete_deluxe.listSource(settings.data, this.selectInput);
        break;
    }
    this.source.autocomplete = this;
    this.source.multiple = settings.multiple;
    if (this.multiple) {
      this.source.container = this.jqObject.parent().parent().children('.autocomplete-deluxe-values');
    }
    this.source.init();

    this.jqObject.autocomplete("option", "source", function(request, response) {
      instance.source.setResponse(request, response);
    });
    this.jqObject.bind("autocompletesearch", function(event, ui) {
      instance.jqObject.addClass('throbbing');
      return ui;
    });
    // Don't set the value input when autocomplete window has focus.
    this.jqObject.bind("autocompletefocus", function(event, ui) {
      return false;
    });
    this.jqObject.bind("autocompletechange", function(event, ui) {
      instance.source.change(event, ui);
    });
    this.jqObject.bind("autocompleteselect", function(event, ui) {
      instance.close();
      instance.opendByFocus = false;
      var ret = instance.source._select(this, ui);
      if (instance.keyPress === false) {
        this.blur();
      } else {
        instance.keyPress = false;
      }
      return ret;
    });
    this.jqObject.blur(function() {
      if (!instance.jqObject.autocomplete("widget").is(":visible")) {
        var val = instance.jqObject.val();
        if (val.substring(val.length, val.length - 2) == ', ') {
          instance.jqObject.val(val.substring(0, val.length - 2));
        }
      }
    });
    this.jqObject.keypress(function(event) {
      instance.keyPress = true;
      instance.source.keypress(event);
    });
    this.jqObject.keyup(function(event) {
      if (instance.multiple && event.which == 188 || event.which == 13) {
        instance.jqObject.val('');
        instance.close();
      }
    });

    // Since jquery autocomplete by default strips html text by using .text()
    // we need our own _renderItem function to display html content.
    this.jqObject.data("autocomplete")._renderItem = function(ul, item) {
      return $("<li></li>").data("item.autocomplete", item).append("<a>" + item.label + "</a>").appendTo(ul);
    };

    // Costume response callback to delete the throbbing class. Could be deleted
    // once the ui-autocomplete-loading css class is implemented in seven theme.
    this.jqObject.data("autocomplete")._response = function(content) {
      if (content && content.length) {
        content = this._normalize(content);
        this._suggest(content);
        this._trigger("open");
      }
      else {
        this.close();
      }
      this.element.removeClass('throbbing');
    };

    this.button.click( function() {
      instance.jqObject.blur();
      instance.toggle(true);
    });
  };

  /**
   * EscapeRegex function from jquery autocomplete, is not included in drupal.
   */
  Drupal.autocomplete_deluxe.escapeRegex = function(value) {
    return value.replace(/[-[\]{}()*+?.,\\^$|#\s]/gi, "\\$&");
  };

  /**
   * Filter function from jquery autocomplete, is not included in drupal.
   */
  Drupal.autocomplete_deluxe.filter = function(array, term) {
    var matcher = new RegExp(Drupal.autocomplete_deluxe.escapeRegex(term), "i");
    return $.grep(array, function(value) {
      return matcher.test(value.label || value.value || value);
    });
  };

  /**
   * Open the autocomplete window.
   * @param emptySearch If true it will perform an empty search.
   */
  Drupal.autocomplete_deluxe.prototype.open = function(emptySearch) {
    if ( emptySearch !== undefined) {
      var item = this.jqObject.val();
      var searchFor = item.substring(0, this.minLength);
    }
    else {
      var searchFor = this.jqObject.val();
    }
    this.jqObject.autocomplete("search", searchFor);
    this.button.addClass("ui-state-focus");
  };

  /**
   * Close the autocomplete window.
   */
  Drupal.autocomplete_deluxe.prototype.close = function() {
    this.jqObject.autocomplete("close");
    this.button.removeClass("ui-state-focus");
    this.opendByFocus = false;
  };

  /**
   * Toggle the autcomplete window.
   * @param emptySearch If true and autocomplete is opening, it will perform an
   *                    empty search.
   */
  Drupal.autocomplete_deluxe.prototype.toggle = function(emptySearch) {
    if (this.jqObject.autocomplete("widget").is(":visible")) {
      this.close();
    }
    else {
      this.open(emptySearch);
    }
  };

  /**
   * Handles value elements for multiple entries.
   */
  Drupal.autocomplete_deluxe.value = function(value, source) {
    this.removeLink = $('<span class="autocomplete-deluxe-value-delete">&nbsp;</span>')
    this.span = $('<span class="autocomplete-deluxe-value ui-corner-all ui-button ui-state-default">' + value + '</span>');
    this.value = value;
    this.source = source;
    source.container.append(this.span);
    this.span.append(this.removeLink);

    var object = this;

    this.removeLink.click(function(){
      object.span.remove();
      object.source.removeValue(object.value)
    });
  };

  Drupal.autocomplete_deluxe.value.prototype.value = null;
  Drupal.autocomplete_deluxe.value.prototype.span = null;
  Drupal.autocomplete_deluxe.value.prototype.source = null;

  /**
   * Main abstract source object.
   */
  Drupal.autocomplete_deluxe.source = function() {
  };

  // Some base settings for all source objects.
  Drupal.autocomplete_deluxe.source.prototype.autocomplete = null;
  Drupal.autocomplete_deluxe.source.prototype.multiple = false;
  Drupal.autocomplete_deluxe.source.prototype.container = undefined;

  Drupal.autocomplete_deluxe.source.prototype.highlight = function(term, data) {
    // If no term is entered, we want to return the data as it is.
    if (term == '') {
      return data;
    }
    else {
      // Create a new data array, so we can keep our original data clean
      // (without <strong> tags).
      var newData = new Array();
      var regex = new RegExp("(?![^&;]+;)(?!<[^<>]*)(" + term + ")(?![^<>]*>)(?![^&;]+;)", "gi");
      for ( var i in data) {
        var nterm = data[i].label.replace(regex, "<strong>$1</strong>");
        newData.push({
          label: nterm,
          value: data[i].value
        });
      }
      return newData;
    }
  };

  /**
   * Sets the source element from the autocomplete deluxe object.
   */
  Drupal.autocomplete_deluxe.source.prototype.response = function(request, response, data) {
    response(this.highlight(request.term, data));
  };

  /**
   * Select super function. Super because, in contrary to the .select()
   * function this function will be always called, not depending on the source
   * objects type.
   */
  Drupal.autocomplete_deluxe.source.prototype._select = function(input, ui) {
    // Strip the strong tags from the label.
    ui.item.label = $("<span>" + ui.item.label + "</span>").text();
    this.select(input, ui);
    if (this.multiple) {
      this.addValue(this.autocomplete.jqObject.val());
      input.value = '';
    }
    return false;
  };

  /**
   * Initialization function for setting the default states.
   */
  Drupal.autocomplete_deluxe.source.prototype.init = function() {
  };

  /**
   * Select event function.
   */
  Drupal.autocomplete_deluxe.source.prototype.select = function(input, ui) {
  };

  /**
   * Change event function.
   */
  Drupal.autocomplete_deluxe.source.prototype.change = function(input, ui) {
  };

  /**
   * Keypress event function.
   */
  Drupal.autocomplete_deluxe.source.prototype.keypress = function(event) {
    if (this.multiple && event.which == 44 || event.which == 13) {
      var val = this.autocomplete.jqObject.val();
      if (val != '') {
        this.addValue(val);
      }
    }
  };

  /**
   * Adds a new value.
   */
  Drupal.autocomplete_deluxe.source.prototype.addValue = function(value) {
    new Drupal.autocomplete_deluxe.value(value, this);
  }

  /**
   * Will be called if a value is removed.
   */
  Drupal.autocomplete_deluxe.source.prototype.removeValue = function(value) {
  }

  /**
   * List Source Object
   *
   * @param data
   *          The data for the autocomplete object.
   */
  Drupal.autocomplete_deluxe.listSource = function(data, select) {
    this.list = new Array();
    var instance = this;
    this.selectbox = select;
    jQuery.each(data, function(index, value) {
      instance.list.push({
        label: $.trim(value),
        value: index
      });
    });
  };

  /**
   * Sort function for the list entries.
   */
  Drupal.autocomplete_deluxe.listSource.sortList = function(itemA, itemB) {
    if (itemA.value < itemB.value)
      return -1;
    if (itemA.value > itemB.value)
      return 1;
    return 0;
  }

  // Set base class.
  Drupal.autocomplete_deluxe.listSource.prototype = new Drupal.autocomplete_deluxe.source();

  /**
   * Override init function,
   */
  Drupal.autocomplete_deluxe.listSource.prototype.init = function(data, select) {
    if (this.multiple) {
      var instance = this;
      // Add all selected(probably by #default_value) to the selected list.
      this.selectbox.children("option:selected").each( function() {
        instance.addValue($(this).text());
      });
    } else {
      this.autocomplete.jqObject.val(this.selectbox.children("option:selected").text());
    }
  }

  Drupal.autocomplete_deluxe.listSource.prototype.selectbox = null;

  /**
   * Will be called by the JQuery autocomplete source function to retrieve the
   * data.
   */
  Drupal.autocomplete_deluxe.listSource.prototype.setResponse = function(request, response) {
    var filtered = Drupal.autocomplete_deluxe.filter(this.list, request.term);
    this.response(request, response, filtered);
  };

  /**
   * Override select event function.
   */
  Drupal.autocomplete_deluxe.listSource.prototype.select = function(input, ui) {
    input.value = ui.item.label;
    if (!this.multiple) {
      this.selectbox.children('option:contains("' + input.value + '")').attr("selected", true);
    }
  };

  /**
   * Overrides the  add new value function.
   */
  Drupal.autocomplete_deluxe.listSource.prototype.addValue = function(value) {
    for (var i=0; i < this.list.length; i++) {
      if (value == this.list[i].label) {
        this.selectbox.children('option:contains("' + value + '")').attr("selected", true);
        new Drupal.autocomplete_deluxe.value(value, this);
        this.list.splice(i, 1);
      }
    };
  };

  /**
   * Overrides the remove item event function.
   */
  Drupal.autocomplete_deluxe.listSource.prototype.removeValue = function(value) {
    this.selectbox.children('option:contains("' + value + '")').attr("selected", false);
    this.list.push({
      label: $.trim(value),
      value: this.selectbox.children('option:contains("' + value + '")').val()
    });
    this.list.sort(Drupal.autocomplete_deluxe.listSource. sortList);
  };

  /**
   * Ajax Source Object for selection
   *
   * @param uri
   *          URI to server with the data.
   * @param dataType
   *          If nothing is passed, json will be used as default.
   */
  Drupal.autocomplete_deluxe.ajaxSource = function(uri, dataType) {
    this.cache = new Array();
    this.uri = uri;
    if (dataType === undefined) {
      this.dataType = 'json';
    }
    else {
      this.dataType = dataType;
    }
  };

  // Set base class.
  Drupal.autocomplete_deluxe.ajaxSource.prototype = new Drupal.autocomplete_deluxe.source();
  Drupal.autocomplete_deluxe.ajaxSource.prototype.valueField = null;
  Drupal.autocomplete_deluxe.ajaxSource.prototype.values = null;

  /**
   * Initialization function for setting the default states.
   */
  Drupal.autocomplete_deluxe.ajaxSource.prototype.init = function() {
    if (this.multiple) {
      this.valueField = this.autocomplete.jqObject.parent().parent().children('div.autocomplete-deluxe-value-container').children().children();
      this.valueField.hide();
      this.autocomplete.jqObject.show();
      this.values = (this.valueField.val().split(',') != "") ? this.valueField.val().split(',')  : new Array();
      for (var i in this.values) {
        if (this.values[i] != "" && this.values[i] != " ") {
          new Drupal.autocomplete_deluxe.value(this.values[i], this);
        }
      }
    }
  };

  /**
   * Will be called by the JQuery autocomplete source function to retrieve the
   * data.
   */
  Drupal.autocomplete_deluxe.ajaxSource.prototype.setResponse = function(request, response) {
    var instance = this;
    if (request.term in this.cache) {
      var instance = this;
      var terms = this.cache[request.term].filter(function(val) {
        for (var i in instance.values) {
          if (instance.values[i] == val.value) {
            return false;
          }
        }
        return true;
      });
      instance.response(request, response, (terms));
      return;
    }
    $.ajax({
      url: this.uri + '/' + request.term,
      dataType: this.dataType,
      success: function(data) {
        instance.response(request, response, instance.success(data, request));
      }
    });
  };

  /**
   * Success function for the autocomplete object.
   */
  Drupal.autocomplete_deluxe.ajaxSource.prototype.success = function(data, request) {
    var instance = this;
    this.cache[request.term] = new Array();
    jQuery.each(data, function(index, value) {
      instance.cache[request.term].push({
        label: value,
        value: index
      });
    });

    var terms = this.cache[request.term].filter(function(val) {
      for (var i in instance.values) {
        if (instance.values[i] == val.value) {
          return false;
        }
      }
      return true;
    });
    return terms;
  };

  /**
   * Override select event function.
   */
  Drupal.autocomplete_deluxe.ajaxSource.prototype.select = function(input, ui) {
    input.value = ui.item.value;
  };

  /**
   * Overrides the  add new value function.
   */
  Drupal.autocomplete_deluxe.ajaxSource.prototype.addValue = function(value) {
    new Drupal.autocomplete_deluxe.value(value, this);
    this.values.push(value);
    this.valueField.val(this.values.join(','))
  }

  /**
   * Overrides the remove item event function.
   */
  Drupal.autocomplete_deluxe.ajaxSource.prototype.removeValue = function(value) {
    var idx = this.values.indexOf(value);
    if (idx >-1) {
      this.values.splice(idx, 1);
    }
    this.valueField.val(this.values.join(','))
  }
})(jQuery);
