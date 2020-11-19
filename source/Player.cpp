#include <ogc/pad.h>
#include "Player.h"

	Player::Player()
	{
		this->startX = 0, this->startY = 0;
		this->dirX = 0;
		this->dirY = 0;
		this->offsetX = 0, this->offsetY = 0;
		this->bgX = -32, this->bgY = -32;
		this->playerRect = 0;
		this->deltaTime = 0.3f;
		this->totalTime = 0;
		this->switchTime = 0.8f;
		this->faceRight = true;
		curHp = 30, maxHp = 5;
		isAlive = true;
	}

	Player::~Player()
	{
	}	

	void Player::Inputs(int MapCollider[40][70])
	{
		if((dirX == 0) && (dirY == 0) && isAlive == true) //If the player isnt moving, set the animation to the start
		{
			if (PAD_ButtonsHeld(0) & PAD_BUTTON_LEFT)
			{
				dirX = 4;
				playerRect = 20;
				faceRight = false;
			}
			else if (PAD_ButtonsHeld(0) & PAD_BUTTON_RIGHT)
			{
				dirX = -4;
				playerRect = 12;
				faceRight = true;
			}
	        else if (PAD_ButtonsHeld(0) & PAD_BUTTON_DOWN)
	        {
		        dirY = -4;

				totalTime += deltaTime;
				switchTime = 2.0f;
				if(faceRight) // play idle animation facing right
				{
					if(totalTime >= switchTime)
					{
						totalTime -= switchTime;
						playerRect++;

						if(playerRect>5)
							playerRect = 0;
					}
				}
				else // play idle animation facing left
				{
					if(totalTime >= switchTime)
					{
						totalTime -= switchTime;
						playerRect++;

						if(playerRect>10)
							playerRect = 6;
					}
				}
	        }
	        else if (PAD_ButtonsHeld(0) & PAD_BUTTON_UP)
	        {
		        dirY = 4;
	        }
		}

		if((dirX == 0) && (dirY == 0)) //If the player isnt moving, set the animation to the start
		{
			totalTime += deltaTime;
			switchTime = 2.0f;
			if(faceRight) // play idle animation facing right
			{
				if(totalTime >= switchTime)
				{
					totalTime -= switchTime;
					playerRect++;

					if(playerRect>5)
						playerRect = 0;
				}
			}
			else // play idle animation facing left
			{
				if(totalTime >= switchTime)
				{
					totalTime -= switchTime;
					playerRect++;

					if(playerRect>10)
						playerRect = 6;
				}
			}
        }
		
		if(((MapCollider[9+startY][10+startX]==90) || (MapCollider[9+startY][11+startX]==90)) || ((MapCollider[9+startY][10+startX]==95) || (MapCollider[9+startY][11+startX]==95))) 
		{
        }
        else
		{
            dirX=0;
            dirY=-4;

        		if (faceRight)
        		{
        			playerRect = 28;
        		}
				else
				{
					playerRect = 29;
				}
        }
		
		if(dirX<0) // moving right
		{
            if((MapCollider[7+startY][12+startX]==98) || (MapCollider[7+startY][12+startX]==99) || (MapCollider[8+startY][12+startX]==98) || (MapCollider[8+startY][12+startX]==99)) 
			{
                dirX=0;
            }
            else 
			{

            	totalTime += deltaTime;
            	switchTime = 0.9f; // Updates the speed of the animation
				if(totalTime >= switchTime)
				{
					totalTime -= switchTime;
					playerRect++;

					if(playerRect>19)
						playerRect = 12;
				}
            }
        }
        else if(dirX>0) // moving left
		{
            if((MapCollider[7+startY][9+startX]==98) || (MapCollider[7+startY][9+startX]==99) || (MapCollider[8+startY][9+startX]==98) || (MapCollider[8+startY][9+startX]==99)) 
			{
                dirX=0;
            }
            else 
			{
            	totalTime += deltaTime;
            	switchTime = 0.9f; // Updates the speed of the animation
				if(totalTime >= switchTime)
				{
					totalTime -= switchTime;
					playerRect++;

					if(playerRect>27)
						playerRect = 20;
				}
           }
        }

		if(dirY < 0) 
		{
			//If tile below/above is equal to 90 then your Y axis is equal to zero
            if((MapCollider[9+startY][10+startX] == 90) || (MapCollider[9+startY][11+startX] == 90)) 
			{
                dirY = 0;
            }
        }
		if(dirY != 0)  //If it doesnt equal zero then play an animation
		{
	        	if (faceRight)
        		{
        			playerRect = 28; // Jump/Fall right
        		}
				else
				{
					playerRect = 29; // Jump/Fall left
				}
        }

		if((MapCollider[8+startY][10+startX] == 91) || (MapCollider[8+startY][11+startX] == 91)) // If in the water take damage
		{
			curHp--;     // Need to implement a timer of taking damage 943
			if (curHp == 0)
			{
				isAlive = false;
			}
		}
		
		//OffsetX code
		offsetX+=dirX;
        if(dirX>0)
            bgX++;
        else if(dirX<0)
            bgX--;
        if((bgX>-90) || (bgX<-63))
            bgX=-32;

        if(offsetX==32) {
            offsetX=0;
            dirX=0;
            startX--;
        }
        else if(offsetX==-32) {
            offsetX=0;
            dirX=0;
            startX++;
        }

		//OffsetY code
		offsetY+=dirY;
        if(dirY>0)
            bgY++;
        else if(dirY<0)
            bgY--;
        if((bgY>-90) || (bgY<-63))
            bgY=-32;

        if(offsetY==32) {
            offsetY=0;
            dirY=0;
            startY--;
        }
        else if(offsetY==-32) {
            offsetY=0;
            if(((MapCollider[9+startY][10+startX]==90) || (MapCollider[9+startY][11+startX]==90)) || ((MapCollider[9+startY][10+startX]==95) || (MapCollider[9+startY][11+startX]==95))) {
                dirY=0;
            }
            startY++;
        }
	}