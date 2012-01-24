<?php

/**
 * @file
 * Implementation of UUID hooks for all core modules.
 */

/**
 * @defgroup uuid_node Node module implementations
 * @{
 */

/**
 * Implements hook_entity_uuid_load().
 */
function node_entity_uuid_load(&$entities, $entity_type) {
  if ($entity_type == 'node') {
    foreach ($entities as $entity) {
      $ids = !empty($entity->revision_uid) ? array($entity->uid, $entity->revision_uid) : array($entity->uid);
      $uuids = entity_get_uuid_by_id('user', $ids);

      // 'uid' property.
      if (isset($uuids[$entity->uid])) {
        $entity->uid = $uuids[$entity->uid];
      }

      // 'revision_uid' property.
      if (!empty($entity->revision_uid) && isset($uuids[$entity->revision_uid])) {
        $entity->revision_uid = $uuids[$entity->revision_uid];
      }

      // 'tnid' property.
      if (!empty($entity->tnid)) {
        $uuids = entity_get_uuid_by_id('node', array($entity->tnid));
        if (isset($uuids[$entity->tnid])) {
          $entity->tnid = $uuids[$entity->tnid];
        }
      }
    }
  }
}

/**
 * Implements hook_entity_uuid_presave().
 */
function node_entity_uuid_presave(&$entity, $entity_type) {
  // Transform all UUID properties to local IDs, if they exist.
  if ($entity_type == 'node') {
    $uuids = !empty($entity->revision_uid) ? array($entity->uid, $entity->revision_uid) : array($entity->uid);
    $ids = entity_get_id_by_uuid('user', $uuids);

    // 'uid' property.
    if (isset($ids[$entity->uid])) {
      $entity->uid = $ids[$entity->uid];
    }

    // 'revision_uid' property.
    if (!empty($entity->revision_uid) && isset($ids[$entity->revision_uid])) {
      $entity->revision_uid = $ids[$entity->revision_uid];
    }

    // 'tnid' property.
    $ids = entity_get_id_by_uuid('node', array($entity->tnid));
    if (isset($ids[$entity->tnid])) {
      $entity->tnid = $ids[$entity->tnid];
    }
  }
}

/**
 * @} End of "Node module implementations"
 */

/**
 * @defgroup uuid_comment Comment module implementations
 * @{
 */

/**
 * Implements hook_entity_uuid_load().
 */
function comment_entity_uuid_load(&$entities, $entity_type) {
  foreach ($entities as $entity) {
    // Transform all local ID properties to UUIDs.
    switch ($entity_type) {
      case 'node':
        // 'last_comment_uid' property.
        if (isset($entity->last_comment_uid)) {
          $uuids = entity_get_uuid_by_id('user', array($entity->last_comment_uid));
          if (isset($uuids[$entity->last_comment_uid])) {
            $entity->last_comment_uid = $uuids[$entity->last_comment_uid];
          }
        }
        break;

      case 'comment':
        // 'uid' property.
        $uuids = entity_get_uuid_by_id('user', array($entity->uid, $entity->u_uid));
        if (isset($uuids[$entity->uid])) {
          $entity->uid = $uuids[$entity->uid];
          $entity->u_uid = $uuids[$entity->u_uid];
        }

        // 'nid' property.
        $uuids = entity_get_uuid_by_id('node', array($entity->nid));
        if (isset($uuids[$entity->nid])) {
          $entity->nid = $uuids[$entity->nid];
        }
        break;
    }
  }
}

/**
 * Implements hook_entity_uuid_presave().
 */
function comment_entity_uuid_presave(&$entity, $entity_type) {
  // Transform all UUID properties to local IDs, if they exist.
  switch ($entity_type) {
    case 'node':
      if (isset($entity->last_comment_uid)) {
        $ids = entity_get_id_by_uuid('user', array($entity->last_comment_uid));
        if (isset($ids[$entity->last_comment_uid])) {
          $entity->last_comment_uid = $ids[$entity->last_comment_uid];
        }
      }
      break;

    case 'comment':
      // 'uid' property.
      $ids = entity_get_id_by_uuid('user', array($entity->uid, $entity->u_uid));
      if (isset($ids[$entity->uid])) {
        $entity->uid = $ids[$entity->uid];
        $entity->u_uid = isset($ids[$entity->u_uid]) ? $ids[$entity->u_uid] : $ids[$entity->uid];
      }

      // 'nid' property.
      $ids = entity_get_id_by_uuid('node', array($entity->nid));
      if (isset($ids[$entity->nid])) {
        $entity->nid = $ids[$entity->nid];
      }
      break;
  }
}

/**
 * @} End of "Comment module implementations"
 */

/**
 * @defgroup uuid_file File module implementations
 * @{
 */

/**
 * Implements hook_entity_uuid_load().
 */
function file_entity_uuid_load(&$entities, $entity_type) {
  if ($entity_type == 'file') {
    foreach ($entities as $entity) {
      // 'uid' property.
      $uuids = entity_get_uuid_by_id('user', array($entity->uid));
      if (isset($uuids[$entity->uid])) {
        $entity->uid = $uuids[$entity->uid];
      }
    }
  }
}

/**
 * Implements hook_entity_uuid_presave().
 */
function file_entity_uuid_presave(&$entity, $entity_type) {
  if ($entity_type == 'file') {
    // 'uid' property.
    $ids = entity_get_id_by_uuid('user', array($entity->uid));
    if (isset($ids[$entity->uid])) {
      $entity->uid = $ids[$entity->uid];
    }
  }
}

