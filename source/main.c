#include <tonc.h>
#include <string.h>
#include "red_ow.h"
#include "player_OW.h"
#include "room.h"
#include "map.h"

#define TRUE 1
#define FALSE 0

OBJ_ATTR obj_buffer[128];

int fcount = 0;
int x = 24, y = 47;

int main()
{

    irq_init(NULL);
    irq_add(II_VBLANK, NULL);
    
    REG_DISPCNT= DCNT_OBJ | DCNT_OBJ_1D | DCNT_MODE0 | DCNT_BG0;   

    // Load palette
    memcpy(pal_bg_mem, roomPal, roomPalLen);
    // Load tiles into CBB 0
    memcpy(&tile_mem[0][0], roomTiles, roomTilesLen);
    // Load map into SBB 30
    memcpy(&se_mem[30][0], roomMap, roomMapLen);

    REG_BG0CNT= BG_CBB(0) | BG_SBB(30) | BG_8BPP | BG_REG_32x32;
    REG_BG0HOFS= x;
    REG_BG0VOFS= y;   

    memcpy(&tile_mem[4][0], red_owTiles, red_owTilesLen);
    memcpy(pal_obj_mem, red_owPal, red_owPalLen);

    oam_init(obj_buffer, 128);

    obj_test(red);
    obj_set_pos(red, 7*16 + 2, 5*16 );
    while (1)
    {
        fcount++;
        VBlankIntrWait();
        key_poll();
        handle_mapscroll();
//      obj_test(red);       
        handle_PLAYER_anim();
        oam_copy(oam_mem, obj_buffer, 1);
    }
    return 0;
}

  
  
