<?php
/**
 * @file
 * cc_application.pages_default.inc
 */

/**
 * Implementation of hook_default_page_manager_pages().
 */
function cc_application_default_page_manager_pages() {
  $page = new stdClass;
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'apps';
  $page->task = 'page';
  $page->admin_title = 'Apps';
  $page->admin_description = 'Apps landing page';
  $page->path = 'apps';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass;
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_apps_http_response';
  $handler->task = 'page';
  $handler->subtask = 'apps';
  $handler->handler = 'http_response';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'HTTP response code',
    'contexts' => array(),
    'relationships' => array(),
    'code' => '404',
    'destination' => '',
  );
  $page->default_handlers[$handler->name] = $handler;
  $pages['apps'] = $page;

 return $pages;

}