/**
 * @} End of "File module implementations"
 */

/**
 * @defgroup uuid_field Field module implementations
 * @{
 *
 * @todo
 *   Take better advantage of the multi load functionality in
 *   entity_get_*id_by_*id() in all field implementations. We probably need to
 *   loop twice over $items, but we will save SQL queries.
 */

/**
 * Implements hook_entity_uuid_load().
 */
function field_entity_uuid_load(&$entities, $entity_type) {
  foreach ($entities as $i => $entity) {
    list(, , $bundle_name) = entity_extract_ids($entity_type, $entity);
    $instances = field_info_instances($entity_type, $bundle_name);

    foreach ($instances as $field_name => $instance) {
      $field = field_info_field($field_name);
      foreach ($entity->{$field_name} as $langcode => &$items) {
        // Invoke 'hook_field_uuid_load'. We can't use module_invoke() since
        // that is not passing by reference.
        $function = $field['module'] . '_field_uuid_load';
        if (function_exists($function)) {
          $function($entity_type, $entity, $field, $instance, $langcode, $items);
        }
      }
    }
  }
}

/**
 * Implements hook_entity_uuid_presave().
 */
function field_entity_uuid_presave(&$entity, $entity_type) {
  list(, , $bundle_name) = entity_extract_ids($entity_type, $entity);
  $instances = field_info_instances($entity_type, $bundle_name);

  foreach ($instances as $field_name => $instance) {
    $field = field_info_field($field_name);
    foreach ($entity->{$field_name} as $langcode => &$items) {
      // Invoke 'hook_field_uuid_load'. We can't use module_invoke() since
      // that is not passing by reference.
      $function = $field['module'] . '_field_uuid_presave';
      if (function_exists($function)) {
        $function($entity_type, $entity, $field, $instance, $langcode, $items);
      }
    }
  }
}

/**
 * Implements hook_field_uuid_load().
 */
function taxonomy_field_uuid_load($entity_type, $entity, $field, $instance, $langcode, &$items) {
  foreach ($items as &$item) {
    $item['tid'] = reset(entity_get_uuid_by_id('taxonomy_term', array($item['tid'])));
  }
}

/**
 * Implements hook_field_uuid_presave().
 */
function taxonomy_field_uuid_presave($entity_type, $entity, $field, $instance, $langcode, &$items) {
  foreach ($items as &$item) {
    $item['tid'] = reset(entity_get_id_by_uuid('taxonomy_term', array($item['tid'])));
  }
}

/**
 * Implements hook_field_uuid_load().
 */
function file_field_uuid_load($entity_type, $entity, $field, $instance, $langcode, &$items) {
  foreach ($items as &$item) {
    $item['fid'] = reset(entity_get_uuid_by_id('file', array($item['fid'])));
    $item['uid'] = reset(entity_get_uuid_by_id('user', array($item['uid'])));
  }
}

/**
 * Implements hook_field_uuid_presave().
 */
function file_field_uuid_presave($entity_type, $entity, $field, $instance, $langcode, &$items) {
  foreach ($items as &$item) {
    $item['fid'] = reset(entity_get_id_by_uuid('file', array($item['fid'])));
    $item['uid'] = reset(entity_get_id_by_uuid('user', array($item['uid'])));
  }
}

/**
 * Implements hook_field_uuid_load().
 */
function image_field_uuid_load($entity_type, $entity, $field, $instance, $langcode, &$items) {
  // Image fields works exactly the same way as file fields.
  file_field_uuid_load($entity_type, $entity, $field, $instance, $langcode, $items);
}

/**
 * Implements hook_field_uuid_presave().
 */
function image_field_uuid_presave($entity_type, $entity, $field, $instance, $langcode, &$items) {
  // Image fields works exactly the same way as file fields.
  file_field_uuid_presave($entity_type, $entity, $field, $instance, $langcode, $items);
}

/**
 * @} End of "Field module implementations"
 */

/**
 * @defgroup uuid_references References module implementations
 * @{
 *
 * @todo
 *   When the UUID API has stabilized these implementations can be moved to the
 *   appropriate sub modules of References.
 */

/**
 * Implements hook_field_uuid_load().
 */
function node_reference_field_uuid_load($entity_type, $entity, $field, $instance, $langcode, &$items) {
  foreach ($items as &$item) {
    $item['nid'] = reset(entity_get_uuid_by_id('node', array($item['nid'])));
  }
}

/**
 * Implements hook_field_uuid_presave().
 */
function node_reference_field_uuid_presave($entity_type, $entity, $field, $instance, $langcode, &$items) {
  foreach ($items as &$item) {
    $item['nid'] = reset(entity_get_id_by_uuid('node', array($item['nid'])));
  }
}

/**
 * Implements hook_field_uuid_load().
 */
function user_reference_field_uuid_load($entity_type, $entity, $field, $instance, $langcode, &$items) {
  foreach ($items as &$item) {
    $item['uid'] = reset(entity_get_uuid_by_id('user', array($item['uid'])));
  }
}

/**
 * Implements hook_field_uuid_presave().
 */
function user_reference_field_uuid_presave($entity_type, $entity, $field, $instance, $langcode, &$items) {
  foreach ($items as &$item) {
    $item['uid'] = reset(entity_get_id_by_uuid('user', array($item['uid'])));
  }
}

/**
 * @} End of "References module implementations"
 */
