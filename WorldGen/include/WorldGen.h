#ifndef WORLD_GEN_H
#define WORLD_GEN_H

#include "WorldInterface.h"

class WorldGen : public WorldInterface
{
	private:

	public:
		unsigned const int seed;
		int width;
		int height;

		// Function to linearly interpolate between a0 and a1
		// Weight w should be in the range [0.0, 1.0]
		float lerp(float a0, float a1, float weight);

		// Computes the dot product of the distance and gradient vectors.
		float dotGridGradient(float ix, float iy, float x, float y);

		// Compute Perlin noise at coordinates x, y
		float perlin(float x, float y);
};

#endif

