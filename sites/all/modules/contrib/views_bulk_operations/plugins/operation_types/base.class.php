<?php

/**
 * @file
 * Defines the base class for operations.
 */

abstract class ViewsBulkOperationsBaseOperation {
  /**
   * The entity type that the operation is operating on.
   *
   * Not the same as $operationInfo['type'] since that value can be just
   * "entity", which means "available to every entity type".
   */
  public $entityType;

  /**
   * Contains information about the current operation, as generated
   * by the "list callback" function in the plugin file.
   *
   * @var array
   */
  protected $operationInfo;

  /**
   * Contains the options set by the admin for the current operation.
   *
   * @var array
   */
  protected $adminOptions;

  /**
   * Constructs an operation object.
   *
   * @param $entityType
   *   The entity type that the operation is operating on.
   * @param $operationInfo
   *   An array of information about the operation.
   * @param $adminOptions
   *   An array of options set by the admin.
   */
  public function __construct($entityType, array $operationInfo, array $adminOptions) {
    $this->entityType = $entityType;
    $this->operationInfo = $operationInfo;
    $this->adminOptions = $adminOptions;
  }

  /**
   * Returns the value of an admin option.
   */
  public function getAdminOption($key, $default = NULL) {
    return isset($this->adminOptions[$key]) ? $this->adminOptions[$key] : $default;
  }

  /**
   * Returns the access bitmask for the operation, used for entity access checks.
   */
  public function getAccessMask() {
    // Assume edit by default.
    return VBO_ACCESS_OP_UPDATE;
  }

  /**
   * Returns the human-readable name of the operation, meant to be shown
   * to the user.
   */
  public function label() {
    $admin_label = $this->getAdminOption('label');
    if (!empty($admin_label)) {
      $label = t($admin_label);
    }
    else {
      // If the admin didn't specify any label, fallback to the default one.
      $label = $this->operationInfo['label'];
    }
    return $label;
  }

  /**
   * Returns whether the operation is configurable. Used to determine
   * whether the operation's form methods should be invoked.
   */
  public function configurable() {
    return !empty($this->operationInfo['configurable']);
  }

  /**
   * Returns whether the provided account has access to execute the operation.
   *
   * @param $account
   */
  public function access($account) {
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
  abstract function form($form, &$form_state, array $context);

  /**
   * Validates the configuration form.
   * Only called if the operation is declared as configurable.
   *
   * @param $form
   *   The views form.
   * @param $form_state
   *   An array containing the current state of the form.
   */
  abstract function formValidate($form, &$form_state);

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
  abstract function formSubmit($form, &$form_state);

  /**
   * Returns whether the selected entities should be aggregated
   * (loaded in bulk and passed in together).
   * To be avoided if possible, since aggregation makes it impossible to use
   * Batch API or the Drupal Queue for execution.
   */
  public function aggregate() {
    return !empty($this->operationInfo['aggregate']);
  }

  /**
   * Returns whether the operation needs the full selected views rows to be
   * passed to execute() as a part of $context.
   */
  public function needsRows() {
    return FALSE;
  }

  /**
   * Executes the selected operation on the provided entity.
   *
   * @param $entity
   *   The selected entity, or an array of entities, if aggregation is used.
   * @param $context
   *   An array of related data provided by the caller.
   */
  abstract function execute($entity, array $context);
}
