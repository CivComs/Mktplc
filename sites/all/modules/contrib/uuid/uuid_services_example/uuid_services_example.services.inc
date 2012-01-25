<?php
/**
 * @file
 * uuid_services_example.services.inc
 */

/**
 * Implementation of hook_default_services_endpoint().
 */
function uuid_services_example_default_services_endpoint() {
  $export = array();

  $endpoint = new stdClass;
  $endpoint->disabled = FALSE; /* Edit this to true to make a default endpoint disabled initially */
  $endpoint->api_version = 3;
  $endpoint->name = 'uuid_services_example';
  $endpoint->title = 'UUID Services Example';
  $endpoint->server = 'rest_server';
  $endpoint->path = 'api';
  $endpoint->authentication = array();
  $endpoint->resources = array(
    'uuid_entity' => array(
      'operations' => array(
        'update' => array(
          'enabled' => 1,
        ),
      ),
    ),
  );
  $endpoint->debug = 0;
  $export['uuid_services_example'] = $endpoint;

  return $export;
}
