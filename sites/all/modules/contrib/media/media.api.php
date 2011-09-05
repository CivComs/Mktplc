<?php

/**
 * Return an array of plugins for the media browser.
 *
 * Implementors are expected to return a renderable element.
 *
 * Each element will be a jQuery tab on the media browser.
 *
 * Some elements are special:
 *  - #title: The title that goes on the tab
 *  - #settings: Drupal.settings.media.browser.$key (where key is the array key).
 *  - #callback: If provided, will make the tab an "ajax" tab.
 *
 * Example:
 *   $plugins['library'] = array(
 *  '#title' => t('Library'),
 *  '#attached' => array(
 *    'js' => array(
 *       $path . '/js/plugins/media.library.js',
 *     ),
 *   ),
 *   '#settings' => array(
 *     'viewMode' => 'thumbnails',
 *     'getMediaUrl' => url('media/browser/list'),
 *   ),
 *   '#markup' => '<div> Library goes here</div>',
 * );
 *
 * @param $plugin_name
 *  The name of the plugin to view
 *
 * @param $params
 *  An array of parameters which came in is $_GET['params'].
 *  The expected parameters is still being defined.
 *   - types: Array of media types to support
 *   - multiselect: Boolean enabling or disabling multiselect
 *
 * @return
 *  Renderable array.
 */
function hook_media_browser_plugin_view($plugin_name, $params) {

}

/**
 * Returns a list of plugins for the media browser.
 *
 * Plugins are defined in a multi-dimensional associative
 * array format with the following keys:
 *
 * - #weight (optional): Weight of the plugin in relation to other plugins
 *  when being displayed, e.g. tabs in the browser.
 *
 * @example
 * <code>
 * array(
 *  'unique_plugin_name' => array(
 *     '#weight' => 42,
 *   ),
 * );
 * </code>
 */
function hook_media_browser_plugin_info() {
  
}

/**
 * Returns an array of operations which can be taken on media items.
 *
 * This is used on the admin/content/media page so users can select multiple
 * items and do something with them.
 *
 * The return format is an array or arrays with the following keys:
 *  - label: The string to be shown to the user.
 *  - callback (optional): A callback to be called when the media items are selected.
 *     Media items will be passed in as an argument.
 *  - redirect (optional): A path to redirect to.  %fids should be in the path
 *     It will be replaced with the fids selected delimited by "+".
 *     i.e. mymodule/%fids/something -> mymodule/1+3+2/something if media items
 *     1, 3 and 2 were selected.
 */
function media_media_operations() {
  
}