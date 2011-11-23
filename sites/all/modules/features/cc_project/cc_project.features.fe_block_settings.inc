<?php
/**
 * @file
 * cc_project.features.fe_block_settings.inc
 */

/**
 * Implementation of hook_default_fe_block_settings().
 */
function cc_project_default_fe_block_settings() {
  $export = array();

  // alpha
  $theme = array();

  $theme['views-projects-block_1'] = array(
    'module' => 'views',
    'delta' => 'projects-block_1',
    'theme' => 'alpha',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => -1,
  );

  $export['alpha'] = $theme;

  // bartik
  $theme = array();

  $theme['views-projects-block_1'] = array(
    'module' => 'views',
    'delta' => 'projects-block_1',
    'theme' => 'bartik',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => -1,
  );

  $export['bartik'] = $theme;

  // civiccommons
  $theme = array();

  $theme['views-projects-block_1'] = array(
    'module' => 'views',
    'delta' => 'projects-block_1',
    'theme' => 'civiccommons',
    'status' => 0,
    'weight' => '7',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => -1,
  );

  $export['civiccommons'] = $theme;

  // omega
  $theme = array();

  $theme['views-projects-block_1'] = array(
    'module' => 'views',
    'delta' => 'projects-block_1',
    'theme' => 'omega',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => -1,
  );

  $export['omega'] = $theme;

  // seven
  $theme = array();

  $theme['views-projects-block_1'] = array(
    'module' => 'views',
    'delta' => 'projects-block_1',
    'theme' => 'seven',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
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
