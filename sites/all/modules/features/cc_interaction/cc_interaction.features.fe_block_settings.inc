<?php
/**
 * @file
 * cc_interaction.features.fe_block_settings.inc
 */

/**
 * Implementation of hook_default_fe_block_settings().
 */
function cc_interaction_default_fe_block_settings() {
  $export = array();

  // alpha
  $theme = array();

  $theme['cc_interactions-cc_interactions_apps'] = array(
    'module' => 'cc_interactions',
    'delta' => 'cc_interactions_apps',
    'theme' => 'alpha',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '1',
  );

  $export['alpha'] = $theme;

  // bartik
  $theme = array();

  $theme['cc_interactions-cc_interactions_apps'] = array(
    'module' => 'cc_interactions',
    'delta' => 'cc_interactions_apps',
    'theme' => 'bartik',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '1',
  );

  $export['bartik'] = $theme;

  // civiccommons
  $theme = array();

  $theme['cc_interactions-cc_interactions_apps'] = array(
    'module' => 'cc_interactions',
    'delta' => 'cc_interactions_apps',
    'theme' => 'civiccommons',
    'status' => '1',
    'weight' => '-57',
    'region' => 'sidebar_second',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '1',
  );

  $export['civiccommons'] = $theme;

  // omega
  $theme = array();

  $theme['cc_interactions-cc_interactions_apps'] = array(
    'module' => 'cc_interactions',
    'delta' => 'cc_interactions_apps',
    'theme' => 'omega',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '1',
  );

  $export['omega'] = $theme;

  // seven
  $theme = array();

  $theme['cc_interactions-cc_interactions_apps'] = array(
    'module' => 'cc_interactions',
    'delta' => 'cc_interactions_apps',
    'theme' => 'seven',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '1',
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
