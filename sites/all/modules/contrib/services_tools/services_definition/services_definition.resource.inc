<?php

function services_definition_index() {
  module_load_include('resource_build.inc', 'services');
  // Call _services_build_resources() directly instead of
  // services_get_resources to bypass caching.
  $resources = _services_build_resources();
  $endpoint = services_endpoint_load(services_get_server_info('endpoint', ''));
  return $endpoint;
}