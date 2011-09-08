(function ($) {

Drupal.behaviors.shadowbox = {
  attach: function(context, settings) {
    if (settings.shadowbox.auto_enable_all_images == 1) {
      $("a[href$='jpg'], a[href$='png'], a[href$='gif'], a[href$='jpeg'], a[href$='bmp'], a[href$='JPG'], a[href$='PNG'], a[href$='GIF'], a[href$='JPEG'], a[href$='BMP']").each(function() {
        if ($(this).attr('rel') == '') {
          if (settings.shadowbox.auto_gallery == 1) {
            $(this).attr('rel', 'shadowbox[gallery]');
          }
          else {
            $(this).attr('rel', 'shadowbox');
          }
        }
      });
    }
    Shadowbox.setup();
  }
};

})(jQuery);