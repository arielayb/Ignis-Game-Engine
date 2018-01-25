#ifndef IMAGELOADER_H
#define IMAGELOADER_H

#include "ImageManager.h"
#include <array>
#include <vector>

class ImageLoader : public ImageManager
{
	public:
		ImageLoader();
		ImageLoader(SDL_Texture* image, SDL_Renderer* render);
		~ImageLoader();

		//load the sprites from the image file
		bool load_sprites(std::array<SDL_Rect, Main::total_sprites> &sprites, SDL_Texture *image, SDL_Renderer* renderer);
		bool load_itemEvents(std::array<SDL_Rect, Main::total_sprites> &sprites, SDL_Texture *image, SDL_Renderer* renderer);
		bool load_msg(std::array<SDL_Rect, Main::total_msgtiles>& msgSprites, SDL_Texture *image, SDL_Renderer* renderer);

		SDL_Texture* setImage(SDL_Texture* image);
		SDL_Texture* setMsgImage(SDL_Texture* msgImage);
		SDL_Renderer* setRenderer(SDL_Renderer* render);

	private:
		SDL_Texture*  _image;
		SDL_Texture*  _msgImage;
		SDL_Renderer* _render;
};

#endif