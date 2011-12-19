<?php
/**
 * @file
 * cc_places_feature.features.fe_block_settings.inc
 */

/**
 * Implementation of hook_default_fe_block_settings().
 */
function cc_places_feature_default_fe_block_settings() {
  $export = array();

  // alpha
  $theme = array();

  $theme['views-apps_browse_by-block_2'] = array(
    'module' => 'views',
    'delta' => 'apps_browse_by-block_2',
    'theme' => 'alpha',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => '',
    'title' => '<none>',
    'cache' => '1',
  );

  $theme['views-apps_browse_by-block_3'] = array(
    'module' => 'views',
    'delta' => 'apps_browse_by-block_3',
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

  $theme['views-cc_organizations-block_1'] = array(
    'module' => 'views',
    'delta' => 'cc_organizations-block_1',
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

  $theme['views-places-block_1'] = array(
    'module' => 'views',
    'delta' => 'places-block_1',
    'theme' => 'alpha',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => 'Cities',
    'cache' => '-1',
  );

  $theme['views-places-block_2'] = array(
    'module' => 'views',
    'delta' => 'places-block_2',
    'theme' => 'alpha',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => 'Government agencies',
    'cache' => '-1',
  );

  $export['alpha'] = $theme;

  // bartik
  $theme = array();

  $theme['views-apps_browse_by-block_2'] = array(
    'module' => 'views',
    'delta' => 'apps_browse_by-block_2',
    'theme' => 'bartik',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => '',
    'title' => '<none>',
    'cache' => '1',
  );

  $theme['views-apps_browse_by-block_3'] = array(
    'module' => 'views',
    'delta' => 'apps_browse_by-block_3',
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

  $theme['views-cc_organizations-block_1'] = array(
    'module' => 'views',
    'delta' => 'cc_organizations-block_1',
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

  $theme['views-places-block_1'] = array(
    'module' => 'views',
    'delta' => 'places-block_1',
    'theme' => 'bartik',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => 'Cities',
    'cache' => '-1',
  );

  $theme['views-places-block_2'] = array(
    'module' => 'views',
    'delta' => 'places-block_2',
    'theme' => 'bartik',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => 'Government agencies',
    'cache' => '-1',
  );

  $export['bartik'] = $theme;

  // civiccommons
  $theme = array();

  $theme['views-apps_browse_by-block_2'] = array(
    'module' => 'views',
    'delta' => 'apps_browse_by-block_2',
    'theme' => 'civiccommons',
    'status' => 0,
    'weight' => '-14',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => '',
    'title' => '<none>',
    'cache' => '1',
  );

  $theme['views-apps_browse_by-block_3'] = array(
    'module' => 'views',
    'delta' => 'apps_browse_by-block_3',
    'theme' => 'civiccommons',
    'status' => 0,
    'weight' => '-15',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '<none>',
    'cache' => '1',
  );

  $theme['views-cc_organizations-block_1'] = array(
    'module' => 'views',
    'delta' => 'cc_organizations-block_1',
    'theme' => 'civiccommons',
    'status' => 0,
    'weight' => '-56',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => -1,
  );

  $theme['views-places-block_1'] = array(
    'module' => 'views',
    'delta' => 'places-block_1',
    'theme' => 'civiccommons',
    'status' => 0,
    'weight' => '-13',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => 'Cities',
    'cache' => '-1',
  );

  $theme['views-places-block_2'] = array(
    'module' => 'views',
    'delta' => 'places-block_2',
    'theme' => 'civiccommons',
    'status' => 0,
    'weight' => '-12',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => 'Government agencies',
    'cache' => '-1',
  );

  $export['civiccommons'] = $theme;

  // omega
  $theme = array();

  $theme['views-apps_browse_by-block_2'] = array(
    'module' => 'views',
    'delta' => 'apps_browse_by-block_2',
    'theme' => 'omega',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => '',
    'title' => '<none>',
    'cache' => '1',
  );

  $theme['views-apps_browse_by-block_3'] = array(
    'module' => 'views',
    'delta' => 'apps_browse_by-block_3',
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

  $theme['views-cc_organizations-block_1'] = array(
    'module' => 'views',
    'delta' => 'cc_organizations-block_1',
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

  $theme['views-places-block_1'] = array(
    'module' => 'views',
    'delta' => 'places-block_1',
    'theme' => 'omega',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => 'Cities',
    'cache' => '-1',
  );

  $theme['views-places-block_2'] = array(
    'module' => 'views',
    'delta' => 'places-block_2',
    'theme' => 'omega',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => 'Government agencies',
    'cache' => '-1',
  );

  $export['omega'] = $theme;

  // seven
  $theme = array();

  $theme['views-apps_browse_by-block_2'] = array(
    'module' => 'views',
    'delta' => 'apps_browse_by-block_2',
    'theme' => 'seven',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => '',
    'title' => '<none>',
    'cache' => '1',
  );

  $theme['views-apps_browse_by-block_3'] = array(
    'module' => 'views',
    'delta' => 'apps_browse_by-block_3',
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

  $theme['views-cc_organizations-block_1'] = array(
    'module' => 'views',
    'delta' => 'cc_organizations-block_1',
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

  $theme['views-places-block_1'] = array(
    'module' => 'views',
    'delta' => 'places-block_1',
    'theme' => 'seven',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => 'Cities',
    'cache' => '-1',
  );

  $theme['views-places-block_2'] = array(
    'module' => 'views',
    'delta' => 'places-block_2',
    'theme' => 'seven',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => 'Government agencies',
    'cache' => '-1',
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
