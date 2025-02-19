
//{{BLOCK(room)

//======================================================================
//
//	room, 256x256@8, 
//	+ palette 256 entries, not compressed
//	+ 119 tiles (t|f|p reduced) not compressed
//	+ regular map (flat), not compressed, 32x32 
//	Total size: 512 + 7616 + 2048 = 10176
//
//	Time-stamp: 2025-02-19, 23:54:51
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.6
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_ROOM_H
#define GRIT_ROOM_H

#define roomTilesLen 7616
extern const unsigned short roomTiles[3808];

#define roomMapLen 2048
extern const unsigned short roomMap[1024];

#define roomPalLen 512
extern const unsigned short roomPal[256];

#endif // GRIT_ROOM_H

//}}BLOCK(room)
