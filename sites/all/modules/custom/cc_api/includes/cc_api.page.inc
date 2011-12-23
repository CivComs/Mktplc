<?php
/**
 * @file
 * File containing code for the public API page.
 */
 
/**
 * Main callback for API documentation page.
 */
function cc_api_documentation_page() {
  $api = array();
  
  // Let's get the API data.  We will assume that we only
  // want services resources that are in the format:
  // "mktplc_api_"
  $prefix = 'mktplc_api_';
  
  module_load_include('resource_build.inc', 'services');
  // Call _services_build_resources() directly instead of
  // services_get_resources to bypass caching.
  $resources = _services_build_resources();
  
  // Go through available endpoints.
  $endpoints = services_endpoint_load_all();
  foreach ($endpoints as $ep_id => $ep) {
    // Check prefix first
    if (strpos($ep_id, $prefix) !== 0) {
      continue;
    }
    
    // Start the data
    $api[$ep_id] = $ep;
    
    // Go through resources and add details
    $config_types = array('actions', 'relationships', 'operations');
    foreach ($ep->resources as $entity => $config) {
      foreach ($config as $config_type => $config_set) {
        if (is_array($config_set) && in_array($config_type, $config_types)) {
          foreach ($config_set as $k => $v) {
          
            // These don't match up one to one, so there
            // is some custom logic.
            if ($config_type == 'operations') {
              $api[$ep_id]->resources[$entity][$config_type][$k] += 
                $resources[$entity][$k];
            }
            else {
              $api[$ep_id]->resources[$entity][$config_type][$k] += 
                $resources[$entity][$config_type][$k];
            }
          }
        }
      }
    }
  }
  
  // Allow for alter
  drupal_alter('cc_api', $api);
  
  // Create output
  return cc_api_display_documentation($api);
}

/**
 * Implements hook_cc_api_alter().
 */
function cc_api_cc_api_alter(&$apis) {
  foreach ($apis as $api_id => $api) {
    // Add title and description
    $apis[$api_id]->title = t('Version 01');
    $apis[$api_id]->description = '<p>' . t('The first version of the Marketplace API is focused on providing basic mechanisms for data input and output.  It may be a bit rough around the edges.') . '</p>';
    $apis[$api_id]->base_url = url($api->path, array('absolute' => TRUE));
    
    // Add formatter meta data
    cc_api_documentation_page_formatters(
      $apis[$api_id]->server_settings['rest_server']['formatters'], 
      $apis[$api_id]->base_url . '/node'
    );
    
    // Add parser meta data
    cc_api_documentation_page_parsers(
      $apis[$api_id]->server_settings['rest_server']['parsers']
    );
    
    // Add resource meta data
    cc_api_documentation_page_resources($apis[$api_id]->resources, $apis[$api_id]->base_url);
  }
  
  $method_map = array(
    'retrieve'         => 'GET',
    'update'           => 'PUT',
    'delete'           => 'DELETE',
    'index'            => 'GET',
    'create'           => 'POST',
    'actions'          => 'POST',
    'targeted actions' => 'POST',
    'relationships'    => 'GET',
  );
}

/**
 * Main display operation for documentation
 */
