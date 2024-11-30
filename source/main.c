#include <tonc.h>
#include <string.h>
#include "red_ow.h"

#define TRUE 1
#define FALSE 0

void obj_test(OBJ_ATTR * obj);

OBJ_ATTR obj_buffer[128];

typedef enum {
    DOWN = 0, UP = 4, LEFT = 8, RIGHT = 12 
} WALK_N;

typedef struct overworld {
    OBJ_ATTR * obj;
    int animf;
    int firstanimframe;
    int currentframe;
    WALK_N walkcycleN;
} overworld;

OBJ_ATTR *red = &obj_buffer[0];

overworld PLAYER = {
    &obj_buffer[0],
    0,
    0,
    1,
    DOWN
};

void handle_PLAYER_anim(void);
void handle_input(void);

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

void handle_PLAYER_anim(void)
{
    if (key_held(KEY_DOWN))
        PLAYER.firstanimframe = 0;
    else if (key_held(KEY_UP))
        PLAYER.firstanimframe = 4;
    else if (key_held(KEY_LEFT))
        PLAYER.firstanimframe = 8;
    else if (key_held(KEY_RIGHT))
        PLAYER.firstanimframe = 12;
    else
    {
        PLAYER.obj->attr2 = (PLAYER.obj->attr2 & 0xfc00) | 8*((PLAYER.currentframe=1) + PLAYER.firstanimframe);
        return;
    }
    if (!(PLAYER.animf++%12))
    {
        PLAYER.obj->attr2 = (PLAYER.obj->attr2 & 0xfc00) | 8*(PLAYER.currentframe++%4 + PLAYER.firstanimframe);
    }
}
 
void obj_test(OBJ_ATTR * obj)
{
    u32 tid = 8, pb = 0; //tileid and palbank
    obj_set_attr(obj,
    ATTR0_TALL,
    ATTR1_SIZE_32,
    ATTR2_PALBANK(pb) | tid); 

//  oam_copy(oam_mem, obj_buffer, 1);
}
  
  
