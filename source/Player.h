#pragma once

#include <grrlib.h>
#include "GameManager.h"

#define MapTileWidth (32)
#define MapTileHeight (32)
#define MapWidth (70)
#define MapHeight (30)
#define GRRLIB_WHITE     0xFFFFFFFF

class Player
{

public:
	int startX, startY;
	float dirX, dirY;
	int offsetX, offsetY;
	int bgX, bgY;
	int playerRect;
	float deltaTime;
	float totalTime;
	float switchTime;
	bool faceRight;
	int curHp;
	bool isAlive;
	bool isLive;
	bool isLevelCompleted;
	bool isGameOver;
	bool gameReset;
	bool showFont;
	int key;
	float x, y;

	float totalDeathTime;
	float deathTime;
	
	
public:
	Player();
	~Player();
	MenuFont menuFonts;

	void Inputs(signed int MapCollider[40][70], signed short MapGraphics[40][70]);
	
};