
Drupal.behaviors.uniqueness = {
  attach: function (context) {
    uniqueness = new Drupal.uniqueness(Drupal.settings.uniqueness['URL'], jQuery('.uniqueness-dyn'));
    if (Drupal.settings.uniqueness['preview'] == true) {
      uniqueness.clear();
    }
    // Search off title.
    jQuery('#edit-title').keyup(function() {
    input = this.value;
      if (input.length >= uniqueness.minCharacters) {
        uniqueness.search('title', input);
      }
      else if(input.length == 0 && !uniqueness.prependResults) {
        uniqueness.clear();
      }
    });
    // Search off tags.
    jQuery('#edit-taxonomy-tags-1').blur(function() {
      input = this.value;
      // Some tags set.
      if (input.length > 0) {
        uniqueness.search('tags', input);
      }
    });
  }
};

Drupal.uniqueness = function (uri, widget) {
  this.uri = uri;
  this.delay = 500;
  this.widget = widget;
  if (jQuery('.item-list ul', widget).length == 0) {
    // Same markup as generated by theme('item_list').
    this.widget.append('<div class="item-list"><ul></ul></div>');
  }
  this.list = jQuery('.item-list ul', widget);
  this.notifier = jQuery('.uniqueness-search-notifier', widget);
  this.widgetCSS = {
    'background-image' : "url('" + Drupal.settings.basePath + "misc/throbber.gif" + "')",
    'background-position' : '100% -18px',
    'background-repeat' : 'no-repeat'
  }
  this.searchCache = {};
  this.listCache = {};
  this.prependResults = Drupal.settings.uniqueness['prependResults'];
  this.nid = Drupal.settings.uniqueness['nid'];
  this.type = Drupal.settings.uniqueness['type'];
  this.minCharacters = Drupal.settings.uniqueness['minCharacters'];
}

Drupal.uniqueness.prototype.update = function (data) {
  uniqueness.notifier.removeClass('uniqueness-dyn-searching').empty();
  uniqueness.widget.css('background-image', '');
  uniqueness = this;
  if (uniqueness.prependResults) {
    if (data == undefined && uniqueness.listCache != {}) {
      data = uniqueness.listCache;
    }
    var items = '';
    jQuery.each(data, function(i, item) {
      // Only use what we haven't seen before.
      if (uniqueness.listCache[item.nid] == undefined) {
        items += '<li><a href="' + item.href + '" target="_blank">' + item.title + '</a></li>';
        // Store the new item.
        uniqueness.listCache[item.nid] = item;
      }
    });
    // Show list.
    this.list.prepend(items);
  }
  else { // Replace content. //@todo still use caching?
    if (data == undefined) {
      uniqueness.clear();
      return;
    }
    var items = '';
    jQuery.each(data, function(i, item) {
      if (item.more) {
        items += '<li>' + Drupal.t("... and others.") + '</li>';
      }
      else {
        items += '<li><a href="' + item.href + '" target="_blank">' + item.title + '</a></li>';
      }
    });
    this.list.html(items);
  }
}

Drupal.uniqueness.prototype.search = function (element, searchString) {
  uniqueness = this;

  // If this string has been searched for before we do nothing.
  if (uniqueness.prependResults && uniqueness.searchCache[searchString]) {
    return;
  }

  if (this.timer) {
    clearTimeout(this.timer);
  }
  this.timer = setTimeout(function () {
    // Inform user we're searching.
    if (uniqueness.notifier.hasClass('uniqueness-dyn-searching') == false) {
      uniqueness.notifier.addClass('uniqueness-dyn-searching').html(Drupal.settings.uniqueness['searchingString']);
      uniqueness.widget.css(uniqueness.widgetCSS);
    }
    var query = uniqueness.uri + '?';
    if (uniqueness.nid != undefined) {
      query += 'nid=' + uniqueness.nid + '&';
    }
    if (uniqueness.type != undefined) {
      query += 'type=' + uniqueness.type + '&';
    }
    jQuery.getJSON(query + element + '=' + searchString, function (data) {
      if (data != undefined && data != 'false') {
        // Found results.
        uniqueness.update(data);
        // Save this string, it found results.
        uniqueness.searchCache[searchString] = searchString;
        var blockSet = true;
      }
      // Nothing new found so show existing results.
      if (blockSet == undefined) {
        uniqueness.update();
      }
    });
  }, uniqueness.delay);
}

Drupal.uniqueness.prototype.clear = function () {
  this.list.empty();
}