<?php
/**
 * @file
 * cc_flags.features.inc
 */

/**
 * Implementation of hook_flag_default_flags().
 */
function cc_flags_flag_default_flags() {
  $flags = array();
  // Exported flag: "Bookmarks".
  $flags['bookmarks'] = array(
    'content_type' => 'node',
    'title' => 'Bookmarks',
    'global' => '0',
    'types' => array(
      0 => 'article',
    ),
    'flag_short' => 'Bookmark this',
    'flag_long' => 'Add this post to your bookmarks',
    'flag_message' => 'This post has been added to your bookmarks',
    'unflag_short' => 'Unbookmark this',
    'unflag_long' => 'Remove this post from your bookmarks',
    'unflag_message' => 'This post has been removed from your bookmarks',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'roles' => array(
      'flag' => array(
        0 => 2,
      ),
      'unflag' => array(
        0 => 2,
      ),
    ),
    'show_on_page' => 1,
    'show_on_teaser' => 1,
    'show_on_form' => 1,
    'access_author' => '',
    'i18n' => 0,
    'module' => 'cc_flags',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 2,
  );
  // Exported flag: "Needs Love".
  $flags['needs_love'] = array(
    'content_type' => 'node',
    'title' => 'Needs Love',
    'global' => '0',
    'types' => array(
      0 => 'application',
      1 => 'organization',
      2 => 'project',
    ),
    'flag_short' => 'Flag for editing',
    'flag_long' => '',
    'flag_message' => '',
    'unflag_short' => 'Unflag for editing',
    'unflag_long' => '',
    'unflag_message' => '',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'roles' => array(
      'flag' => array(
        0 => '2',
      ),
      'unflag' => array(
        0 => '2',
      ),
    ),
    'show_on_page' => 1,
    'show_on_teaser' => 1,
    'show_on_form' => 0,
    'access_author' => '',
    'i18n' => 0,
    'module' => 'cc_flags',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 2,
  );
  // Exported flag: "Users".
  $flags['users'] = array(
    'content_type' => 'node',
    'title' => 'Users',
    'global' => '0',
    'types' => array(
      0 => 'application',
    ),
    'flag_short' => 'I use this',
    'flag_long' => '',
    'flag_message' => '',
    'unflag_short' => 'I don\'t use this',
    'unflag_long' => '',
    'unflag_message' => '',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'roles' => array(
      'flag' => array(
        0 => '2',
      ),
      'unflag' => array(
        0 => '2',
      ),
    ),
    'show_on_page' => 1,
    'show_on_teaser' => 1,
    'show_on_form' => 0,
    'access_author' => '',
    'i18n' => 0,
    'module' => 'cc_flags',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 2,
  );
  // Exported flag: "Watch this Organization".
  $flags['watch_this_org'] = array(
    'content_type' => 'node',
    'title' => 'Watch this Organization',
    'global' => '0',
    'types' => array(
      0 => 'organization',
    ),
    'flag_short' => 'Watch this [node:field-organization-type:field-watchname]',
    'flag_long' => '',
    'flag_message' => '',
    'unflag_short' => 'Unwatch this [node:field-organization-type:field-watchname]',
    'unflag_long' => '',
    'unflag_message' => '',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'roles' => array(
      'flag' => array(
        0 => '2',
      ),
      'unflag' => array(
        0 => '2',
      ),
    ),
    'show_on_page' => 1,
    'show_on_teaser' => 0,
    'show_on_form' => 0,
    'access_author' => '',
    'i18n' => 0,
    'module' => 'cc_flags',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 2,
  );
  // Exported flag: "App you&#039;re watching".
  $flags['watching_app'] = array(
    'content_type' => 'node',
    'title' => 'App you\'re watching',
    'global' => '0',
    'types' => array(
      0 => 'application',
    ),
    'flag_short' => 'Watch this App',
    'flag_long' => '',
    'flag_message' => '',
    'unflag_short' => 'Unwatch this App',
    'unflag_long' => '',
    'unflag_message' => '',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'roles' => array(
      'flag' => array(
        0 => '2',
      ),
      'unflag' => array(
        0 => '2',
      ),
    ),
    'show_on_page' => 1,
    'show_on_teaser' => 0,
    'show_on_form' => 0,
    'access_author' => '',
    'i18n' => 0,
    'module' => 'cc_flags',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 2,
  );
  return $flags;
}
