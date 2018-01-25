#ifndef _TESTLEVEL_H_
#define _TESTLEVEL_H_

#include "WorldInterface.h"

class TestLevel : public WorldInterface
{
	public:
		
		TestLevel();
		~TestLevel();

		//this loads the total of tiles
		static const int total_tiles = 1599;

		//load all the sprites for the world.
		bool loadTiles(SDL_Texture* image, SDL_Renderer* renderer, std::array<SDL_Rect, total_sprites> tileSet, std::string level, std::string event);

		//load the collision for this world
		bool loadWalls(SDL_Rect collision, std::array<SDL_Rect, total_tiles> &wall);

		//load the collision for events
		bool loadEvents(SDL_Rect collision, std::array<SDL_Rect, total_tiles> &event);

		//the collision management and set of wall detection for the player.
		void collisionManagement(SDL_Rect playerBox, std::array<SDL_Rect, total_tiles> &wallBox, std::array<SDL_Rect, total_tiles> &eventBox);

		//the collision detection fucntion
		bool checkingCollisions(SDL_Rect playerBox, SDL_Rect wall);

};
#endif