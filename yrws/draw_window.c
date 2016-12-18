#include "../include/kernel.h"
#include "../include/yrws.h"

extern struct Layer_Master *LAYER_MASTER;

void draw_window(i16_t start_x, i16_t start_y, i16_t width, i16_t height){
      struct Layer *window = layer_alloc(LAYER_MASTER);
      u8_t *window_buf = (u8_t *)memory_alloc_4k(memman, width * height);
      layer_chbuf(window, window_buf);
      modify_layer(window, width, height, 255);
      int i;
      for(i = 0;i < width*height;i++){
            window->data[i] = 0;
      }
      move_layer(LAYER_MASTER, window, 100, 100);
      layer_ch_position(LAYER_MASTER, window, 2);

      redraw_all_layer(LAYER_MASTER, window, 0, 0, binfo->scrny, binfo->scrny);
}
