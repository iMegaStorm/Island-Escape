#include <grrlib.h>
#include "Enemy.h"

Enemy::Enemy()
{
	#define GRRLIB_WHITE   0xFFFFFFFF
	dirX = 0, dirY = 0;
	skeletonRect = 0;
		//GRRLIB_Rectangle(player.x, player.y, 50, 50, GRRLIB_BLACK, 1);
		//GRRLIB_DrawImg(5, 5, tex_mario, 0, 0, 0xFFFFFFFF, 1);
		//GRRLIB_DrawImg(player.x, player.y, tex_ball, 0, 0, 0xFFFFFFFF, 1);
}
Enemy::~Enemy()
{}

void Enemy::Draw()
{
	//GRRLIB_Rectangle(200, 200, 100, 100, GRRLIB_WHITE, 1);
}

void Enemy::AIController()
{
	if ((dirX == 0) && (dirY == 0))
	{
		skeletonRect++;
		if(skeletonRect > 4)
			skeletonRect = 0;
	}
}

	//void Player::Inputs(int MapCollider[30][70])
	//{
	//	if((dirX == 0) && (dirY == 0)) //If the player isnt moving, set the animation to the start
	//	{
	//		if (PAD_ButtonsHeld(0) & PAD_BUTTON_LEFT)
	//		{
	//			dirX = 4;
	//			playerRect = 15;
	//			faceRight = false;
	//		}
	//		else if (PAD_ButtonsHeld(0) & PAD_BUTTON_RIGHT)
	//		{
	//			dirX = -4;
	//			playerRect = 10;
	//			faceRight = true;
	//		}
	//        else if (PAD_ButtonsHeld(0) & PAD_BUTTON_DOWN)
	//        {
	//	        dirY = -4;
	//        }
	//        else if (PAD_ButtonsHeld(0) & PAD_BUTTON_UP)
	//        {
	//	        dirY = 4;
	//        }
	//			}

	//	if((dirX == 0) && (dirY == 0)) //If the player isnt moving, set the animation to the start
	//	{
	//		totalTime += deltaTime;
	//		switchTime = 1.2f;
	//		if(faceRight) // play idle animation facing right
	//		{
	//			if(totalTime >= switchTime)
	//			{
	//				totalTime -= switchTime;
	//				playerRect++;

	//				if(playerRect>4)
	//					playerRect = 0;
	//			}
	//		}
	//		else // play idle animation facing left
	//		{
	//			if(totalTime >= switchTime)
	//			{
	//				totalTime -= switchTime;
	//				playerRect++;

	//				if(playerRect>9)
	//					playerRect = 5;
	//			}
	//		}
 //       }
	//			
	//	if(dirX<0) // moving right
	//	{
 //           if((MapCollider[7+startY][12+startX]==98) || (MapCollider[7+startY][12+startX]==99) || (MapCollider[8+startY][12+startX]==98) || (MapCollider[8+startY][12+startX]==99)) 
	//		{
 //               dirX=0;
 //           }
 //           else 
	//		{

 //           	totalTime += deltaTime;
 //           	switchTime = 0.5f; // Updates the speed of the animation
	//			if(totalTime >= switchTime)
	//			{
	//				totalTime -= switchTime;
	//				playerRect++;

	//				if(playerRect>14)
	//					playerRect = 10;
	//			}
 //           }
 //       }
 //       else if(dirX>0) // moving left
	//	{
 //           if((MapCollider[7+startY][9+startX]==98) || (MapCollider[7+startY][9+startX]==99) || (MapCollider[8+startY][9+startX]==98) || (MapCollider[8+startY][9+startX]==99)) 
	//		{
 //               dirX=0;
 //           }
 //           else 
	//		{
 //           	totalTime += deltaTime;
 //           	switchTime = 0.5f; // Updates the speed of the animation
	//			if(totalTime >= switchTime)
	//			{
	//				totalTime -= switchTime;
	//				playerRect++;

	//				if(playerRect>19)
	//					playerRect = 15;
	//			}
 //          }
 //       }

	//	if(dirY < 0) 
	//	{
	//		//If tile below/above is equal to 90 then your Y axis is equal to zero
 //           if((MapCollider[9+startY][10+startX] == 90) || (MapCollider[9+startY][11+startX] == 90)) 
	//		{
 //               dirY = 0;
 //           }
 //       }
	//	if(dirY != 0)  //If it doesnt equal zero then play an animation
	//	{
 //           playerRect++;
 //           if(playerRect > 0)
 //               playerRect = 0;
 //       }
	//}