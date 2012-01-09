<?php
/**
 * @file
 * File containing code for the public API page.
 *
 * TODO: It would make sense to utilize
 * render arrays for this and just make a huge
 * renderable array.
 */
 
/**
 * Main callback for API documentation page.
 */
function cc_api_documentation_page() {
  // Let's get the API data.  We will assume that we only
  // want services resources that are in the format:
  // "mktplc_api_"
  $prefix = 'mktplc_api_';
  
  // Let's put this all behind a cache, so check first
  $api = cache_get('cc_api_doc_page');
  if (!$api) {
  
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
    
    // Set the cache
    cache_set('cc_api_doc_page', $api);
  }
  else {
    $api = $api->data;
  }
  
  // Include some CSS and JS
  drupal_add_css(drupal_get_path('module', 'cc_api') . '/cc_api.css');
  drupal_add_js(drupal_get_path('module', 'cc_api') . '/js/jquery.tableofcontents.js');
  drupal_add_js(drupal_get_path('module', 'cc_api') . '/js/cc_api.page.js');
  
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
    
    // Add data model information.
    cc_api_documentation_page_data_model($apis[$api_id]);
    
    // Views data if its enabled
    if (isset($api->resources['views']) && !empty($api->resources['views'])) {
      cc_api_documentation_page_views($apis[$api_id]);
    }
  }
}

/**
 * Main display operation for documentation
 */
