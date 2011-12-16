<?php
/**
 * @file
 * cc_user_feature.features.user_role.inc
 */

/**
 * Implementation of hook_user_default_roles().
 */
function cc_user_feature_user_default_roles() {
  $roles = array();

  // Exported role: content editor
  $roles['content editor'] = array(
    'name' => 'content editor',
    'weight' => '8',
  );

  // Exported role: pre-authenticated
  $roles['pre-authenticated'] = array(
    'name' => 'pre-authenticated',
    'weight' => '9',
  );

  return $roles;
}
