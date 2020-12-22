#include "GameManager.h"


GameManager::GameManager()
{
	gameScreenTex = GRRLIB_LoadTexture(bg);
}

GameManager::~GameManager()
{
	
}

void GameManager::DrawGS(float width, float height, float x, float y)
{
	GRRLIB_InitTileSet(gameScreenTex, width, height, 0);
	GRRLIB_DrawTile(x, y, gameScreenTex, 0, 1, 1, GRRLIB_WHITE, 0);
}

void GameManager::LevelOneDraw(float width, float height, float x, float y)
{
	GRRLIB_ClipDrawing(0, 0, rmode->fbWidth, rmode->efbHeight);
	tex_maincharacter = GRRLIB_LoadTexture(maincharacter);
	GRRLIB_InitTileSet(tex_maincharacter, 64, 64, 0);
	tex_tileset = GRRLIB_LoadTexture(tileset);
	GRRLIB_InitTileSet(tex_tileset, MapTileWidth, MapTileHeight, 0);
}
