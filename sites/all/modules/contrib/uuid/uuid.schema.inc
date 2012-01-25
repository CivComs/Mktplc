<?php

/**
 * @file
 * Installer helper functions for adding UUIDs to schemas.
 */

/**
 * Helper function that adds a UUID column to a schema definition.
 *
 * @param $schema
 *   Reference to the schema structure to update.
 * @param $table
 *   The name of the table to add the UUID column to.
 * @param $field
 *   The name of the UUID column.
 *
 * @see uuid_schema_alter()
 */
function uuid_schema_generate(&$schema, $table, $field = 'uuid') {
  $schema[$table]['fields'][$field] = array(
    'type' => 'char',
    'length' => 36,
    'not null' => TRUE,
    'default' => '',
    'description' => 'The Universally Unique Identifier.',
  );
  $schema[$table]['indexes']['uuid'] = array($field);
}

/**
 * Adds the UUID fields to the specified table.
 */
function uuid_add_field($schema, $table) {
  foreach ($schema[$table]['fields'] as $name => $field) {
    db_add_field($table, $name, $field);
  }
  foreach ($schema[$table]['indexes'] as $name => $fields) {
    db_add_index($table, $name, $fields);
  }
}

/**
 * Removes the UUID fields from the specified table.
 */
function uuid_drop_field($schema, $table) {
  foreach (array_keys($schema[$table]['indexes']) as $index) {
    db_drop_index($table, $index);
  }
  foreach (array_keys($schema[$table]['fields']) as $field) {
    db_drop_field($table, $field);
  }
}
