<?php

/**
 * @file
 * Provides the theming functions for fivestar
 */

function theme_fivestar_settings($variables) {
  $form = $variables['form'];
  drupal_add_css(drupal_get_path('module', 'fivestar') .'/css/fivestar-admin.css', 'module', 'all', FALSE);
  drupal_set_title(t('Fivestar Settings'));

  // Default preview.
  $form['widget']['fivestar_widget']['default']['#description'] = 'Default '. t('Preview') .':<br />'. theme('fivestar_preview_widget', array('css_file' => 'default'));

  // Preview for each classic widget.
  foreach (element_children($form['widget']['fivestar_widget']) as $widget_key) {
    if ($widget_key != 'default') {
      $form['widget']['fivestar_widget'][$widget_key]['#description'] = $form['widget']['fivestar_widget'][$widget_key]['#title'] .' '. t('Preview') .':<br />'. theme('fivestar_preview_widget', array('css_file' => $widget_key));
    }
  }

  // Preview for each color-enabled widget.
  foreach (element_children($form['widget']['fivestar_color_widget']) as $widget_key) {
    $form['widget']['fivestar_color_widget'][$widget_key] = $form['widget']['fivestar_widget'][$widget_key];
    $form['widget']['fivestar_color_widget'][$widget_key]['#description'] = $form['widget']['fivestar_color_widget'][$widget_key]['#title'] .' '. t('Preview') .':<br />'. theme('fivestar_preview_widget', array('css_file' => $widget_key));
    unset($form['widget']['fivestar_widget'][$widget_key]);
  }

  // Add the new styles to the page.
  drupal_add_css(fivestar_get_inline_css(), array('type' => 'inline'));

  $form['widget']['fivestar_widget']['#attributes']['class'][] = ' clearfix';
  $form['widget']['fivestar_color_widget']['#attributes']['class'][] = ' fivestar-color-widgets clearfix';

  return drupal_render_children($form);
}

/**
 * Show a preview of a widget using a custom CSS file.
 */
function theme_fivestar_preview_widget($variables) {
  static $default_css_added = FALSE;

  $css_file = $variables['css_file'];
  // Add the default CSS to the page to ensure the defaults take precedence.
  if (!$default_css_added) {
    $css = file_get_contents(drupal_get_path('module', 'fivestar') .'/css/fivestar.css');
    // Prepend the classes with the unique widget div.
    $css = preg_replace('/((div)?\.fivestar-widget)/', 'div.fivestar-widgets $1', $css);
    // Update relative URLs with absolute locations.
    $css = preg_replace('/url\(\.\.\/(.*?)\)/', 'url('. base_path() . drupal_get_path('module', 'fivestar') .'/$1)', $css);
    fivestar_add_inline_css('default', $css);
    $default_css_added = TRUE;
  }

  // Add widget specific CSS to the page.
  $widget_name = str_replace('.css', '', basename($css_file));
  $widget_path = dirname($css_file);
  if ($widget_name != 'default') {
    $css = file_get_contents($css_file);
    // Prepend the classes with the unique widget div.
    $css = preg_replace('/((div)?\.fivestar-widget)/', 'div#fivestar-preview-'. $widget_name .' $1', $css);
    // Update relative URLs with absolute locations.
    $css = preg_replace('/url\((.*?)\)/', 'url('. base_path() . $widget_path .'/$1)', $css);
    fivestar_add_inline_css($widget_name, $css);
  }

  $form = array(
    '#post' => array(),
    '#programmed' => FALSE,
    '#tree' => FALSE,
    '#parents' => array(),
    '#array_parents' => array(),
    '#required' => FALSE,
    '#attributes' => array(),
    '#title_display' => 'before',
  );
  $form_state = form_state_defaults();
  $form_state['values'] = array();
  $form_state['process_input'] = array();
  $form_state['complete form'] = array();

  $form['vote'] = array(
    '#type' => 'fivestar',
    '#stars' => 5,
    '#auto_submit' => FALSE,
    '#allow_clear' => TRUE,
  );

  $form = form_builder('fivestar_preview', $form, $form_state);

  $output = '<div class="fivestar-star-preview" id="fivestar-preview-'. $widget_name .'">';
  $output .= drupal_render_children($form);
  $output .= '</div>';

  return $output;
}

function theme_fivestar_preview($variables) {
  extract($variables, EXTR_SKIP);
  $values = array(
    'average' => 50,
    'user' => 80,
    'count' => 20,
  );
  $settings = array(
    'stars' => $stars,
    'allow_clear' => $unvote,
    'style' => $style,
    'text' => $text,
    'title' => $title,
    'autosubmit' => FALSE,
    'feedback_enable' => $feedback_enable,
    'labels_enable' => $labels_enable,
    'labels' => $labels,
    'tag' => 'vote',
  );

  $form = drupal_get_form('fivestar_custom_widget', $values, $settings);
  $form = drupal_render($form);
  // This regex is sadly necessary because having duplicate form_tokens or
  // form_id elements can cause the content type form to choke. Forms inside of
  // forms is also frowned upon, so this removes the wrapping form tag as well.
  $form = str_replace(array('<form', '</form>'), array('<div', '</div>'), $form);
  $form = preg_replace('/( method=".*?")|( action=".*?")|(<input.*?name="(form_token|form_id|destination|form_build_id)".*?\/>)/', '', $form);
  return $form;
}

