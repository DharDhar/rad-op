#include <tonc.h>
#include <string.h>
#include "red_ow.h"
#include "player_OW.h"

#define TRUE 1
#define FALSE 0

OBJ_ATTR obj_buffer[128];

int fcount = 0;

int main()
{
    int x = 112, y = 64;

    irq_init(NULL);
    irq_add(II_VBLANK, NULL);
    
    REG_DISPCNT= DCNT_OBJ | DCNT_OBJ_1D;   
    
    memcpy(&tile_mem[4][0], red_owTiles, red_owTilesLen);
    memcpy(pal_obj_mem, red_owPal, red_owPalLen);

    oam_init(obj_buffer, 128);

    obj_test(red);
    obj_set_pos(red, x, y);
    while (1)
    {
//      fcount++;
        VBlankIntrWait();
        key_poll();
//      obj_test(red);       
        handle_PLAYER_anim();
        oam_copy(oam_mem, obj_buffer, 1);
    }
    return 0;
}

  
  
