#include "WorldGen.h"
#include <cmath>
#include "ImageManager.h"

#define IYMAX 255
#define IXMAX 255

WorldGen::WorldGen()
{
}

WorldGen::~WorldGen()
{
}


// Function to linearly interpolate between a0 and a1
// Weight w should be in the range [0.0, 1.0]
float WorldGen::lerp(float a0, float a1, float weight)
{
	return (1.0 - weight)*a0 + weight*a1;
}

// Computes the dot product of the distance and gradient vectors
float WorldGen::dotGridGradient(float ix, float iy, float x, float y)
{
	// Precomputed (or otherwise) gradient vectors at each grid node
	std::vector<std::vector<std::vector<float>>> gradient;
	
	gradient[IYMAX][IXMAX][2];
	//float Gradient[IYMAX][IXMAX][2];

	// Compute the distance vector
	float dx = x - ix;
	float dy = y - iy;

	// Compute the dot-product
	return (dx*gradient[iy][ix][0] + dy*gradient[iy][ix][1]);

}

// Compute Perlin noise at coordinates x, y
float WorldGen::perlin(float x, float y)
{
	// Determine grid cell coordinates
	int x0 = floor(x);
	int x1 = x0 + 1;
	int y0 = floor(y);
	int y1 = y0 + 1;

	// Determine interpolation weights
	// Could also use higher order polynomial/s-curve here
	float sx = x - x0;
	float sy = y - y0;

	// Interpolate between grid point gradients
	float n0, n1, ix0, ix1, value;

	n0 = dotGridGradient(x0, y0, x, y);
	n1 = dotGridGradient(x1, y0, x, y);
	ix0 = lerp(n0, n1, sx);
	n0 = dotGridGradient(x0, y1, x, y);
	n1 = dotGridGradient(x1, y1, x, y);
	ix1 = lerp(n0, n1, sx);
	value = lerp(ix0, ix1, sy);

	return value;
}

//load all the sprites for the world.
bool WorldGen::loadTiles(SDL_Texture* image, SDL_Renderer* renderer, std::array<SDL_Rect, total_sprites>& tileSet)
{
	
	ImageManager load;
	
	load.renderTexture(indexX, indexY, image, renderer, &tileSet.at(darkGrass));
	perlin(indexX, indexY);

	return true;
}

//load all the items
bool WorldGen::loadItems(SDL_Texture* image, SDL_Texture* msgEvent, SDL_Renderer* renderer, std::array<SDL_Rect, total_sprites>& tileSet)
{
	return true;
}