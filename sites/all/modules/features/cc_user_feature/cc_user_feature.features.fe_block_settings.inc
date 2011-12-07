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

  $theme['block-user_signup'] = array(
    'module' => 'block',
    'theme' => 'alpha',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'user/login
user/denied
toboggan/denied',
    'title' => 'Not a Member Yet?',
    'cache' => -1,
    'machine_name' => 'user_signup',
  );

  $theme['block-user_login'] = array(
    'module' => 'block',
    'theme' => 'alpha',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'user/register',
    'title' => 'Already a Member?',
    'cache' => -1,
    'machine_name' => 'user_login',
  );

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
user/register
user/denied
toboggan/denied
denied',
    'title' => '',
    'cache' => -1,
  );

  $export['alpha'] = $theme;

  // bartik
  $theme = array();

  $theme['block-user_signup'] = array(
    'module' => 'block',
    'theme' => 'bartik',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'user/login
user/denied
toboggan/denied',
    'title' => 'Not a Member Yet?',
    'cache' => -1,
    'machine_name' => 'user_signup',
  );

  $theme['block-user_login'] = array(
    'module' => 'block',
    'theme' => 'bartik',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'user/register',
    'title' => 'Already a Member?',
    'cache' => -1,
    'machine_name' => 'user_login',
  );

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
user/register
user/denied
toboggan/denied
denied',
    'title' => '',
    'cache' => -1,
  );

  $export['bartik'] = $theme;

  // civiccommons
  $theme = array();

  $theme['block-user_signup'] = array(
    'module' => 'block',
    'theme' => 'civiccommons',
    'status' => '1',
    'weight' => '0',
    'region' => 'sidebar_second',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'user/login
user/denied
toboggan/denied',
    'title' => 'Not a Member Yet?',
    'cache' => -1,
    'machine_name' => 'user_signup',
  );

  $theme['block-user_login'] = array(
    'module' => 'block',
    'theme' => 'civiccommons',
    'status' => '1',
    'weight' => '0',
    'region' => 'sidebar_second',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'user/register',
    'title' => 'Already a Member?',
    'cache' => -1,
    'machine_name' => 'user_login',
  );

  $theme['menu-menu-user-tasks'] = array(
    'module' => 'menu',
    'delta' => 'menu-user-tasks',
    'theme' => 'civiccommons',
    'status' => 0,
    'weight' => '-46',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'user/login
user/register
user/denied
toboggan/denied
denied',
    'title' => '',
    'cache' => -1,
  );

  $export['civiccommons'] = $theme;

  // omega
  $theme = array();

  $theme['block-user_signup'] = array(
    'module' => 'block',
    'theme' => 'omega',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'user/login
user/denied
toboggan/denied',
    'title' => 'Not a Member Yet?',
    'cache' => -1,
    'machine_name' => 'user_signup',
  );

  $theme['block-user_login'] = array(
    'module' => 'block',
    'theme' => 'omega',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'user/register',
    'title' => 'Already a Member?',
    'cache' => -1,
    'machine_name' => 'user_login',
  );

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
user/register
user/denied
toboggan/denied
denied',
    'title' => '',
    'cache' => -1,
  );

  $export['omega'] = $theme;

  // seven
  $theme = array();

  $theme['block-user_signup'] = array(
    'module' => 'block',
    'theme' => 'seven',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'user/login
user/denied
toboggan/denied',
    'title' => 'Not a Member Yet?',
    'cache' => -1,
    'machine_name' => 'user_signup',
  );

  $theme['block-user_login'] = array(
    'module' => 'block',
    'theme' => 'seven',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'user/register',
    'title' => 'Already a Member?',
    'cache' => -1,
    'machine_name' => 'user_login',
  );

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
user/register
user/denied
toboggan/denied
denied',
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
