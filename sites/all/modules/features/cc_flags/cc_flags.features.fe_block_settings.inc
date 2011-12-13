<?php
/**
 * @file
 * cc_flags.features.fe_block_settings.inc
 */

/**
 * Implementation of hook_default_fe_block_settings().
 */
function cc_flags_default_fe_block_settings() {
  $export = array();

  // alpha
  $theme = array();

  $theme['cc_flag_block-flag_block'] = array(
    'module' => 'cc_flag_block',
    'delta' => 'flag_block',
    'theme' => 'alpha',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '<none>',
    'cache' => '1',
  );

  $theme['views-watching_app-block'] = array(
    'module' => 'views',
    'delta' => 'watching_app-block',
    'theme' => 'alpha',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'user/*',
    'title' => '',
    'cache' => -1,
  );

  $theme['views-watching_orgs-block'] = array(
    'module' => 'views',
    'delta' => 'watching_orgs-block',
    'theme' => 'alpha',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'user/*
user',
    'title' => '',
    'cache' => -1,
  );

  $export['alpha'] = $theme;

  // bartik
  $theme = array();

  $theme['cc_flag_block-flag_block'] = array(
    'module' => 'cc_flag_block',
    'delta' => 'flag_block',
    'theme' => 'bartik',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '<none>',
    'cache' => '1',
  );

  $theme['views-watching_app-block'] = array(
    'module' => 'views',
    'delta' => 'watching_app-block',
    'theme' => 'bartik',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'user/*',
    'title' => '',
    'cache' => -1,
  );

  $theme['views-watching_orgs-block'] = array(
    'module' => 'views',
    'delta' => 'watching_orgs-block',
    'theme' => 'bartik',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'user/*
user',
    'title' => '',
    'cache' => -1,
  );

  $export['bartik'] = $theme;

  // civiccommons
  $theme = array();

  $theme['cc_flag_block-flag_block'] = array(
    'module' => 'cc_flag_block',
    'delta' => 'flag_block',
    'theme' => 'civiccommons',
    'status' => '1',
    'weight' => '-58',
    'region' => 'sidebar_second',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '<none>',
    'cache' => '1',
  );

  $theme['views-watching_app-block'] = array(
    'module' => 'views',
    'delta' => 'watching_app-block',
    'theme' => 'civiccommons',
    'status' => 0,
    'weight' => '12',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'user/*',
    'title' => '',
    'cache' => -1,
  );

  $theme['views-watching_orgs-block'] = array(
    'module' => 'views',
    'delta' => 'watching_orgs-block',
    'theme' => 'civiccommons',
    'status' => 0,
    'weight' => '8',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'user/*
user',
    'title' => '',
    'cache' => -1,
  );

  $export['civiccommons'] = $theme;

  // omega
  $theme = array();

  $theme['cc_flag_block-flag_block'] = array(
    'module' => 'cc_flag_block',
    'delta' => 'flag_block',
    'theme' => 'omega',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '<none>',
    'cache' => '1',
  );

  $theme['views-watching_app-block'] = array(
    'module' => 'views',
    'delta' => 'watching_app-block',
    'theme' => 'omega',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'user/*',
    'title' => '',
    'cache' => -1,
  );

  $theme['views-watching_orgs-block'] = array(
    'module' => 'views',
    'delta' => 'watching_orgs-block',
    'theme' => 'omega',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'user/*
user',
    'title' => '',
    'cache' => -1,
  );

  $export['omega'] = $theme;

  // seven
  $theme = array();

  $theme['cc_flag_block-flag_block'] = array(
    'module' => 'cc_flag_block',
    'delta' => 'flag_block',
    'theme' => 'seven',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '<none>',
    'cache' => '1',
  );

  $theme['views-watching_app-block'] = array(
    'module' => 'views',
    'delta' => 'watching_app-block',
    'theme' => 'seven',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'user/*',
    'title' => '',
    'cache' => -1,
  );

  $theme['views-watching_orgs-block'] = array(
    'module' => 'views',
    'delta' => 'watching_orgs-block',
    'theme' => 'seven',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'user/*
user',
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
