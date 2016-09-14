<div class="json-feed-import-form">
<?php print $form; ?>
</div>
<div class="json-feed-import-config">
  <?php
  print t(
    'To configure periodic import open following link: !link',
    array('!link' => l('Configuration', 'admin/structure/feeds/digg_top_stories/settings'))
  );
?>
</div>

<div class="json-feed-import-results">
  <h2><?php print t('Imported items'); ?></h2>
  <?php print $results; ?>
</div>
