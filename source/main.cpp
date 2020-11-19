#include <grrlib.h>
#include <stdlib.h>

#include "gfx/tileset.h"
#include "gfx/maincharacter.h"
#include "gfx/skeleton.h"
#include "gfx/bg.h"

#include "Player.h"
#include "Enemy.h"

#define GRRLIB_BLACK   0x000000FF
#define GRRLIB_WHITE   0xFFFFFFFF

#define MapTileWidth (32)
#define MapTileHeight (32)
#define MapWidth (70)
#define MapHeight (30)

signed short MapGraphics[40][70] =
{{00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00},
 {00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00},
 {00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00},
 {00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00},
 {00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00},
 {00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00},
 {00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00},
 {00,00,00,00,00,00,07, 8,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00},
 {00,00,00,00,00,00,17,18,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00},
 {00,00,00,00,00,00,27,28,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,01,02,02,04,05,02,02,02,02,02,02,02,02,04,05,03,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00},
 {00,00,00,00,00,00,37,38,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,24,25,00,00,00,00,00,00,00,00,24,25,00,00,00,00,00,00,00,01,02,02,04,05,02,03,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00},
 {02,02,02,02,02,02,02,02,03,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,14,15,00,00,00,00,00,00,00,00,14,15,00,00,00,00,00,00,00,00,00,00,24,25,11,13,00,00,00,00,00,00,00,00,01,02,02,02,02,02,02,02},
 {12,12,12,12,12,12,12,12,13,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,24,25,00,00,00,00,00,00,00,00,24,25,00,00,00,00,00,00,00,00,00,00,14,15,11,13,00,00,00,00,00,00,00,01,12,12,12,12,12,12,12,12},
 {12,12,12,12,12,12,12,12,13,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,14,15,00,00,00,00,00,00,00,00,14,15,00,00,00,00,00,00,00,00,00,00,24,25,11,12,02,02,02,03,00,00,00,11,12,12,12,12,12,12,12,12},
 {12,12,12,12,12,12,12,12,12,02,02,02,02,02,02,04,05,02,02,02,02,02,02,02,02,02,02,02,02,02,03,00,00,00,00,00,00,01,02,02,03,00,00,01,02,02,02,03,00,00,14,15,11,13,00,00,00,00,00,00,00,11,12,12,12,12,12,12,12,12},
 {12,12,12,12,12,12,12,12,13,00,00,00,00,00,00,14,15,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,24,25,11,13,00,00,00,00,00,00,00,11,12,12,12,12,12,12,12,12},
 {12,12,12,12,12,12,12,12,13,00,00,00,00,00,00,24,25,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,14,15,11,13,00,00,00,00,00,00,00,11,12,12,12,12,12,12,12,12},
 {12,12,12,12,12,12,12,12,13,00,00,00,00,00,00,14,15,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,24,25,11,13,00,00,00,00,00,00,00,11,12,12,12,12,12,12,12,12},
 {12,12,12,12,12,12,12,12,12,02,02,04,05,02,02,02,02,02,02,02,02,02,03,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,01,02,04,05,03,00,00,00,00,14,15,11,13,00,00,00,00,00,00,00,11,12,12,12,12,12,12,12,12},
 {12,12,12,12,12,12,12,12,13,00,00,14,15,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,14,15,00,00,00,00,00,24,25,11,13,00,00,00,00,00,00,00,11,12,12,12,12,12,12,12,12},
 {12,12,12,12,12,12,12,12,13,00,00,24,25,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,24,25,00,00,00,00,00,14,15,11,13,00,00,00,00,00,00,00,11,12,12,12,12,12,12,12,12},
 {12,12,12,12,12,12,12,12,13,00,00,14,15,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,14,15,00,00,00,00,00,24,25,11,13,00,00,01,02,02,02,02,12,12,12,12,12,12,12,12,12},
 {12,12,12,12,12,12,12,12,13,00,00,24,25,00,00,00,00,00,00,00,00,00,00,01,02,02,02,02,02,02,02,02,02,02,03,00,00,00,00,00,00,00,00,24,25,00,00,00,00,00,14,15,21,23,00,00,00,00,00,00,00,11,12,12,12,12,12,12,12,12},
 {12,12,12,12,12,12,12,12,13,00,00,14,15,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,01,02,02,02,02,02,02,02,02,02,02,02,00,00,00,00,00,00,00,11,12,12,12,12,12,12,12,12},
 {12,12,12,12,12,12,12,12,13,00,01,02,02,02,04,05,02,03,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,11,12,12,12,12,12,12,12,12},
 {12,12,12,12,12,12,12,12,13,00,00,00,00,00,14,15,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,11,12,12,12,12,12,12,12,12},
 {12,12,12,12,12,12,12,12,13,00,00,00,00,00,24,25,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,11,12,12,12,12,12,12,12,12},
 {12,12,12,12,12,12,12,12,13,00,00,00,00,00,14,15,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,11,12,12,12,12,12,12,12,12},
 {12,12,12,12,12,12,12,12,12,02,02,02,02,02,02,02,02,02,02,02,02,02,03,00,00,00,00,00,00,00,01,02,02,02,02,02,02,02,03,00,00,01,02,03,00,00,00,00,01,02,02,02,02,02,02,02,02,02,02,02,02,12,12,12,12,12,12,12,12,12},
 {12,12,12,12,12,12,12,12,12,34,34,34,34,34,34,34,34,34,34,34,34,34,45,06,06,06,06,06,06,06,44,34,34,34,34,34,34,34,45,06,06,44,34,45,06,06,06,06,44,34,34,34,34,34,34,34,34,34,34,34,34,12,12,12,12,12,12,12,12,12},
 {12,12,12,12,12,12,12,12,12,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,12,12,12,12,12,12,12,12,12},
 {12,12,12,12,12,12,12,12,12,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,12,12,12,12,12,12,12,12,12},
 {12,12,12,12,12,12,12,12,12,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,12,12,12,12,12,12,12,12,12},
 {12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12},
 {59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59},
 {59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59},
 {59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59},
 {59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59},
 {59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59},
 {59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59}};


