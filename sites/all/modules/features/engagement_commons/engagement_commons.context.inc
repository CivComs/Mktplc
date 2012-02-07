<?php
/**
 * @file
 * engagement_commons.context.inc
 */

/**
 * Implementation of hook_context_default_contexts().
 */
function engagement_commons_context_default_contexts() {
  $export = array();

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'engagement_commons_main_page';
  $context->description = 'Provides a context for the engagement commons main page.';
  $context->tag = 'Engagement Commons';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'engagement-commons' => 'engagement-commons',
        'engagement_commons' => 'engagement_commons',
        'engagementcommons' => 'engagementcommons',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'block-24' => array(
          'module' => 'block',
          'delta' => 24,
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'block-37' => array(
          'module' => 'block',
          'delta' => 37,
          'region' => 'content_leftcolumn',
          'weight' => '-10',
        ),
        'block-36' => array(
          'module' => 'block',
          'delta' => 36,
          'region' => 'search_bar',
          'weight' => '-59',
        ),
      ),
    ),
    'theme_html' => array(
      'class' => 'engagement-commons engagement-commons-main-page',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Engagement Commons');
  t('Provides a context for the engagement commons main page.');
  $export['engagement_commons_main_page'] = $context;

  return $export;
}
