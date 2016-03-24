#include <pebble.h>
#include "dualtime_layers.h"

// BEGIN AUTO-GENERATED UI CODE; DO NOT MODIFY
static Window *s_window;
static GFont s_res_crystal_digital_font_26;
static Layer *s_layer_1;
static TextLayer *s_textlayer_1;

static void initialise_ui(void) {
  s_window = window_create();
  window_set_background_color(s_window, GColorBlack);
  #ifndef PBL_SDK_3
    window_set_fullscreen(s_window, 1);
  #endif
  
  s_res_crystal_digital_font_26 = fonts_load_custom_font(resource_get_handle(RESOURCE_ID_CRYSTAL_DIGITAL_FONT_26));
  // s_layer_1
  s_layer_1 = layer_create(GRect(-1, 0, 144, 139));
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_layer_1);
  
  // s_textlayer_1
  s_textlayer_1 = text_layer_create(GRect(20, 139, 102, 26));
  text_layer_set_text(s_textlayer_1, "23:47");
  text_layer_set_text_alignment(s_textlayer_1, GTextAlignmentCenter);
  text_layer_set_font(s_textlayer_1, s_res_crystal_digital_font_26);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_textlayer_1);
}

static void destroy_ui(void) {
  window_destroy(s_window);
  layer_destroy(s_layer_1);
  text_layer_destroy(s_textlayer_1);
  fonts_unload_custom_font(s_res_crystal_digital_font_26);
}
// END AUTO-GENERATED UI CODE

static void handle_window_unload(Window* window) {
  destroy_ui();
}

void show_analog(void) {
  initialise_ui();
  window_set_window_handlers(s_window, (WindowHandlers) {
    .unload = handle_window_unload,
  });
  window_stack_push(s_window, true);
}

void hide_analog(void) {
  window_stack_remove(s_window, true);
}
