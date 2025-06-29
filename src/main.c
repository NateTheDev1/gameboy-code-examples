#include <gb/gb.h>
#include "StartbucksSplash.h"
#include "Frog.h"

uint8_t frog_x = 80;
uint8_t frog_y = 72;
uint8_t speed = 1;

// uint8_t scroll_x = 0;
// uint8_t scroll_y = 0;

void init_gfx(void) {
    // set_bkg_data(0, StartbucksSplash_TILE_COUNT, StartbucksSplash_tiles);
    // set_bkg_tiles(0, 0, 20, 18, StartbucksSplash_map);

    set_sprite_data(0, Frog_TILE_COUNT, Frog_tiles);

    move_metasprite(Frog_metasprites[0], 0, 0, frog_x, frog_y);

    SHOW_SPRITES;
    SHOW_BKG;
    DISPLAY_ON;
}

void main(void)
{
	init_gfx();

    // Loop forever
    while(1) {
		// Game main loop processing goes here
        uint8_t keys = joypad();
        
        if(keys & J_A) {
            speed  = 2;
        } else {
            speed = 1;
        }

        if(keys & J_UP) frog_y -= speed;
        if(keys & J_DOWN) frog_y += speed;
        if(keys & J_LEFT) frog_x -= speed;
        if(keys & J_RIGHT) frog_x += speed;

        // if(keys & J_LEFT) scroll_x--;
        // if(keys & J_RIGHT) scroll_x++;
        // if(keys & J_DOWN) scroll_y--;
        // if(keys & J_UP) scroll_y++;

        // if(keys & J_A) {
        //     scroll_x = 0;
        //     scroll_y = 0;
        // }

        // if(keys & J_START) {
        //     scroll_x = 10;
        // }

        move_metasprite(Frog_metasprites[0], 0, 0, frog_x, frog_y);

        // scroll_bkg(scroll_x, scroll_y);

		// Done processing, yield CPU and wait for start of next frame
        vsync();
    }
}
