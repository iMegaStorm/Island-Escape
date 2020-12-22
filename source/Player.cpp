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
		curHp = 30;
		isAlive = true;
		isLevelCompleted = false;
		showFont = false;
		x = 288, y = 192;
		totalDeathTime = 50.0f;
		deathTime = 1.0f;
		
		key = 0;
	}

	Player::~Player()
	{
	}	

	void Player::Inputs(signed int MapCollider[40][70], signed short MapGraphics[40][70])
	{
	
		if((dirX == 0) && (dirY == 0) && isAlive == true && isLevelCompleted == false) //If the player isnt moving, set the animation to the start
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
			else if (curHp <= 0)
			{
				playerRect = 31;
			}
		}
		else if (isAlive == false)
		{
			if(faceRight)
				playerRect = 30;
			else
				playerRect = 31;
		}
		
		if((dirX == 0) && (dirY == 0) && isAlive) //If the player isnt moving, set the animation to the start
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
        {
            bgX++;  
        }
        else if(dirX<0)
        {
            bgX--;
        }
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

		if (PAD_ButtonsHeld(0) & PAD_BUTTON_A)
		{
			if(MapGraphics[8+startY][10+startX] == 54) // Changes the tile on the players feet
			{
				MapGraphics[8+startY][10+startX] = 58;
				key += 1;
			}
			else if(MapGraphics[8+startY][11+startX] == 54)
			{
				MapGraphics[8 + startY][11 + startX] = 58;
				key += 1;
			}

			if(((MapCollider[8+startY][10+startX] == 97) || (MapCollider[8+startY][11+startX] == 97)) && key == 3 && PAD_ButtonsHeld(0) & PAD_BUTTON_A)
			{
				isLevelCompleted = true;
			}	
		}

		if(curHp <= 0)
		{
			
			if (totalDeathTime >= deathTime)
			{
				deathTime += 1;
			}
			else
			{
				showFont = true;
			}
		}
	}

	// Dev Cheat Mode
	//if (PAD_ButtonsHeld(0) & PAD_BUTTON_X)
	//{
	//	//x = 288, y = 192;
	//	//this->startX = 0, this->startY = 0;
	//	//this->dirX = 0;
	//	//this->dirY = 0;
	//	//this->offsetX = 0, this->offsetY = 0;
	//	//this->bgX = -32, this->bgY = -32;
	//	//key = 0;*/
	//	//key = 3;
	//	//isLevelCompleted = true;
	//	//curHp = 0;
	//	//showFont = true;
	//}

