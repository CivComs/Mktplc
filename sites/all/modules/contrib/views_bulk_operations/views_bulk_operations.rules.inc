<?php

/**
 * @file
 * Views Bulk Operations conditions and actions for Rules.
 */

/**
 * Implements hook_rules_condition_info().
 */
function views_bulk_operations_rules_condition_info() {
  $conditions = array();
  $conditions['views_bulk_operations_condition_result_count'] = array(
    'label' => t('Check number of results returned by a VBO View'),
    'parameter' => array(
      'view' => array(
        'type' => 'text',
        'label' => t('View and display'),
        'options list' => 'views_bulk_operations_views_list',
        'description' => t('Select the VBO view and display you want to check'),
        'restriction' => 'input',
      ),
      'args' => array(
        'type' => 'text',
        'label' => t('Arguments'),
        'description' => t('Any arguments to pass to the view, one per line.
          You may use token replacement patterns.'),
        'optional' => TRUE,
      ),
      'minimum' => array(
        'type' => 'integer',
        'label' => t('Minimum number of results'),
        'description' => t('This condition returns TRUE if the view has at
          least the given number of results.'),
      ),
    ),
    'group' => t('Views Bulk Operations'),
  );

  return $conditions;
}

/**
 * Implements hook_rules_action_info().
 */
function views_bulk_operations_rules_action_info() {
  $actions = array();
  $actions['views_bulk_operations_action_load_list'] = array(
    'label' => t('Load a list of entities from a VBO View.'),
    'parameter' => array(
      'view' => array(
        'type' => 'text',
        'label' => t('View and display'),
        'options list' => 'views_bulk_operations_views_list',
        'description' => t('Select the view and display you want to use to
          create a list.'),
        'restriction' => 'input',
      ),
      'args' => array(
        'type' => 'text',
        'label' => t('Arguments'),
        'description' => t('Any arguments to pass to the view, one per line.
          You may use token replacement patterns.'),
        'optional' => TRUE,
      ),
    ),
    'provides' => array(
      'entity_list' => array(
        'type' => 'list<entity>',
        'label' => t('A list of entities'),
      ),
    ),
    'group' => t('Views Bulk Operations'),
  );

  return $actions;
}

/**
 * Lists all available VBO Views and their displays.
 * Naturally, only the displays that contain a VBO field are listed.
 *
 * @return array
 *   An array of all views and their displays on the form 'view|display',
 *   formatted to be used as an select list.
 */
function views_bulk_operations_views_list() {
  $selectable_displays = array();
  foreach (views_get_all_views() as $name => $view) {
    foreach ($view->display as $display_name => $display) {
      $view->build($display_name);
      $vbo = _views_bulk_operations_get_field($view);
      if ($vbo) {
        $selectable_displays[$view->name . '|' . $display_name] = check_plain($view->human_name) . ' | ' . check_plain($display->display_title);
      }
    }
  }
  return $selectable_displays;
}

/**
 * The 'views_bulk_operations_condition_result_count' condition.
 *
 * @param $view
 *   A string in the format "$view_name|$display_name".
 * @param $args
 *   Arguments that should be passed to the View.
 * @param $minimum
 *   An integer representing the minimum number of results that satisfies the
 *   condition.
 *
 * @return
 *   TRUE if the view has more than $minimum results, FALSE otherwise.
 */
function views_bulk_operations_condition_result_count($view, $args, $minimum) {
  $vbo = _views_bulk_operations_rules_get_field($view, $args);
  return (count($vbo->view->result) >= $minimum);
}

/**
 * The 'views_bulk_operations_action_views_load_list' action.
 *
 * @param $view
 *   A string in the format "$view_name|$display_name".
 * @param $args
 *   Arguments that should be passed to the View.
 */
function views_bulk_operations_action_load_list($view, $args) {
  $vbo = _views_bulk_operations_rules_get_field($view, $args);

  // Get all entity ids.
  $ids = array();
  foreach ($vbo->view->result as $row_index => $result) {
    $ids[] = $result->{$vbo->field_alias};
  }
  $entities = entity_load($vbo->get_entity_type(), $ids);

  return array('entity_list' => $entities);
}

/**
 * Helper function that loads, builds and executes the specified view,
 * then returns its VBO field.
 *
 * @param $view
 *   A string in the format "$view_name|$display_name".
 * @param $args
 *   Arguments that should be passed to the View.
 *
 * @return
 *   The VBO field. Contains a reference to the View.
 */
function _views_bulk_operations_rules_get_field($view, $args) {
  $views_settings = explode('|', $view);
  $view_name = $views_settings[0];
  $display_name = $views_settings[1];
  $view_arguments = explode("\r", $args);

  // Load the view and set the properties.
  $view = views_get_view($view_name);
  $view->set_display($display_name);
  $view->set_arguments($view_arguments);
  $view->display_handler->set_option('pager', array('type' => 'none', 'options' => array()));
  $view->build();
  $vbo = _views_bulk_operations_get_field($view);
  // Unset every field except the VBO one (which holds the entity id).
  // That way the performance hit becomes much smaller, because there is no
  // chance of views_handler_field_field::post_execute() firing entity_load().
  foreach ($view->field as $field_name => $field) {
    if ($field_name != $vbo->options['id']) {
      unset($view->field[$field_name]);
    }
  }
  $view->execute($view->current_display);

  return $vbo;
}
