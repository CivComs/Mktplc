<?php

/**
 * @file
 * Entity related functions for UUID module.
 */

/**
 * @defgroup uuid_entity_hooks UUID implementation of Entity API
 * @{
 */

/**
 * Implements of hook_entity_info_alter().
 *
 * This enables UUID for all core entities.
 */
function uuid_entity_info_alter(&$info) {
  $info['node']['uuid'] = TRUE;
  $info['node']['entity keys']['uuid'] = 'uuid';
  $info['node']['entity keys']['revision uuid'] = 'vuuid';
  $info['user']['uuid'] = TRUE;
  $info['user']['entity keys']['uuid'] = 'uuid';
  if (module_exists('comment')) {
    $info['comment']['uuid'] = TRUE;
    $info['comment']['entity keys']['uuid'] = 'uuid';
  }
  if (module_exists('file')) {
    $info['file']['uuid'] = TRUE;
    $info['file']['entity keys']['uuid'] = 'uuid';
  }
  if (module_exists('taxonomy')) {
    $info['taxonomy_term']['uuid'] = TRUE;
    $info['taxonomy_term']['entity keys']['uuid'] = 'uuid';
  }
}

/**
 * Implements of hook_entity_property_info_alter().
 *
 * This adds the UUID as an entity property for all UUID-enabled entities
 * which automatically gives us token and Rules integration.
 */
function uuid_entity_property_info_alter(&$info) {
  foreach (entity_get_info() as $entity_type => $entity_info) {
    if (isset($entity_info['uuid']) && $entity_info['uuid'] == TRUE && !empty($entity_info['entity keys']['uuid'])) {
      $info[$entity_type]['properties'][$entity_info['entity keys']['uuid']] = array(
        'label' => t('UUID'),
        'type' => 'text',
        'description' => t('The universally unique ID.'),
        'schema field' => $entity_info['entity keys']['uuid'],
      );
      if (!empty($entity_info['entity keys']['revision uuid'])) {
        $info[$entity_type]['properties'][$entity_info['entity keys']['revision uuid']] = array(
          'label' => t('Revision UUID'),
          'type' => 'text',
          'description' => t("The revision's universally unique ID."),
          'schema field' => $entity_info['entity keys']['revision uuid'],
        );
      }
    }
  }
}

/**
 * Implements of hook_entity_presave().
 *
 * This is where all UUID-enabled entities get their UUIDs.
 */
function uuid_entity_presave($entity, $entity_type) {
  $info = entity_get_info($entity_type);
  if (isset($info['uuid']) && $info['uuid'] == TRUE && !empty($info['entity keys']['uuid'])) {
    $uuid_key = $info['entity keys']['uuid'];
    if (empty($entity->{$uuid_key})) {
      $entity->{$uuid_key} = uuid_generate();
    }
    if (!empty($info['entity keys']['revision uuid'])) {
      $vuuid_key = $info['entity keys']['revision uuid'];
      if (isset($entity->revision) && $entity->revision == TRUE) {
        $entity->{$vuuid_key} = uuid_generate();
      }
    }
  }
}

/**
 * @} End of "UUID implementation of Entity API"
 */

/**
 * @defgroup uuid_entity_support UUID support for Entity API
 * @{
 * Functions that extends the Entity API with UUID support.
 */

/**
 * Load entities only containing UUID references.
 * 
 * This function is mostly useful if you want to load an entity from the local
 * database that only should contain UUID references.
 *
 * @see entity_load()
 */
function entity_uuid_load($entity_type, $uuids = array(), $conditions = array(), $reset = FALSE) {
  $ids = entity_get_id_by_uuid($entity_type, $uuids);
  $entities = entity_load($entity_type, $ids, $conditions, $reset);

  // Let other modules transform local ID references to UUID references.
  if (!empty($entities)) {
    module_invoke_all('entity_uuid_load', $entities, $entity_type);
  }

  return $entities;
}

/**
 * Permanently saves an entity by its UUID. This function depends on the
 * Entity API module to provide the 'entity_save()' function.
 *
 * This function is mostly useful if you want to save an entity into the local
 * database that only contains UUID references.
 *
 * @see entity_save()
 */
