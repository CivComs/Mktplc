<?php

/**
 * @file
 * File containing functions relating to the color widget.
 */

/**
 * Menu callback function for fivestar/preview/color.
 *
 * Outputs a dynamically generated star or cancel png.
 */
function fivestar_preview_color() {
  $args = func_get_args();
  // Remove query string if it gets passed in as argument.
  $filename = preg_replace('/\?.*$/', '', array_pop($args));
  $type = array_pop($args);
  $widget = array_pop($args);

  // Convert args to our color scheme.
  $color_scheme = array(
    'on1' => $args[0],
    'on2' => $args[1],
    'hover1' => $args[2],
    'hover2' => $args[3],
    'off1' => $args[4],
    'off2' => $args[5],
    'matte' => $args[6],
  );

  // Find the source location of the desired widget.
  $widgets = module_invoke_all('fivestar_widgets');
  foreach ($widgets as $key => $name) {
    if (drupal_strtolower($name) == $widget) {
      $source_directory = str_replace($widget .'.css', '', $key);
      break;
    }
  }

  // Generate the requested image and exit.
  $image = _fivestar_color_render($source_directory . str_replace('.png', '-template.png', $filename), $color_scheme, $type);
  drupal_add_http_header('Content-type', 'image/png');
  drupal_add_http_header('Expires', gmdate("D, d M Y H:i:s", time() + 300) ." GMT");
  drupal_add_http_header('Last-Modified', gmdate("D, d M Y H:i:s") ." GMT");
  drupal_add_http_header('Cache-Control', 'max-age=300');
  imagepng($image);
  exit();
}

/**
 * Form callback. Returns the configuration form.
 */
function fivestar_color_form() {
  $form = array(
    '#tree' => FALSE,
    '#theme' => 'fivestar_color_form',
    '#type' => 'fieldset',
    '#title' => t('Color scheme'),
    '#weight' => -1,
    '#attributes' => array('id' => 'fivestar_color_scheme_form'),
    '#description' => t('A custom color widget must be selected to choose colors. Only the selected widget will be previewed.'),
  );

  $disabled = FALSE;
  if(variable_get('file_default_scheme','public') != 'public' || !is_dir(variable_get('file_public_path'))) {
    $disabled = TRUE;
    $form['#description'] = t('Custom colors are only supported when the <a href="!url">download method</a> is set to public and the "Public file system path" propery is filled.', array('!url' => url('admin/config/media/file-system')));
  }

  // Create the list of available schemes.
  $options = array(
    '#fff633,#f5d000,#d2e7f9,#027ac6,#cccccc,#dfdfdf' => t('Blue Lagoon (default)'),
    '#ffeb38,#fff385,#ffd60a,#ffe561,#8f8f8f,#e6e6e6' => t('Yellow'),
    '#ad0002,#ff5f61,#ff1a1f,#f3b3b4,#8f8f8f,#e6e6e6' => t('Red'),
    '#001efa,#bbc3fb,#1022c1,#2e41ee,#8f8f8f,#e6e6e6' => t('Blue'),
    '#015700,#7cf47c,#12c610,#c8f9c7,#8f8f8f,#e6e6e6' => t('Green'),
    '' => t('Custom'),
  );

  // See if we're using a predefined scheme.
  $palette = explode(',', array_search(t('Blue Lagoon (default)'), $options));
  $default_palette['on1'] = $palette[0];
  $default_palette['on2'] = $palette[1];
  $default_palette['hover1'] = $palette[2];
  $default_palette['hover2'] = $palette[3];
  $default_palette['off1'] = $palette[4];
  $default_palette['off2'] = $palette[5];
  $default_palette['matte'] = '#ffffff';

  $palette = variable_get('fivestar_colors', $default_palette);
  $scheme_default = implode(',', array_slice($palette, 0, count($palette) - 1));

  $form['fivestar_color_type'] = array(
    '#type' => 'select',
    '#title' => t('Color display'),
    '#options' => array('default' => t('Default display'), 'solid' => t('Solid color'), 'gradient' => t('Gradient')),
    '#default_value' => variable_get('fivestar_color_type', 'solid'),
    '#access' => !$disabled,
  );

  // Add scheme selector.
  $form['scheme'] = array(
    '#type' => 'select',
    '#title' => t('Color set'),
    '#options' => $options,
    '#default_value' => isset($options[$scheme_default]) ? $scheme_default : '',
    '#access' => !$disabled,
  );

  // Add palette fields.
  $names = array(
    'on1' => t('On colors'),
    'on2' => NULL,
    'hover1' => t('Hover colors'),
    'hover2' => NULL,
    'off1' => t('Off colors'),
    'off2' => NULL,
    'matte' => t('Matte color'),
  );

  $form['fivestar_colors'] = array(
    '#tree' => TRUE,
    '#access' => !$disabled,
  );
  foreach ($names as $key => $name) {
    $form['fivestar_colors'][$key] = array(
      '#type' => 'textfield',
      '#title' => $name,
      '#default_value' => $palette[$key],
      '#size' => 8,
    );
  }

  if ($disabled) {
    $form['fivestar_color_type']['#value'] = 'default';
  }

  return $form;
}

