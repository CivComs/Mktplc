<?php
/**
 * @file
 * cc_menus.features.menu_custom.inc
 */

/**
 * Implementation of hook_menu_default_menu_custom().
 */
function cc_menus_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: devel
  $menus['devel'] = array(
    'menu_name' => 'devel',
    'title' => 'Development',
    'description' => 'Development link',
  );
  // Exported menu: features
  $menus['features'] = array(
    'menu_name' => 'features',
    'title' => 'Features',
    'description' => 'Menu items for any enabled features.',
  );
  // Exported menu: main-menu
  $menus['main-menu'] = array(
    'menu_name' => 'main-menu',
    'title' => 'Main menu',
    'description' => 'The <em>Main</em> menu is used on many sites to show the major sections of the site, often in a top navigation bar.',
  );
  // Exported menu: management
  $menus['management'] = array(
    'menu_name' => 'management',
    'title' => 'Management',
    'description' => 'The <em>Management</em> menu contains links for administrative tasks.',
  );
  // Exported menu: menu-add-content
  $menus['menu-add-content'] = array(
    'menu_name' => 'menu-add-content',
    'title' => 'Add Content',
    'description' => '',
  );
  // Exported menu: menu-breadcrumbs
  $menus['menu-breadcrumbs'] = array(
    'menu_name' => 'menu-breadcrumbs',
    'title' => 'Breadcrumbs',
    'description' => '',
  );
  // Exported menu: menu-cc-main-nav
  $menus['menu-cc-main-nav'] = array(
    'menu_name' => 'menu-cc-main-nav',
    'title' => 'CC Main Nav',
    'description' => '',
  );
  // Exported menu: menu-meta-nav
  $menus['menu-meta-nav'] = array(
    'menu_name' => 'menu-meta-nav',
    'title' => 'Meta Nav',
    'description' => '',
  );
  // Exported menu: menu-mktplc-section-nav
  $menus['menu-mktplc-section-nav'] = array(
    'menu_name' => 'menu-mktplc-section-nav',
    'title' => 'Mktplc Section Nav',
    'description' => '',
  );
  // Exported menu: menu-topmenu1
  $menus['menu-topmenu1'] = array(
    'menu_name' => 'menu-topmenu1',
    'title' => 'topmenu1',
    'description' => 'civic commons top menu',
  );
  // Exported menu: menu-topmenu2
  $menus['menu-topmenu2'] = array(
    'menu_name' => 'menu-topmenu2',
    'title' => 'topmenu2',
    'description' => '',
  );
  // Exported menu: menu-user-tasks
  $menus['menu-user-tasks'] = array(
    'menu_name' => 'menu-user-tasks',
    'title' => 'User Tasks',
    'description' => '',
  );
  // Exported menu: navigation
  $menus['navigation'] = array(
    'menu_name' => 'navigation',
    'title' => 'Navigation',
    'description' => 'The <em>Navigation</em> menu contains links intended for site visitors. Links are added to the <em>Navigation</em> menu automatically by some modules.',
  );
  // Exported menu: user-menu
  $menus['user-menu'] = array(
    'menu_name' => 'user-menu',
    'title' => 'User menu',
    'description' => 'The <em>User</em> menu contains links related to the user\'s account, as well as the \'Log out\' link.',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Add Content');
  t('Breadcrumbs');
  t('CC Main Nav');
  t('Development');
  t('Development link');
  t('Features');
  t('Main menu');
  t('Management');
  t('Menu items for any enabled features.');
  t('Meta Nav');
  t('Mktplc Section Nav');
  t('Navigation');
  t('The <em>Main</em> menu is used on many sites to show the major sections of the site, often in a top navigation bar.');
  t('The <em>Management</em> menu contains links for administrative tasks.');
  t('The <em>Navigation</em> menu contains links intended for site visitors. Links are added to the <em>Navigation</em> menu automatically by some modules.');
  t('The <em>User</em> menu contains links related to the user\'s account, as well as the \'Log out\' link.');
  t('User Tasks');
  t('User menu');
  t('civic commons top menu');
  t('topmenu1');
  t('topmenu2');


  return $menus;
}