function theme_fivestar_preview_wrapper($variables) {
  return '<div class="fivestar-preview fivestar-preview-'. $variables['type'] .'">'. $variables['content'] .'</div>';
}

/**
 * Theme color form.
 */
function theme_fivestar_color_form($variables) {
  $form = $variables['form'];
  if (isset($form['#access']) && $form['#access'] == FALSE) {
    return '';
  }

  // Add Farbtastic color picker.
  drupal_add_js(drupal_get_path('module', 'fivestar') .'/js/fivestar-color.js');
  drupal_add_library('system', 'farbtastic');

  // Add custom CSS/JS.
  $default_colors = array();
  foreach (element_children($form['fivestar_colors']) as $key) {
    $default_colors[$key] = $form['fivestar_colors'][$key]['#value'];
  }

  drupal_add_js(array('fivestar' => array('reference' => $default_colors, 'transparent' => t('none'), 'colorPreview' => url('fivestar/preview/color'))), 'setting');

  $output = '';

  // Wrapper.
  $output .= '<div class="color-form clearfix">';

  // Color schemes.
  $output .= drupal_render($form['fivestar_color_type']);
  $output .= drupal_render($form['scheme']);

  // Palette.
  $output .= '<div id="fivestar-palette" class="clearfix">';
  foreach (element_children($form['fivestar_colors']) as $key => $name) {
    // Render pairs on a single line inside a new form element.
    if (strpos($name, '1')) {
      $name2 = str_replace('1', '2', $name);
      $title = $form['fivestar_colors'][$name]['#title'];
      unset($form['fivestar_colors'][$name]['#title']);
      $element = array(
        '#type' => 'item',
        '#title' => $title,
        '#title_display' => 'before',
        '#children' => drupal_render($form['fivestar_colors'][$name]) . drupal_render($form['fivestar_colors'][$name2]),
      );
      $output .= theme('form_element', array('element' => $element));
    }
    $output .= drupal_render($form['fivestar_colors'][$name]);
  }
  $output .= '</div>';

  // Render the form.
  $output .= drupal_render_children($form);
  // Close wrapper.
  $output .= '</div>';

  return $output;
}

/**
 * Theme function for 'default' fivestar field formatter.
 */
function theme_fivestar_formatter_default($variables) {
  $element = $variables['element'];
  if (!isset($element['#item'][0]['rating'])) {
    $element['#item'][0]['rating'] = 0;
  }
  if (empty($element['#instance_settings']['stars'])) {
    $element['#instance_settings']['stars'] = 5;
  }

  return theme('fivestar_static', array('rating' => $element['#item'][0]['rating'], 'stars' => $element['#instance_settings']['stars']));
}

/**
 * Theme function for 'rating' fivestar field formatter.
 */
function theme_fivestar_formatter_rating($variables) {
  $element = $variables['element'];

  if (!isset($element['#item'][0]['rating'])) {
    $element['#item'][0]['rating'] = 0;
  }

  return $element['#item'][0]['rating'];
}

/**
 * Theme function for 'percentage' fivestar field formatter.
 */
function theme_fivestar_formatter_percentage($variables) {
  $element = $variables['element'];

  if (empty($element['#item'][0]['rating'])) {
    $element['#item'][0]['rating'] = 0;
  }
  if (empty($element['#instance_settings']['stars'])) {
    $element['#instance_settings']['stars'] = 5;
  }

  return round(100/$element['#item'][0]['rating'], 1)/$element['#instance_settings']['stars'];
}

/**
 * Theme the fivestar form element by adding necessary css and javascript.
 */
function theme_fivestar($variables) {
  $element = $variables['element'];
  if (empty($element['#description'])) {
    if ($element['#feedback_enable']) {
      $element['#description'] = '<div class="fivestar-summary fivestar-feedback-enabled">&nbsp;</div>';
    }
    elseif ($element['#labels_enable']) {
      $element['#description'] = '<div class="fivestar-summary">&nbsp;</div>';
    }
  }

  return theme('form_element', array('element' => $element));
}

/**
 * Theme the straight HTML version of the fivestar select list. This is used
 * to remove the wrapping 'form-item' div from the select list.
 */
function theme_fivestar_select($variables) {
  $element = $variables['element'];
  element_set_attributes($element, array('id', 'name', 'size'));
  _form_set_class($element, array('form-select'));
  return '<select' . drupal_attributes($element['#attributes']) . '>' . form_select_options($element) . '</select>';
}
/**
 * Theme an entire fivestar widget, including the submit button and the normal
 * fivestar widget themed in the theme_fivestar() function.
 */
