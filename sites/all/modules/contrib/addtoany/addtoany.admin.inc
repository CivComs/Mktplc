<?php

/**
 * @file
 * Administration settings for AddToAny button integration
 */

/**
 * Administration settings form.
 *
 * @return
 *   The completed form definition.
 */
function addtoany_admin_settings() {
  $form = array();

  global $base_path;
  $button_img = '<img src="' . $base_path . drupal_get_path('module', 'addtoany') . '/images/%s" width="%d" height="%d" />';

  $button_options = array(
    'share_16_16.png|16|16'    => sprintf($button_img, 'share_16_16.png', 16, 16),
    'share_save_171_16.png|171|16' => sprintf($button_img, 'share_save_171_16.png', 171, 16),
    'share_save_256_24.png|256|24' => sprintf($button_img, 'share_save_256_24.png', 256, 24),
    'custom'        		=> 'Custom button',
	'text'					=> 'Text only',
  );

  $form['addtoany_general_settings'] = array(
    '#type'  => 'fieldset',
    '#title' => t('General'),
  );
  $form['addtoany_general_settings']['addtoany_nodetypes'] = array(
    '#type'          => 'checkboxes',
    '#title'         => t('Node types'),
    '#description'   => t('Display an AddToAny button for these node types.'),
    '#default_value' => variable_get('addtoany_nodetypes', array('page', 'article')),
    '#options'       => node_type_get_names(),
  );
  $form['addtoany_general_settings']['addtoany_display_in_teasers'] = array(
    '#type'          => 'checkbox',
    '#title'         => t('Display in node TEASERS'),
    '#default_value' => variable_get('addtoany_display_in_teasers', '1'),
    '#description'   => t('Display an AddToAny button in node teasers.'),
  );
  $form['addtoany_general_settings']['addtoany_display_in_nodelink'] = array(
    '#type'          => 'checkbox',
    '#title'         => t('Display in LINK section'),
    '#default_value' => variable_get('addtoany_display_in_nodelink', '1'),
    '#description'   => t('Display an AddToAny button in LINK section of node pages.'),
  );
  $form['addtoany_general_settings']['addtoany_display_in_nodecont'] = array(
    '#type'          => 'checkbox',
    '#title'         => t('Display in CONTENT section'),
    '#default_value' => variable_get('addtoany_display_in_nodecont', '0'),
    '#description'   => t('Display an AddToAny button in CONTENT section of node pages.'),
  );
  $form['addtoany_general_settings']['addtoany_display_weight'] = array(
    '#type'          => 'weight',
    '#title'         => t('Weight'),
    '#default_value' => variable_get('addtoany_display_weight', 40),
    '#delta'         => 50,
    '#description'   => t('Optional: WEIGHT value for AddToAny button displayed in CONTENT section'),
  );

  $form['addtoany_button_settings'] = array(
    '#type'         => 'fieldset',
    '#title'        => t('Button'),
    '#collapsible'  => TRUE,
    '#collapsed'    => FALSE,
  );
  $form['addtoany_button_settings']['addtoany_image'] = array(
    '#type'      => 'radios',
    '#title'      => t('Button'),
    '#default_value' => variable_get('addtoany_image', 'share_save_171_16.png|171|16'),
    '#options'      => $button_options,
  );
  $form['addtoany_button_settings']['addtoany_custom_image'] = array(
    '#type'          => 'textfield',
    '#title'         => t('Custom button URL'),
    '#default_value' => variable_get('addtoany_custom_image', ''),
    '#description'   => t('URL to the button image of your choosing. Example: http://example.com/share.png'),
  );
  $form['addtoany_button_settings']['addtoany_image_attributes'] = array(
    '#type'          => 'textfield',
    '#title'         => t('Button image HTML attributes'),
    '#default_value' => variable_get('addtoany_image_attributes', 'alt="Share/Save"'),
    '#description'   => t('Extra HTML attributes for img tag. Example: alt=""'),
  );
  $form['addtoany_button_settings']['addtoany_link_text'] = array(
    '#type'          => 'textfield',
    '#title'         => t('Link text'),
    '#default_value' => variable_get('addtoany_link_text', ''),
    '#description'   => t('Text for the AddToAny button link. Example: Share'),
  );

  $form['addtoany_additional_settings'] = array(
    '#type'         => 'fieldset',
    '#title'        => t('Additional options'),
    '#collapsible'  => TRUE,
    '#collapsed'    => TRUE,
  );
  $form['addtoany_additional_settings']['addtoany_additional_js'] = array(
    '#type'          => 'textarea',
    '#title'         => t('Additional script'),
    '#default_value' => variable_get('addtoany_additional_js', ''),
    '#description'   => t('You can set special JavaScript variables for each Share/Save menu. Advanced users might want to check out AddToAny\'s <a href="http://www.addtoany.com/buttons/api/">JavaScript API</a> and <a href="http://www.addtoany.com/buttons/customize/">documentation</a>.'),
  );

  $form['addtoany_widget_settings'] = array(
    '#type'         => 'fieldset',
    '#title'        => t('Drop-down menu'),
    '#collapsible'  => TRUE,
    '#collapsed'    => TRUE,
  );
  $form['addtoany_widget_settings']['addtoany_dropdown_disabled'] = array(
    '#type'          => 'checkbox',
    '#title'         => t('Disable dropdown'),
    '#default_value' => variable_get('addtoany_dropdown_disabled', '0'),
    '#description'   => t('You can disable the drop-down for selecting where to share your link and use a pop-up window instead.'),
  );

  return system_settings_form($form);
}
