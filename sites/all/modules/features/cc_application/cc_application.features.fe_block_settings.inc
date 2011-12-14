<?php
/**
 * @file
 * cc_application.features.fe_block_settings.inc
 */

/**
 * Implementation of hook_default_fe_block_settings().
 */
function cc_application_default_fe_block_settings() {
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
    'title' => 'Add Connections',
    'cache' => '1',
  );

  $theme['views--exp-applications-page_1'] = array(
    'module' => 'views',
    'delta' => '-exp-applications-page_1',
    'theme' => 'alpha',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'all/apps',
    'title' => 'Search apps',
    'cache' => -1,
  );

  $theme['views--exp-applications-page_2'] = array(
    'module' => 'views',
    'delta' => '-exp-applications-page_2',
    'theme' => 'alpha',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'most-watched/apps',
    'title' => 'Search apps',
    'cache' => -1,
  );

  $theme['views--exp-applications-page_3'] = array(
    'module' => 'views',
    'delta' => '-exp-applications-page_3',
    'theme' => 'alpha',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'most-used/apps',
    'title' => 'Search apps',
    'cache' => -1,
  );

  $theme['views--exp-applications-page_4'] = array(
    'module' => 'views',
    'delta' => '-exp-applications-page_4',
    'theme' => 'alpha',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'recent/apps',
    'title' => '',
    'cache' => -1,
  );

  $theme['views--exp-applications-page_5'] = array(
    'module' => 'views',
    'delta' => '-exp-applications-page_5',
    'theme' => 'alpha',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'deployed/apps',
    'title' => '',
    'cache' => -1,
  );

  $theme['views-6411095ab78ed6f4a9989c94614d5403'] = array(
    'module' => 'views',
    'delta' => '6411095ab78ed6f4a9989c94614d5403',
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

  $theme['views-application_categories-block_1'] = array(
    'module' => 'views',
    'delta' => 'application_categories-block_1',
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

  $theme['views-applications-block_1'] = array(
    'module' => 'views',
    'delta' => 'applications-block_1',
    'theme' => 'alpha',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'applications',
    'title' => '',
    'cache' => -1,
  );

  $theme['views-applications-block_2'] = array(
    'module' => 'views',
    'delta' => 'applications-block_2',
    'theme' => 'alpha',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'applications',
    'title' => '',
    'cache' => -1,
  );

  $theme['views-applications-block_3'] = array(
    'module' => 'views',
    'delta' => 'applications-block_3',
    'theme' => 'alpha',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'applications',
    'title' => '',
    'cache' => -1,
  );

  $theme['views-applications-block_4'] = array(
    'module' => 'views',
    'delta' => 'applications-block_4',
    'theme' => 'alpha',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'applications',
    'title' => 'Recently deployed',
    'cache' => -1,
  );

  $theme['views-at_a_glance_application_-block'] = array(
    'module' => 'views',
    'delta' => 'at_a_glance_application_-block',
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

  $theme['views-cc_organizations-block'] = array(
    'module' => 'views',
    'delta' => 'cc_organizations-block',
    'theme' => 'alpha',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/*',
    'title' => '',
    'cache' => -1,
  );

  $theme['views-d0c47a77065f0e15e04252546a319bde'] = array(
    'module' => 'views',
    'delta' => 'd0c47a77065f0e15e04252546a319bde',
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

  $theme['views-interactions-block_2'] = array(
    'module' => 'views',
    'delta' => 'interactions-block_2',
    'theme' => 'alpha',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/*',
    'title' => '<none>',
    'cache' => -1,
  );

  $theme['views-projects_use_this_app-block'] = array(
    'module' => 'views',
    'delta' => 'projects_use_this_app-block',
    'theme' => 'alpha',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => 'Projects that use this app',
    'cache' => -1,
  );

  $theme['views-related_apps_block-block'] = array(
    'module' => 'views',
    'delta' => 'related_apps_block-block',
    'theme' => 'alpha',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/*',
    'title' => '',
    'cache' => -1,
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
    'title' => 'Add Connections',
    'cache' => '1',
  );

  $theme['views--exp-applications-page_1'] = array(
    'module' => 'views',
    'delta' => '-exp-applications-page_1',
    'theme' => 'bartik',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'all/apps',
    'title' => 'Search apps',
    'cache' => -1,
  );

  $theme['views--exp-applications-page_2'] = array(
    'module' => 'views',
    'delta' => '-exp-applications-page_2',
    'theme' => 'bartik',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'most-watched/apps',
    'title' => 'Search apps',
    'cache' => -1,
  );

  $theme['views--exp-applications-page_3'] = array(
    'module' => 'views',
    'delta' => '-exp-applications-page_3',
    'theme' => 'bartik',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'most-used/apps',
    'title' => 'Search apps',
    'cache' => -1,
  );

  $theme['views--exp-applications-page_4'] = array(
    'module' => 'views',
    'delta' => '-exp-applications-page_4',
    'theme' => 'bartik',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'recent/apps',
    'title' => '',
    'cache' => -1,
  );

  $theme['views--exp-applications-page_5'] = array(
    'module' => 'views',
    'delta' => '-exp-applications-page_5',
    'theme' => 'bartik',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'deployed/apps',
    'title' => '',
    'cache' => -1,
  );

  $theme['views-6411095ab78ed6f4a9989c94614d5403'] = array(
    'module' => 'views',
    'delta' => '6411095ab78ed6f4a9989c94614d5403',
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

  $theme['views-application_categories-block_1'] = array(
    'module' => 'views',
    'delta' => 'application_categories-block_1',
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

  $theme['views-applications-block_1'] = array(
    'module' => 'views',
    'delta' => 'applications-block_1',
    'theme' => 'bartik',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'applications',
    'title' => '',
    'cache' => -1,
  );

  $theme['views-applications-block_2'] = array(
    'module' => 'views',
    'delta' => 'applications-block_2',
    'theme' => 'bartik',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'applications',
    'title' => '',
    'cache' => -1,
  );

  $theme['views-applications-block_3'] = array(
    'module' => 'views',
    'delta' => 'applications-block_3',
    'theme' => 'bartik',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'applications',
    'title' => '',
    'cache' => -1,
  );

  $theme['views-applications-block_4'] = array(
    'module' => 'views',
    'delta' => 'applications-block_4',
    'theme' => 'bartik',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'applications',
    'title' => 'Recently deployed',
    'cache' => -1,
  );

  $theme['views-at_a_glance_application_-block'] = array(
    'module' => 'views',
    'delta' => 'at_a_glance_application_-block',
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

  $theme['views-cc_organizations-block'] = array(
    'module' => 'views',
    'delta' => 'cc_organizations-block',
    'theme' => 'bartik',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/*',
    'title' => '',
    'cache' => -1,
  );

  $theme['views-d0c47a77065f0e15e04252546a319bde'] = array(
    'module' => 'views',
    'delta' => 'd0c47a77065f0e15e04252546a319bde',
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

  $theme['views-interactions-block_2'] = array(
    'module' => 'views',
    'delta' => 'interactions-block_2',
    'theme' => 'bartik',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/*',
    'title' => '<none>',
    'cache' => -1,
  );

  $theme['views-projects_use_this_app-block'] = array(
    'module' => 'views',
    'delta' => 'projects_use_this_app-block',
    'theme' => 'bartik',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => 'Projects that use this app',
    'cache' => -1,
  );

  $theme['views-related_apps_block-block'] = array(
    'module' => 'views',
    'delta' => 'related_apps_block-block',
    'theme' => 'bartik',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/*',
    'title' => '',
    'cache' => -1,
  );

  $export['bartik'] = $theme;

  // civiccommons
  $theme = array();

  $theme['cc_interactions-cc_interactions_apps'] = array(
    'module' => 'cc_interactions',
    'delta' => 'cc_interactions_apps',
    'theme' => 'civiccommons',
    'status' => 0,
    'weight' => '-54',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => 'Add Connections',
    'cache' => '1',
  );

  $theme['views--exp-applications-page_1'] = array(
    'module' => 'views',
    'delta' => '-exp-applications-page_1',
    'theme' => 'civiccommons',
    'status' => '1',
    'weight' => '-52',
    'region' => 'sidebar_second',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'all/apps',
    'title' => 'Search apps',
    'cache' => -1,
  );

  $theme['views--exp-applications-page_2'] = array(
    'module' => 'views',
    'delta' => '-exp-applications-page_2',
    'theme' => 'civiccommons',
    'status' => '1',
    'weight' => '-51',
    'region' => 'sidebar_second',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'most-watched/apps',
    'title' => 'Search apps',
    'cache' => -1,
  );

  $theme['views--exp-applications-page_3'] = array(
    'module' => 'views',
    'delta' => '-exp-applications-page_3',
    'theme' => 'civiccommons',
    'status' => '1',
    'weight' => '-50',
    'region' => 'sidebar_second',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'most-used/apps',
    'title' => 'Search apps',
    'cache' => -1,
  );

  $theme['views--exp-applications-page_4'] = array(
    'module' => 'views',
    'delta' => '-exp-applications-page_4',
    'theme' => 'civiccommons',
    'status' => '1',
    'weight' => '-49',
    'region' => 'sidebar_second',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'recent/apps',
    'title' => '',
    'cache' => -1,
  );

  $theme['views--exp-applications-page_5'] = array(
    'module' => 'views',
    'delta' => '-exp-applications-page_5',
    'theme' => 'civiccommons',
    'status' => '1',
    'weight' => '-48',
    'region' => 'sidebar_second',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'deployed/apps',
    'title' => '',
    'cache' => -1,
  );

  $theme['views-6411095ab78ed6f4a9989c94614d5403'] = array(
    'module' => 'views',
    'delta' => '6411095ab78ed6f4a9989c94614d5403',
    'theme' => 'civiccommons',
    'status' => '1',
    'weight' => '-57',
    'region' => 'sidebar_second',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => -1,
  );

  $theme['views-application_categories-block_1'] = array(
    'module' => 'views',
    'delta' => 'application_categories-block_1',
    'theme' => 'civiccommons',
    'status' => 0,
    'weight' => '-27',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => -1,
  );

  $theme['views-applications-block_1'] = array(
    'module' => 'views',
    'delta' => 'applications-block_1',
    'theme' => 'civiccommons',
    'status' => 0,
    'weight' => '-50',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'applications',
    'title' => '',
    'cache' => -1,
  );

  $theme['views-applications-block_2'] = array(
    'module' => 'views',
    'delta' => 'applications-block_2',
    'theme' => 'civiccommons',
    'status' => 0,
    'weight' => '-49',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'applications',
    'title' => '',
    'cache' => -1,
  );

  $theme['views-applications-block_3'] = array(
    'module' => 'views',
    'delta' => 'applications-block_3',
    'theme' => 'civiccommons',
    'status' => 0,
    'weight' => '-48',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'applications',
    'title' => '',
    'cache' => -1,
  );

  $theme['views-applications-block_4'] = array(
    'module' => 'views',
    'delta' => 'applications-block_4',
    'theme' => 'civiccommons',
    'status' => 0,
    'weight' => '-47',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'applications',
    'title' => 'Recently deployed',
    'cache' => -1,
  );

  $theme['views-at_a_glance_application_-block'] = array(
    'module' => 'views',
    'delta' => 'at_a_glance_application_-block',
    'theme' => 'civiccommons',
    'status' => '1',
    'weight' => '-56',
    'region' => 'sidebar_second',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => -1,
  );

  $theme['views-cc_organizations-block'] = array(
    'module' => 'views',
    'delta' => 'cc_organizations-block',
    'theme' => 'civiccommons',
    'status' => '1',
    'weight' => '-54',
    'region' => 'content',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/*',
    'title' => '',
    'cache' => -1,
  );

  $theme['views-d0c47a77065f0e15e04252546a319bde'] = array(
    'module' => 'views',
    'delta' => 'd0c47a77065f0e15e04252546a319bde',
    'theme' => 'civiccommons',
    'status' => '1',
    'weight' => '-55',
    'region' => 'sidebar_second',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => -1,
  );

  $theme['views-interactions-block_2'] = array(
    'module' => 'views',
    'delta' => 'interactions-block_2',
    'theme' => 'civiccommons',
    'status' => '1',
    'weight' => '-52',
    'region' => 'content',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/*',
    'title' => '<none>',
    'cache' => -1,
  );

  $theme['views-projects_use_this_app-block'] = array(
    'module' => 'views',
    'delta' => 'projects_use_this_app-block',
    'theme' => 'civiccommons',
    'status' => '1',
    'weight' => '-55',
    'region' => 'content',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => 'Projects that use this app',
    'cache' => -1,
  );

  $theme['views-related_apps_block-block'] = array(
    'module' => 'views',
    'delta' => 'related_apps_block-block',
    'theme' => 'civiccommons',
    'status' => '1',
    'weight' => '-53',
    'region' => 'sidebar_second',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/*',
    'title' => '',
    'cache' => -1,
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
    'title' => 'Add Connections',
    'cache' => '1',
  );

  $theme['views--exp-applications-page_1'] = array(
    'module' => 'views',
    'delta' => '-exp-applications-page_1',
    'theme' => 'omega',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'all/apps',
    'title' => 'Search apps',
    'cache' => -1,
  );

  $theme['views--exp-applications-page_2'] = array(
    'module' => 'views',
    'delta' => '-exp-applications-page_2',
    'theme' => 'omega',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'most-watched/apps',
    'title' => 'Search apps',
    'cache' => -1,
  );

  $theme['views--exp-applications-page_3'] = array(
    'module' => 'views',
    'delta' => '-exp-applications-page_3',
    'theme' => 'omega',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'most-used/apps',
    'title' => 'Search apps',
    'cache' => -1,
  );

  $theme['views--exp-applications-page_4'] = array(
    'module' => 'views',
    'delta' => '-exp-applications-page_4',
    'theme' => 'omega',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'recent/apps',
    'title' => '',
    'cache' => -1,
  );

  $theme['views--exp-applications-page_5'] = array(
    'module' => 'views',
    'delta' => '-exp-applications-page_5',
    'theme' => 'omega',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'deployed/apps',
    'title' => '',
    'cache' => -1,
  );

  $theme['views-6411095ab78ed6f4a9989c94614d5403'] = array(
    'module' => 'views',
    'delta' => '6411095ab78ed6f4a9989c94614d5403',
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

  $theme['views-application_categories-block_1'] = array(
    'module' => 'views',
    'delta' => 'application_categories-block_1',
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

  $theme['views-applications-block_1'] = array(
    'module' => 'views',
    'delta' => 'applications-block_1',
    'theme' => 'omega',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'applications',
    'title' => '',
    'cache' => -1,
  );

  $theme['views-applications-block_2'] = array(
    'module' => 'views',
    'delta' => 'applications-block_2',
    'theme' => 'omega',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'applications',
    'title' => '',
    'cache' => -1,
  );

  $theme['views-applications-block_3'] = array(
    'module' => 'views',
    'delta' => 'applications-block_3',
    'theme' => 'omega',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'applications',
    'title' => '',
    'cache' => -1,
  );

  $theme['views-applications-block_4'] = array(
    'module' => 'views',
    'delta' => 'applications-block_4',
    'theme' => 'omega',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'applications',
    'title' => 'Recently deployed',
    'cache' => -1,
  );

  $theme['views-at_a_glance_application_-block'] = array(
    'module' => 'views',
    'delta' => 'at_a_glance_application_-block',
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

  $theme['views-cc_organizations-block'] = array(
    'module' => 'views',
    'delta' => 'cc_organizations-block',
    'theme' => 'omega',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/*',
    'title' => '',
    'cache' => -1,
  );

  $theme['views-d0c47a77065f0e15e04252546a319bde'] = array(
    'module' => 'views',
    'delta' => 'd0c47a77065f0e15e04252546a319bde',
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

  $theme['views-interactions-block_2'] = array(
    'module' => 'views',
    'delta' => 'interactions-block_2',
    'theme' => 'omega',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/*',
    'title' => '<none>',
    'cache' => -1,
  );

  $theme['views-projects_use_this_app-block'] = array(
    'module' => 'views',
    'delta' => 'projects_use_this_app-block',
    'theme' => 'omega',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => 'Projects that use this app',
    'cache' => -1,
  );

  $theme['views-related_apps_block-block'] = array(
    'module' => 'views',
    'delta' => 'related_apps_block-block',
    'theme' => 'omega',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/*',
    'title' => '',
    'cache' => -1,
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
    'title' => 'Add Connections',
    'cache' => '1',
  );

  $theme['views--exp-applications-page_1'] = array(
    'module' => 'views',
    'delta' => '-exp-applications-page_1',
    'theme' => 'seven',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'all/apps',
    'title' => 'Search apps',
    'cache' => -1,
  );

  $theme['views--exp-applications-page_2'] = array(
    'module' => 'views',
    'delta' => '-exp-applications-page_2',
    'theme' => 'seven',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'most-watched/apps',
    'title' => 'Search apps',
    'cache' => -1,
  );

  $theme['views--exp-applications-page_3'] = array(
    'module' => 'views',
    'delta' => '-exp-applications-page_3',
    'theme' => 'seven',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'most-used/apps',
    'title' => 'Search apps',
    'cache' => -1,
  );

  $theme['views--exp-applications-page_4'] = array(
    'module' => 'views',
    'delta' => '-exp-applications-page_4',
    'theme' => 'seven',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'recent/apps',
    'title' => '',
    'cache' => -1,
  );

  $theme['views--exp-applications-page_5'] = array(
    'module' => 'views',
    'delta' => '-exp-applications-page_5',
    'theme' => 'seven',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'deployed/apps',
    'title' => '',
    'cache' => -1,
  );

  $theme['views-6411095ab78ed6f4a9989c94614d5403'] = array(
    'module' => 'views',
    'delta' => '6411095ab78ed6f4a9989c94614d5403',
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

  $theme['views-application_categories-block_1'] = array(
    'module' => 'views',
    'delta' => 'application_categories-block_1',
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

  $theme['views-applications-block_1'] = array(
    'module' => 'views',
    'delta' => 'applications-block_1',
    'theme' => 'seven',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'applications',
    'title' => '',
    'cache' => -1,
  );

  $theme['views-applications-block_2'] = array(
    'module' => 'views',
    'delta' => 'applications-block_2',
    'theme' => 'seven',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'applications',
    'title' => '',
    'cache' => -1,
  );

  $theme['views-applications-block_3'] = array(
    'module' => 'views',
    'delta' => 'applications-block_3',
    'theme' => 'seven',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'applications',
    'title' => '',
    'cache' => -1,
  );

  $theme['views-applications-block_4'] = array(
    'module' => 'views',
    'delta' => 'applications-block_4',
    'theme' => 'seven',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'applications',
    'title' => 'Recently deployed',
    'cache' => -1,
  );

  $theme['views-at_a_glance_application_-block'] = array(
    'module' => 'views',
    'delta' => 'at_a_glance_application_-block',
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

  $theme['views-cc_organizations-block'] = array(
    'module' => 'views',
    'delta' => 'cc_organizations-block',
    'theme' => 'seven',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/*',
    'title' => '',
    'cache' => -1,
  );

  $theme['views-d0c47a77065f0e15e04252546a319bde'] = array(
    'module' => 'views',
    'delta' => 'd0c47a77065f0e15e04252546a319bde',
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

  $theme['views-interactions-block_2'] = array(
    'module' => 'views',
    'delta' => 'interactions-block_2',
    'theme' => 'seven',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/*',
    'title' => '<none>',
    'cache' => -1,
  );

  $theme['views-projects_use_this_app-block'] = array(
    'module' => 'views',
    'delta' => 'projects_use_this_app-block',
    'theme' => 'seven',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => 'Projects that use this app',
    'cache' => -1,
  );

  $theme['views-related_apps_block-block'] = array(
    'module' => 'views',
    'delta' => 'related_apps_block-block',
    'theme' => 'seven',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'node/*',
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
