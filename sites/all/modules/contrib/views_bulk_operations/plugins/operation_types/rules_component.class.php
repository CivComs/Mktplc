<?php

/**
 * @file
 * Defines the class for rules components (rule, ruleset, action).
 * Belongs to the "rules_component" operation type plugin.
 */

class ViewsBulkOperationsRulesComponent extends ViewsBulkOperationsBaseOperation {
  /**
   * Returns whether the provided account has access to execute the operation.
   *
   * @param $account
   */
  public function access($account) {
    return rules_action('component_' . $this->operationInfo['key'])->access();
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
    $entity_key = $this->operationInfo['parameters']['entity_key'];
    // List types need to match the original, so passing list<node> instead of
    // list<entity> won't work. However, passing 'node' instead of 'entity'
    // will work, and is needed in order to get the right tokens.
    $list_type = 'list<' . $this->operationInfo['type'] . '>';
    $entity_type = $this->aggregate() ? $list_type : $this->entityType;
    $info = entity_get_info($this->entityType);

    // The component is wrapped in an action set so that the configuration form
    // has access to the entity's tokens.
    $set = rules_action_set(array($entity_key => array('type' => $entity_type, 'label' => $info['label'])));
    $action = rules_action('component_' . $this->operationInfo['key'], array($entity_key . ':select' => $entity_key));
    $set->action($action);
    $action->form($form, $form_state);

    // Remove the form element for the "entity" param. It will be passed in manually.
    unset($form['parameter'][$entity_key]);

    return $form;
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
    rules_ui_form_rules_config_validate($form, $form_state);
  }

  /**
   * Stores the rules element added to the form state in form(), so that it
   * can be used in execute().
   * Only called if the operation is declared as configurable.
   *
   * @param $form
   *   The views form.
   * @param $form_state
   *   An array containing the current state of the form.
   */
  public function formSubmit($form, $form_state) {
    $this->rulesElement = $form_state['rules_element']->root();
  }

  /**
   * Executes the selected operation on the provided entity.
   *
   * @param $entity
   *   The selected entity.
   * @param $context
   *   An array of related data provided by the caller.
   */
  public function execute($entity, array $context) {
    // If there was a config form, there's a rules_element.
    // If not, fallback to the component key.
    if ($this->configurable()) {
      $element = $this->rulesElement;
    }
    else {
     $element = rules_action('component_' . $this->operationInfo['parameters']['component_key']);
    }
    $element->execute($entity);
  }
}
