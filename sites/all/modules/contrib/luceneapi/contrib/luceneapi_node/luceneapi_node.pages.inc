<?php

/**
 * @file
 */

/**
 *
 */
function luceneapi_node_index_page($node) {
  $build = array();

  $header = array(
    'index' => t('Index'),
    'status' => t('Status'),
  );

  $rows = array(
    array(
      'index' => t('Node'),
      'status' => t('In index'),
    ),
    array(
      'index' => t('Node2'),
      'status' => t('Not in index'),
    ),
  );

  $build['table'] = array(
    '#theme' => 'table',
    '#header' => $header,
    '#rows' => $rows,
    '#empty' => t('This node is not in any search indexes.'),
  );

  return $build;
}
