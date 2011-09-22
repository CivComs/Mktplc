(function ($) {

Drupal.behaviors.rpx = {
  attach: function (context, settings) {
    function finishCallback(results) {
      var setting = settings.rpx.clicked_link_settings;
      if ('cookie' in setting) {
        $.each(results, function(key, provider) {
          if (provider.success) {
            $.cookie('Drupal.visitor.rpx_social_' + setting.cookie.type, setting.cookie.id, {path: '/'});
            location.replace(Drupal.settings.basePath + '?q=rpx/cookie_handler&destination=' + location.href);
            return false;
          }
        });
      }
    }
    function popupSocial() {
      RPXNOW.loadAndRun(['Social'], function () {
        var post = settings.rpx.clicked_link_settings.post;
        var activity = new RPXNOW.Social.Activity(
          post.label,
          post.linktext,
          post.link
        );
        if ('comment' in post) {
          activity.setUserGeneratedContent(post.comment);
        }
        if ('summary' in post) {
          activity.setDescription(post.summary);
        }
        if ('title' in post) {
          activity.setTitle(post.title);
        }
        RPXNOW.Social.publishActivity(activity, {finishCallback: finishCallback});
      });
    };
    if ('rpx' in settings && 'atonce' in settings.rpx) {
      settings.rpx.clicked_link_settings = settings.rpx.atonce;
      popupSocial();
    }
    $('.rpx-link-social', context).once('rpx-link-social', function() {
      $(this).bind('click', function(e) {
        settings.rpx.clicked_link_settings = settings.rpx[$(this).attr('id')];
        popupSocial();
        return false;
      });
    });
  }
};

})(jQuery);
