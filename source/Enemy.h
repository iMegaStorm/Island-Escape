#pragma once

class Enemy
{

public:
	int startX, startY;
	float dirX, dirY;
	int offsetX, offsetY;
	int width, height;
	int skeletonRect;
	
public:
	Enemy();
	~Enemy();
	void Draw();
	void AIController();
};