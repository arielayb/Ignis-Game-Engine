#ifndef WORLD_GEN_H
#define WORLD_GEN_H

#include "WorldInterface.h"

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

class DLLAPI WorldGen : public WorldInterface
{
	private:
		//set the indexes of the map
		float indexX = 0.0f;
		float indexY = 0.0f;


	public:
		WorldGen();
		~WorldGen();

		int seed;
		int width;
		int height;

		// Function to linearly interpolate between a0 and a1
		// Weight w should be in the range [0.0, 1.0]
		float lerp(float a0, float a1, float weight);

		// Computes the dot product of the distance and gradient vectors.
		float dotGridGradient(float ix, float iy, float x, float y);

		// Compute Perlin noise at coordinates x, y
		float perlin(float x, float y);

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