function theme_fivestar_widget($variables) {
  $form = $variables['form'];
  // Only print out the summary if text is being displayed or using rollover text.
  if (empty($form['vote']['#description']) && strpos($form['vote']['#prefix'], 'fivestar-labels-hover') === FALSE) {
    unset($form['vote']['#description']);
  }

  $class = 'fivestar-form';
  $class .= '-'. (isset($form['vote']['#tag']) ? $form['vote']['#tag'] : 'vote');
  $class .= '-'. (isset($form['content_id']['#value']) ? $form['content_id']['#value'] : 0);

  $output  = '';
  $output .= '<div class="'. $class .' clearfix">';
  $output .= drupal_render_children($form);
  $output .= '</div>';
  return $output;
}

/**
 * Display a plain HTML view-only version of the widget with a specified rating.
 *
 * @param $rating
 *   The desired rating to display out of 100 (i.e. 80 is 4 out of 5 stars).
 * @param $stars
 *   The total number of stars this rating is out of.
 * @param $tag
 *   Allows multiple ratings per node.
 * @return
 *   A themed HTML string representing the star widget.
 */
function theme_fivestar_static($variables) {
  $rating  = $variables['rating'];
  $stars = $variables['stars'];
  $tag = $variables['tag'];
  $output = '';
  $output .= '<div class="fivestar-widget-static fivestar-widget-static-'. $tag .' fivestar-widget-static-'. $stars .' clearfix">';
  if (empty($stars)) {
    $stars = 5;
  }
  $numeric_rating = $rating/(100/$stars);
  for ($n=1; $n <= $stars; $n++) {
    $star_value = ceil((100/$stars) * $n);
    $prev_star_value = ceil((100/$stars) * ($n-1));
    $zebra = ($n % 2 == 0) ? 'even' : 'odd';
    $first = $n == 1 ? ' star-first' : '';
    $last = $n == $stars ? ' star-last' : '';
    $output .= '<div class="star star-'. $n .' star-'. $zebra . $first . $last .'">';
    if ($rating < $star_value && $rating > $prev_star_value) {
      $percent = (($rating - $prev_star_value) / ($star_value - $prev_star_value)) * 100;
      $output .= '<span class="on" style="width: '. $percent .'%">';
    }
    elseif ($rating >= $star_value) {
      $output .= '<span class="on">';
    }
    else {
      $output .= '<span class="off">';
    }
    if ($n == 1)$output .= $numeric_rating;
    $output .= '</span></div>';
  }
  $output .= '</div>';
  return $output;
}

/**
 * Display the text associated with a static star display.
 *
 * Note that passing in explicit data types is extremely important when using
 * this function. A NULL value will exclude the value entirely from display,
 * while a 0 value indicates that the text should be shown but it has no value
 * yet.
 *
 * All ratings are from 0 to 100.
 *
 * @param $user_rating
 *   The current user's rating.
 * @param $average
 *   The average rating.
 * @param $votes
 *   The total number of votes.
 * @param $stars
 *   The number of stars being displayed.
 * @param $feedback
 *   A toggle that enables AJAX indicator message when a vote is being saved.
 * @return
 *   A themed HTML string representing the star widget.
 */
function theme_fivestar_summary($variables) {
  extract($variables, EXTR_SKIP);
  $output = '';
  $div_class = '';
  if (isset($user_rating)) {
    $div_class = isset($votes) ? 'user-count' : 'user';
    $user_stars = round(($user_rating * $stars) / 100, 1);
    $output .= '<span class="user-rating">'. t('Your rating: <span>!stars</span>', array('!stars' => $user_rating ? $user_stars : t('None'))) .'</span>';
  }
  if (isset($user_rating) && isset($average_rating)) {
    $output .= ' ';
  }
  if (isset($average_rating)) {
    $div_class = isset($votes) ? 'average-count' : 'average';
    $average_stars = round(($average_rating * $stars) / 100, 1);
    $output .= '<span class="average-rating">'. t('Average: <span>!stars</span>', array('!stars' => $average_stars)) .'</span>';
  }
  if (isset($user_rating) && isset($average_rating)) {
    $div_class = 'combo';
  }

  if (isset($votes) && !(isset($user_rating) || isset($average_rating))) {
    $output .= ' <span class="total-votes">'. format_plural($votes, '<span>@count</span> vote', '<span>@count</span> votes') .'</span>';
    $div_class = 'count';
  }
  elseif (isset($votes)) {
    $output .= ' <span class="total-votes">('. format_plural($votes, '<span>@count</span> vote', '<span>@count</span> votes') .')</span>';
  }

  if ($votes === 0) {
    $output = '<span class="empty">'. t('No votes yet') .'</span>';
  }

  $output = '<div class="fivestar-summary fivestar-summary-'. $div_class . ($feedback_enable ? ' fivestar-feedback-enabled' : '') .'">'. $output .'</div>';
  return $output;
}

/**
 * Display a static fivestar value as stars with a title and description.
 */
function theme_fivestar_static_element($variables) {
  $output = '';
  $output .= '<div class="fivestar-static-form-item">';
  $element = array(
    '#type' => 'item',
    '#title' => $variables['title'],
    '#description' => $variables['description'],
    '#children' => $variables['star_display'],
  );

  $output .= theme('form_element', array('element' => $element));
  $output .= '</div>';
  return $output;
}
