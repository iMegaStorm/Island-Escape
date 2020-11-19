#pragma once

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
	int maxHp;
	bool isAlive;
	
public:
	Player();
	~Player();
	void Inputs(int MapCollider[40][70]);
	
};