signed int MapCollider[40][70] =
{{00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00},
 {00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00},
 {00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00},
 {00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00},
 {00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00},
 {00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00},
 {00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00},
 {00,00,00,00,00,00,99,98,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00},
 {00,00,00,00,00,00,99,98,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00},
 {00,00,00,00,00,00,99,98,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,90,90,90,95,95,90,90,90,90,90,90,90,90,95,95,90,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00},
 {00,00,00,00,00,00,99,98,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,95,95,00,00,00,00,00,00,00,00,95,95,00,00,00,00,00,00,00,90,90,90,95,95,90,90,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00},
 {90,90,90,90,90,90,90,90,90,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,95,95,00,00,00,00,00,00,00,00,95,95,00,00,00,00,00,00,00,00,00,00,95,95,99,98,00,00,00,00,00,00,00,00,90,90,90,90,90,90,90,90},
 {98,98,98,98,98,98,98,98,98,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,95,95,00,00,00,00,00,00,00,00,95,95,00,00,00,00,00,00,00,00,00,00,95,95,99,98,00,00,00,00,00,00,00,90,98,98,98,98,98,98,98,98},
 {98,98,98,98,98,98,98,98,98,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,95,95,00,00,00,00,00,00,00,00,95,95,00,00,00,00,00,00,00,00,00,00,95,95,99,98,90,90,90,90,00,00,00,99,98,98,98,98,98,98,98,98},
 {98,98,98,98,98,98,98,98,98,90,90,90,90,90,90,95,95,90,90,90,90,90,90,90,90,90,90,90,90,90,90,00,00,00,00,00,00,90,90,90,90,00,00,90,90,90,90,90,00,00,95,95,99,98,00,00,00,00,00,00,00,98,98,98,98,98,98,98,98,98},
 {98,98,98,98,98,98,98,98,98,00,00,00,00,00,00,95,95,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,95,95,99,98,00,00,00,00,00,00,00,98,98,98,98,98,98,98,98,98},
 {98,98,98,98,98,98,98,98,98,00,00,00,00,00,00,95,95,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,95,95,99,98,00,00,00,00,00,00,00,98,98,98,98,98,98,98,98,98},
 {98,98,98,98,98,98,98,98,98,00,00,00,00,00,00,95,95,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,95,95,99,98,00,00,00,00,00,00,00,98,98,98,98,98,98,98,98,98},
 {98,98,98,98,98,98,98,98,98,90,90,95,95,90,90,90,90,90,90,90,90,90,90,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,90,90,95,95,90,00,00,00,00,95,95,99,98,00,00,00,00,00,00,00,98,98,98,98,98,98,98,98,98},
 {98,98,98,98,98,98,98,98,98,00,00,95,95,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,95,95,00,00,00,00,00,95,95,99,98,00,00,00,00,00,00,00,98,98,98,98,98,98,98,98,98},
 {98,98,98,98,98,98,98,98,98,00,00,95,95,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,95,95,00,00,00,00,00,95,95,99,98,00,00,00,00,00,00,00,98,98,98,98,98,98,98,98,98},
 {98,98,98,98,98,98,98,98,98,00,00,95,95,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,95,95,00,00,00,00,00,95,95,99,98,00,00,90,90,90,90,90,98,98,98,98,98,98,98,98,98},
 {98,98,98,98,98,98,98,98,98,00,00,95,95,00,00,00,00,00,00,00,00,00,00,90,90,90,90,90,90,90,90,90,90,90,90,00,00,00,00,00,00,00,00,95,95,00,00,00,00,00,95,95,99,98,00,00,00,00,00,00,00,98,98,98,98,98,98,98,98,98},
 {98,98,98,98,98,98,98,98,98,00,00,95,95,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,90,90,90,90,90,90,90,90,90,90,90,90,00,00,00,00,00,00,00,98,98,98,98,98,98,98,98,98},
 {98,98,98,98,98,98,98,98,98,00,90,90,90,90,95,95,90,90,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,98,98,98,98,98,98,98,98,98},
 {98,98,98,98,98,98,98,98,98,00,00,00,00,00,95,95,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,98,98,98,98,98,98,98,98,98},
 {98,98,98,98,98,98,98,98,98,00,00,00,00,00,95,95,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,98,98,98,98,98,98,98,98,98},
 {98,98,98,98,98,98,98,98,98,00,00,00,00,00,95,95,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,98,98,98,98,98,98,98,98,98},
 {98,98,98,98,98,98,98,98,98,90,90,90,90,90,90,90,90,90,90,90,90,90,90,00,00,00,00,00,00,00,90,90,90,90,90,90,90,90,90,00,00,90,90,90,00,00,00,00,90,90,90,90,90,90,90,90,90,90,90,90,90,98,98,98,98,98,98,98,98,98},
 {98,98,98,98,98,98,98,98,98,90,90,90,90,90,90,90,90,90,90,90,90,90,90,06,06,06,06,06,06,06,90,90,90,90,90,90,90,90,90,06,06,90,90,90,06,06,06,06,90,90,90,90,90,90,90,90,90,90,90,90,90,98,98,98,98,98,98,98,98,98},
 {98,98,98,98,98,98,98,98,98,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,98,98,98,98,98,98,98,98,98},
 {98,98,98,98,98,98,98,98,98,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,98,98,98,98,98,98,98,98,98},
 {98,98,98,98,98,98,98,98,98,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,98,98,98,98,98,98,98,98,98},
 {98,98,98,98,98,98,98,98,98,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,98,98,98,98,98,98,98,98,98},
 {90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90},
 {90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90},
 {90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90},
 {90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90},
 {90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90},
 {90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90}};


