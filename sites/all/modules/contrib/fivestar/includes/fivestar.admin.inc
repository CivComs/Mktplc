<?php

/**
 * @file
 * Configuration pages for Fivestar module.
 */

/**
 * Callback function for admin/settings/fivestar. Display the settings form.
 */
function fivestar_settings($form, $form_state) {
  module_load_include('inc', 'fivestar', 'includes/fivestar.color');

  $form['widget'] = array(
    '#tree' => FALSE,
    '#type' => 'fieldset',
    '#title' => t('Widget display'),
    '#description' => t('Choose a widget set to be used on your site. Widgets supporting custom colors can be further customized by adjusting the color scheme.'),
    '#weight' => -2,
  );

  $widgets = module_invoke_all('fivestar_widgets');
  $classic_widgets = array();
  $color_widgets = array();
  foreach ($widgets as $path => $name) {
    $directory = dirname($path);
    $matches = file_scan_directory($directory, '/-template\./');
    if (empty($matches)) {
      $classic_widgets[$path] = $name;
    }
    else {
      $color_widgets[$path] = $name;
    }
  }

  // If using a color widget, set the default value to the original path.
  $default_value = variable_get('fivestar_widget', 'default');
  foreach ($color_widgets as $path => $name) {
    if (basename($path) == basename($default_value)) {
      $default_value = $path;
    }
  }

  $form['widget']['fivestar_widget'] = array(
    '#type' => 'radios',
    '#options' => array('default' => t('Default')) + $classic_widgets + $color_widgets,
    '#default_value' => $default_value,
    '#attributes' => array('class' => array('fivestar-widgets')),
  );

  $form['widget']['fivestar_color_widget'] = array(
    '#type' => 'radios',
    '#title' => t('Custom color widgets'),
    '#options' => $color_widgets,
    '#attributes' => array('class' => array('fivestar-widgets')),
  );

  $form['tags'] = array(
    '#tree' => FALSE,
    '#type' => 'fieldset',
    '#title' => t('Voting tags'),
    '#description' => t('Choose the voting tags that will be available for node rating. A tag is simply a category of vote. If you only need to rate one thing per node, leave this as the default "vote".'),
    '#weight' => 3,
   );

  $form['tags']['tags'] = array(
    '#type' => 'textfield',
    '#title' => t('Tags'),
    '#default_value' => variable_get('fivestar_tags', 'vote'),
    '#required' => TRUE,
    '#description' => t('Separate multiple tags with commas.'),
   );

  $form['color'] = fivestar_color_form();
  $form['#validate'][] = 'fivestar_color_form_validate';
  $form['#submit'][] = 'fivestar_color_form_submit';
  $form['#submit'][] ='fivestar_settings_submit';

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save configuration'),
    '#weight' => 45,
  );

  return $form;
}

function fivestar_settings_submit($form, &$form_state) {
  // TODO We could delete all variables for removed tags
  variable_set('fivestar_tags', $form_state['values']['tags']);
  variable_set('fivestar_widget', $form_state['values']['fivestar_widget']);

  // Rebuild the menu in case tags were changed
  menu_rebuild();
}
