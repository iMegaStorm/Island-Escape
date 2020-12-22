#pragma once

#include <gccore.h>
#include <grrlib.h>
#include <ogc/pad.h>

#include "gfx/bg.h"
#include "gfx/tileset.h"
#include "gfx/maincharacter.h"
#include "MenuFont.h"

#define MapTileWidth (32)
#define MapTileHeight (32)

#define GRRLIB_WHITE     0xFFFFFFFF

class GameManager
{
public:
	GRRLIB_texImg *gameScreenTex;
	GRRLIB_texImg *levelCompletedTex;
	GRRLIB_texImg *tex_tileset;
	GRRLIB_texImg *tex_maincharacter;
	GRRLIB_ttfFont* font;	

public:
	GameManager();
	~GameManager();

	void DrawGS(float width, float height, float x,float y);
	void LevelOneDraw(float width, float height, float x,float y);
};