int main()
{
	GRRLIB_Init();
	GRRLIB_Settings.antialias = false;
	PAD_Init();
	GRRLIB_ClipDrawing(0,0,rmode->fbWidth,rmode->efbHeight);
	GRRLIB_texImg *tex_tileset = GRRLIB_LoadTexture(tileset);
    GRRLIB_InitTileSet(tex_tileset, MapTileWidth, MapTileHeight, 0);
	GRRLIB_texImg *tex_maincharacter = GRRLIB_LoadTexture(maincharacter); // main character
    GRRLIB_InitTileSet(tex_maincharacter, 64, 64, 0);
	GRRLIB_texImg *tex_skeleton = GRRLIB_LoadTexture(skeleton); // skeleton
	GRRLIB_InitTileSet(tex_skeleton, 64, 64, 0);
	
	GRRLIB_texImg *tex_bg = GRRLIB_LoadTexture(bg);

	Player player;
	Enemy enemy;

	while(1)
	{
		int x,y;
		
		PAD_ScanPads(); // Scans for a controller pad
		player.Inputs(MapCollider); //Inputs for the player
		enemy.AIController();
		for(x = 0; x <= 21; x++) //Draws 20 tiles on screen and 1 off screen to make it look smoother
		{
			for(y = 0; y <= 17; y++) //Draws 16  tiles on screen and 1 off screen to make it look smoother
			{
                if(MapGraphics[y+player.startY][x+player.startX] != 0) //If the value in the map isnt 0 then draw tiles from the map 
				{
                    GRRLIB_DrawTile(x*MapTileWidth+player.offsetX-MapTileHeight,y*MapTileHeight+player.offsetY-MapTileHeight,tex_tileset,0,1,1,0xFFFFFFFF,MapGraphics[y+player.startY][x+player.startX]-1);
                }
            }
        }
		GRRLIB_DrawTile(MapTileWidth*9,MapTileHeight*6,tex_maincharacter,0,1,1,GRRLIB_WHITE,(int)player.playerRect);
		//GRRLIB_DrawImg(0, 0, tex_bg, 0, 1, 1, 0xFFFFFFFF);
		GRRLIB_DrawTile(50, 50, tex_skeleton, 0, 1, 1, GRRLIB_WHITE, (int)enemy.skeletonRect);
		//GRRLIB_DrawTile(player.dirX, player.dirY, tex_maincharacter, 0, 0.5, 0.5, GRRLIB_WHITE, 0); //Bind the sprite to the player and spawns the player in
		GRRLIB_Render();
	}
	
	GRRLIB_FreeTexture(tex_maincharacter);
	GRRLIB_FreeTexture(tex_skeleton);
	GRRLIB_FreeTexture(tex_bg);
	GRRLIB_Exit();
	exit(0); //Used by STDLib
}