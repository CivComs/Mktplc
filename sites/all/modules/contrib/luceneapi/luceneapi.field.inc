<?php

/**
 * @file
 *
 */

/**
 * Filters field instances that are marked as hidden when indexing content.
 * Useful as a callback to array_filter().
 *
 * @param $field
 *   An array containing the entity field instance.
 * @return
 *   A boolean flagging whether the item should remain in the array.
 */
function luceneapi_filter_hidden_entity_field(array $field) {
  return (empty($field['display']['search_index']['type']) || $field['display']['search_index']['type'] != 'hidden');
}

/**
 * Extracts text from entity fields.
 *
 * @param $build
 *   A mixed value containing the data being indexed.
 * @param $field
 *   An array containing the field definition.
 * @return
 *   A string containing the text being indexed.
 */
function luceneapi_extract_entity_field($build, array $field) {
  return (!empty($field['name'])) ? drupal_render($build[$field['name']]) : FALSE;
}

/**
 * Converts entity fields to Search Lucene API field definitions that can be
 * used in hook_luceneapi_field_info() implementations.
 *
 * @param $entity
 *   A string containing the machine readable name of the entity.
 * @return
 *   An array containing the Search Lucene API field definitions.
 */
function luceneapi_get_entity_field_info($entity) {
  // Gets field mapping if Field module is enabled.
  $mapping = luceneapi_get_entity_field_mapping();

  // Builds Search Lucene API field definitions.
  $field_info = array();
  foreach (field_info_instances($entity) as $bundle => $instances) {
    $instances = array_filter($instances, 'luceneapi_filter_hidden_entity_field');
    foreach ($instances as $field_name => $instance) {

      // Initializes the Search Lucene API field information.
      $field = field_info_field($field_name);
      $field_info[$field_name] = array(
        'label' => $instance['label'],
        'description' => $instance['description'],
        'extract callback' => 'luceneapi_extract_entity_field',
        'group' => t('Entity fields'),
      );

      // Applies default mappings.
      if (isset($mapping[$field['type']])) {
        $field_info[$field_name] += $mapping[$field['type']];
      }
      else {
        $field_info[$field_name] += array(
          'field type' => 'unstored',
          'default bias' => 0,
          'data type' => 'string',
        );
      }

      // Takes special cases into account.
      if ('number_decimal' == $field['type']) {
        $field_info[$field_name]['data type options'] = $field['settings'];
      }

    }
  }

  return $field_info;
}

/**
 * Returns entity field mappings.
 *
 * @return
 *   An array keyed by field type to default Search Lucene API field info.
 */
function luceneapi_get_entity_field_mapping() {
  $mappings = module_invoke_all('luceneapi_entity_field_mapping');
  drupal_alter('luceneapi_entity_field_mapping', $mappings);
  return $mappings;
}

/**
 * Implements hook_luceneapi_entity_field_mapping().
 */
function luceneapi_luceneapi_entity_field_mapping() {
  return array(

    // Text
    'text' => array(
      'field type' => 'unstored',
      'default bias' => 0,
      'data type' => 'string',
    ),
    'text_long' => array(
      'field type' => 'unstored',
      'default bias' => 0,
      'data type' => 'string',
    ),
    'text_with_summary' => array(
      'field type' => 'unstored',
      'default bias' => 0,
      'data type' => 'string',
    ),

    // Number
    'number_integer' => array(
      'field type' => 'keyword',
      'data type' => 'integer',
    ),

    // Decimal
    'number_decimal' => array(
      'field type' => 'keyword',
      'data type' => 'decimal',
    ),

    // Float
    'number_float' => array(
      'field type' => 'keyword',
      'data type' => 'float',
    ),

    // List
    'list_integer' => array(
      'field type' => 'unstored',
      'default bias' => 0,
      'data type' => 'string',
    ),
    'list_float' => array(
      'field type' => 'keyword',
      'data type' => 'float',
    ),
    'list_text' => array(
      'field type' => 'unstored',
      'default bias' => 0,
      'data type' => 'string',
    ),
    'list_boolean' => array(
      'field type' => 'keyword',
      'data type' => 'boolean',
    ),

    // File
    'file' => array(
      'field type' => 'unstored',
      'default bias' => 0,
      'data type' => 'string',
    ),

    // Image
    'image' => array(
      'field type' => 'unstored',
      'default bias' => 0,
      'data type' => 'string',
    ),

    // Taxonomy
    'taxonomy_term_reference' => array(
      'field type' => 'unstored',
      'default bias' => 0,
      'data type' => 'string',
    ),
  );
}

