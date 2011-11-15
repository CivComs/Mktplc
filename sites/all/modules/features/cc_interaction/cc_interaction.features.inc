<?php
/**
 * @file
 * cc_interaction.features.inc
 */

/**
 * Implementation of hook_node_info().
 */
function cc_interaction_node_info() {
  $items = array(
    'interaction' => array(
      'name' => t('Interaction'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