/**
 * Validate handler for color form.
 */
function fivestar_color_form_validate($form, &$form_state) {
  if ($form_state['values']['fivestar_color_type'] == 'default' || !isset($_POST['fivestar_color_type'])) {
    $form_state['values']['fivestar_color_type'] = 'default';
    return;
  }

  foreach ($form_state['values']['fivestar_colors'] as $key => $value) {
    $form_state['values']['fivestar_colors'][$key] = trim(drupal_strtolower($value));
    if (!preg_match('/^#([0-9a-f]{3}|[0-9a-f]{6})$/', $form_state['values']['fivestar_colors'][$key]) && !($key == 'matte' && ($value == 'none' || $value == ''))) {
      form_set_error('fivestar_colors]['. $key, t('The entered value %color is not a valid hex color.', array('%color' => $value)));
    }
  }
}

/**
 * Submit handler for color change form.
 */
function fivestar_color_form_submit($form, &$form_state) {
  if ($form_state['values']['fivestar_colors']['matte'] == t('none')) {
    $form_state['values']['fivestar_colors']['matte'] = '';
  }

  // Check if we're using a color-enabled set of stars.
  if (!array_key_exists($form_state['values']['fivestar_widget'], $form['widget']['fivestar_color_widget']['#options']) || $form_state['values']['fivestar_color_type'] == 'default') {
    return;
  }

  $widget = str_replace('.css', '', basename($form_state['values']['fivestar_widget']));
  $widget_css = $form_state['values']['fivestar_widget'];
  $widget_rtl_css = str_replace('.css', '-rtl.css', $widget_css);
  $upload_directory = variable_get('file_public_path') .'/fivestar';
  $widget_directory = $upload_directory .'/'. $widget;
  $current_widget = variable_get('fivestar_widget', 'default');

  // Delete the previous set of stars if any from the files directory.
  if (strpos($current_widget, $upload_directory) === 0) {
    $current_widget_directory = dirname($current_widget);
    file_scan_directory($current_widget_directory, '.*', array('.', '..', 'CVS'), 'unlink');
    rmdir($current_widget_directory);
  }

  // Check the destination directory.
  file_prepare_directory($upload_directory, FILE_CREATE_DIRECTORY);
  file_prepare_directory($widget_directory, FILE_CREATE_DIRECTORY);

  // Create the new stars.
  $star = _fivestar_color_render(str_replace($widget .'.css', 'star-template.png', $form_state['values']['fivestar_widget']), $form_state['values']['fivestar_colors'], $form_state['values']['fivestar_color_type']);
  $cancel = _fivestar_color_render(str_replace($widget .'.css', 'cancel-template.png', $form_state['values']['fivestar_widget']), $form_state['values']['fivestar_colors'], $form_state['values']['fivestar_color_type']);
  imagepng($star, $widget_directory .'/star.png');
  imagepng($cancel, $widget_directory .'/cancel.png');

  // Copy over the stylesheet.
  file_unmanaged_copy($widget_css, $widget_directory .'/'. $widget .'.css', FILE_EXISTS_REPLACE);

  // Copy over RTL stylesheet.
  if (file_exists($widget_rtl_css)) {
    file_unmanaged_copy($widget_rtl_css, $widget_directory .'/'. $widget .'-rtl.css', FILE_EXISTS_REPLACE);
  }

  $form_state['values']['fivestar_widget'] = $widget_css;

  variable_set('fivestar_colors', $form_state['values']['fivestar_colors']);
  variable_set('fivestar_color_type', $form_state['values']['fivestar_color_type']);

  drupal_clear_css_cache();
  drupal_set_message(t('Custom %name stars generated. You may need to clear your browser cache before the new stars are visible.', array('%name' => t($widget))));
}

