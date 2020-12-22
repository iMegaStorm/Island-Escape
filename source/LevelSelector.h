#pragma once

#include <gccore.h>
#include <grrlib.h>
#include <ogc/pad.h>

#include "GameManager.h"
#include "gfx/tileset.h"
#include "gfx/maincharacter.h"
#include "gfx/bg.h"
#include "Player.h"

#define MapTileWidth (32)
#define MapTileHeight (32)
#define MapWidth (70)
#define MapHeight (30)

class LevelSelector
{
public:
	enum switcher {gameScreen = 0, level1 = 1} currentLevel;
	GameManager gm;
	Player player;
	MenuFont fonts;

public:
	LevelSelector();
	~LevelSelector();

	void LevelSwitcher(signed int MapCollider[40][70], signed short MapGraphics[40][70]);
	void GameScreen();
	void LevelOne(signed int MapCollider[40][70], signed short MapGraphics[40][70]);
	void LevelOneCompleted();
	void Textures();
};