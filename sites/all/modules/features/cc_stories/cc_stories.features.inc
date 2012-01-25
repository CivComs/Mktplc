<?php
/**
 * @file
 * cc_stories.features.inc
 */

/**
 * Implementation of hook_node_info().
 */
function cc_stories_node_info() {
  $items = array(
    'story' => array(
      'name' => t('Story'),
      'base' => 'node_content',
      'description' => t('A story is an informal write up about a project that references Apps or Organizations.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => t('A story is an informal write up about a project that references Apps or Organizations.'),
    ),
  );
  return $items;
}
