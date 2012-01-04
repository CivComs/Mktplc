<?php
/**
 * @file
 * Callbacks for services module resource hooks.
 */

/**
 * Callback for retrieving views resources.
 *
 * @param $view_name
 *   String. The views name.
 * @param $display_id
 *   String (optional). The views display name.
 * @param $offset
 *   Integer (optional). An offset integer for paging.
 * @param $limit
 *   Integer (optional). A limit integer for paging.
 * @param $args
 *   Array (optional). A list of arguments to pass to the view.
 * @param $return_type
 *   String (optional). Whether to return the raw data results (FALSE), the entire views object ('view') or themed results ('theme').
 * @param $args
 *   Array (optional). A list of exposed filters to pass to the view.
 *
 * @return
 *  Array. The views return.
 */
function services_views_retrieve($view_name, $display_id = 'default', $args = array(), $offset = 0, $limit = 10, $return_type = FALSE, $filters = array()) {
  $result = array();
  $view = views_get_view($view_name);

  // Put all arguments and filters and then execute.
  $view->set_arguments($args, FALSE);
  $view->set_exposed_input($filters);
  $view->set_offset($offset);

  // Support for Views 2
  if (method_exists($view, 'set_use_pager')) {
    // If offset is set we can't have a user pager.
    if (empty($offset)) {
      $view->set_use_pager(TRUE);
      $view->set_items_per_page($limit);
    }
    else {
      // Disable the user pager.
      $view->set_use_pager(FALSE);
    }
  }
  else {
    $view->set_items_per_page($limit);
  }
  if (empty($return_type)) {
    $view->set_display($display_id);
    $view->execute();
    $result = $view->result;

    $row_plugin = $view->display_handler->get_option('row_plugin');
    // If row plugin is node, then we should load each node
    if ($row_plugin == 'node') {
      $nodes = array();
      foreach ($view->result as $row) {
        $nodes[] = services_node_load(node_load($row->nid));
      }
      $result = $nodes;
    }
  }
  elseif ($return_type == 'view') {
    $view->set_display($display_id);
    $view->execute();
    return $view;
  }
  else {
    // We want to keep the result an array.
    $result[] = $view->preview($display_id);
  }
  return $result;
}
