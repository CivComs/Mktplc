<?php
/**
 * @file
 * cc_user_feature.features.fe_block_settings.inc
 */

/**
 * Implementation of hook_default_fe_block_settings().
 */
function cc_user_feature_default_fe_block_settings() {
  $export = array();

  // alpha
  $theme = array();

  $theme['menu-menu-user-tasks'] = array(
    'module' => 'menu',
    'delta' => 'menu-user-tasks',
    'theme' => 'alpha',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'user/login
user/register',
    'title' => '',
    'cache' => -1,
  );

  $export['alpha'] = $theme;

  // bartik
  $theme = array();

  $theme['menu-menu-user-tasks'] = array(
    'module' => 'menu',
    'delta' => 'menu-user-tasks',
    'theme' => 'bartik',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'user/login
user/register',
    'title' => '',
    'cache' => -1,
  );

  $export['bartik'] = $theme;

  // civiccommons
  $theme = array();

  $theme['menu-menu-user-tasks'] = array(
    'module' => 'menu',
    'delta' => 'menu-user-tasks',
    'theme' => 'civiccommons',
    'status' => '1',
    'weight' => '-47',
    'region' => 'sidebar_second',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'user/login
user/register',
    'title' => '',
    'cache' => -1,
  );

  $export['civiccommons'] = $theme;

  // omega
  $theme = array();

  $theme['menu-menu-user-tasks'] = array(
    'module' => 'menu',
    'delta' => 'menu-user-tasks',
    'theme' => 'omega',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'user/login
user/register',
    'title' => '',
    'cache' => -1,
  );

  $export['omega'] = $theme;

  // seven
  $theme = array();

  $theme['menu-menu-user-tasks'] = array(
    'module' => 'menu',
    'delta' => 'menu-user-tasks',
    'theme' => 'seven',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'user/login
user/register',
    'title' => '',
    'cache' => -1,
  );

  $export['seven'] = $theme;

  $theme_default = variable_get('theme_default', 'garland');
  $themes = list_themes();
  foreach ($export as $theme_key => $settings) {
    if ($theme_key != $theme_default && empty($themes[$theme_key]->status)) {
      unset($export[$theme_key]);
    }
  }
  return $export;
}
