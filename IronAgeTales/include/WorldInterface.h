//this is the wold map. Everything in the world will be drawn here.

#ifndef _WORLD_H_
#define _WORLD_H_

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <SDL_timer.h>

#include <array>
#include "ItemManager.h"
#include "Main.h"

class WorldInterface : public Main
{
	private:
		
		//the tile's width and height
		int tileHeight_;
		int tileWidth_;

		//generate the world map
		bool generate;

		//set the level parameters
		int levelWidth_;
		int levelHeight_;
	
		//this loads the total of tiles
		static const int total_tiles = 1599;

		//the player's velocity
		float velX;
		float velY;

		////set camera 
		//SDL_Rect camera = {
		//	0, 0, screen_width, screen_height
		//};

		//Maximum axis velocity of the player
		float player_vel = 2.0f;

		//player's collision box
		SDL_Rect collision;

		//events are enabled
		bool eventsEnabled;

		//the player's sprite
		SDL_Rect player;

		SDL_Rect testTile;

		//check for hero default sprite
		bool loaded_hero;

		//check if the user quit the game
		bool quit;

		//the animation frame
		int playerFrame = 0;
		int coinFrame   = 0;

		//player's position
		float xPos;
		float yPos;

		friend class Levels;
		friend class WorldGen;
		friend class MsgManager;

	public:	
		
		//constructor and destructor
		WorldInterface();

		virtual ~WorldInterface();
		
		//the mouse x and y position
		int mouseXPosition, mouseYPosition;

		//determine if the player move up
		bool playerUp;
		bool playerDown;
		bool playerLeft;
		bool playerRight;

		//player facing
		bool playerFacingUp;
		bool playerFacingDown;
		bool playerFacingLeft;
		bool playerFacingRight;


		//player action
		bool eventTouch;
		bool attack;
		bool attackDown;
		bool attackUp;
		bool attackLeft;
		bool attackRight;


		//the input for the player.
		void playerInput(SDL_Event events);

		static const int total_sprites = 87;

		/*
		* pure virtual functions
		*/
		
		//load every tile and setup the width and height.
		//virtual SDL_Rect storeTiles(int x, int y, int tileHeight, int tileWidth, SDL_Rect tile) = 0;
		
		//load all the sprites for the world.
		virtual bool loadTiles(SDL_Texture* image, SDL_Renderer* renderer, std::array<SDL_Rect, total_sprites>& tileSet) = 0;

		//load all the items for the world
		virtual bool loadItems(SDL_Texture* image, SDL_Texture* msgEvent, SDL_Renderer* renderer, std::array<SDL_Rect, total_sprites>& tileSet) = 0;

		/**********************/

		//set the animation for the player
		SDL_Rect playerAnimation(SDL_Rect player, std::array<SDL_Rect, total_sprites> tileSet);
		SDL_Rect playerSwordAttackAnimation(SDL_Rect player, std::array<SDL_Rect, total_sprites> tileSet);

		//set the animation for the player
		SDL_Rect coinAnimation(SDL_Rect coin, std::array<SDL_Rect, total_sprites> tileSet);
};

#endif