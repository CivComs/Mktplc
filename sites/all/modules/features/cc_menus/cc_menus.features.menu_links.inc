<?php
/**
 * @file
 * cc_menus.features.menu_links.inc
 */

/**
 * Implementation of hook_menu_default_menu_links().
 */
function cc_menus_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu:<front>
  $menu_links['main-menu:<front>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Home',
    'options' => array(),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '1',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
  );
  // Exported menu link: menu-add-content:node/add/application
  $menu_links['menu-add-content:node/add/application'] = array(
    'menu_name' => 'menu-add-content',
    'link_path' => 'node/add/application',
    'router_path' => 'node/add/application',
    'link_title' => 'App',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-50',
  );
  // Exported menu link: menu-add-content:node/add/interaction
  $menu_links['menu-add-content:node/add/interaction'] = array(
    'menu_name' => 'menu-add-content',
    'link_path' => 'node/add/interaction',
    'router_path' => 'node/add/interaction',
    'link_title' => 'Interaction',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-46',
  );
  // Exported menu link: menu-add-content:node/add/organization
  $menu_links['menu-add-content:node/add/organization'] = array(
    'menu_name' => 'menu-add-content',
    'link_path' => 'node/add/organization',
    'router_path' => 'node/add/organization',
    'link_title' => 'Organization',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'query' => array(
        'org' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-47',
  );
  // Exported menu link: menu-add-content:node/add/project
  $menu_links['menu-add-content:node/add/project'] = array(
    'menu_name' => 'menu-add-content',
    'link_path' => 'node/add/project',
    'router_path' => 'node/add/project',
    'link_title' => 'Project',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-49',
  );
  // Exported menu link: menu-add-content:node/add/standard
  $menu_links['menu-add-content:node/add/standard'] = array(
    'menu_name' => 'menu-add-content',
    'link_path' => 'node/add/standard',
    'router_path' => 'node/add/standard',
    'link_title' => 'Standard',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-48',
  );
  // Exported menu link: menu-breadcrumbs:user
  $menu_links['menu-breadcrumbs:user'] = array(
    'menu_name' => 'menu-breadcrumbs',
    'link_path' => 'user',
    'router_path' => 'user',
    'link_title' => 'Dashboard',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
  );
  // Exported menu link: menu-cc-main-nav:<front>
  $menu_links['menu-cc-main-nav:<front>'] = array(
    'menu_name' => 'menu-cc-main-nav',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Marketplace',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '1',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
  );
  // Exported menu link: menu-cc-main-nav:http://civiccommons.org/projects
  $menu_links['menu-cc-main-nav:http://civiccommons.org/projects'] = array(
    'menu_name' => 'menu-cc-main-nav',
    'link_path' => 'http://civiccommons.org/projects',
    'router_path' => '',
    'link_title' => 'Projects',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '1',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
  );
  // Exported menu link: menu-cc-main-nav:http://wiki.civiccommons.org
  $menu_links['menu-cc-main-nav:http://wiki.civiccommons.org'] = array(
    'menu_name' => 'menu-cc-main-nav',
    'link_path' => 'http://wiki.civiccommons.org',
    'router_path' => '',
    'link_title' => 'Wiki',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '1',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
  );
  // Exported menu link: menu-meta-nav:http://civiccommons.org/about
  $menu_links['menu-meta-nav:http://civiccommons.org/about'] = array(
    'menu_name' => 'menu-meta-nav',
    'link_path' => 'http://civiccommons.org/about',
    'router_path' => '',
    'link_title' => 'About',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '1',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
  );
  // Exported menu link: menu-meta-nav:http://civiccommons.org/blog
  $menu_links['menu-meta-nav:http://civiccommons.org/blog'] = array(
    'menu_name' => 'menu-meta-nav',
    'link_path' => 'http://civiccommons.org/blog',
    'router_path' => '',
    'link_title' => 'Blog',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '1',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
  );
  // Exported menu link: menu-meta-nav:http://civiccommons.org/community
  $menu_links['menu-meta-nav:http://civiccommons.org/community'] = array(
    'menu_name' => 'menu-meta-nav',
    'link_path' => 'http://civiccommons.org/community',
    'router_path' => '',
    'link_title' => 'Community',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '1',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
  );
  // Exported menu link: menu-meta-nav:http://civiccommons.org/contact
  $menu_links['menu-meta-nav:http://civiccommons.org/contact'] = array(
    'menu_name' => 'menu-meta-nav',
    'link_path' => 'http://civiccommons.org/contact',
    'router_path' => '',
    'link_title' => 'Contact',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '1',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
  );
  // Exported menu link: menu-mktplc-section-nav:<front>
  $menu_links['menu-mktplc-section-nav:<front>'] = array(
    'menu_name' => 'menu-mktplc-section-nav',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Marketplace',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '1',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-50',
  );
  // Exported menu link: menu-mktplc-section-nav:applications
  $menu_links['menu-mktplc-section-nav:applications'] = array(
    'menu_name' => 'menu-mktplc-section-nav',
    'link_path' => 'applications',
    'router_path' => 'applications',
    'link_title' => 'Apps',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-49',
  );
  // Exported menu link: menu-mktplc-section-nav:places
  $menu_links['menu-mktplc-section-nav:places'] = array(
    'menu_name' => 'menu-mktplc-section-nav',
    'link_path' => 'places',
    'router_path' => 'places',
    'link_title' => 'Places',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-47',
  );
  // Exported menu link: menu-mktplc-section-nav:projects
  $menu_links['menu-mktplc-section-nav:projects'] = array(
    'menu_name' => 'menu-mktplc-section-nav',
    'link_path' => 'projects',
    'router_path' => 'projects',
    'link_title' => 'Projects',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '1',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-48',
  );
  // Exported menu link: menu-topmenu1:<front>
  $menu_links['menu-topmenu1:<front>'] = array(
    'menu_name' => 'menu-topmenu1',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'SIGN UP',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '1',
    'has_children' => '0',
    'expanded' => '1',
    'weight' => '-47',
  );
  // Exported menu link: menu-topmenu1:user
  $menu_links['menu-topmenu1:user'] = array(
    'menu_name' => 'menu-topmenu1',
    'link_path' => 'user',
    'router_path' => 'user',
    'link_title' => 'LOGIN',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '1',
    'weight' => '-46',
  );
  // Exported menu link: menu-topmenu2:<front>
  $menu_links['menu-topmenu2:<front>'] = array(
    'menu_name' => 'menu-topmenu2',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Marketplace',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '1',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-49',
  );
  // Exported menu link: menu-topmenu2:http://wiki.civiccommons.org
  $menu_links['menu-topmenu2:http://wiki.civiccommons.org'] = array(
    'menu_name' => 'menu-topmenu2',
    'link_path' => 'http://wiki.civiccommons.org',
    'router_path' => '',
    'link_title' => 'Wiki',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '1',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
  );
  // Exported menu link: menu-topmenu2:http://www.civiccommons.org
  $menu_links['menu-topmenu2:http://www.civiccommons.org'] = array(
    'menu_name' => 'menu-topmenu2',
    'link_path' => 'http://www.civiccommons.org',
    'router_path' => '',
    'link_title' => 'HOME',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '1',
    'has_children' => '0',
    'expanded' => '1',
    'weight' => '-50',
  );
  // Exported menu link: user-menu:user
  $menu_links['user-menu:user'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'user',
    'router_path' => 'user',
    'link_title' => 'User account',
    'options' => array(
      'alter' => TRUE,
    ),
    'module' => 'system',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-10',
  );
  // Exported menu link: user-menu:user/logout
  $menu_links['user-menu:user/logout'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'user/logout',
    'router_path' => 'user/logout',
    'link_title' => 'Log out',
    'options' => array(),
    'module' => 'system',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '10',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('About');
  t('App');
  t('Apps');
  t('Blog');
  t('Community');
  t('Contact');
  t('Dashboard');
  t('HOME');
  t('Home');
  t('Interaction');
  t('LOGIN');
  t('Log out');
  t('Marketplace');
  t('Organization');
  t('Places');
  t('Project');
  t('Projects');
  t('SIGN UP');
  t('Standard');
  t('User account');
  t('Wiki');


  return $menu_links;
}
