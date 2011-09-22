<?php

/**
 * @file
 * CCK Field for United Kingdom phone numbers.
 */

function _uk_phone_rules() {
  // TODO: more detailed check by area codes
  $regex = '/^
      ([0]*)(2[03489])(\d{4})(\d{4})  # 02x [eight-digit local number]
      |
      ([0]*)(11[3-8])(\d{3})(\d{4})   # 011x [seven-digit local number]
      |
      ([0]*)(1[2-9]1)(\d{3})(\d{4})   # 01x1 [seven-digit local number]
      |
      ([0]*)(1[2-9][0|2-9]\d)(\d{5,6})   # 01xxx [mostly six-digit local numbers] (but not 01x1 codes)
    $/x';

  return $regex;
}

/**
 * Validate country level phone number.
 *
 * @param $number
 *   Digits only value.
 * @param $ext
 *   Digits only value.
 * @param $error
 *   The error message to shown to user.
 *   Available parameters to use in the error message are
 *   - "%countrycode": the alpha-2 CC
 *   - "%phone_input": the original number input by user (could be invalid)
 *   - "%max_length": allowed maximum length of the phone number
 * @return boolean
 *   TRUE if it is a valid phone number for that country, FALSE otherwise.
 */
function gb_validate_number($number, $ext = '', &$error) {
  // We don't want to worry about separators
  $number = cck_phone_clean_number($number);

  if (preg_match(_uk_phone_rules(), $number)) {
    return TRUE;
  }

  // t() is no needed
  $error = '"%phone_input" is not a valid United Kingdom phone number, it should be 10 digits number like "99 9999 9999", with optional leading "0"';
  return FALSE;
}

/**
 * Cleanup user-entered values for a phone number field for saving to DB.
 *
 * @param $number
 *   A single phone number item.
 */
function gb_sanitize_number(&$number) {
  // Remove trunk prefix '0'
  $number = preg_replace('/^([0]*)/', '', $number);
}

/**
 * Default formatter for international phone number.
 *
 * @param $element
 *   $element['#item']['country_codes']: alpha-2 country code
 *   $element['#item']['number']: phone number
 * @param $error
 *   The error message to shown to user.
 *   Available parameters to use in the error message are
 *   - "%countrycode": the alpha-2 CC
 *   - "%phone_input": the original number input by user (could be invalid)
 *   - "%max_length": allowed maximum length of the phone number
 * @return boolean
 *   TRUE if it is a valid phone number for that country, FALSE otherwise.
 */
function gb_formatter_default($element) {
  $item = $element['#item'];

  // Display a global phone number with country code.
  $cc = cck_phone_countrycodes($item['country_codes']);

  $result = preg_match(_uk_phone_rules(), $item['number'], $matches);

  if ($result) {
    // output as +44 AA BBBB CCCC, +44 AAA BBB CCCC or +44 AAAA BBB CCC
    $phone =  $cc['code'] . $matches[1] . '-' . $matches[2] . ' ' . $matches[3];
  }

  return $phone;
}


/**
 * Local formatter for local phone number.
 *
 * @param $element
 *   $element['#item']['country_codes']: alpha-2 country code
 *   $element['#item']['number']: phone number
 * @param $error
 *   The error message to shown to user.
 *   Available parameters to use in the error message are
 *   - "%countrycode": the alpha-2 CC
 *   - "%phone_input": the original number input by user (could be invalid)
 *   - "%max_length": allowed maximum length of the phone number
 * @return boolean
 *   TRUE if it is a valid phone number for that country, FALSE otherwise.
 */
function gb_formatter_local($element) {
  // Display a local phone number without country code.
  $result = preg_match(_uk_phone_rules(), $item['number'], $matches);

  if ($result) {
    // output as 0AA BBBB CCCC,  0AAA BBB CCCC or 0AAAA BBB CCC
    $phone =  '0' . $matches[1] . '-' . $matches[2] . ' ' . $matches[3];
  }

  return $phone;
}
