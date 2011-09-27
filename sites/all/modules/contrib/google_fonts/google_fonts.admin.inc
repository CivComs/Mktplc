<?php

/**
 * @file
 * Administrative page callbacks for the Google Fonts module.
 */

/**
 * Implements hook_admin_settings() for configuring the module
 */
function google_fonts_admin_settings_form($form, &$form_state) {
  
  drupal_add_css(drupal_get_path('module', 'google_fonts') . '/google_fonts.admin.css');
  
  $form = array(
    '#attributes' => array('class' => array('google_fonts_admin_form')),
  );
  $form['introduction'] = array(
    '#markup' => '<p>' . t('Select the fonts that you want to be available on your website. Keep in mind that each font takes some time to download. For the best performance, only enable fonts that you are actually using on your website. More information about these fonts is available on the <a href="!link">Google font directory</a>.', array('!link' => 'http://code.google.com/webfonts')) . '</p>',
  );
  
  $all_fonts = _google_fonts_available_fonts();

  $form_options = array('enabled' => array(), 'disabled' => array());
  $enabled_fonts = variable_get('google_fonts_enabled_fonts', array());
  
  /* Load all fonts in CSS to display their example */
  $style_to_add = '';
  $fonts_to_load = array();
  foreach ($all_fonts as $font) {
    
    if (isset($font->family)) {
      $current_font_path = _google_fonts_family_pathname($font->family);
      $current_array_key = _google_fonts_family_array_key_encode($font->family);
      $style_to_add .= '.' . $current_array_key . '{ font-family: "' . $font->family . '"; } ' . PHP_EOL;
      $fonts_to_load[] = $current_font_path;
      
      if (!empty($enabled_fonts[$current_array_key])) {
        $form_options['enabled'][] = $font;
      }
      else {
        $form_options['disabled'][$current_array_key] = _google_fonts_admin_font_example($font);
      }
    }
    
  }
  _google_fonts_load_css($fonts_to_load);
  drupal_add_css($style_to_add, 'inline');

  /* Check if there are any enabled fonts, otherwise don't create the fieldset and display a message*/
  if (!empty($form_options['enabled'])) {
    
    $form['google_fonts_fieldset_enabled_fonts'] = array(
      '#type' => 'fieldset',
      '#title' => t('Enabled Google Fonts'),
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
      '#attributes' => array('class' => array('enabled_fonts')),
    );
    $form['google_fonts_fieldset_enabled_fonts']['enabled_fonts'] = array(
      '#type' => 'value',
      '#value' => $form_options['enabled'],
    );

    foreach ($form_options['enabled'] as $font) {  
      
      $key = _google_fonts_family_array_key_encode($font->family);

      if (isset($enabled_fonts[$key]['variants'])) {
        $enabled_fonts[$key]['variants'] = _google_fonts_admin_array_values($enabled_fonts[$key]['variants']);
      }
      elseif (array_search('general', $font->variants)) {
        $enabled_fonts[$key]['variants'] = array('general', 'general');
      }
      elseif (array_search('400', $font->variants)) {
        // a weight of 400 is usally the default when there is no general
        $enabled_fonts[$key]['variants'] = array('400', '400');
      }
      else {
        // Get the first variant (array_shift) to be selected as default
        $enabled_fonts[$key]['variants'] = array(array_shift(_google_fonts_admin_array_values($font->variants)));
      }

      $enabled_fonts[$key]['subsets'] = isset($enabled_fonts[$key]['subsets']) ? (array) $enabled_fonts[$key]['subsets'] : array(key(_google_fonts_admin_array_values($font->subsets)));

      $form['google_fonts_fieldset_enabled_fonts'][$key] = array(
        
        '#type' => 'fieldset',
        '#title' => check_plain($font->family),
        '#collapsible' => FALSE,
        '#collapsed' => FALSE,
        '#description' => _google_fonts_admin_font_example($font, FALSE),
        
        $key . '_variants' => array(
          '#type' => 'checkboxes', 
          '#options' => _google_fonts_format_variants(_google_fonts_admin_array_values($font->variants)),
          '#title' => t('Variants'),
          '#required' => TRUE,
          '#default_value' => $enabled_fonts[$key]['variants'],
        ),
        
        $key . '_subsets' => array(
          '#type' => 'checkboxes', 
          '#options' => _google_fonts_format_subsets(_google_fonts_admin_array_values($font->subsets)),
          '#title' => t('Subsets'),
          '#required' => TRUE,
          '#default_value' => $enabled_fonts[$key]['subsets'],
        ),
        
        $key . '_enabler' => array(
          '#type' => 'checkbox', 
          '#title' => t('Disable this font'),
          '#default_value' => FALSE,
        ),
      );
    }
    
    // Fetch the first family name (using array_shift) to include it in the example CSS code
    $first_family = $form_options['enabled'][array_shift(array_keys($form_options['enabled']))]->family;
    $form['google_fonts_fieldset_enabled_fonts']['css_code'] = array(
      '#type' => 'textarea',
      '#title' => t('CSS code'),
      '#description' => t('The module applies CSS code for you automatically if you add it here.<br />This could be useful if you don\'t use a custom theme or if you don\'t have access to it.<br />Example: !code', array('!code' => '<code>#site-name { font-family: "' . $first_family . '"; font-size: 3em; }</code>')),
      '#resizable' => FALSE,
      '#cols' => 80,
      '#default_value' => variable_get('google_fonts_css_contents', ''),
    );
  }
  elseif (!empty($all_fonts)) {
    drupal_set_message(t('No Google Fonts have been enabled yet. Please enable one or more Google Fonts below.'), 'status');
  }
  
  // Check if there are any available fonts that have not been enabled yet
  // otherwise don't create the fieldset but display a message
  if (!empty($form_options['disabled'])) {
    $form['google_fonts_fieldset_disabled_fonts'] = array(
      '#type' => 'fieldset',
      '#title' => t('Available Google Fonts'),
      '#description' => t('This list of available fonts is fetched once and then cached locally. To retrieve the newest fonts, you can <a href="@link">update this list</a>.', array('@link' => url('admin/config/system/google_fonts/update'))),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
      '#attributes' => array('class' => array('disabled_fonts')),
    );  
    
    $form['google_fonts_fieldset_disabled_fonts']['google_fonts_disabled_fonts'] = array(
      '#type' => 'checkboxes',
      '#default_value' => array(),
      '#options' => $form_options['disabled'],
    );
  }
  elseif (!empty($all_fonts)) {
    drupal_set_message(t('All available Google Fonts have been enabled.'), 'status');
  }
  
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save configuration'),
    '#weight' => 5,
  );
  
  return $form;
}

