<?php
/**
 * @file
 * cc_user_feature.features.fe_block_boxes.inc
 */

/**
 * Implementation of hook_default_fe_block_boxes().
 */
function cc_user_feature_default_fe_block_boxes() {
  $export = array();

  $fe_block_boxes = new stdClass;
  $fe_block_boxes->info = 'Log In';
  $fe_block_boxes->format = 'filtered_html';
  $fe_block_boxes->machine_name = 'user_login';
  $fe_block_boxes->body = '<a href="/user/login">Log in Here!</a>';

  $export['user_login'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass;
  $fe_block_boxes->info = 'Sign Up';
  $fe_block_boxes->format = 'filtered_html';
  $fe_block_boxes->machine_name = 'user_signup';
  $fe_block_boxes->body = ' <a href="/user/register">Sign up Here!</a>';

  $export['user_signup'] = $fe_block_boxes;

  return $export;
}
