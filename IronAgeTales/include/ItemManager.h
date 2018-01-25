#ifndef _ITEMMANAGER_H_
#define _ITEMMANAGER_H_

#include "Main.h"

class ItemManager : public Main
{
	public:
		ItemManager();
		ItemManager(std::string itemType, SDL_Rect &item);
		~ItemManager();

		std::string getItemType(std::string itemType, SDL_Rect item);
		void setItemType(std::string itemType);
		void replaceItem(SDL_Rect item);
		SDL_Rect& getItem();
		SDL_Rect& setItem(SDL_Rect* item);
		bool updateItem(int indexX, int indexY, SDL_Texture* image, SDL_Renderer* renderer, SDL_Rect* item);

		//load all the items
		//bool loadItems(SDL_Texture* image, SDL_Renderer* renderer, std::array<SDL_Rect, total_sprites> tileSet, std::string event);

	private:
		SDL_Rect	*_item;
		std::string	_itemType;
};
#endif