/**
 * Submit handler of the admin settings form
 * Saves the fonts, CSS code and settings
 */
function google_fonts_admin_settings_form_submit($form, &$form_state) {
  $enabled_fonts = array();

  if (isset($form_state['values']['enabled_fonts'])) {
    foreach ($form_state['values']['enabled_fonts'] as $key => $font) {
      $font_key = _google_fonts_family_array_key_encode($font->family);
      
      // Strip out unchecked font variants
      foreach ($form_state['values'][$font_key . '_variants'] as $variant_key => $variant) {
        if (!$variant) {
          unset($form_state['values'][$font_key . '_variants'][$variant_key]);
        }
      }
      
      // Only add the font if the enabler checkbox is not checked
      if (!$form_state['values'][$font_key . '_enabler']) {
        $enabled_fonts[$font_key] = array(
          'family' => $font->family,
          'variants' => $form_state['values'][$font_key . '_variants'],
          'subsets' => $form_state['values'][$font_key . '_subsets'],
        );
      }
    }
  }
  
  foreach ($form_state['values']['google_fonts_disabled_fonts'] as $key => $font) {
    if (!empty($font)) {
      $enabled_fonts[$key] = array('family' => $font);
    }
  }

  // Save the font settings to the database
  variable_set('google_fonts_enabled_fonts', $enabled_fonts);
  
  // Save the CSS code. If left empty, just delete the existing variable
  if (empty($form_state['values']['css_code'])) {
    variable_del('google_fonts_css_contents');
  }
  else {
    variable_set('google_fonts_css_contents', $form_state['values']['css_code']);
    
    // Save the CSS code as local file
    if (!_google_fonts_cache($form_state['values']['css_code'], TRUE)) {
      drupal_set_message(t('Could not generate the CSS code for the Google Fonts.'), 'error');
    }
  }
  // Clear the current messages (to prevent an unneeded 'No Google Fonts have been enabled' message)
  drupal_get_messages('status');
  drupal_set_message(t('Configuration saved'), 'status');
}

