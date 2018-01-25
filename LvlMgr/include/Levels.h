#ifndef _LEVEL_H_
#define _LEVEL_H_

#include <vector>
#include "WorldInterface.h"
#include <stdlib.h>
#include "ItemManager.h"
#include <Windows.h>

#if defined(__APPLE__)
#include <OpenGL/gl3.h>
#else
//#include "glew/glew.h"
#endif

//#include "glfw/glfw3.h"
#include <stdio.h>

#ifdef MAKEDLL
	#define DLLAPI __declspec(dllexport)
#else
	#define DLLAPI __declspec(dllimport)
#endif

class DLLAPI Levels : public WorldInterface
{
	private:

		//location of the coin index from the array
		int coinIndex;

		//  testing
		int eventIndex;
		int transitionIndex;

		int itemIndex;
		int totalCoins;

		//set a temp position for the player
		int tempXPos;
		int tempYPos;

		//temp variable
		SDL_Rect coin;

		std::string _levelfile;
		std::string _eventfile;

		std::string _prevLevelfile;
		std::string _prevEventfile;

		std::string itemType;

		//event touched by plaer
		bool eventActive;

		//visit next level
		bool nextLevel;
		bool nextEvents;
		bool changedLevel;
		bool prevChangedLevel;

		//previous level
		bool previousLevel;

		//collected object
		bool collectedObject;

		bool overrideIndex;

		ItemManager* coinCollected;

		//collecting coins started?
		bool collectionStarted;

		//  set the box2d stuff here
		//b2Body  * _body;
		//b2World * _world;

		//b2FixtureDef _fixtureDef;

		//b2BodyDef _bodyDef;

		////  player's collision box
		//b2PolygonShape _playerShape;

		////  test box for collision
		//b2PolygonShape _boxTest;

		//  debug draw for box2s
		//BoxDebugDraw draw;
		//DebugDraw draw;

	public:

		Levels();

		~Levels();

		//keep track of coins
		int coinCount;
	
		//set camera 
		SDL_Rect Camera;

		//ItemManager* coinCollected;
	
		//set of walls from the loaded map
		std::array<SDL_Rect, total_tiles> setOfWalls;

		//set of events from the loaded event
		std::array<SDL_Rect, total_tiles> setOfEvents;

		//set of coins
		std::array<SDL_Rect, total_tiles> setOfCoins;
	
		//set of transition levels
		std::array<SDL_Rect, total_tiles> setOfTransition;

		//load all the sprites for the world.
		//bool loadTiles(SDL_Texture* image, SDL_Renderer* renderer, std::array<SDL_Rect, total_sprites>& tileSet, std::string level);
		bool loadTiles(SDL_Texture* image, SDL_Renderer* renderer, std::array<SDL_Rect, total_sprites>& tileSet);

		//load all the items
		//bool loadItems(SDL_Texture* image, SDL_Texture* msgEvent, SDL_Renderer* renderer, std::array<SDL_Rect, total_sprites>& tileSet, std::array<SDL_Rect, total_msgtiles>& msgsprites, std::string eventLayer);
		bool loadItems(SDL_Texture* image, SDL_Texture* msgEvent, SDL_Renderer* renderer, std::array<SDL_Rect, total_sprites>& tileSet);

		//load the collision for this world
		bool loadWalls(SDL_Rect collision, std::array<SDL_Rect, total_tiles> wall);

		//load the collision for events
		bool loadEvents(SDL_Rect collision, std::array<SDL_Rect, total_tiles> event);

		//load the next level
		bool loadTransition(SDL_Rect collision, std::array<SDL_Rect, total_tiles> transition);

		//load the collision for coins
		bool loadCoins(SDL_Rect collision, std::array<SDL_Rect, total_tiles>& coins);

		//the collision management and set of wall detection for the player.
		void collisionManagement(SDL_Rect playerBox, std::array<SDL_Rect, total_tiles> wallBox, std::array<SDL_Rect, total_tiles> eventBox, std::array<SDL_Rect, total_tiles>& coins);
		//void collisionManagement(SDL_Rect playerBox);

		//the collision detection fucntion
		bool checkingCollisions(SDL_Rect playerBox, SDL_Rect object);

		//set the coins to zero!
		SDL_Rect storeTiles(int x, int y, int tileHeight, int tileWidth, SDL_Rect tile);
		
		//change the render image for the coin that was collected
		bool collectedCoin(SDL_Rect coin, SDL_Texture *image);

		//box2d testbed
		//void testBed();

		//set the level string
		std::string setLevel(std::string level);

		//set the event string
		std::string setEvent(std::string events);

};

extern "C" DLLAPI WorldInterface* __cdecl createLevel()
{

	//return the created function
	return new Levels();
}

#endif

