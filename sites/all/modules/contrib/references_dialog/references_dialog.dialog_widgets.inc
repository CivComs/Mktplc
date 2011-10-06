<?php

/**
 * @file
 * Implements dialogs for node reference and user reference fields.
 */

/**
 * Implements hook_references_dialog_widgets().
 */
function references_dialog_references_dialog_widgets() {
  return array(
    'node_reference_autocomplete' => array(
      'element_type' => 'textfield',
      'dialog_form' => 'node_reference_dialog_form',
      'entity_type' => 'node',
      'format' => '$label [nid: $entity_id]',
      'views_query' => 'references_dialog_node_reference_views_query',
      'operations' => array(
        'search' => array(
          'function' => 'references_dialog_get_views_search_links',
          'title' => t('Search Dialog'),
        ),
        'edit' => array(
          'function' => 'references_dialog_node_reference_edit_link',
          'title' => t('Edit dialog'),
        ),
        'add' => array(
          'function' => 'references_dialog_node_reference_add_link',
          'title' => t('Add dialog'),
        ),
      ),
    ),
    'user_reference_autocomplete' => array(
      'element_type' => 'textfield',
      'entity_type' => 'user',
      'format' => '$label [uid: $entity_id]',
      'operations' => array(
        'search' => array(
          'function' => 'references_dialog_get_views_search_links',
          'title' => t('Search Dialog'),
        ),
        'edit' => array(
          'function' => 'references_dialog_user_reference_edit_link',
          'title' => t('Edit dialog'),
        ),
        'add' => array(
          'function' => 'references_dialog_user_reference_add_link',
          'title' => t('Add dialog'),
        ),
      ),
    ),
  );
}

/**
 * Edit link callback for node references.
 */
function references_dialog_node_reference_edit_link($element, $widget_settings, $field, $instance) {
  if (isset($element['#default_value'])) {
    $node = node_load($element['#default_value']);
    if (node_access('update', $node)) {
      return array(
        array(
          'title' => t('Edit'),
          'href' => 'node/' . $element['#default_value'] . '/edit'
        ),
      );
    }
  }
  return array();
}

/**
 * Add link callback for node references.
 */
function references_dialog_node_reference_add_link($element, $widget_settings, $field, $instance) {
  $add_links = array();
  foreach ($field['settings']['referenceable_types'] as $type => $active) {
    if ($active !== 0) {
      $node_type = node_type_load($type);
      if (node_access('create', $node_type->type)) {
        $add_links[] = array(
          'title' => t('Create @type', array('@type' => $node_type->name)),
          'href' => 'node/add/' . strtr($type, array('_' => '-')),
        );
      }
    }
  }
  return $add_links;
}

/**
 * View query callback for node references.
 */
function references_dialog_node_reference_views_query($display, $view, $instance, $field) {
  // We need to make sure that no entries that we can't add to our field shows
  // up, so we need to limit the data here.
  $types = array();
  foreach ($field['settings']['referenceable_types'] as $type => $active) {
    if ($active !== 0) {
      $types[] = $type;
    }
  }
  $view->query->add_where(0, "$view->base_table.type", $types);
}

/**
 * Edit callback for user references.
 */
function references_dialog_user_reference_edit_link($element, $widget_settings, $field, $instance) {
  global $user;
  $user_links = array();
  if (is_numeric($element['#default_value']) && user_load($element['#default_value']) &&
       user_access('access user profiles') &&
       (user_access('administer users') || $user->uid == $element['#default_value'])) {
    $user_links[] = array(
      'title' => t('Edit'),
      'href' => 'user/' . $element['#default_value'] . '/edit',
    );
  }
  return $user_links;
}

/**
 * Add link callback for user references.
 */
function references_dialog_user_reference_add_link($element, $widget_settings, $field, $instance) {
  $user_links = array();
  // Check permissions for adding users.
  if (user_access('administer users')) {
    $user_links[] = array(
      'title' => t('Create user'),
      'href' => 'admin/people/create'
    );
  }
  return $user_links;
}