<?php
/**
 * @file
 * engagement_commons.features.fe_block_boxes.inc
 */

/**
 * Implementation of hook_default_fe_block_boxes().
 */
function engagement_commons_default_fe_block_boxes() {
  $export = array();

  $fe_block_boxes = new stdClass;
  $fe_block_boxes->info = 'Provides a header for the Engagement Commons Header';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'engagement_commons_header';
  $fe_block_boxes->body = '<span class="engagement-commons-header-title">Engagement Commons</span> <span class="engagement-commons-header-subtitle">Discover apps to engage your community</span>';

  $export['engagement_commons_header'] = $fe_block_boxes;

  return $export;
}
