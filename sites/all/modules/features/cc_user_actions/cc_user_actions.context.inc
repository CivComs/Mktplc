<?php
/**
 * @file
 * cc_user_actions.context.inc
 */

/**
 * Implementation of hook_context_default_contexts().
 */
function cc_user_actions_context_default_contexts() {
  $export = array();

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'user_action';
  $context->description = 'Context for user actions, like the CC Actions block.';
  $context->tag = 'user';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '~engagement-commons' => '~engagement-commons',
        '~applications' => '~applications',
        '~places' => '~places',
        '~places/*' => '~places/*',
        '~<front>' => '~<front>',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'cc_actions-cc_actions' => array(
          'module' => 'cc_actions',
          'delta' => 'cc_actions',
          'region' => 'sidebar_second',
          'weight' => '-67',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Context for user actions, like the CC Actions block.');
  t('user');
  $export['user_action'] = $context;

  return $export;
}
