<?php

/**
 * @file
 * Defines the class for core actions.
 * Belongs to the "action" operation type plugin.
 */

class ViewsBulkOperationsAction extends ViewsBulkOperationsBaseOperation {
  /**
   * Contains the options provided by the user in the configuration form.
   *
   * @var array
   */
  public $formOptions = array();

  /**
   * Returns the access bitmask for the operation, used for entity access checks.
   */
  public function getAccessMask() {
    // Assume edit by default.
    if (!isset($this->operationInfo['behavior'])) {
      $this->operationInfo['behavior'] = array('changes_property');
    }

    $mask = 0;
    if (in_array('views_property', $this->operationInfo['behavior'])) {
      $mask |= VBO_ACCESS_OP_VIEW;
    }
    if (in_array('changes_property', $this->operationInfo['behavior'])) {
      $mask |= VBO_ACCESS_OP_UPDATE;
    }
    if (in_array('creates_property', $this->operationInfo['behavior'])) {
      $mask |= VBO_ACCESS_OP_CREATE;
    }
    if (in_array('deletes_property', $this->operationInfo['behavior'])) {
      $mask |= VBO_ACCESS_OP_DELETE;
    }
    return $mask;
  }

  /**
   * Returns whether the provided account has access to execute the operation.
   *
   * @param $account
   */
  public function access($account) {
    // Use actions_permissions if enabled.
    if (module_exists('actions_permissions')) {
      $perm = actions_permissions_get_perm($this->operationInfo['label'], $this->operationInfo['callback']);
      if (!user_access($perm, $account)) {
        return FALSE;
      }
    }
    // Check against additional permissions.
    if (!empty($this->operationInfo['permissions'])) {
      foreach ($this->operationInfo['permissions'] as $perm) {
        if (!user_access($perm, $account)) {
          return FALSE;
        }
      }
    }
    // Access granted.
    return TRUE;
  }

  /**
   * Returns the configuration form for the operation.
   * Only called if the operation is declared as configurable.
   *
   * @param $form
   *   The views form.
   * @param $form_state
   *   An array containing the current state of the form.
   * @param $context
   *   An array of related data provided by the caller ("selection", for example).
   */
  public function form($form, &$form_state, array $context) {
    $form_callback = $this->operationInfo['callback'] . '_form';
    return $form_callback($context);
  }

  /**
   * Validates the configuration form.
   * Only called if the operation is declared as configurable.
   *
   * @param $form
   *   The views form.
   * @param $form_state
   *   An array containing the current state of the form.
   */
  public function formValidate($form, &$form_state) {
    $validation_callback = $this->operationInfo['callback'] . '_validate';
    if (function_exists($validation_callback)) {
      $validation_callback($form, $form_state);
    }
  }

  /**
   * Handles the submitted configuration form.
   * This is where the operation can transform and store the submitted data.
   * Only called if the operation is declared as configurable.
   *
   * @param $form
   *   The views form.
   * @param $form_state
   *   An array containing the current state of the form.
   */
  public function formSubmit($form, &$form_state) {
    $submit_callback = $this->operationInfo['callback'] . '_submit';
    $this->formOptions = $submit_callback($form, $form_state);
  }

  /**
   * Returns whether the operation needs the full selected views rows to be
   * passed to execute() as a part of $context.
   */
  public function needsRows() {
    return !empty($this->operationInfo['pass rows']);
  }

  /**
   * Executes the selected operation on the provided entity.
   *
   * @param $entity
   *   The selected entity, or an array of entities, if aggregation is used.
   * @param $context
   *   An array of related data provided by the caller.
   */
  public function execute($entity, array $context) {
    $context['entity_type'] = $this->entityType;
    $context['settings'] = $this->getAdminOption('settings', array());
    $context += $this->formOptions;
    $context += $this->operationInfo['parameters'];

    actions_do($this->operationInfo['callback'], $entity, $context);
    // Actions that specify 'changes_property' need to be explicitly saved.
    if (in_array('changes_property', $this->operationInfo['behavior'])) {
      entity_save($this->entityType, $entity);
    }
  }
}
