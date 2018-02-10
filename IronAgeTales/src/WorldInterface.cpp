#include <fstream>
#include <iostream>
#include <thread>
#include <vector>

#include "WorldInterface.h"

WorldInterface::WorldInterface()
{
	//the player's velocity
	velX = 0.0f;
	velY = 0.0f;

	//player's position
	xPos = 280.0f;
	yPos = 100.0f;

	//check for hero default sprite
	loaded_hero = false;

	//set the attack to false
	attack = false;

	/*set the level parameters:
	there's 40 x 40 =  1600 tiles. Each tile has a width and height of 20.
	Therefore, 40 tiles of 20 width and height of image 20 X 40 = 800 */
	levelWidth_  = 800;
	levelHeight_ = 800;

	tileHeight_  = 20;
	tileWidth_   = 20;

	eventsEnabled = true;
}

WorldInterface::~WorldInterface()
{
}

//the input of the player's control
void WorldInterface::playerInput(SDL_Event events)
{
	//movement part
	if (events.type == SDL_KEYDOWN && events.key.repeat == 0)
	{
		switch (events.key.keysym.sym)
		{
			case SDLK_UP:
				playerUp = true;
				if (playerUp == true)
				{
					velY -= player_vel;
				}
				break;
			case SDLK_DOWN:
				playerDown = true;
				playerFacingDown = true;
				if (playerDown == true)
				{
					velY += player_vel;
				}
				break;
			case SDLK_LEFT:
				playerLeft = true;
				if (playerLeft == true)
				{
					velX -= player_vel;
				}
				break;
			case SDLK_RIGHT:
				playerRight = true;
				if (playerRight == true)
				{
					velX += player_vel;
				}
				break;
		}
	}
	else if (events.type == SDL_KEYUP && events.key.repeat == 0)
	{
		switch (events.key.keysym.sym)
		{
			case SDLK_UP:
				playerUp = false;
				if (playerUp == false)
				{
					velY += player_vel;
				}
				break;
			case SDLK_DOWN:
				playerDown = false;
				if (playerDown == false)
				{
					velY -= player_vel;
				}
				break;
			case SDLK_LEFT:
				playerLeft = false;
				if (playerLeft == false)
				{
					velX += player_vel;
				}
				break;
			case SDLK_RIGHT:
				playerRight = false;
				if (playerRight == false)
				{
					velX -= player_vel;
				}
				break;
		}
	}

	//action inputs
	if (events.type == SDL_KEYDOWN && events.key.repeat == 0)
	{
		switch (events.key.keysym.sym)
		{
			case SDLK_z:
				eventTouch = true;
			break;
			case SDLK_x:
				attack = true;
				std::cout << "the attack key was pressed" << std::endl;
				if (playerFacingDown == true && attackDown ==false)
				{
					attackDown = true;
				}
			break;
		}
	}
	else if (events.type == SDL_KEYUP && events.key.repeat == 0)
	{
		switch (events.key.keysym.sym)
		{
			case SDLK_z:
				eventTouch = false;
			break;
			case SDLK_x:
				attack = false;
			break;
		}
	}

	//If mouse event happened 
	if (events.type == SDL_MOUSEMOTION || events.type == SDL_MOUSEBUTTONDOWN || events.type == SDL_MOUSEBUTTONUP)
	{ 
		//Get mouse position 
		SDL_GetMouseState(&mouseXPosition, &mouseYPosition);
		std::cout << "x: " << mouseXPosition << " y: " << mouseYPosition << std::endl;
	}

}

//the player's animation.
SDL_Rect WorldInterface::playerAnimation(SDL_Rect player, std::array<SDL_Rect, total_sprites> tileSet)
{
	SDL_Rect moveUp[6] = {
		tileSet.at(heroup1), tileSet.at(heroup2), tileSet.at(heroup3),
		tileSet.at(heroup1), tileSet.at(heroup4), tileSet.at(heroup5)
	};

	SDL_Rect moveDown[6] = {
		tileSet.at(herodown1), tileSet.at(herodown2), tileSet.at(herodown3),
		tileSet.at(herodown1), tileSet.at(herodown4), tileSet.at(herodown5)
	};

	SDL_Rect moveRight[6] = {
		tileSet.at(heroright2), tileSet.at(heroright3), tileSet.at(heroright1),
		tileSet.at(heroright4), tileSet.at(heroright5), tileSet.at(heroright1)
	};

	SDL_Rect moveLeft[6] = {
		tileSet.at(heroleft2), tileSet.at(heroleft3), tileSet.at(heroleft1),
		tileSet.at(heroleft4), tileSet.at(heroleft5), tileSet.at(heroleft1)
	};
	
	if (playerUp == true && playerDown == false )
	{
		player = moveUp[playerFrame/6];

		playerFrame++;
		if (playerFrame / 6 >= 6)
		{
			playerFrame = 0;
		}
	}
	else if (playerDown == true && playerUp == false )
	{
		player = moveDown[playerFrame/6];
		
		playerFrame++;
		if (playerFrame / 6 >= 6)
		{
			playerFrame = 0;
		}
	}
	else if (playerRight == true && playerLeft == false )
	{
		player = moveRight[playerFrame / 6];

		playerFrame++;
		if (playerFrame / 6 >= 6)
		{
			playerFrame = 0;
		}
	}
	else if (playerLeft == true && playerRight == false )
	{
		player = moveLeft[playerFrame / 6];

		playerFrame++;
		if (playerFrame / 6 >= 6)
		{
			playerFrame = 0;
		}
	}

	return player;
}

SDL_Rect WorldInterface::playerSwordAttackAnimation(SDL_Rect player, std::array<SDL_Rect, total_sprites> tileSet)
{
	SDL_Rect playerSwordAttackDown[4] = {
		tileSet.at(heroAttackDown1), tileSet.at(heroAttackDown2),
		tileSet.at(heroAttackDown3), tileSet.at(herodown1)
	};

	if (playerFacingDown == true)
	{
		if (attackDown == true)
		{
			player = playerSwordAttackDown[playerFrame / 4];

			playerFrame++;
			if (playerFrame / 4 >= 4)
			{
				playerFrame = 0;
				attackDown  = false;
			}
		}
	}

	return player;
}

//coin animation
SDL_Rect WorldInterface::coinAnimation(SDL_Rect coin, std::array<SDL_Rect, total_sprites> tileSet)
{
	
	SDL_Rect spin[4] = {
		tileSet.at(coinAnim1), tileSet.at(coinAnim2), 
		tileSet.at(coinAnim3), tileSet.at(coinAnim4)
	};

	coin = spin[coinFrame / 4];
		
	coinFrame++;
	if (coinFrame / 4 >= 4)
	{
		coinFrame = 0;
	}
	
	return coin;
}
