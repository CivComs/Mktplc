<?php

/**
 * @file
 * Drush integration for the git_deploy module.
 */

/**
 * Implements hook_drush_command().
 */
function git_deploy_drush_command() {
  $items['git-deploy-download'] = array(
    'description' => dt('Downloads the Glip library from https://github.com/halstead/glip/.'),
    'arguments' => array(
      'path' => dt('Optional. A path to the download folder. If omitted Drush will use the sites/all/libraries/glip (if libraries module is enabled). Else, the git_deploy module folder is used.'),
    ),
    'aliases' => array('gdd'),
  );
  return $items;
}

/**
 * Implementation of hook_drush_help().
 */
function git_deploy_drush_help($section) {
  switch ($section) {
    case 'drush:git_deploy-download':
      return dt('Downloads the Glip library from https://github.com/halstead/glip/. Places it in the libraries directory. Skips download if library already present. This all happens automatically if you enable git_deploy using drush.');
  }
}

/**
 * A command callback. Download the Glip library using git.
 */
function drush_git_deploy_download() {
  $args = func_get_args();
  if (isset($args[0])) {
    $path = $args[0];
  }
  else {
    $path = drush_get_context('DRUSH_DRUPAL_ROOT');
    if (module_exists('libraries')) {
      $path .= '/'. libraries_get_path('glip');
    }
    else {
      $path .= '/'. drupal_get_path('module', 'git_deploy') . '/glip';
    }
  }

  if (is_dir($path)) {
    drush_log('Glip already present. No download required.', 'ok');
  }
  elseif (drush_shell_cd_and_exec(dirname($path), 'git clone https://github.com/halstead/glip.git && cd glip && git checkout 1.1')) {
    drush_log(dt('Glip has been cloned via git to @path.', array('@path' => $path)), 'success');
  }
  else {
    drush_log(dt('Drush was unable to clone Glip to @path.', array('@path' => $path)), 'error');
  }
}

/**
 * Implements drush_MODULE_post_COMMAND().
 */
function drush_git_deploy_post_pm_enable() {
  $modules = func_get_args();
  if (in_array('git_deploy', $modules)) {
    drush_git_deploy_download();
  }
}
