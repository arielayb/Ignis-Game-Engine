#include "ItemManager.h"
#include "ImageLoader.h"

ItemManager::ItemManager()
{}

ItemManager::ItemManager(std::string itemType, SDL_Rect &item)
{
	_itemType = itemType;
	_item	  = &item;

}

ItemManager::~ItemManager()
{
	
}

std::string ItemManager::getItemType(std::string itemType, SDL_Rect item)
{
	itemType = _itemType;
	item	 = *_item;

	if (itemType == "coin")
	{
		
	}

	return itemType;
}

void ItemManager::setItemType(std::string itemType)
{
	_itemType = itemType;
}

SDL_Rect& ItemManager::getItem()
{
	return *_item;
}

SDL_Rect& ItemManager::setItem(SDL_Rect* item)
{
	_item = item;

	return *_item;
}

bool ItemManager::updateItem(int indexX, int indexY, SDL_Texture* image, SDL_Renderer* renderer, SDL_Rect* item)
{
	ImageLoader load;

	load.renderTexture(indexX, indexY, image, renderer, item);

	return true;
}