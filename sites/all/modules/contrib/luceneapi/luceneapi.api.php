<?php

/**
 * @file
 * Hooks provided by the Search Lucene API module.
 *
 * @ingroup luceneapi
 */

/**
 * @addtogroup hooks
 * @{
 */

/**
 * Defines a backend plugin.
 */
function hook_luceneapi_backends() {
  return array(
    'zend_framework' => array(
      'handler' => array(
        'label' => t('Zend Framework'),
        'description' => t("The Zend Framework's PHP port of Lucene."),
        'class' => 'LuceneapiBackendZendFramework',
      ),
    ),
  );
}

/**
 * Defines an indexer plugin.
 */
function hook_luceneapi_indexers() {
  return array(
    'node' => array(
      'handler' => array(
        'label' => t('Node content'),
        'description' => t("Indexes the site's node content."),
        'class' => 'LuceneapiIndexerNode',
      ),
    ),
  );
}


/**
 *
 */
function hook_luceneapi_highlighters() {

}

/**
 *
 */
function hook_luceneapi_normalizers() {

}

/**
 *
 */
function hook_luceneapi_filters() {

}

/**
 *
 */
function hook_luceneapi_entity_field_mapping() {

}

/**
 *
 */
function hook_luceneapi_entity_field_mapping_alter(array &$mappings) {

}

/**
 * Defines fields that can be indexed by Search Lucene API.
 *
 * @param $indexer_module
 *   A string containing the machine readable name of the indexer.
 * @return
 *   An associative array of
 */
function hook_luceneapi_field_info($indexer_module) {
  $fields = array();
  if ('luceneapi_node' == $indexer_module) {

    $fields['nid'] = array(
      'label' => t('Node ID'),
      'description' => t('The unique identifier of the node.'),
      'field type' => 'keyword',
      'data type' => 'integer',
      'data type options' => array(),
      'configurable' => FALSE,
      'sortable' => FALSE,
      'default bias' => FALSE,
      'default value' => FALSE,
      'extract callback' => 'luceneapi_node_property_extract',
      'extract arguments' => array(),
    );

  }
  return $fields;
}

/**
 *
 */
function hook_luceneapi_field_info_alter(array &$fields, $indexer_module) {

}

/**
 * Allows modules to act on the index that is being "opened".
 */
function hook_luceneapi_index_open(LuceneapiIndex $index) {
  // Useful for adding additional highlighters and normalizers.
}

/**
 * Allows modules to alter the query array before it is converted to the
 * backend's native query API and executed.
 */
function hook_luceneapi_query_alter(LuceneapiQuery &$query) {

}

/**
 * @} End of "addtogroup hooks".
 */
