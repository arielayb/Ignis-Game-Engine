#ifndef _IMAGEMANAGER_H_
#define _IMAGEMANAGER_H_

#include <sstream>
#include <stdio.h>
#include <string>
#include "Main.h"

//load images and other media
class ImageManager : public Main
{
	public:
		ImageManager();
		ImageManager(SDL_Texture* image, SDL_Renderer* render);
		
		~ImageManager();
	
		static const int layers = 2;

		//layers for the sdl_surface
		//std::array<SDL_Surface*, layers> loaded_surface;

		//list of layers
		enum layerSet{layers0 = 0, layers1 = 1};

		//the state of the layer
		int layerState = 0;

		//load the texture and font
		SDL_Texture* loadTexture(std::string file, SDL_Texture *textures, SDL_Renderer *render);
		SDL_Texture* loadFont(std::string time, TTF_Font* fontType, SDL_Color fontColor, SDL_Renderer* render);

		//render image
		bool renderTexture(float x, float y, SDL_Texture* image, SDL_Renderer* render, SDL_Rect* clip);

	private:
		SDL_Texture* _image;
		SDL_Renderer* _render;
};

#endif