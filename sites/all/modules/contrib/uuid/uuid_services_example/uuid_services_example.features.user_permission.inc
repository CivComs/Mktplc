<?php
/**
 * @file
 * uuid_services_example.features.user_permission.inc
 */

/**
 * Implementation of hook_user_default_permissions().
 */
function uuid_services_example_user_default_permissions() {
  $permissions = array();

  // Exported permission: use entity resource
  $permissions['use entity resource'] = array(
    'name' => 'use entity resource',
    'roles' => array(
      0 => 'administrator',
      1 => 'anonymous user',
      2 => 'authenticated user',
    ),
    'module' => 'uuid_services',
  );

  return $permissions;
}