/**
 * Render images that match a given palette.
 *
 * @param $source
 *   The original image source (star-template.png or cancel-template.png).
 * @param $palette
 *   The colors to be used in the generation of this image.
 * @param $type
 *   The type of color to be rendered: solid or gradient.
 */
function _fivestar_color_render($source, $palette, $type) {

  // Pull in the template image.
  $template = imagecreatefrompng($source);
  imagealphablending($template, TRUE);
  $width = imagesx($template) / 2;
  $height = imagesy($template);

  // Create a true color mask image from the left side of the template.
  $mask = imagecreatetruecolor($width, $height);
  $transparent = imagecolorallocatealpha($mask, 0, 0, 0, 127);
  imagefill($mask, 0, 0, $transparent);
  imagecopy($mask, $template, 0, 0, 0, 0, $width, $height);

  // Create a true color overlay image from the right side of the template.
  $overlay = imagecreatetruecolor($width, $height);
  $transparent = imagecolorallocatealpha($overlay, 0, 0, 0, 127);
  imagefill($overlay, 0, 0, $transparent);
  imagecopy($overlay, $template, 0, 0, $width, 0, $width, $height);

  // No need for the template image any more.
  imagedestroy($template);

  // Apply the selected colors to the mask.
  $slices = (basename($source) == 'star-template.png') ? 3 : 2;
  $slice_height = floor($height / $slices);
  foreach ($slices == 2 ? array('off', 'hover') : array('off', 'on', 'hover') as $slice => $key) {
    $slice_y = $slice_height * $slice;
    if ($type == 'gradient') {
      _fivestar_color_mask_linear_gradient($mask, $palette[$key .'1'], $palette[$key .'2'], $palette['matte'], 0, $slice_y, $width, $slice_height);
    }
    else {
      _fivestar_color_mask($mask, $palette[$key .'1'], $palette['matte'], 0, $slice_y, $width, $slice_height);
    }
  }

  // Apply the overlay on top of the mask.
  imagealphablending($mask, TRUE);
  imagecopy($mask, $overlay, 0, 0, 0, 0, $width, $height);
  imagedestroy($overlay);

  // Set the background color.
  if ($palette['matte'] == 'transparent') {
    // A simple case, just make this save as a 24-bit PNG.
    imagesavealpha($mask, TRUE);
    $return = $mask;
  }
  else {
    // If there is a matte, create a new 8-bit image, fill with the matte,
    // apply the star over the top, then set the matte to transparent.
    $return = imagecreatetruecolor($width, $height);
    $matte_rgb = _fivestar_color_unpack($palette['matte']);
    $transparent = imagecolorallocate($return, $matte_rgb[0], $matte_rgb[1], $matte_rgb[2]);
    imagefill($return, 0, 0, $transparent);
    imagealphablending($return, TRUE);
    imagecopy($return, $mask, 0, 0, 0, 0, $width, $height);
    imagecolortransparent($return, $transparent);
    imagetruecolortopalette($return, TRUE, 255);
  }

  return $return;
}