/** 
 * Returns the font family name, including a span with added styling
 */
function _google_fonts_admin_font_example($font, $display_with_icons = TRUE) {
  $module_path = base_path() . drupal_get_path('module', 'google_fonts');
  $class_name = _google_fonts_family_array_key_encode($font->family);
  $example = '<span class="' . $class_name . ' font_example">' . $font->family . '</span>';
  
  if ($display_with_icons && isset($font->subsets)) {
    
    // Add the subset icons
    $example .= '<span class="subsets">';
    foreach ($font->subsets as $subset) {
      switch ($subset) {
        /* To prevent double icons, we can ignore the extended subsets */
        case 'cyrillic-ext':
        case 'greek-ext':
        case 'latin-ext':
        case 'khmer-ext':
          break;
          
        case 'cyrillic':
          $example .= '<img src="' . $module_path . '/icons/cyrillic.png" alt="Cyrillic" title="' . t('Available for the @subset character range', array('@subset' => 'cyrillic')) . '" />';
          break;
          
        case 'greek':
          $example .= '<img src="' . $module_path . '/icons/greek.png" alt="Greek" title="' . t('Available for the @subset character range', array('@subset' => 'greek')) . '" />';
          break;
        
        case 'khmer':
          $example .= '<img src="' . $module_path . '/icons/khmer.png" alt="Khmer" title="' . t('Available for the @subset character range', array('@subset' => 'khmer')) . '" />';
          break;
        
        case 'vietnamese':
          $example .= '<img src="' . $module_path . '/icons/vietnamese.png" alt="Vietnamese" title="' . t('Available for the @subset character range', array('@subset' => 'vietnamese')) . '" />';
          break;
        
        default:
          $example .= '<img src="' . $module_path . '/icons/latin.png" alt="Latin" title="' . t('Available for the @subset character range', array('@subset' => 'latin')) . '" />';
          break;
      }
    }
    $example .= '</span>';
    
    // Add variant descriptions
    if (sizeof($font->variants) > 1) {
      $example .= '<span class="variants">' . t('<span>@count</span> variants (@variants)', array('@count' => sizeof($font->variants), '@variants' => implode(', ', _google_fonts_format_variants($font->variants)))) . '</span>';
    }
  }
  
  return $example;
}

/** 
 * Return an array with the same keys as values
 */
function _google_fonts_admin_array_values($array_in) {
  $array_out = array();
  foreach ($array_in as $value) {
    $array_out[$value] = $value;
  }
  return $array_out;
}

/** 
 * Return an array with formatted variants (eg: change bolditalic into Bold/Italic)
 */
function _google_fonts_format_variants($variants) {
  foreach ($variants as $key => $variant) {
    switch ($variant) {
      case 'bolditalic':
        $variants[$key] = 'Bold/Italic';
        break;
      default:
        $variants[$key] = ucfirst(check_plain($variant));
    }
  }
  return $variants;
}

/** 
 * Return an array with formatted subsets (eg: change latin-ext into Latin extended)
 */
function _google_fonts_format_subsets($subsets) {
  foreach ($subsets as $key => $subset) {
    $subsets[$key] = ucfirst(str_replace('-ext', ' extended', check_plain($subset)));
  }
  return $subsets;
}