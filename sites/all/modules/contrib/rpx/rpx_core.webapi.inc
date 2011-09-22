<?php

/**
 * @file
 *
 * Engage web API for Drupal.
 *
 * @see http://rpxnow.com/docs
 */

class RPX {
  const lookup_api = 'https://rpxnow.com/plugin/lookup_rp';
  const auth_api = 'https://rpxnow.com/api/v2/auth_info';
  const map_api = 'https://rpxnow.com/api/v2/map';
  const unmap_api = 'https://rpxnow.com/api/v2/unmap';

  /**
   * Performs a lookup_rp request.
   *
   * @param string $api_key
   *   The API key for the Engage App we are looking up.
   *
   * @return
   *   An array of (lookup_rp) data about the app. FALSE if unexpected
   *   error occured.
   *
   * @see http://rpxnow.com/docs
   */
  static function lookup($api_key) {
    global $base_url;

    $post_data = 'apiKey=' . $api_key . '&format=json&pluginName=Drupal&pluginVersion=' . RPX_MODULE_VERSION;

    $headers = array(
      'Referer' => $base_url,
      'User-Agent' => 'Janrain_Engage_Drupal_Module',
    );
    $options = array(
      'headers' => $headers,
      'data' => $post_data,
      'method' => 'POST',
      'max_redirects' => 5,
    );

    $result = drupal_http_request(RPX::lookup_api, $options);

    // Fail on all errors except 400 Bad Request 'No RP found'.
    if (isset($result->data) && $result->data == 'No RP found') {
      return $result->data;
    }
    if (isset($result->error)) {
      RPX::report_http_error($result);
      return FALSE;
    }

    if (!isset($result->data)) {
      return FALSE;
    }

    // Request was a success.
    return json_decode($result->data, true);
  }

  /**
   * Fetches Engage user profile information for an authenticated user.
   *
   * @param string $token
   *   The token POST'ed to rpx_token_handler() upon user authentication.
   * @param string $api_key
   *   The API key for the Engage app we are using.
   * @param boolean $extended
   *   If TRUE, extended user profile data will be requested from Engage.
   *
   * @return
   *   An array of (auth_info) data about the user; FALSE if an
   *   error occured.
   *
   * @see rpx_token_handler()
   * @see http://rpxnow.com/docs
   */
  static function auth_info( $token, $api_key, $extended = FALSE) {
    $post_data = 'token='.$token . '&apiKey='.$api_key . '&format=json';

    if ($extended) {
      $post_data .= '&extended=true';
    }

    $options['data'] = $post_data;
    $options['method'] = 'POST';

    $result = drupal_http_request(RPX::auth_api, $options);

    if(isset($result->error)) {
      RPX::report_http_error($result);
      return FALSE;
    }

    return json_decode($result->data, TRUE);
  }

  /**
   * Performs a map request.
   *
   * @param string $api_key
   *   The API key for the Engage App instance we are using.
   * @param string $authname
   *   The identifier we are mapping to a Drupal uid.
   * @param string $uid
   *   The Drupal user ID we are mapping to.
   * @return
   *   An array of RPX request info (stat, err, etc.)
   *
   * @see http://rpxnow.com/docs
   */
  static function map($api_key, $authname, $uid) {
    $post_data = 'apiKey='.$api_key . '&identifier='.$authname . '&primaryKey='.$uid . '&overwrite=true';

    $options['data'] = $post_data;
    $options['method'] = 'POST';

    $result = drupal_http_request(RPX::map_api, $options);

    if(isset($result->error)) {
      RPX::report_http_error($result);
    }

    return json_decode($result->data, TRUE);
  }

  /**
   * Performs an unmap request.
   *
   * @param string $api_key
   *   The API key for the Engage App instance we are using.
   * @param string $authname
   *   The identifier we are unlinking from a Drupal uid.
   * @param string $uid
   *   The Drupal user ID we are unlinking for.
   * @param boolean $all
   *   Set to TRUE if we should unmap all identifiers mapped to $uid (for example,
   *   when user is deleted.)
   *
   * @return
   *   An array of RPX request info (stat, err, etc.)
   *
   * @see http://rpxnow.com/docs
   */
  static function unmap($api_key, $authname, $uid, $all = FALSE) {
    $post_data = 'apiKey='.$api_key . '&primaryKey='.$uid;

    if ($all) {
      $post_data .= '&all_identifiers=true';
    }
    else {
      $post_data .= '&identifier='.$authname;
    }

    $options['data'] = $post_data;
    $options['method'] = 'POST';

    $result = drupal_http_request(RPX::unmap_api, $options);

    if(isset($result->error)) {
      RPX::report_http_error($result);
    }

    return json_decode($result->data, TRUE);
  }

  /**
   * Fetches Engage identity provider list (and their order in the widget).
   *
   * @param string $realm
   *   Engage relying party instance name.
   * @param string $realm_scheme
   *   RP instance access protocal (http or https).
   *
   * @return
   *   An array of enabled identity providers occured.
   */
  static function get_enabled_providers($realm, $realm_scheme = 'http') {
    if (!in_array($realm_scheme, array('http', 'https'))) {
      $realm_scheme = 'http';
    }

    $url = $realm_scheme."://" . $realm . "/openid/ui_config";

    $result = drupal_http_request($url);

    if(isset($result->error)) {
      RPX::report_http_error($result);
      return '';
    }

    $data = json_decode($result->data, TRUE);
    return $data['enabled_providers'];
  }

  static function locales() {
    return array('pt-BR', 'vi', 'zh', 'nl', 'sr', 'ko', 'ru', 'sv-SE', 'ro', 'pt', 'it', 'hu', 'fr', 'ja', 'en', 'bg', 'es', 'el', 'pl', 'de', 'cs', 'da');
  }

  /**
   * Helper function for the Engage web API wrappers.
   */
  static function report_http_error($result) {
    watchdog('rpx_core', 'Engage web API seems to be inaccessible due to "%error".', array('%error' => $result->code . ' ' . $result->error), WATCHDOG_WARNING);
    drupal_set_message(t('Engage web API seems to be inaccessible because of error "%error".', array('%error' => $result->code . ' ' . $result->error)), 'error');
  }
}
