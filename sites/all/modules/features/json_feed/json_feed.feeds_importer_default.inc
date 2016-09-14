<?php
/**
 * @file
 * json_feed.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function json_feed_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'digg_top_stories';
  $feeds_importer->config = array(
    'name' => 'Digg Top Stories',
    'description' => '',
    'fetcher' => array(
      'plugin_key' => 'FeedsHTTPFetcher',
      'config' => array(
        'auto_detect_feeds' => 0,
        'use_pubsubhubbub' => 0,
        'designated_hub' => '',
        'request_timeout' => '',
        'auto_scheme' => 'https://ajax.googleapis.com/ajax/services/feed/load?v=1.0&num=100&q=http://www.digg.com/rss/index.xml',
        'accept_invalid_cert' => 0,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsExJsonPath',
      'config' => array(
        'sources' => array(
          'title' => array(
            'name' => 'Title',
            'value' => 'title',
            'debug' => 0,
            'weight' => '1',
          ),
          'link' => array(
            'name' => 'Link',
            'value' => 'link',
            'debug' => 0,
            'weight' => '2',
          ),
          'content' => array(
            'name' => 'Content',
            'value' => 'content',
            'debug' => 0,
            'weight' => '3',
          ),
          'contentsnippet' => array(
            'name' => 'ContentSnippet',
            'value' => 'contentSnippet',
            'debug' => 0,
            'weight' => '4',
          ),
          'publisheddate' => array(
            'name' => 'PublishedDate',
            'value' => 'publishedDate',
            'debug' => 0,
            'weight' => '5',
          ),
        ),
        'context' => array(
          'value' => '$.responseData.feed.entries.*',
        ),
        'display_errors' => 0,
        'source_encoding' => array(
          0 => 'auto',
        ),
        'debug_mode' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'expire' => '-1',
        'author' => 0,
        'authorize' => 1,
        'mappings' => array(
          0 => array(
            'source' => 'link',
            'target' => 'guid',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'title',
            'target' => 'title',
            'unique' => FALSE,
            'language' => 'und',
          ),
          2 => array(
            'source' => 'content',
            'target' => 'body',
            'unique' => FALSE,
            'language' => 'und',
          ),
          3 => array(
            'source' => 'contentsnippet',
            'target' => 'field_teaser',
            'unique' => FALSE,
            'language' => 'und',
          ),
          4 => array(
            'source' => 'link',
            'target' => 'field_link',
            'unique' => FALSE,
            'language' => 'und',
          ),
          5 => array(
            'source' => 'publisheddate',
            'target' => 'created',
            'unique' => FALSE,
            'language' => 'und',
          ),
        ),
        'insert_new' => '1',
        'update_existing' => '2',
        'update_non_existent' => 'skip',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'story',
        'language' => 'und',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '1800',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['digg_top_stories'] = $feeds_importer;

  return $export;
}
