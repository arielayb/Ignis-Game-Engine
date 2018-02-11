#ifndef WORLD_GEN_H
#define WORLD_GEN_H

#include <vector>
#include "WorldInterface.h"
#include <stdlib.h>
#include "ItemManager.h"
#include <Windows.h>
//#include "FastNoise.h"

//#if defined(__APPLE__)
//#include <OpenGL/gl3.h>
//#else
////#include "glew/glew.h"
//#endif

//#include "glfw/glfw3.h"
#include <stdio.h>

#ifdef MAKEDLL
#define DLLAPI __declspec(dllexport)
#else
#define DLLAPI __declspec(dllimport)
#endif

class DLLAPI WorldGen : public WorldInterface
{
	private:

		std::string _levelfile;
		std::string _genMap;
		//FastNoise noise;

		bool generated;

	public:
		WorldGen();
		~WorldGen();

		int seed;
		int width;
		int height;

		//load all the world sprites for the level.
		bool loadWorldTiles(SDL_Texture* image, SDL_Renderer* renderer, std::array<SDL_Rect, total_worldMapSprites>& worldTileSet);

		//load all the sprites for the world.
		bool loadTiles(SDL_Texture* image, SDL_Renderer* renderer, std::array<SDL_Rect, total_sprites>& tileSet);

		//load all the items
		bool loadItems(SDL_Texture* image, SDL_Texture* msgEvent, SDL_Renderer* renderer, std::array<SDL_Rect, total_sprites>& tileSet);

};

extern "C" DLLAPI WorldInterface* __cdecl createWorld()
{

	//return the created function
	return new WorldGen();
}

#endif

