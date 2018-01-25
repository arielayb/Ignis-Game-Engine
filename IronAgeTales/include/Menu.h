#ifndef MENU_H
#define MENU_H

#include "Main.h"

class Menu : public Main
{
	public:
		void SetMenu(SDL_Texture* image, SDL_Renderer* render);
		void LoadMenu(SDL_Texture* image, SDL_Renderer* render);
	private:
		//the x and y position of the arrow selection sprite
		
};

#endif