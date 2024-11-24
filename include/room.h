
//{{BLOCK(room)

//======================================================================
//
//	room, 256x256@8, 
//	+ palette 256 entries, not compressed
//	+ 117 tiles (t|f|p reduced) not compressed
//	+ regular map (in SBBs), not compressed, 32x32 
//	Total size: 512 + 7488 + 2048 = 10048
//
//	Time-stamp: 2024-07-31, 15:10:45
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.6
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_ROOM_H
#define GRIT_ROOM_H

#define roomTilesLen 7488
extern const unsigned short roomTiles[3744];

#define roomMapLen 2048
extern const unsigned short roomMap[1024];

#define roomPalLen 512
extern const unsigned short roomPal[256];

#endif // GRIT_ROOM_H

//}}BLOCK(room)
