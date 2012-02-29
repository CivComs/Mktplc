<?php
/**
 * @file
 * cc_contexts.context.inc
 */

/**
 * Implementation of hook_context_default_contexts().
 */
function cc_contexts_context_default_contexts() {
  $export = array();

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'api_block';
  $context->description = 'Context for the API block.';
  $context->tag = 'api';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'application' => 'application',
        'interaction' => 'interaction',
        'organization' => 'organization',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
    'views' => array(
      'values' => array(
        'taxonomy_term_listing' => 'taxonomy_term_listing',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'cc_api-cc_api' => array(
          'module' => 'cc_api',
          'delta' => 'cc_api',
          'region' => 'sidebar_second',
          'weight' => '56',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Context for the API block.');
  t('api');
  $export['api_block'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'apps';
  $context->description = '';
  $context->tag = 'theme';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'apps' => 'apps',
        'applications' => 'applications',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-94b2fa9ab164ade56e342b3e41a8126c' => array(
          'module' => 'views',
          'delta' => '94b2fa9ab164ade56e342b3e41a8126c',
          'region' => 'content',
          'weight' => '-52',
        ),
        'views-f82803d13f34398606eb9cd5221204ee' => array(
          'module' => 'views',
          'delta' => 'f82803d13f34398606eb9cd5221204ee',
          'region' => 'content',
          'weight' => '-52',
        ),
        'views-63fb1cb1767fac294dbf5bc3ed35bd09' => array(
          'module' => 'views',
          'delta' => '63fb1cb1767fac294dbf5bc3ed35bd09',
          'region' => 'content',
          'weight' => '-10',
        ),
        'views-applications-block_1' => array(
          'module' => 'views',
          'delta' => 'applications-block_1',
          'region' => 'content_leftcolumn',
          'weight' => '0',
        ),
        'views-applications-block_2' => array(
          'module' => 'views',
          'delta' => 'applications-block_2',
          'region' => 'content_rightcolumn',
          'weight' => '0',
        ),
        'views-applications-block_3' => array(
          'module' => 'views',
          'delta' => 'applications-block_3',
          'region' => 'content_leftcolumn_lower',
          'weight' => '-10',
        ),
        'views-applications-block_4' => array(
          'module' => 'views',
          'delta' => 'applications-block_4',
          'region' => 'content_rightcolumn_lower',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('theme');
  $export['apps'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'beta';
  $context->description = 'Beta Splash Page';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'preview' => 'preview',
      ),
    ),
  );
  $context->reactions = array(
    'region' => array(
      'alpha' => array(
        'disable' => array(
          'page_top' => 0,
          'page_bottom' => 0,
          'content' => 0,
          'header' => 0,
          'footer' => 0,
          'sidebar_first' => 0,
          'sidebar_second' => 0,
          'dashboard_main' => 0,
          'dashboard_sidebar' => 0,
          'dashboard_inactive' => 0,
        ),
      ),
      'bartik' => array(
        'disable' => array(
          'header' => 0,
          'help' => 0,
          'page_top' => 0,
          'page_bottom' => 0,
          'highlighted' => 0,
          'featured' => 0,
          'content' => 0,
          'sidebar_first' => 0,
          'sidebar_second' => 0,
          'triptych_first' => 0,
          'triptych_middle' => 0,
          'triptych_last' => 0,
          'footer_firstcolumn' => 0,
          'footer_secondcolumn' => 0,
          'footer_thirdcolumn' => 0,
          'footer_fourthcolumn' => 0,
          'footer' => 0,
          'dashboard_main' => 0,
          'dashboard_sidebar' => 0,
          'dashboard_inactive' => 0,
        ),
      ),
      'civiccommons' => array(
        'disable' => array(
          'sidebar_second' => 'sidebar_second',
          'search_bar' => 'search_bar',
          'content_bottom' => 'content_bottom',
          'content_bottom2' => 'content_bottom2',
          'content_bottom3' => 'content_bottom3',
          'page_top' => 0,
          'page_bottom' => 0,
          'content' => 0,
          'branding' => 0,
          'top_menu' => 0,
          'content_top' => 0,
          'content_top2' => 0,
          'content_top3' => 0,
          'content_leftcolumn' => 0,
          'content_rightcolumn' => 0,
          'content_main' => 0,
          'content_region_spacer' => 0,
          'content_leftcolumn_lower' => 0,
          'content_rightcolumn_lower' => 0,
          'content_doormat' => 0,
          'footer_first' => 0,
          'footer_second' => 0,
          'dashboard_main' => 0,
          'dashboard_sidebar' => 0,
          'dashboard_inactive' => 0,
        ),
      ),
      'omega' => array(
        'disable' => array(
          'page_top' => 0,
          'page_bottom' => 0,
          'content' => 0,
          'user_first' => 0,
          'user_second' => 0,
          'branding' => 0,
          'menu' => 0,
          'sidebar_first' => 0,
          'sidebar_second' => 0,
          'header_first' => 0,
          'header_second' => 0,
          'preface_first' => 0,
          'preface_second' => 0,
          'preface_third' => 0,
          'postscript_first' => 0,
          'postscript_second' => 0,
          'postscript_third' => 0,
          'postscript_fourth' => 0,
          'footer_first' => 0,
          'footer_second' => 0,
          'dashboard_main' => 0,
          'dashboard_sidebar' => 0,
          'dashboard_inactive' => 0,
        ),
      ),
      'seven' => array(
        'disable' => array(
          'content' => 0,
          'help' => 0,
          'page_top' => 0,
          'page_bottom' => 0,
          'sidebar_first' => 0,
          'dashboard_main' => 0,
          'dashboard_sidebar' => 0,
          'dashboard_inactive' => 0,
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Beta Splash Page');
  $export['beta'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'dashboard';
  $context->description = '';
  $context->tag = 'theme';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'user' => 'user',
        'users/*' => 'users/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'block-16' => array(
          'module' => 'block',
          'delta' => 16,
          'region' => 'content',
          'weight' => '34',
        ),
        'views-watching_orgs-block' => array(
          'module' => 'views',
          'delta' => 'watching_orgs-block',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'block-15' => array(
          'module' => 'block',
          'delta' => 15,
          'region' => 'content_top',
          'weight' => '-10',
        ),
        'block-17' => array(
          'module' => 'block',
          'delta' => 17,
          'region' => 'content_top2',
          'weight' => '-10',
        ),
        'views-watching_app-block' => array(
          'module' => 'views',
          'delta' => 'watching_app-block',
          'region' => 'content_top3',
          'weight' => '-10',
        ),
      ),
    ),
    'breadcrumb' => 'user',
    'delta' => array(
      'delta_template' => 'user_layout',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('theme');
  $export['dashboard'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'home';
  $context->description = '';
  $context->tag = 'home';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'block-22' => array(
          'module' => 'block',
          'delta' => 22,
          'region' => 'content',
          'weight' => '-10',
        ),
        'cc_wiki-cc_wiki_home' => array(
          'module' => 'cc_wiki',
          'delta' => 'cc_wiki_home',
          'region' => 'content_doormat',
          'weight' => '-10',
        ),
        'cc_activity-cc_activity_press' => array(
          'module' => 'cc_activity',
          'delta' => 'cc_activity_press',
          'region' => 'content_doormat',
          'weight' => '-9',
        ),
        'cc_activity-cc_activity_recent' => array(
          'module' => 'cc_activity',
          'delta' => 'cc_activity_recent',
          'region' => 'content_doormat',
          'weight' => '-8',
        ),
        'views-bd03f50c003e3695ccac2c405ee2189c' => array(
          'module' => 'views',
          'delta' => 'bd03f50c003e3695ccac2c405ee2189c',
          'region' => 'content_main_left',
          'weight' => '-10',
        ),
        'views-5cf5174068e83941c214a8509efabc2a' => array(
          'module' => 'views',
          'delta' => '5cf5174068e83941c214a8509efabc2a',
          'region' => 'content_main_middle',
          'weight' => '-10',
        ),
        'block-24' => array(
          'module' => 'block',
          'delta' => 24,
          'region' => 'content_main_right',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('home');
  $export['home'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'organization';
  $context->description = 'organization context';
  $context->tag = 'theme';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'organization' => 'organization',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
    'node_taxonomy' => array(
      'values' => array(
        124 => 124,
        125 => 125,
        126 => 126,
        127 => 127,
        128 => 128,
        129 => 129,
        130 => 130,
        131 => 131,
        132 => 132,
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-applications-block_6' => array(
          'module' => 'views',
          'delta' => 'applications-block_6',
          'region' => 'content',
          'weight' => '-58',
        ),
        'views-interactions-block_3' => array(
          'module' => 'views',
          'delta' => 'interactions-block_3',
          'region' => 'content',
          'weight' => '-57',
        ),
        'views-at_a_glance-block' => array(
          'module' => 'views',
          'delta' => 'at_a_glance-block',
          'region' => 'sidebar_second',
          'weight' => '-56',
        ),
        'views-commercial_services-block' => array(
          'module' => 'views',
          'delta' => 'commercial_services-block',
          'region' => 'sidebar_second',
          'weight' => '-55',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('organization context');
  t('theme');
  $export['organization'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'person';
  $context->description = 'person organization context';
  $context->tag = 'theme';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'organization' => 'organization',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
    'node_taxonomy' => array(
      'values' => array(
        229 => 229,
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-apps_org_has_created-block' => array(
          'module' => 'views',
          'delta' => 'apps_org_has_created-block',
          'region' => 'content',
          'weight' => '-9',
        ),
        'views-interactions-block_3' => array(
          'module' => 'views',
          'delta' => 'interactions-block_3',
          'region' => 'content',
          'weight' => '-8',
        ),
        'views-commercial_services-block' => array(
          'module' => 'views',
          'delta' => 'commercial_services-block',
          'region' => 'sidebar_second',
          'weight' => '-52',
        ),
        'views-at_a_glance-block' => array(
          'module' => 'views',
          'delta' => 'at_a_glance-block',
          'region' => 'sidebar_second',
          'weight' => '-52',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('person organization context');
  t('theme');
  $export['person'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'place';
  $context->description = 'Place display page';
  $context->tag = 'theme';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'places/*' => 'places/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-applications-block_7' => array(
          'module' => 'views',
          'delta' => 'applications-block_7',
          'region' => 'content_leftcolumn',
          'weight' => '-10',
        ),
        'views-cc_organizations-block_3' => array(
          'module' => 'views',
          'delta' => 'cc_organizations-block_3',
          'region' => 'content_leftcolumn',
          'weight' => '-9',
        ),
        'views-cc_organizations-block_1' => array(
          'module' => 'views',
          'delta' => 'cc_organizations-block_1',
          'region' => 'content_leftcolumn',
          'weight' => '-8',
        ),
        'views-interactions-block_4' => array(
          'module' => 'views',
          'delta' => 'interactions-block_4',
          'region' => 'content_rightcolumn',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Place display page');
  t('theme');
  $export['place'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'places';
  $context->description = 'Places Landing Page';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'places' => 'places',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-places-block_1' => array(
          'module' => 'views',
          'delta' => 'places-block_1',
          'region' => 'content_leftcolumn',
          'weight' => '-10',
        ),
        'views-places-block_2' => array(
          'module' => 'views',
          'delta' => 'places-block_2',
          'region' => 'content_rightcolumn',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Places Landing Page');
  $export['places'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'project';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'project' => 'project',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-projects-block_1' => array(
          'module' => 'views',
          'delta' => 'projects-block_1',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['project'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'search';
  $context->description = 'Search page ';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'search/node' => 'search/node',
        'search/node/*' => 'search/node/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'custom_search_blocks-2' => array(
          'module' => 'custom_search_blocks',
          'delta' => 2,
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Search page ');
  $export['search'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'taxonomy';
  $context->description = 'Taxonomy listing pages';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'taxonomy/term/*' => 'taxonomy/term/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-taxonomy_term_listing-block_1' => array(
          'module' => 'views',
          'delta' => 'taxonomy_term_listing-block_1',
          'region' => 'content',
          'weight' => '-10',
        ),
        'views-taxonomy_term_listing-block_2' => array(
          'module' => 'views',
          'delta' => 'taxonomy_term_listing-block_2',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Taxonomy listing pages');
  $export['taxonomy'] = $context;

  return $export;
}
