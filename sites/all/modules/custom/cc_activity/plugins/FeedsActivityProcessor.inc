<?php

/**
 * @file
 * FeedsActivityProcessor class.
 */

/**
 * Feeds processor plugin. Create CC Activity data from feed items.
 */
class FeedsActivityProcessor extends FeedsProcessor {
  /**
   * Define entity type.
   */
  public function entityType() {
    return 'cc_activity';
  }

  /**
   * Implements parent::entityInfo().
   */
  protected function entityInfo() {
    $info = parent::entityInfo();
    $info['label plural'] = t('Activities');
    return $info;
  }

  /**
   * Creates a new user account in memory and returns it.
   */
  protected function newEntity(FeedsSource $source) {
    $activity = new stdClass();
    $activity->id = 0;
    return $activity;
  }

  /**
   * Loads an existing user.
   */
  protected function entityLoad(FeedsSource $source, $id) {
    return cc_activity_load($id);
  }

  /**
   * Validates a user account.
   */
  protected function entityValidate($activity) {
    if (empty($activity->content)) {
      throw new FeedsValidationException(t('Activity has no content.'));
    }
  }

  /**
   * Save a user account.
   */
  protected function entitySave($activity) {
    cc_activity_save($activity);
  }

  /**
   * Delete multiple user accounts.
   */
  protected function entityDeleteMultiple($activities) {
    foreach ($activities as $activity) {
      cc_activity_delete($activity);
    }
  }

  /**
   * Override parent::configDefaults().
   */
  public function configDefaults() {
    return array(
    ) + parent::configDefaults();
  }

  /**
   * Override parent::configForm().
   */
  public function configForm(&$form_state) {
    $form = parent::configForm($form_state);
    
    $form['update_existing'] = array(
      '#type' => 'checkbox',
      '#title' => t('Replace existing activites'),
      '#description' => t('If an existing activites is found for an imported user, replace it. Existing activites will be determined using mappings that are a "unique target".'),
      '#default_value' => $this->config['update_existing'],
    );
    
    return $form;
  }

  /**
   * Return available mapping targets.
   */
  public function getMappingTargets() {
    $targets = parent::getMappingTargets();
    $targets += array(
      'id' => array(
        'name' => t('Activity ID'),
        'description' => t('Unique ID of the Activity.'),
        'optional_unique' => TRUE,
       ),
      'original_url' => array(
        'name' => t('Activity URL'),
        'description' => t('URL of original content.'),
        'optional_unique' => TRUE,
       ),
      'type' => array(
        'name' => t('Activity Type'),
        'description' => t('The type of the activity, e.g. twitter.'),
       ),
      'title' => array(
        'name' => t('Activity Title'),
        'description' => t('The activity feed title.'),
      ),
      'content' => array(
        'name' => t('Activity Content'),
        'description' => t('The content from the activity feed.'),
      ),
    );

    // Let other modules expose mapping targets.
    self::loadMappers();
    feeds_alter('feeds_processor_targets', $targets, 'cc_activity', 'cc_activity');

    return $targets;
  }

  /**
   * Get id of an existing feed item term if available.
   */
  protected function existingEntityId(FeedsSource $source, FeedsParserResult $result) {
    if ($id = parent::existingEntityId($source, $result)) {
      return $id;
    }

    // Iterate through all unique targets and try to find a user for the
    // target's value.
    foreach ($this->uniqueTargets($source, $result) as $target => $value) {
      switch ($target) {
        case 'id':
          $id = db_query("SELECT id FROM {cc_activity} WHERE id = :id", array(':id' => $value))->fetchField();
          break;
        case 'url':
          $id = db_query("SELECT url FROM {cc_activity} WHERE url = :url", array(':url' => $value))->fetchField();
          break;
      }
      if ($id) {
        // Return with the first id found.
        return $id;
      }
    }
    return 0;
  }
}