/**
 * Apply a color to a portion of a black and white mask image.
 *
 * @param $mask
 *   A GD image reference containing the mask image.
 * @param $color
 *   A hex color value (i.e. ffdd00) to apply to the mask.
 */
function _fivestar_color_mask(&$mask, $color, $matte_color, $x_offset, $y_offset, $width, $height) {
  $rgb = _fivestar_color_unpack($color);
  for ($x = $x_offset; $x < $x_offset + $width; $x++) {
    for ($y = $y_offset; $y < $y_offset + $height; $y++) {
      $current_pixel = imagecolorsforindex($mask, imagecolorat($mask, $x, $y));
      $new_color = imagecolorallocatealpha($mask, $rgb[0], $rgb[1], $rgb[2], $current_pixel['alpha']);
      // Matte coloring:
      if ($matte_color != 'transparent' && $current_pixel['alpha'] != 127) {
        $matte_rgb = _fivestar_color_unpack($matte_color);
        $matte = imagecolorallocate($mask, $matte_rgb[0], $matte_rgb[1], $matte_rgb[2]);
        imagealphablending($mask, FALSE);
        imagesetpixel($mask, $x, $y, $matte);
        imagealphablending($mask, TRUE);
        imagesetpixel($mask, $x, $y, $new_color);
      }
      // Transparent matte:
      else {
        imagealphablending($mask, FALSE);
        imagesetpixel($mask, $x, $y, $new_color);
        imagealphablending($mask, TRUE);
      }
    }
  }
}

/**
 * Apply a gradient to a portion of a black and white mask image.
 *
 * The two colors passed in will form a linear gradient from top to bottom.
 *
 * @param $mask
 *   A GD image reference containing the mask image.
 * @param $color1
 *   The color used at the top of the linear gradient.
 * @param $color2
 *   The color used at the bottom of the linear gradient.
 */
function _fivestar_color_mask_linear_gradient(&$mask, $color1, $color2, $matte_color, $x_offset, $y_offset, $width, $height) {
  for ($y = $y_offset; $y < $y_offset + $height; $y++) {
    $color = _fivestar_color_blend($color1, $color2, ($y - $y_offset) / $height);
    _fivestar_color_mask($mask, $color, $matte_color, 0, $y, $width, 1);
  }
}

/**
 * Blend two hex colors and return the resulting hex color.
 */
function _fivestar_color_blend($hex1, $hex2, $alpha) {
  $in1 = _fivestar_color_unpack($hex1);
  $in2 = _fivestar_color_unpack($hex2);
  for ($i = 0; $i < 3; ++$i) {
    $out[] = $in1[$i] + ($in2[$i] - $in1[$i]) * $alpha;
  }
  return _fivestar_color_pack($out);
}

/**
 * Convert a hex color into an RGB triplet.
 */
function _fivestar_color_unpack($hex, $normalize = FALSE) {
  if (strlen($hex) == 4) {
    $hex = $hex[1] . $hex[1] . $hex[2] . $hex[2] . $hex[3] . $hex[3];
  }
  $c = hexdec($hex);
  for ($i = 16; $i >= 0; $i -= 8) {
    $out[] = (($c >> $i) & 0xFF) / ($normalize ? 255 : 1);
  }
  return $out;
}

/**
 * Convert an RGB triplet to a hex color.
 */
function _fivestar_color_pack($rgb, $normalize = FALSE) {
  $out = 0;
  foreach ($rgb as $k => $v) {
    $out |= (($v * ($normalize ? 255 : 1)) << (16 - $k * 8));
  }
  return '#'. str_pad(dechex($out), 6, 0, STR_PAD_LEFT);
}
