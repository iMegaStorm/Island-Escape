#include "LevelSelector.h"

LevelSelector::LevelSelector()
{
	currentLevel = gameScreen;
}	

LevelSelector::~LevelSelector()
{
	
}

void LevelSelector::LevelSwitcher(signed int MapCollider[40][70], signed short MapGraphics[40][70])
{
	switch (currentLevel)
	{
	case 0:
		GameScreen();
		break;
	case 1:
		LevelOne(MapCollider, MapGraphics);
		break;
	};
}

void LevelSelector::GameScreen()
{
		gm.DrawGS(640, 528, 0 ,0);
	
	if (PAD_ButtonsHeld(0) & PAD_BUTTON_A)
	{
		gm.LevelOneDraw(640, 528, 0 , 0);
		currentLevel = level1;
	}
}

void LevelSelector::LevelOne(signed int MapCollider[40][70], signed short MapGraphics[40][70])
{
	player.Inputs(MapCollider, MapGraphics); //Inputs for the player

	int x, y;
	for (x = 0; x <= 21; x++) //Draws 20 tiles on screen and 1 off screen to make it look smoother
	{
		for (y = 0; y <= 17; y++) //Draws 16  tiles on screen and 1 off screen to make it look smoother
		{
			if (MapGraphics[y + player.startY][x + player.startX] != 0) //If the value in the map isnt 0 then draw tiles from the map 
			{
				GRRLIB_DrawTile(x*MapTileWidth + player.offsetX - MapTileHeight, y*MapTileHeight + player.offsetY - MapTileHeight, gm.tex_tileset, 0, 1, 1, 0xFFFFFFFF, MapGraphics[y + player.startY][x + player.startX] - 1);
			}
		}
	}
	GRRLIB_DrawTile(player.x, player.y, gm.tex_maincharacter, 0, 1, 1, GRRLIB_WHITE, (int)player.playerRect);

	if (player.curHp <= 0 && player.showFont)
	{
		GRRLIB_Rectangle(70, 139, 500, 250, 0x000000FF, 1);
		GRRLIB_Printf(120, 180, fonts.tex_fontImg, GRRLIB_WHITE, 2.5, "GAME OVER!");
		GRRLIB_Printf(100, 300, fonts.tex_fontImg, GRRLIB_WHITE, 1.5, "PRESS X TO RESTART");

		if (PAD_ButtonsHeld(0) & PAD_BUTTON_B)
		{
			player.x = 288, player.y = 192;
			player.startX = 0, player.startY = 0;
			player.dirX = 0;
			player.dirY = 0;
			player.offsetX = 0, player.offsetY = 0;
			player.bgX = -32, player.bgY = -32;
			MapGraphics[27][21] = 54;
			MapGraphics[21][32] = 54;
			MapGraphics[27][42] = 54;
			MapGraphics[13][45] = 54;
			player.isGameOver = false;
			player.showFont = false;
			player.isAlive = true;
			player.curHp = 30;
			player.key = 0;
		}
	}

	if (player.isLevelCompleted)
	{
		GRRLIB_Rectangle(0, 0, 640, 528, 0x000000FF, 1);
		LevelOneCompleted();
		if (PAD_ButtonsHeld(0) & PAD_BUTTON_B)
		{
			
			player.x = 288, player.y = 192;
			player.startX = 0, player.startY = 0;
			player.dirX = 0;
			player.dirY = 0;
			player.offsetX = 0, player.offsetY = 0;
			player.bgX = -32, player.bgY = -32;
			MapGraphics[27][21] = 54;
			MapGraphics[21][32] = 54;
			MapGraphics[27][42] = 54;
			MapGraphics[13][45] = 54;
			player.isLevelCompleted = false;
			player.isAlive = true;
			player.curHp = 30;
			player.key = 0;
		}
	}
}

void LevelSelector::LevelOneCompleted()
{
	GRRLIB_Printf(10, 100, fonts.tex_fontImg, GRRLIB_WHITE, 2.5, "LEVEL COMPLETED!");
	GRRLIB_Printf(50, 200, fonts.tex_fontImg, GRRLIB_WHITE, 1.5, "THANK YOU FOR PLAYING");
	GRRLIB_Printf(0, 300, fonts.tex_fontImg, GRRLIB_WHITE, 1.5, "PRESS X TO REPLAY THE LEVEL");
}

void LevelSelector::Textures()
{
	GRRLIB_texImg *tex_maincharacter = GRRLIB_LoadTexture(maincharacter);
	GRRLIB_FreeTexture(tex_maincharacter);
	GRRLIB_FreeTexture(gm.gameScreenTex);
}