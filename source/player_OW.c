#include <tonc.h>
#include "player_OW.h"

OBJ_ATTR *red = &obj_buffer[0];

overworld PLAYER = {
    &obj_buffer[0],
    0,
    0,
    1,
    DOWN
};

void handle_PLAYER_anim(void)
{
    //TODO: smoothen out the anims. very crude atm
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
    if (!(PLAYER.animf++%10))
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
