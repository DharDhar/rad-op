#include <tonc.h>
#include "map.h"
#include "player_OW.h"

#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4

int mapfcount = 0;
u16 sx = (24<<8), sy = (47<<8);
extern overworld PLAYER;

void handle_mapscroll(void);
void set_x(void);
static int vx = 0, vy = 0;
bool movement_init = false;
int pressed_key = 0;

void handle_mapscroll(void)
{

    if (key_tri_vert() == 1 && movement_init == false && PLAYER.firstanimframe == 0)
    {
        pressed_key = UP;
        movement_init = true;
    }
    else if (key_tri_vert() == -1 && movement_init == false && PLAYER.firstanimframe == 4)
    {
        pressed_key = DOWN;
        movement_init = true;
    }
    else if (key_tri_horz() == 1 && movement_init == false && PLAYER.firstanimframe == 12)
    {
        pressed_key = RIGHT;
        movement_init = true;
    }
    else if (key_tri_horz() == -1 && movement_init == false && PLAYER.firstanimframe == 8)
    {
        pressed_key = LEFT;
        movement_init = true;
    }
    if (movement_init == true && ((mapfcount++)%17))
    {
        switch (pressed_key){
            case RIGHT: {sx += 256; break;}
            case LEFT:  {sx -= 256; break;}
            case UP:    {sy += 256; break;}
            case DOWN:  {sy -= 256; break;}
        }
//  sx += 512; 
//  sy += 512;

    REG_BG0HOFS= sx>>8;
    REG_BG0VOFS= sy>>8;
    }
    else movement_init = false;
//  vx = 0;
//  vy = 0;

//  if (key_tri_horz() == 0 && )
//      return;
    



/*
        if (key_held(KEY_DOWN))
            {do (REG_BG0VOFS= y++); while (y%16);}
        if (key_held(KEY_UP))
            {do (REG_BG0VOFS= y--); while (y%16);}
        if (key_held(KEY_LEFT))
            {do (REG_BG0HOFS= x--); while (x%16);}
        if (key_held(KEY_RIGHT))
            {do (REG_BG0HOFS= x++); while (x%16);}
    

    if (key_held(KEY_UP))
        y--;
    if (key_held(KEY_LEFT))
        x--;
    if (key_held(KEY_RIGHT))
        x++;

//  REG_BG0HOFS= x;
    REG_BG0VOFS= y;
*/
}