function cc_api_display_documentation($apis) {
  $output = '';
  
  // There could be multiple (versions) apis.
  foreach ($apis as $api_id => $api) {
    dpm($api);
    
    $output .= '
      <h2 class="api-title">' . $api->title . '</h2>
      <div class="api-description">
        ' . $api->description . '
      </div>
      
      <h3>' . t('URLs') . '</h3>
      <div class="api-description-url">
        <p>' . t('This API is a RESTful API, where URLs will be formed like the following:') . '</p>
        <code>' . $api->base_url . '/:entity.:format?:key=:value</code>
        <p>' . t('For instance:') . '</p>
        <code>' . $api->base_url . '/node.json?page=3</code>
      </div>
      
      <h3>' . t('Authentication') . '</h3>
      <div class="api-description-auth">
        <p>' . t('…') . '</p>
      </div>
    ';
    
    // Formatters.  Assuming rest servers.
    // Note that the Server settings need to be saved
    // for these options to be in the endpoint
    // object.
    $output .= '
      <h3>' . t('Output Formatters') . '</h3>
      <div class="api-description-formatters">
        <p>' . t('The following are the output formatters that are available with the API.') . '</p>
        <ul>
    ';
    foreach ($api->server_settings['rest_server']['formatters'] as $f => $enabled) {
      $output .= '
        <li>
          <strong>' . check_plain($f) . '</strong>: ' . $enabled['description'] . '
          <ul><li>
            ' . t('Example URL') . ': <code>' . $enabled['example_url'] . '</code>
          </li></ul>
        </li>';
    }
    $output .= '
        </ul>
      </div>
    ';
      
    // Parsers.  Assuming Rest server.
    $output .= '
      <h3>' . t('Input Parsers') . '</h3>
      <div class="api-description-parsers">
        <p>' . t('The following are the output formatters that are available with the API.') . '</p>
        <ul>
    ';
    foreach ($api->server_settings['rest_server']['parsers'] as $p => $enabled) {
      $output .= '
        <li>
          <strong>' . check_plain($p) . '</strong>: ' . $enabled['description'] . '
          <ul><li>
            ' . t('Example data') . ': <code><pre class="brush: plain">' . $enabled['example_data'] . '</pre></code>
          </li></ul>
        </li>';
    }
    $output .= '
        </ul>
      </div>
    ';
      
    $output .= '
      <h3>' . t('Limitations') . '</h3>
      <div class="api-description-limitation">
        <p>' . t('…') . '</p>
      </div>
    ';
      
    $output .= '
      <h3>' . t('Resources') . '</h3>
      <div class="api-description-resources">
    ';
    foreach ($api->resources as $r => $resource) {
      $output .= '
        <h4>' . $resource['name'] . '</h4>
        <p>' . $resource['description'] . '</p>
      ';
      
      // Resource object types
      foreach ($resource as $t => $type) {
        if (!in_array($t, array('name', 'description'))) {
          $output .= '
            <h5>' . $type['name'] . '</h5>
            <p>' . $type['description'] . '</p>
          ';
          
          // Type actions
          foreach ($type as $a => $action) {
            if (!in_array($a, array('name', 'description'))) {
              $output .= '
                <h6>' . $action['name'] . '</h6>
                <p>' . $action['description'] . '</p>
              ';
              if (!empty($action['examples'])) {
                $output .= '<ul>';
                foreach ($action['examples'] as $e => $example) {
                  $output .= '
                    <li>' . $example['title'] . ':
                    <code><pre class="' . $example['class'] . '">
                      ' . $example['data'] . '
                    </pre></code>
                    </li>
                  ';
                }
                $output .= '</ul>';
              }
            }
          }
        }
      }      
    }
    $output .= '
      </div>
    ';
  }
  
  return $output;
}

/**
 * Add meta data to formatters.
 */
function cc_api_documentation_page_formatters(&$formatters, $base_url) {
  $formatters_meta = array(
    'bencode' => array(
      'description' => t('<a href="@url">Bencode</a> is used by BitTorrent.', array ('@url' => 'http://en.wikipedia.org/wiki/Bencode')),
      'example_url' => $base_url . '.bencode',
    ),
    'json' => array(
      'description' => t('<a href="@url">JSON</a> is a popular format used to describe Javascript objects.', array ('@url' => 'http://en.wikipedia.org/wiki/Json')),
      'example_url' => $base_url . '.json',
    ),
    'php' => array(
      'description' => t('Output data as a <a href="@url">serialized PHP</a> object.', array ('@url' => 'http://php.net/manual/en/function.serialize.php')),
      'example_url' => $base_url . '.php',
    ),
    'rss' => array(
      'description' => t('<a href="@url">RSS</a> is a popular format for syndicating content like blogs.   (seems to be some errors with this format)', array ('@url' => 'http://en.wikipedia.org/wiki/Rss')),
      'example_url' => $base_url . '.rss',
    ),
    'xml' => array(
      'description' => t('<a href="@url">XML</a> is a markup language similar to HTML.', array ('@url' => 'http://en.wikipedia.org/wiki/Xml')),
      'example_url' => $base_url . '.rss',
    ),
    'yaml' => array(
      'description' => t('<a href="@url">YAML</a> is a markup language meant for simplicity.  (seems to be always empty)', array ('@url' => 'http://en.wikipedia.org/wiki/Yaml')),
      'example_url' => $base_url . '.yaml',
    ),
    'jsonp' => array(
      'description' => t('<a href="@url">JSONP</a> is similar to JSON but is meant to get around Javascript cross-domain limitations.  This format takes an extra argument in the query string, <code>callback</code>, which is a Javascript callback function on your client-side code.  (seems to be responding with empty set)', array ('@url' => 'http://en.wikipedia.org/wiki/JSONP')),
      'example_url' => $base_url . '.jsonp?callback=ExampleCallback',
    ),
  );
  
  // Merge
  foreach ($formatters as $f => $format) {
    if (!is_array($formatters[$f])) {
      $formatters[$f] = array('enabled' => $formatters[$f]);
    }
    $formatters[$f] += $formatters_meta[$f];
  }
}

