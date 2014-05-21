<article data-page="<?php $page = get_query_var('paged'); echo  $page ? $page : 1; ?>" <?php post_class(); ?>>
  <div class="entry-inner">
    <?php if(has_post_thumbnail()) : ?>
    <div class="entry-thumbnail">
      <?php the_post_thumbnail(); ?>
    </div>
    <?php endif; ?>
    <header>
      <h2 class="entry-title"><time class="published" datetime="<?php echo get_the_time('c'); ?>"><?php echo get_the_date(); ?></time></h2>
    </header>
    <div class="entry-content">
      <?php the_content( __('Continue Reading &rarr;', 'dw-timeline') ); ?>
    </div>
  </div>
</article>
