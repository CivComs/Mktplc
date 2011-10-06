<?php

/**
 * @file
 * Contains the default display plugin.
 */

/**
 * A plugin to handle defaults on a view.
 *
 * @ingroup views_display_plugins
 */
class references_dialog_plugin_display extends references_plugin_display {
  function option_definition() {
    $options = parent::option_definition();

    // Allow the use of any style plugin.
    unset($options['style_plugin']['default']);
    $options['defaults']['default']['style_plugin'] = TRUE;
    $options['defaults']['default']['style_options'] = FALSE;
    $options['row_plugin']['default'] = 'fields';
    $options['defaults']['default']['row_plugin'] = FALSE;
    $options['defaults']['default']['row_options'] = FALSE;

    // Set the display title to an empty string (not used in this display type).
    $options['title']['default'] = '';
    $options['defaults']['default']['title'] = FALSE;

    // Set the things we actually add with this plugin.
    $options['field_instances'] = array('default' => array());
    return $options;
  }

  function options_summary(&$categories, &$options) {
    parent::options_summary($categories, $options);
    $categories['references_dialog'] = array(
      'title' => t('References Dialog'),
      'column' => 'second',
      'build' => array(
        '#weight' => -10,
      ),
    );
    $field_instances = $this->get_option('field_instances');
    $options['field_instances'] = array(
      'category' => 'references_dialog',
      'title' => t('Field instances'),
      'value' => views_ui_truncate(implode(',', $field_instances), 24),
    );
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    if ($form_state['section'] == 'field_instances') {
      // Find the entity that matches our base table.
      $entities = entity_get_info();
      foreach ($entities as $entity_type => $entity_info) {
        if ($entity_info['base table'] == $this->view->base_table) {
          break;
        }
      }
      $instances = references_dialog_get_search_view_instances();
      $instance_options = array();

      foreach ($instances as $instance) {
        $instance_options[$instance['entity_type'] . ':' . $instance['field_name'] . ':' . $instance['bundle']] = $instance['field_name'];
      }
      $form['field_instances'] = array(
        '#type' => 'checkboxes',
        '#options' => $instance_options,
        '#default_value' => $this->get_option('field_instances'),
        '#title' => t('Field instances'),
      );
    }
  }

  function options_submit(&$form, &$form_state) {
    parent::options_submit($form, $form_state);
    $this->set_option('field_instances', $this->_sanitize_checkboxes($form_state['values']['field_instances']));
  }

  function _sanitize_checkboxes($boxes) {
    $sanitized = array();
    foreach ($boxes as $key => $box) {
      if ($box) {
        $sanitized[] = $box;
      }
    }
    return $sanitized;
  }

  function _set_access_arguments(&$items) {
    $access_plugin = $this->get_plugin('access');
    if (!isset($access_plugin)) {
      $access_plugin = views_get_plugin('access', 'none');
    }

    // Get access callback might return an array of the callback + the dynamic arguments.
    $access_plugin_callback = $access_plugin->get_access_callback();

    if (is_array($access_plugin_callback)) {
      $access_arguments = array();

      // Find the plugin arguments.
      $access_plugin_method = array_shift($access_plugin_callback);
      $access_plugin_arguments = array_shift($access_plugin_callback);
      if (!is_array($access_plugin_arguments)) {
        $access_plugin_arguments = array();
      }

      $access_arguments[0] = array($access_plugin_method, &$access_plugin_arguments);

      // Move the plugin arguments to the access arguments array.
      $i = 1;
      foreach ($access_plugin_arguments as $key => $value) {
        if (is_int($value)) {
          $access_arguments[$i] = $value;
          $access_plugin_arguments[$key] = $i;
          $i++;
        }
      }
    }
    else {
      $access_arguments = array($access_plugin_callback);
    }
    foreach ($items as &$item) {
      $item['access arguments'] = $access_arguments;
    }
  }

  function execute_hook_menu() {
    $items = array();
    $instances = $this->get_option('field_instances');
    $view_name = $this->view->name;
    $display_name = $this->display->id;
    foreach ($instances as $instance) {
      $items['references-dialog/search/' . $view_name . '/' . $display_name . '/' . $instance] = array(
        'type' => MENU_CALLBACK,
        'page callback' => 'references_dialog_search_view',
        'page arguments' => array($view_name, $display_name, $instance),
        'access callback' => 'views_access',
      );
    }
    $this->_set_access_arguments($items);
    return $items;
  }

  function uses_exposed() { return TRUE; }

  /**
   * Override references_plugin_display, and
   * allow for other style types.
   */
  function get_style_type() { return 'normal'; }

  function get_path() {
    // If we have information about the instance, then use it to build the proper
    // path.
    if (isset($this->view->references_dialog['instance'])) {
      $instance = &$this->view->references_dialog['instance'];
      $instance_info = implode(':', array($instance['entity_type'], $instance['field_name'], $instance['bundle']));
      $view_name = $this->view->name;
      $display_name = $this->display->id;
      return 'references-dialog/search/' . $view_name . '/' . $display_name . '/' . $instance_info;
    }
    else {
      return parent::get_path();
    }
  }

  function execute() {
    // Let the world know that this is the page view we're using.
    views_set_page_view($this->view);
    // Prior to this being called, the $view should already be set to this
    // display, and arguments should be set on the view.
    $this->view->build();
    if (!empty($this->view->build_info['fail'])) {
      return drupal_not_found();
    }

    $this->view->get_breadcrumb(TRUE);

    // And the title, which is much easier.
    drupal_set_title(filter_xss_admin($this->view->get_title()), PASS_THROUGH);
    $content = $this->view->render();
    // Let's add the data necessary to javascript, so that we can
    // act upon it there.
    $js_result = array();
    foreach ($this->view->result as $result) {
      $js_result[] = array('entity_id' => $result->{$this->view->base_field}, 'title' => $result->node_title);
    }
    drupal_add_js(drupal_get_path('module', 'references_dialog') . '/js/search-reference.js');
    drupal_add_js(array('ReferencesDialog' => array('entities' => $js_result)), 'setting');

    return $content;
  }

  function query() {
    // At this point we need to see if our widget needs to inject something
    // into the query in order to filter out unwanted data.
    if (isset($this->view->references_dialog['instance'])) {
      $widget_type = $this->view->references_dialog['instance']['widget']['type'];
      $dialog_widget = references_dialog_widget_load($widget_type);
      if (isset($dialog_widget['views_query']) && function_exists($dialog_widget['views_query'])) {
        $dialog_widget['views_query']($this, $this->view, $this->view->references_dialog['instance'], $this->view->references_dialog['field']);
      }
    }
  }

  function render() {
    return theme($this->theme_functions(), array('view' => $this->view));
  }
}