/**
 * Add meta data to parsers.
 */
function cc_api_documentation_page_parsers(&$parsers) {
  $parsers_meta = array(
    'application/json' => array(
      'description' => t('<a href="@url">JSON</a> is a popular format used to describe Javascript objects.', array ('@url' => 'http://en.wikipedia.org/wiki/Bencode')),
      'example_data' => '
{
  key1: "value1", 
  key2: "value2"
}
      ',
    ),
    'application/vnd.php.serialized' => array(
      'description' => t('Input data as a <a href="@url">serialized PHP</a> object.', array ('@url' => 'http://php.net/manual/en/function.serialize.php')),
      'example_data' => 'a:2:{s:4:"key1";s:6:"value1";s:4:"key2";s:6:"value2";}',
    ),
    'application/x-yaml' => array(
      'description' => t('<a href="@url">YAML</a> is a markup language meant for simplicity.', array ('@url' => 'http://en.wikipedia.org/wiki/Yaml')),
      'example_data' => '
key1: value1
key2: value2
      ',
    ),
    'multipart/form-data' => array(
      'description' => t('<a href="@url">form-data</a> is an HTTP specification for sending data.', array ('@url' => 'http://www.w3.org/TR/html4/interact/forms.html#h-17.13.4.2')),
      'example_data' => '
Content-Type: multipart/form-data; boundary=AaB03x

--AaB03x
Content-Disposition: form-data; name="submit-name"

Larry
--AaB03x
Content-Disposition: form-data; name="files"; filename="file1.txt"
Content-Type: text/plain

... contents of file1.txt ...
--AaB03x--
      ',
    ),
    'application/x-www-form-urlencoded' => array(
      'description' => t('<a href="@url">x-www-form-urlencoded</a> is an HTTP specification for sending data with simple URL encoding.', array ('@url' => 'http://www.w3.org/TR/html4/interact/forms.html#h-17.13.4.1')),
      'example_data' => 'key1=value1&key2=value2',
    ),
  );
  
  // Merge
  foreach ($parsers as $p => $parser) {
    if (!is_array($parsers[$p])) {
      $parsers[$p] = array('enabled' => $parsers[$p]);
    }
    $parsers[$p] += $parsers_meta[$p];
  }
}

/**
 * Add meta data to resources.
 */
function cc_api_documentation_page_resources(&$resources, $url) {
  $resources_meta = array(
    'comment' => array(
      'name' => t('Comments'),
      'description' => t('Comments are user supplied data that are attached to content, like nodes.'),
      'operations' => array(
        'name' => t('Comment Operations'),
        'description' => t('Basic operations for the Comment objects.'),
      ),
      'actions' => array(
        'name' => t('Comment Actions'),
        'description' => t('Actions for the Comment objects.'),
      ),
    ),
    'node' => array(
      'name' => t('Nodes (Content)'),
      'description' => t('Nodes are the basic content objects in the system.'),
      'operations' => array(
        'name' => t('Node Operations'),
        'description' => t('Basic operations for the Node objects.'),
        'retrieve' => array(
          'name' => t('Retrieve Nodes'),
          'description' => t('Use this endpoint to retrieve a specific node.'),
          'examples' => array(
            'curl_retrieve' => array(
              'title' => t('CURL'),
              'class' => 'brush:plain',
              'data' => 'curl -data ' . $url . '/node/retrieve?nid',
            ),
          ),
        ),
      ),
      'relationships' => array(
        'name' => t('Node Relationships'),
        'description' => t('Retrieve objects that are related to nodes.'),
      ),
    ),
    'taxonomy_term' => array(
      'name' => t('Taxonomy Terms'),
      'description' => t('Taxonomies are ways of grouping objects, like nodes, and the terms are the specific category terms.'),
      'operations' => array(
        'name' => t('Term Operations'),
        'description' => t('Basic operations for Taxonomy Term objects.'),
      ),
      'actions' => array(
        'name' => t('Term Actions'),
        'description' => t('Actions for the Term objects.'),
      ),
    ),
  );
  
  // Merge
  foreach ($resources as $r => $resource) {
    if (!is_array($resources[$r])) {
      $resources[$r] = array('enabled' => $resources[$r]);
    }
    // array_merge_recursive kind of sucks, so be careful.
    $resources[$r] = array_merge_recursive($resources[$r], $resources_meta[$r]);
  }
}