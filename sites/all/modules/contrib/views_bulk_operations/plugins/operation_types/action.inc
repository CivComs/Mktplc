<?php

/**
 * @file
 * CTools plugin. Provides support for core actions.
 */

$plugin = array(
  'title' => t('Action'),
  'list callback' => 'views_bulk_operations_operation_action_list',
  'handler' => array(
    'file' => 'action.class.php',
    'class' => 'ViewsBulkOperationsAction',
  ),
);

function views_bulk_operations_operation_action_list() {
  $action_operations = actions_list() + views_bulk_operations_operation_advanced_action_list();
  $operations = array();
  foreach ($action_operations as $callback => $operation) {
    $key = isset($operation['key']) ? $operation['key'] : $callback;
    $operations[$key] = array(
      'plugin' => 'action',
      'key' => $key,
      'label' => isset($operation['label']) ? $operation['label'] : '',
      'callback' => $callback,
      'parameters' => isset($operation['parameters']) ? $operation['parameters'] : array(),
      'configurable' => !empty($operation['configurable']),
      'type' => $operation['type'],
      'aggregate' => !empty($operation['aggregate']),
      'behavior' => isset($operation['behavior']) ? $operation['behavior'] : array(),
      'permissions' => isset($operation['permissions']) ? $operation['permissions'] : NULL,
      'pass rows' => !empty($operation['pass rows']),
    );
  }
  return $operations;
}

/**
 * Get a list of advanced actions (created through the Action UI).
 */
function views_bulk_operations_operation_advanced_action_list() {
  $actions = array();
  $static_actions = actions_list();
  $result = db_query("SELECT * FROM {actions} WHERE parameters > ''");
  foreach ($result as $action) {
    $parameters = unserialize($action->parameters);
    $actions[$action->aid] = array(
      'label' => isset($action->label) ? $action->label : '',
      'callback' => $action->callback,
      'type' => $action->type,
      'configurable' => FALSE,
      'parameters' => $parameters,
      'key' => $action->callback . (empty($parameters) ? '' : ':'. md5($action->parameters)),
    );
    foreach (array('aggregate', 'behavior', 'permissions', 'pass rows') as $attribute) {
      if (isset($static_actions[$action->callback][$attribute])) {
        $actions[$action->aid][$attribute] = $static_actions[$action->callback][$attribute];
      }
    }
    if (isset($static_actions[$action->callback['parameters']])) {
      $actions[$action->aid]['parameters'] = array_merge($actions[$action->aid]['parameters'], $static_actions[$action->callback]['parameters']);
    }
  }
  return $actions;
}
