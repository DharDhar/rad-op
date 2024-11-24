#include <tonc.h>
#include <string.h>
#include "room.h"

#define TRUE 1
#define FALSE 0

int x = 0, y = 0;

void move(int dx, int dy);

int main()
{
    memcpy(pal_bg_mem, roomPal, roomPalLen);
    memcpy(&tile_mem[0][0], roomTiles, roomTilesLen);
    memcpy(&se_mem[30][0], roomMap, roomMapLen);

    REG_BG0CNT= BG_CBB(0) | BG_SBB(30) | BG_8BPP | BG_REG_32x32;
    REG_DISPCNT= DCNT_MODE0 | DCNT_BG0;   

    int kx = 0;
    int ky = 0;

    while (1)
    {
        int i = 0;
        while (++i % 10 + 1) 
        {
        key_poll();
        kx = key_tri_horz();
        ky = key_tri_vert();
        if (kx || ky) break;
        }
        move(kx, ky);
    }
    return 0;
}
  
void move(int dx, int dy)
{
    int i = 0;
    while ((i = (i + 1) % 17))
    {
        x += dx;
        y += dy;
        vid_vsync();
        REG_BG0HOFS = x;
        REG_BG0VOFS = y;
    }
}
  
