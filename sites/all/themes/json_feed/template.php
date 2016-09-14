<?php
/**
 * @file
 * The primary PHP file for this theme.
 */

function json_feed_preprocess_node(&$vars) {
  if ($vars['type'] == 'story') {
    $vars['publish_date'] = format_date($vars['changed'], 'custom', 'F jS, Y @ h:i a');

    $vars['source_link'] = '';
    if (!empty($vars['field_link'][0]['safe_value'])) {
      $vars['source_link'] = l(
        t('Read story'),
        $vars['field_link'][0]['safe_value'],
        array('attributes' => array(
          'target' => '_blank',
        ))
      );
    }
  }
}
