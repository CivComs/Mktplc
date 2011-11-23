<?php
/**
 * @file
 * cc_content_creation.features.fe_block_settings.inc
 */

/**
 * Implementation of hook_default_fe_block_settings().
 */
function cc_content_creation_default_fe_block_settings() {
  $export = array();

  // alpha
  $theme = array();

  $theme['block-cc_jm_add_content'] = array(
    'module' => 'block',
    'theme' => 'alpha',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '<none>',
    'cache' => -1,
    'machine_name' => 'cc_jm_add_content',
  );

  $theme['menu-menu-add-content'] = array(
    'module' => 'menu',
    'delta' => 'menu-add-content',
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

  $theme['block-cc_jm_add_content'] = array(
    'module' => 'block',
    'theme' => 'bartik',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '<none>',
    'cache' => -1,
    'machine_name' => 'cc_jm_add_content',
  );

  $theme['menu-menu-add-content'] = array(
    'module' => 'menu',
    'delta' => 'menu-add-content',
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

  $theme['block-cc_jm_add_content'] = array(
    'module' => 'block',
    'theme' => 'civiccommons',
    'status' => '1',
    'weight' => '-56',
    'region' => 'search_bar',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '<none>',
    'cache' => -1,
    'machine_name' => 'cc_jm_add_content',
  );

  $theme['menu-menu-add-content'] = array(
    'module' => 'menu',
    'delta' => 'menu-add-content',
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

  $export['civiccommons'] = $theme;

  // omega
  $theme = array();

  $theme['block-cc_jm_add_content'] = array(
    'module' => 'block',
    'theme' => 'omega',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '<none>',
    'cache' => -1,
    'machine_name' => 'cc_jm_add_content',
  );

  $theme['menu-menu-add-content'] = array(
    'module' => 'menu',
    'delta' => 'menu-add-content',
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

  $theme['block-cc_jm_add_content'] = array(
    'module' => 'block',
    'theme' => 'seven',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '<none>',
    'cache' => -1,
    'machine_name' => 'cc_jm_add_content',
  );

  $theme['menu-menu-add-content'] = array(
    'module' => 'menu',
    'delta' => 'menu-add-content',
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