function cc_api_display_documentation($apis) {
  $output = '';
  
  // Check for Syntaxhighlighter module
  $class = '';
  if (module_exists('syntaxhighlighter')) {
    $class = 'brush:plain';
  }
  
  // Vertical tabs stuff
  drupal_add_js('misc/vertical-tabs.js');
  drupal_add_css('misc/vertical-tabs.css');
  
  // Put a top level example link
  if ($example = variable_get('cc_api_doc_page_examples_path', 'api/examples')) {
    $output .= '
      <p>' . t('This page is focused on providing a complete technical overview of the API.  For a set of examples, please go to the <a href="@url">example page</a>.', array(
        '@url' => url($example),
      )) . '</p>
    ';
  }

  $output .= '
    <div class="api-container">
  ';
  
  // There could be multiple (versions) apis.
  foreach ($apis as $api_id => $api) {
    
    // Top level title
    $output .= '
      <h2 class="api-title">' . $api->title . '</h2>
      <div class="api-description">
        ' . $api->description . '
      </div>
    ';
    
    // Start vertical tabs
    $output .= '
      <div class="vertical-tabs-panes">
    ';
      
    // URLs
    $output .= cc_api_display_documentation_top_level(
      t('URLs'),
      t('This API is a <a href="@url">RESTful API</a>, where URLs will be formed (most often) like the following:', array('@url' => 'http://en.wikipedia.org/wiki/Representational_state_transfer')),
      'url',
      array(
        1 => array(
          'title' => t('URL formation'),
          'class' => $class,
          'data' => $api->base_url . '/:method.:format?:key=:value',
        ),
        2 => array(
          'title' => t('URL example'),
          'class' => $class,
          'data' => $api->base_url . '/node.json?page=3',
        )
      )
    );
    
    $output .= cc_api_display_documentation_top_level(
      t('Authentication'),
      '<div class="api-description-auth">
        <p>' . t('You will need to authenticate in some way if you want to create, update or delete data in the system.') . '</p>
        <h4>' . t('Session/Cookie Based') . '</h4>
        <p>' . t('Session based authentication is a method in which you post your username and password to an endpoint, and you will be given a <strong>session name</strong> and <strong>session ID</strong> that can be used for requests that require specific authenticated access (such as creating an Organization).  Please see the User Actions below for more in-depth look at the methods.') . '</p>
        <strong>' . t('CURL example') . '</strong>
        <p>' . t('Use the following command to get back the session data.  We use the verbose flag just so that you can see what is going on.') . '</p>
        <code><pre>
          curl -v --data \'{"username":"[[your_username]]","password":"[[your_password]]"}\' --header "Content-Type:application/json" ' . $api->base_url . '/user/login
        </pre></code>
        <p>' . t('You should recieve an object back that is similar to the following:') . '</p>
        <code><pre>
          sessid: XXXXXXXXXXXXXXX
          session_name: YYYYYYYYYYYYY
          user: |
        </pre></code>
        <p>' . t('These can then be used in a call to create a node within the cookie.') . '</p>
        <code><pre>
          curl -v --data \'{"title":"New Organization","type":"organization"}\' --header "Content-Type:application/json" --header "Cookie: [[session_name]]=[[Session_id]]" ' . $api->base_url . '/node
        </pre></code>
      </div>',
      'authentication'
    );
    
    // Formatters.  Assuming rest servers.
    // Note that the Server settings need to be saved
    // for these options to be in the endpoint
    // object.
    $output .= cc_api_display_documentation_top_level(
      t('Output Formatters'),
      t('The following are the output formatters that are available with the API.'),
      'output-formatters',
      array(),
      array(
        'formatters' => cc_api_display_documentation_formatters($api->server_settings['rest_server']['formatters']),
      )
    );
    
    // Parsers.  Assuming Rest server.
    $output .= cc_api_display_documentation_top_level(
      t('Input Parsers'),
      t('The following are the output formatters that are available with the API.'),
      'input-parsers',
      array(),
      array(
        'parsers' => cc_api_display_documentation_parsers($api->server_settings['rest_server']['parsers']),
      )
    );
    
    // Parsers.  Assuming Rest server.
    $output .= cc_api_display_documentation_top_level(
      t('Limitations'),
      t('coming soon.'),
      'limitations'
    );
    
    // Data Model top level
    $output .= cc_api_display_documentation_top_level(
      t('Data Model'),
      t('Without knowing much about the data model, working with the API will be difficult.  The following is a list of entities and fields available on the site.  For reference, checkout what <a href="@field_url">Fields</a> and <a href="@entity_url">Entities</a> are in Drupal.  Note that often the name and description of the data model fields and entities are taken from their user-focused counter parts and may not fully be appropriate for this context.', array(
        '@entity_url' => 'http://drupal.org/node/1261744',
        '@field_url' => 'http://drupal.org/node/443536',
      )),
      'data-model'
    );
    
    // Go through each data model type
    foreach ($api->data_model as $mid => $model) {
      $output .= cc_api_display_documentation_top_level(
        t('Data Model: %type', array('%type' => $model['name'])),
        filter_xss($model['description']),
        'data-model-' . $mid,
        array(),
        array(
          'data_model' => cc_api_display_documentation_bundles($model),
        )
      );
    }
    
    // Stop vertical tabs
    $output .= '
      <div class="vertical-tabs-panes">
    ';
    
    if (isset($api->views_searching) && is_array($api->views_searching)
       && count($api->views_searching) > 0) { 
      $output .= '
        <h3>' . t('Searching') . '</h3>
        <div class="api-description-searching">
          <p>' . t('Utilizing the Views methods as described below, you can find specific content.') . '</p>
          <p>' . t('Please see the <a href="#views">Views</a> section to get a general description of using the Searching API.') . '</p>
        </div>
      ';
      
      // Go through Views
      foreach ($api->views_searching as $v => $view) {
        if (!in_array($v, array('name', 'description'))) {
          $title = !empty($view['name']) ? $view['name'] : t('-no title-');
          $output .= '
            <h4>' . $title . '</h4>
            <p>' . $view['description'] . '</p>
            <ul>
              <li><strong>' . t('Identifier') . '</strong>: ' . $view['id'] . '</li>
              <li><strong>' . t('Base table') . '</strong>: ' . $view['base_table'] . '</li>
            </ul>
          ';
          
          // Displays
          foreach ($view['displays'] as $d => $display) {
            $output .= '
              <h5>' . $display['name'] . '</h5>
              <p>' . $display['description'] . '</p>
            ';
            
            // Examples
            if (isset($display['examples'])) {
              $output .= '
                <strong>' . t('Examples') . '</strong>
                <ul>
              ';
              foreach ($display['examples'] as $example) {
                $output .= '
                  <li>' . $example['title'] . ':
                  <code><pre class="' . $example['class'] . '">
                    ' . $example['data'] . '
                  </pre></code>
                  </li>
                ';
              }
              $output .= '
                </ul>
              ';
            }
            
            // Filters
            if (isset($display['filters'])) {
              $output .= '
                <strong>' . t('Filters') . '</strong>
              ';
            
              $rows = array();
              $headers = array(t('Name'), t('Identifier'), t('Required'));
              foreach ($display['filters'] as $filter) {
                $rows[] = array(
                  $filter['name'], 
                  $filter['id'], 
                  (empty($filter['required'])) ? t('no') : t('yes'),
                );
              }
              $output .= theme('table', array(
                'header' => $headers,
                'rows' => $rows,
              ));
            }
          }
        }
      }
    }
      
    $output .= '
      <h3>' . t('Resources/Methods') . '</h3>
      <div class="api-description-resources">
        <p>' . t('Resource, or methods, are the specific RESTful API calls for manipulating data.') . '</p>
      </div>
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
          
          // Methods
          foreach ($type as $a => $action) {
            if (!in_array($a, array('name', 'description'))) {
              $output .= '
                <h6>' . $action['name'] . '</h6>
                <p>' . $action['description'] . '</p>
                <p><strong>Method:</strong> ' . $action['method'] . '</p>
              ';
              
              // Arguments
              if (!empty($action['args'])) {
                $output .= '<strong>' . t('Arguments') . '</strong>';
                $rows = array();
                $headers = array(t('Key'), t('Type'), t('Description'), t('Required'), t('Source'));
                foreach ($action['args'] as $arg) {
                  $rows[] = array(
                    $arg['name'], 
                    $arg['type'], 
                    (isset($arg['description'])) ? $arg['description'] : '', 
                    (!empty($arg['optional'])) ? t('no') : t('yes'),
                    (is_array($arg['source'])) ? implode(', ', array_flip($arg['source'])) : 
                      t('post body'),
                  );
                }
                $output .= theme('table', array(
                  'header' => $headers,
                  'rows' => $rows,
                ));
              }
              
              // Examples
              if (!empty($action['examples'])) {
                $output .= '<strong>' . t('Examples') . '</strong>';
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
  
  $output .= '</div>';
  return $output;
}

/**
 * Sub theme function for top level section
 */
function cc_api_display_documentation_top_level($title, $description, $class, $examples = array(), $children = array()) {
  $examples_output = '';
  if ($examples) {
    $examples_output .= '
      <div class="' . $class . '-examples">
        ' . cc_api_display_documentation_examples($examples) . '
      </div>
    ';
  }
  
  // Children
  $children_output = '';
  if ($children) {
    $children_output .= '<div class="' . $class . '-children">';
    foreach ($children as $c => $child) {
      $children_output .= $child;
    }
    $children_output .= '</div>';
  }
  
  $output = '
    <fieldset>
      <legend>' . $title . '</legend>
      <div class="' . $class . '-container">
        <h3 id="id-' . $class . '">' . $title . '</h3>
        <div class="' . $class . '-description">
          <p>' . $description . '</p>
        </div>
        ' . $children_output . '
        ' . $examples_output . '
      </div>
    </fieldset>
  ';
      
  return $output;
}

/**
 * Render examples
 */
function cc_api_display_documentation_examples($examples = array()) {
  $output = '<strong>' . t('Examples') . '</strong>';
  $output .= '<ul>';
  foreach ($examples as $e => $example) {
    $output .= '
      <li>' . $example['title'] . ':
      <code><pre class="' . $example['class'] . '">
        ' . $example['data'] . '
      </pre></code>
      </li>
    ';
  }
  $output .= '</ul>';
  
  return $output;
}

/**
 * Formatters output
 */
function cc_api_display_documentation_formatters($formatters = array()) {    
  $output .= '<dl>';
  foreach ($formatters as $f => $enabled) {
    $output .= '
      <dt>' . check_plain($f) . '</dt>
      <dd><p>' . $enabled['description'] . '</p>
        ' . t('Example URL') . ': 
        <code><pre class="' . $class . '">
          ' . $enabled['example_url'] . '
        </pre></code>
      </dd>';
  }
  $output .= '</dl>';
  
  return $output;
}

/**
 * Parsers output
 */
function cc_api_display_documentation_parsers($parsers = array()) {    
  $output .= '<dl>';
  foreach ($parsers as $p => $enabled) {
    $output .= '
      <dt>' . check_plain($p) . '</dt>
      <dd><p>' . $enabled['description'] . '</p>
        ' . t('Example data') . ': 
        <code><pre class="' . $class . '">
          ' . $enabled['example_data'] . '
        </pre></code>
      </dd>';
  }
  $output .= '</dl>';
  
  return $output;
}

/**
 * Data model
 */
function cc_api_display_documentation_bundles($bundles = array()) {
  $output = '';
    
  // Model types, aka entity bundles
  foreach ($bundles as $b => $bundle) {
    if (!in_array($b, array('name', 'description'))) {
      $output .= '
        <h4>' . check_plain($bundle['name']) . '</h4>
        <p>' . filter_xss($bundle['description']) . '</p>
      ';
          
      // Custom fields
      if (!empty($bundle['fields'])) {
        $output .= '<strong>' . t('Custom Fields') . '</strong>';
        $rows = array();
        $headers = array(t('id'), t('Label'), t('Description'), t('Type'));
        foreach ($bundle['fields'] as $f) {
          $rows[] = array(
            $f['id'], 
            filter_xss($f['label']), 
            filter_xss($f['description']),
            $f['type'],
          );
        }
        $output .= theme('table', array(
          'header' => $headers,
          'rows' => $rows,
        ));
      }
    }
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
      'example_url' => $base_url . '.xml',
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
  $method_map = array(
    'retrieve' => 'GET',
    'update' => 'PUT',
    'delete' => 'DELETE',
    'index' => 'GET',
    'create' => 'POST',
    'actions' => 'POST',
    'targeted actions' => 'POST',
    'relationships' => 'GET',
  );
  
  $resources_meta = array(
    // Comments
    'comment' => array(
      'name' => t('Comments'),
      'description' => t('Comments are user supplied data that are attached to content, like nodes.'),
      'operations' => array(
        'name' => t('Comment Operations'),
        'description' => t('Basic operations for the Comment objects.'),
        'create' => array(
          'name' => t('Create Comments'),
          'description' => t('Use this method to create a specific comment.'),
          'examples' => array(
            'curl_retrieve' => array(
              'title' => t('CURL'),
              'class' => 'brush:plain',
              'data' => 'curl -data ' . $url . '/comment/ ????',
            ),
          ),
          'method' => $method_map['create'],
        ),
        'retrieve' => array(
          'name' => t('Retrieve Comments'),
          'description' => t('Use this method to retrieve a specific comment.'),
          'examples' => array(
            'curl_retrieve' => array(
              'title' => t('CURL'),
              'class' => 'brush:plain',
              'data' => 'curl -data ' . $url . '/comment/:cid',
            ),
          ),
          'method' => $method_map['retrieve'],
        ),
        'update' => array(
          'name' => t('Update Comment'),
          'description' => t('Use this method to update a specific comment.'),
          'examples' => array(
            'curl_retrieve' => array(
              'title' => t('CURL'),
              'class' => 'brush:plain',
              'data' => 'curl -data ' . $url . '/comment/ ?????',
            ),
          ),
          'method' => $method_map['update'],
        ),
        'delete' => array(
          'name' => t('Delete Comment'),
          'description' => t('Use this method to delete a specific comment.'),
          'examples' => array(
            'curl_retrieve' => array(
              'title' => t('CURL'),
              'class' => 'brush:plain',
              'data' => 'curl -data ' . $url . '/comment/ ?????',
            ),
          ),
          'method' => $method_map['delete'],
        ),
        'index' => array(
          'name' => t('Search Comment'),
          'description' => t('Use this method to search comments.'),
          'examples' => array(
            'curl_retrieve' => array(
              'title' => t('CURL'),
              'class' => 'brush:plain',
              'data' => 'curl -data ' . $url . '/comment ?????',
            ),
          ),
          'method' => $method_map['index'],
        ),
      ),
      'actions' => array(
        'name' => t('Comment Actions'),
        'description' => t('Actions for the Comment objects.'),
        'countAll' => array(
          'name' => t('Count Comments per Node'),
          'description' => t('Returns the number of comments are on a single node.'),
          'examples' => array(
            'curl_retrieve' => array(
              'title' => t('CURL'),
              'class' => 'brush:plain',
              'data' => 'curl -data ' . $url . '/comment ?????',
            ),
          ),
          'method' => $method_map['index'],
        ),
        'countNew' => array(
          'name' => t('Count New Comments per Node'),
          'description' => t('Returns the number of new comments are on a single node, given a timestamp.'),
          'examples' => array(
            'curl_retrieve' => array(
              'title' => t('CURL'),
              'class' => 'brush:plain',
              'data' => 'curl -data ' . $url . '/comment ?????',
            ),
          ),
          'method' => $method_map['index'],
        ),
      ),
    ),
    // Nodes
    'node' => array(
      'name' => t('Nodes (Content)'),
      'description' => t('Nodes are the basic content objects in the system.'),
      'operations' => array(
        'name' => t('Node Operations'),
        'description' => t('Basic operations for the Node objects.'),
        'create' => array(
          'name' => t('Create Node'),
          'description' => t('Use this method to create a specific node.'),
          'examples' => array(
            'curl_retrieve' => array(
              'title' => t('CURL'),
              'class' => 'brush:plain',
              'data' => 'curl -data ' . $url . '/node/ ????',
            ),
          ),
          'method' => $method_map['create'],
        ),
        'retrieve' => array(
          'name' => t('Retrieve Nodes'),
          'description' => t('Use this endpoint to retrieve a specific node.'),
          'examples' => array(
            'curl_retrieve' => array(
              'title' => t('CURL'),
              'class' => 'brush:plain',
              'data' => 'curl -data ' . $url . '/node/:nid',
            ),
          ),
          'method' => $method_map['retrieve'],
        ),
        'update' => array(
          'name' => t('Update Node'),
          'description' => t('Use this method to update a specific node.'),
          'examples' => array(
            'curl_retrieve' => array(
              'title' => t('CURL'),
              'class' => 'brush:plain',
              'data' => 'curl -data ' . $url . '/node/ ?????',
            ),
          ),
          'method' => $method_map['update'],
        ),
        'delete' => array(
          'name' => t('Delete Node'),
          'description' => t('Use this method to delete a specific comment.'),
          'examples' => array(
            'curl_retrieve' => array(
              'title' => t('CURL'),
              'class' => 'brush:plain',
              'data' => 'curl -data ' . $url . '/node/ ?????',
            ),
          ),
          'method' => $method_map['delete'],
        ),
        'index' => array(
          'name' => t('Search Nodes'),
          'description' => t('Use this method to search nodes.'),
          'examples' => array(
            'curl_retrieve' => array(
              'title' => t('CURL'),
              'class' => 'brush:plain',
              'data' => 'curl -data ' . $url . '/node ?????',
            ),
          ),
          'method' => $method_map['index'],
        ),
      ),
      'relationships' => array(
        'name' => t('Node Relationships'),
        'description' => t('Retrieve objects that are related to nodes.'),
        'files' => array(
          'name' => t('Files Attached to Node'),
          'description' => t('Use this method to get files that are associated with a node.'),
          'examples' => array(
            'curl_retrieve' => array(
              'title' => t('CURL'),
              'class' => 'brush:plain',
              'data' => 'curl -data ' . $url . '/node ?????',
            ),
          ),
          'method' => $method_map['index'], // ???
        ),
        'comments' => array(
          'name' => t('New Comments Attached to Node'),
          'description' => t('Use this method to get new comments associated with a node.'),
          'examples' => array(
            'curl_retrieve' => array(
              'title' => t('CURL'),
              'class' => 'brush:plain',
              'data' => 'curl -data ' . $url . '/node ?????',
            ),
          ),
          'method' => $method_map['index'],
        ),
      ),
    ),
    'taxonomy_term' => array(
      'name' => t('Taxonomy Terms'),
      'description' => t('Taxonomies are ways of grouping objects, like nodes, and the terms are the specific category terms.'),
      'operations' => array(
        'name' => t('Term Operations'),
        'description' => t('Basic operations for Taxonomy Term objects.'),
        'create' => array(
          'name' => t('Create Term'),
          'description' => t('Use this method to create a specific Taxonomy Term.'),
          'examples' => array(
            'curl_retrieve' => array(
              'title' => t('CURL (Session auth)'),
              'class' => 'brush:plain',
              'data' => 'curl -v -X POST --data \'{"title":"new title"}\' --header "Cookie: [[session_name]]=[[session_id]]" ' . $url . '/taxonomy_term',
            ),
          ),
          'method' => $method_map['create'],
        ),
        'retrieve' => array(
          'name' => t('Retrieve Term'),
          'description' => t('Use this endpoint to retrieve a specific Term.'),
          'examples' => array(
            'curl_retrieve' => array(
              'title' => t('CURL'),
              'class' => 'brush:plain',
              'data' => 'curl -v ' . $url . '/taxonomy_term/[[tid]].json',
            ),
          ),
          'method' => $method_map['retrieve'],
        ),
        'update' => array(
          'name' => t('Update Term'),
          'description' => t('Use this method to update a specific term.'),
          'examples' => array(
            'curl_retrieve' => array(
              'title' => t('CURL (Session auth)'),
              'class' => 'brush:plain',
              'data' => 'curl -v -X PUT --data \'{"title":"new title"}\' --header "Cookie: [[session_name]]=[[session_id]]" ' . $url . '/taxonomy_term/[[tid]]',
            ),
          ),
          'method' => $method_map['update'],
        ),
        'delete' => array(
          'name' => t('Delete Term'),
          'description' => t('Use this method to delete a specific term.'),
          'examples' => array(
            'curl_retrieve' => array(
              'title' => t('CURL (Session auth)'),
              'class' => 'brush:plain',
              'data' => 'curl -v -X DELETE --header "Cookie: [[session_name]]=[[session_id]]" ' . $url . '/taxonomy_term/[[tid]]',
            ),
          ),
          'method' => $method_map['delete'],
        ),
        'index' => array(
          'name' => t('Search Terms'),
          'description' => t('Use this method to search Terms.'),
          'examples' => array(
            'curl_retrieve' => array(
              'title' => t('CURL'),
              'class' => 'brush:plain',
              'data' => 'curl -v ' . $url . '/taxonomy_term.json',
            ),
            'curl_parameters' => array(
              'title' => t('CURL with parameters'),
              'class' => 'brush:plain',
              'data' => 'curl -v ' . $url . '/taxonomy_term.json?parameters%5Bvid%5D=[[vid]]',
            ),
          ),
          'method' => $method_map['index'],
        ),
      ),
      'actions' => array(
        'name' => t('Term Actions'),
        'description' => t('Actions for the Term objects.'),
        'selectNodes' => array(
          'name' => t('Nodes with Term'),
          'description' => t('Use this method to get all nodes with specific Term.'),
          'examples' => array(
            'curl_select' => array(
              'title' => t('CURL'),
              'class' => 'brush:plain',
              'data' => 'curl -v ' . $url . '/taxonomy_term/selectNodes.json?tid=[[tid]]',
            ),
          ),
          'method' => $method_map['index'],
        ),
      ),
    ),
    'views' => array(
      'name' => t('Views'),
      'description' => t('Views are queries of data as defined in configuration.'),
      'operations' => array(
        'name' => t('Views Operations'),
        'description' => t('Basic operations on Views.'),
        'retrieve' => array(
          'name' => t('Search Views'),
          'description' => t('Use this method to search Views.'),
          'examples' => array(
            'curl_retrieve' => array(
              'title' => t('CURL'),
              'class' => 'brush:plain',
              'data' => 'curl -v --data ' . $url . '/views/[[view-name]].json',
            ),
          ),
          'method' => $method_map['retrieve'],
        ),
      ),
    ),
    'user' => array(
      'name' => t('User'),
      'description' => t('User methods.'),
      'actions' => array(
        'name' => t('User Actions'),
        'description' => t('User actions like logging in and logging out.'),
        'login' => array(
          'name' => t('User Login'),
          'description' => t('Use this method to login into the site with a username and password.  you will recieve a session name and session ID that can then be used within a cookie to make requests that require authentication.'),
          'examples' => array(
            'curl_login' => array(
              'title' => t('CURL'),
              'class' => 'brush:plain',
              'data' => 'curl -v --data \'{"username":"[[your_username]]","password":"[[your_password]]"}\' --header "Content-Type:application/json" ' . $url .'/user/login ',
            ),
          ),
          'method' => $method_map['actions'],
        ),
        'logout' => array(
          'name' => t('User Logout'),
          'description' => t('Logout a user, given the session.'),
          'examples' => array(
            'curl_login' => array(
              'title' => t('CURL'),
              'class' => 'brush:plain',
              'data' => 'curl -v --header "Cookie: [[session_name]]=[[session_id]]" ' . $url . '/user/logout',
            ),
          ),
          'method' => $method_map['actions'],
        ),
      ),
    ),
  );
  
  // Merge
  $resources = cc_api_merge_arrays($resources_meta, $resources);
}

/**
 * Add meta data to data model.
 */
function cc_api_documentation_page_data_model(&$api) {
  $api->data_model = isset($api->data_model) ? $api->data_model : array();
  
  // Nodes
  $node_types = node_type_get_types();
  $api->data_model['nodes'] = array(
    'name' => t('Nodes'),
    'description' => t('Nodes, often referred to as content, are the building blocks of the application and Drupal in general.'),
  );
  
  // Check node type configuration
  $enabled = variable_get('cc_api_doc_page_data_model_content_types', array('application', 'interaction', 'organization'));
  
  // Add node type data to $api object
  foreach ($node_types as $type_id => $node_type) {
    // Check configuration
    if (!in_array($type_id, $enabled)) {
      continue;
    }
    
    $api->data_model['nodes'][$type_id] = array(
      'id' => $type_id,
      'name' => $node_type->name,
      'description' => $node_type->description,
    );
    
    // Add field data to $api object
    $fields = field_info_instances('node', $type_id);
    foreach ($fields as $fid => $field) {
      $field_details = field_info_field($fid);
      $api->data_model['nodes'][$type_id]['fields'][$fid] = array(
        'id' => $field['field_name'],
        'label' => $field['label'],
        'description' => $field['description'],
        'type' => $field_details['type'],
      );
    }
  }
}


/**
 * Add meta data to data model.
 */
function cc_api_documentation_page_views(&$api) {
  $api->views_searching = isset($api->views_searching) ? $api->views_searching : array();
  $tag = variable_get('cc_api_doc_page_views_tag', 'api');
  
  $views = views_get_all_views();
  foreach ($views as $view) {
    // Check tag
    if (!empty($tag) && $view->tag != $tag) {
      continue;
    }

    $data = array();
    $data['id'] = $view->name;
    $data['name'] = $view->human_name;
    $data['description'] = $view->description;
    $data['base_table'] = $view->base_table;
  
    // Get displays
    $data['displays'] = array();
    $default_filters = array();
    foreach ($view->display as $d => $display) {
      $data['displays'][$d] = array(
        'id' => $display->id,
        'name' => ($d == 'default') ? t('Default') : $display->display_title,
        'description' => isset($display->display_options['display_description']) ?
          $display->display_options['display_description'] : '',
      );
      
      // Filters
      if (isset($display->display_options['filters'])) {
        $data['displays'][$d]['filters'] = array();
        foreach ($display->display_options['filters'] as $f => $filter) {
          if (isset($filter['exposed']) && $filter['exposed']) {
            $data['displays'][$d]['filters'][$f] = array(
              'name' => $filter['expose']['label'],
              'id' => $filter['expose']['identifier'],
              'required' => isset($filter['expose']['required']) ? 
                $filter['expose']['required'] : 0,
            );
          }
        }
      }
      
      // Merge with defaults
      if ($d != 'default') {
        $data['displays'][$d]['filters'] = isset($data['displays'][$d]['filters']) ?
          $data['displays'][$d]['filters'] : array();
        $data['displays'][$d]['filters'] = array_merge($data['displays'][$d]['filters'], $default_filters);
      }
      else {
        $default_filters = $data['displays'][$d]['filters'];
      }
      
      // An example
      $data['displays'][$d]['examples'] = array(
        'search_filters' => array(
          'title' => t('Search with filters'),
          'data' => ($d == 'default') ?
            $api->base_url . '/views/' . $data['id'] . '.json&filters[:id1]=:value1&filters[:id2]=:value2' :
            $api->base_url . '/views/' . $data['id'] . '.json?display_id=' . $d . '&filters[:id1]=:value1&filters[:id2]=:value2',
          'class' => 'brush:plain',
        ),
      );
      
      // Don't display default for now, unless theres a better way
      // to handle it
      if ($d == 'default') {
        unset($data['displays'][$d]);
      }
    }

    // Attach data
    $api->views_searching[$view->name] = $data;
  }
}

/**
 * Recursive array merge
 */
function cc_api_merge_arrays($arr1, $arr2) {
  if (is_array($arr1) && is_array($arr2)) {
    foreach ($arr2 as $k => $v) {
      if (isset($arr1[$k]) && is_array($v) && is_array($arr1[$k])) {
        $arr1[$k] = cc_api_merge_arrays($arr1[$k], $v);
      }
      else {
        $arr1[$k] = $v;
      }
    }
  }
  
  return $arr1;
}