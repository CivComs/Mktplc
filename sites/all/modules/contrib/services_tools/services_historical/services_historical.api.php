<?php
/**
 * @file
 * Document services_historical hooks.
 *
 * @author Jimmy Berry ("boombatower", http://drupal.org/user/214218)
 */

/**
 * Define historical services provided by the module.
 *
 * @return
 *   An associative array whose keys will be used for reference and whose
 *   values contain the historical descriptions. Each historical description is
 *   itself an associative array, with the following key-value pairs:
 *   - 'endpoint': (required) The name of the endpoint to which the historical
 *   endpoints are related.
 *   - 'version': (required) The current version of the API (ex. 1.7).
 *   - 'suffix': (optional) A numerical suffix to append to
 *   hook_services_historical_endpoint() and to each
 *   hook_services_historical_update_N() before the N. The suffix will not
 *   effect the version number used for the update hooks (ie. N will include
 *   the suffix). The suffix is useful if an API with two or more 'levels' has
 *   more then one major version and those are defined separately. For example,
 *   an API with the following versions: 1.0, 1.1, 1.2, 2.0, 2.1 could use a
 *   suffix of 1 and 2 to define each historical set separately, but the
 *   'version' in each should be the same. By defining major API versions
 *   separately they can be placed in separate modules and/or have different
 *   base endpoints. Defaults to blank.
 *   - 'levels': (optional) The number of levels in the API version, must be
 *   >= 1. For example, 2 levels would mean version numbers like: 1.0, 1.1.
 *   Defaults to 2.
 *   - 'format': (optional) The version number format to use in labels and the
 *   URL, see sprintf() for documentation. The format is generated if not
 *   defined based on the number of levels. Defaults to %d.%d.
 *   - 'module': (optional) The module providing the hooks. Defaults to the
 *   module for which this hook is written.
 */
function hook_services_historical_info() {
  // Simple example where the entire historical API is defined once.
  return array(
    'my_historical_api' => array(
      'endpoint' => 'my_api',
      'version' => '1.7',
    ),
  );

  // Complex example where the historical API is split for each major API
  // version.
  return array(
    'my_historical_api_1' => array(
      'endpoint' => 'my_api',
      'version' => '2.0',
      'suffix' => 1,
    ),
    'my_historical_api_2' => array(
      'endpoint' => 'my_api',
      'version' => '2.0',
      'suffix' => 2,
    ),
  );
}

/**
 * Define the base endpoint used to generate versioned endpoints.
 *
 * @return
 *   A single endpoint object.
 * @see hook_default_services_endpoint()
 */
function hook_services_historical_endpoint() {
  $endpoint = new stdClass;
  $endpoint->disabled = FALSE; /* Edit this to true to make a default endpoint disabled initially */
  $endpoint->api_version = 3;
  $endpoint->name = 'my_api';
  $endpoint->title = 'My API';
  $endpoint->server = 'rest_server';
  $endpoint->path = 'api';
  $endpoint->authentication = array(
    'services_sessauth' => array(),
  );
  $endpoint->resources = array(
    // Can include either core services resources or other module resources
    // that are used in the endpoint, but not changed along with the API and
    // they will be left alone. Any resources that are defined in the update_N
    // hooks will override resources defined here.
  );
  $endpoint->debug = 0;
  $endpoint->status = 1;
  return $endpoint;
}

/**
 * Update the previous resources for the current version.
 *
 * The N should be replaced by the version number this update hook will
 * generate. The version number should be formatted with underscores between
 * each level.For example, a two level version number of 1.1 would be formatted
 * as 1_1.
 *
 * Alternatively you can copy and paste the entire resources array for each
 * version in the corresponding update hook.
 *
 * @param $resources
 *   The resources from the previous update hook which should be altered to
 *   suite the current version of the API. If this is the first update hook,
 *   usually something like 1.0, then $resources will be a blank array and
 *   should set to the original resources provided in the 1.0 version of the
 *   API. Each subsequent update hook will be give the resources provided by
 *   the previous version.
 * @param $version
 *   The formated version string.
 */
function hook_services_historical_update_N(&$resources, $version) {
  // The original update hook (full 1.0 resources definition).
  $resources = array(
    'thing' => array(
      'actions' => array(
        'talk' => array(
          // ...
          'args' => array(
            array(
              'name' => 'type',
              'type' => 'string',
              'description' => 'The type of thing.',
              'source' => 'data',
              'optional' => TRUE,
            ),
          ),
        ),
      ),
    ),
  );

  // The next update hook.
  $resources['thing']['actions']['talk']['args'][0]['optional'] = FALSE;

  // Another update hook down the road.
  unset($resources['thing']);
}