function entity_uuid_save($entity_type, $entity) {
  // This function, and this function only, depends on the entity module.
  if (!module_exists('entity')) {
    watchdog('uuid', 'Calling %function requires the entity module.', array('%function' => __FUNCTION__), WATCHDOG_ERROR);
  }

  $info = entity_get_info($entity_type);
  if (isset($info['uuid']) && $info['uuid'] == TRUE && !empty($info['entity keys']['uuid'])) {
    // Get the keys for local ID and UUID.
    $id_key = $info['entity keys']['id'];
    $uuid_key = $info['entity keys']['uuid'];
    // Fetch the local ID by its UUID.
    $id = reset(entity_get_id_by_uuid($entity_type, array($entity->{$uuid_key})));
    // Set the correct local ID.
    if (empty($id)) {
      unset($entity->{$id_key});
    }
    else {
      $entity->{$id_key} = $id;
    }

    if (!empty($info['entity keys']['revision uuid'])) {
      // Get the keys for local revison ID and revision UUID.
      $vid_key = $info['entity keys']['revision'];
      $vuuid_key = $info['entity keys']['revision uuid'];
      // Fetch the local revision ID by its UUID.
      $vid = reset(entity_get_id_by_uuid($entity_type, array($entity->{$vuuid_key}), TRUE));
      if (empty($vid)) {
        unset($entity->{$vid_key});
        $entity->revision = TRUE;
      }
      else {
        $entity->{$vid_key} = $vid;
      }
    }

    try {
      // Let other modules transform UUID references to local ID references.
      module_invoke_all('entity_uuid_presave', $entity, $entity_type);
    }
    catch (Exception $e) {
      throw $e;
    }

    // Save the entity.
    entity_save($entity_type, $entity);
  }
}

/**
 * Helper function that retrieves entity IDs by their UUIDs.
 *
 * @param $entity_type
 *   The entity type we should be dealing with.
 * @param $uuids
 *   An array of UUIDs for which we should find their entity IDs. If $revision
 *   is TRUE this should be revision UUIDs instead.
 * @param $revision
 *   If TRUE the revision IDs is returned instead.
 * @return
 *   Array of entity IDs keyed by their UUIDs. If $revision is TRUE revision
 *   IDs and UUIDs are returned instead.
 */
function entity_get_id_by_uuid($entity_type, $uuids, $revision = FALSE) {
  if (empty($uuids)) {
    return FALSE;
  }
  $info = entity_get_info($entity_type);
  // Find out what entity keys to use.
  if (!$revision) {
    $table = $info['base table'];
    $id_key = $info['entity keys']['id'];
    $uuid_key = $info['entity keys']['uuid'];
  }
  elseif (isset($info['revision table'])) {
    $table = $info['revision table'];
    $id_key = $info['entity keys']['revision'];
    $uuid_key = $info['entity keys']['revision uuid'];
  }
  // If we want revision IDs, but the entity doesn't support it. Return empty.
  else {
    return array();
  }

  // Get all UUIDs in one query.
  $query = db_select($table, ' t');
  $query->addField('t', $id_key, 'id');
  $query->addField('t', $uuid_key, 'uuid');
  $result = $query
    ->condition($uuid_key, array_values($uuids), 'IN')
    ->execute();

  $ids = array();
  foreach ($result as $record) {
    $ids[$record->uuid] = $record->id;
  }
  return $ids;
}

/**
 * Helper function that retrieves UUIDs by their entity IDs.
 *
 * @param $entity_type
 *   The entity type we should be dealing with.
 * @param $ids
 *   An array of entity IDs for which we should find their UUIDs. If $revision
 *   is TRUE this should be revision IDs instead.
 * @param $revision
 *   If TRUE the revision UUIDs is returned instead.
 * @return
 *   Array of entity UUIDs keyed by their IDs. If $revision is TRUE revision
 *   IDs and UUIDs are returned instead.
 */
function entity_get_uuid_by_id($entity_type, $ids, $revision = FALSE) {
  $info = entity_get_info($entity_type);
  // Find out what entity keys to use.
  if (!$revision) {
    $table = $info['base table'];
    $id_key = $info['entity keys']['id'];
    $uuid_key = $info['entity keys']['uuid'];
  }
  elseif (isset($info['revision table'])) {
    $table = $info['revision table'];
    $id_key = $info['entity keys']['revision'];
    $uuid_key = $info['entity keys']['revision uuid'];
  }
  // If we want revision UUIDs, but the entity doesn't support it. Return empty.
  else {
    return array();
  }

  // Get all UUIDs in one query.
  $query = db_select($table, ' t');
  $query->addField('t', $id_key, 'id');
  $query->addField('t', $uuid_key, 'uuid');
  $result = $query
    ->condition($id_key, array_values($ids), 'IN')
    ->execute();

  $ids = array();
  foreach ($result as $record) {
    $ids[$record->id] = $record->uuid;
  }
  return $ids;
}

/**
 * @} End of "UUID support for Entity API"
 */
