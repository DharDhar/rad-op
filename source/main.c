#include <tonc.h>
#include <string.h>
#include "red_ow.h"

#define TRUE 1
#define FALSE 0

void obj_test(OBJ_ATTR * obj);

OBJ_ATTR obj_buffer[128];

OBJ_ATTR *red = &obj_buffer[0];

void handleredanim(void);

int fcount = 0;

int main()
{
    int x = 0, y = 0;

    obj_set_pos(red, x, y);
    irq_init(NULL);
    irq_add(II_VBLANK, NULL);
    
    REG_DISPCNT= DCNT_OBJ | DCNT_OBJ_1D;   

    memcpy(&tile_mem[4][0], red_owTiles, red_owTilesLen);
    memcpy(pal_obj_mem, red_owPal, red_owPalLen);

    oam_init(obj_buffer, 128);

    obj_test(red);
    while (1)
    {
        fcount++;
        VBlankIntrWait();
        handleredanim();
        oam_copy(oam_mem, obj_buffer, 1);
    }
    return 0;
}

void handleredanim(void)
{
    static int ind = 2;
    static int inc = 0;
    if (!(fcount%12))
    {
        red->attr2 = (red->attr2 & 0xfc00) | 8*ind;
        if (inc && ind == 2) inc = 0;
        if (!inc && ind == 0) inc = 1;
        if (inc) ind++;
        else ind--;
    }
}

void obj_test(OBJ_ATTR * obj)
{
    u32 tid = 8, pb = 0; //tileid and palbank
    obj_set_attr(obj,
    ATTR0_TALL,
    ATTR1_SIZE_32,
    ATTR2_PALBANK(pb) | tid); 

    oam_copy(oam_mem, obj_buffer, 1);
}
  
  
