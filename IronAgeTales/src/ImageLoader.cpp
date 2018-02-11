#include "ImageLoader.h"
#include "ImageManager.h"

ImageLoader::ImageLoader()
{}

ImageLoader::ImageLoader(SDL_Texture* image, SDL_Renderer* render)
{
	_image  = image;
	_render = render;
}


ImageLoader::~ImageLoader()
{}

//A.A: This long piece of code loads all the sprites from the sprite sheet.
bool ImageLoader::load_sprites(std::array<SDL_Rect, Main::total_sprites> &sprites, SDL_Texture *image, SDL_Renderer* renderer)
{
	
	ImageManager manage;

	// load the image file
	image   = manage.loadTexture("images/IgnisSheet.png", image, renderer);
	_image	= image;
	_render = renderer;

	if (image == NULL)
	{
		printf("image failed to load %s\n", SDL_GetError());

		return false;
	}
	else
	{

		//Set the hero's sprite
		//the hero's sprite moving down.
		sprites[herodown1].x = 0;
		sprites[herodown1].y = 0;
		sprites[herodown1].w = 14;
		sprites[herodown1].h = 19;

		//sprites.push_back(store_sprite(0, 0, 14, 19, object));

		sprites[herodown2].x = 15;
		sprites[herodown2].y = 0;
		sprites[herodown2].w = 14;
		sprites[herodown2].h = 19;

		//sprites.push_back(store_sprite(15, 0, 14, 19, sprites));

		sprites[herodown3].x = 30;
		sprites[herodown3].y = 0;
		sprites[herodown3].w = 14;
		sprites[herodown3].h = 19;

		//sprites.push_back(store_sprite(30, 0, 14, 19, sprites));

		sprites[herodown4].x = 44;
		sprites[herodown4].y = 0;
		sprites[herodown4].w = 14;
		sprites[herodown4].h = 19;

		//sprites.push_back(store_sprite(44, 0, 14, 19, sprites));

		sprites[herodown5].x = 59;
		sprites[herodown5].y = 0;
		sprites[herodown5].w = 14;
		sprites[herodown5].h = 19;

		//sprites.push_back(store_sprite(59, 0, 14, 19, sprites));

		//the hero's sprite moving up.
		sprites[heroup1].x = 0;
		sprites[heroup1].y = 62;
		sprites[heroup1].w = 14;
		sprites[heroup1].h = 19;

		//sprites.push_back(store_sprite(0, 62, 14, 19, sprites));

		sprites[heroup2].x = 15;
		sprites[heroup2].y = 62;
		sprites[heroup2].w = 14;
		sprites[heroup2].h = 19;

		//sprites.push_back(store_sprite(15, 62, 14, 19, sprites));

		sprites[heroup3].x = 30;
		sprites[heroup3].y = 62;
		sprites[heroup3].w = 14;
		sprites[heroup3].h = 19;

		//sprites.push_back(store_sprite(30, 62, 14, 19, sprites));

		sprites[heroup4].x = 45;
		sprites[heroup4].y = 62;
		sprites[heroup4].w = 14;
		sprites[heroup4].h = 19;

		//sprites.push_back(store_sprite(45, 62, 14, 19, sprites));

		sprites[heroup5].x = 60;
		sprites[heroup5].y = 62;
		sprites[heroup5].w = 14;
		sprites[heroup5].h = 19;

		//sprites.push_back(store_sprite(60, 62, 14, 19, sprites));

		//the hero's sprite moving right
		sprites[heroright1].x = 2;
		sprites[heroright1].y = 22;
		sprites[heroright1].w = 14;
		sprites[heroright1].h = 19;

		//sprites.push_back(store_sprite(2, 22, 14, 19, sprites));

		sprites[heroright2].x = 16;
		sprites[heroright2].y = 21;
		sprites[heroright2].w = 14;
		sprites[heroright2].h = 19;

		//sprites.push_back(store_sprite(16, 21, 14, 19, sprites));

		sprites[heroright3].x = 30;
		sprites[heroright3].y = 21;
		sprites[heroright3].w = 14;
		sprites[heroright3].h = 19;

		//sprites.push_back(store_sprite(30, 21, 14, 19, sprites));

		sprites[heroright4].x = 45;
		sprites[heroright4].y = 21;
		sprites[heroright4].w = 14;
		sprites[heroright4].h = 19;

		//sprites.push_back(store_sprite(45, 21, 14, 19, sprites));

		sprites[heroright5].x = 59;
		sprites[heroright5].y = 21;
		sprites[heroright5].w = 14;
		sprites[heroright5].h = 19;

		//sprites.push_back(store_sprite(59, 21, 14, 19, sprites));

		//the hero's sprite moving left
		sprites[heroleft1].x = 2;
		sprites[heroleft1].y = 42;
		sprites[heroleft1].w = 12;
		sprites[heroleft1].h = 19;

		//sprites.push_back(store_sprite(2, 42, 12, 19, sprites));

		sprites[heroleft2].x = 14;
		sprites[heroleft2].y = 41;
		sprites[heroleft2].w = 12;
		sprites[heroleft2].h = 19;

		//sprites.push_back(store_sprite(14, 41, 12, 19, sprites));

		sprites[heroleft3].x = 29;
		sprites[heroleft3].y = 41;
		sprites[heroleft3].w = 12;
		sprites[heroleft3].h = 19;

		//sprites.push_back(store_sprite(29, 41, 12, 19, sprites));

		sprites[heroleft4].x = 42;
		sprites[heroleft4].y = 41;
		sprites[heroleft4].w = 12;
		sprites[heroleft4].h = 19;

		//sprites.push_back(store_sprite(42, 41, 12, 19, sprites));

		sprites[heroleft5].x = 59;
		sprites[heroleft5].y = 41;
		sprites[heroleft5].w = 12;
		sprites[heroleft5].h = 19;

		//Hero attacks with a sword down
		sprites[heroAttackDown1].x = 277;
		sprites[heroAttackDown1].y = 295;
		sprites[heroAttackDown1].w = 21;
		sprites[heroAttackDown1].h = 20;

		sprites[heroAttackDown2].x = 302;
		sprites[heroAttackDown2].y = 296;
		sprites[heroAttackDown2].w = 18;
		sprites[heroAttackDown2].h = 21;

		sprites[heroAttackDown3].x = 329;
		sprites[heroAttackDown3].y = 296;
		sprites[heroAttackDown3].w = 13;
		sprites[heroAttackDown3].h = 28;

		sprites[heroAttackDown4].x = 347;
		sprites[heroAttackDown4].y = 295;
		sprites[heroAttackDown4].w = 24;
		sprites[heroAttackDown4].h = 24;

		//Hero attacks with a sword right
		sprites[heroAttackRight1].x = 278;
		sprites[heroAttackRight1].y = 327;
		sprites[heroAttackRight1].w = 11;
		sprites[heroAttackRight1].h = 21;

		sprites[heroAttackRight2].x = 299;
		sprites[heroAttackRight2].y = 327;
		sprites[heroAttackRight2].w = 18;
		sprites[heroAttackRight2].h = 21;

		sprites[heroAttackRight3].x = 325;
		sprites[heroAttackRight3].y = 329;
		sprites[heroAttackRight3].w = 24;
		sprites[heroAttackRight3].h = 19;

		sprites[heroAttackRight4].x = 354;
		sprites[heroAttackRight4].y = 329;
		sprites[heroAttackRight4].w = 20;
		sprites[heroAttackRight4].h = 19;

		sprites[heroAttackRight5].x = 382;
		sprites[heroAttackRight5].y = 329;
		sprites[heroAttackRight5].w = 18;
		sprites[heroAttackRight5].h = 19;

		//Hero attacks with a sword left
		sprites[heroAttackLeft1].x = 277;
		sprites[heroAttackLeft1].y = 351;
		sprites[heroAttackLeft1].w = 12;
		sprites[heroAttackLeft1].h = 21;

		sprites[heroAttackLeft2].x = 300;
		sprites[heroAttackLeft2].y = 349;
		sprites[heroAttackLeft2].w = 12;
		sprites[heroAttackLeft2].h = 23;

		sprites[heroAttackLeft3].x = 315;
		sprites[heroAttackLeft3].y = 353;
		sprites[heroAttackLeft3].w = 25;
		sprites[heroAttackLeft3].h = 19;

		sprites[heroAttackLeft4].x = 346;
		sprites[heroAttackLeft4].y = 353;
		sprites[heroAttackLeft4].w = 21;
		sprites[heroAttackLeft4].h = 19;

		sprites[heroAttackLeft5].x = 374;
		sprites[heroAttackLeft5].y = 353;
		sprites[heroAttackLeft5].w = 19;
		sprites[heroAttackLeft5].h = 19;

		//Hero attacks with a sword up
		sprites[heroAttackUp1].x = 277;
		sprites[heroAttackUp1].y = 379;
		sprites[heroAttackUp1].w = 12;
		sprites[heroAttackUp1].h = 20;

		sprites[heroAttackUp2].x = 290;
		sprites[heroAttackUp2].y = 381;
		sprites[heroAttackUp2].w = 16;
		sprites[heroAttackUp2].h = 19;

		sprites[heroAttackUp3].x = 310;
		sprites[heroAttackUp3].y = 374;
		sprites[heroAttackUp3].w = 14;
		sprites[heroAttackUp3].h = 26;

		sprites[heroAttackUp4].x = 327;
		sprites[heroAttackUp4].y = 375;
		sprites[heroAttackUp4].w = 16;
		sprites[heroAttackUp4].h = 25;

		//sprites.push_back(store_sprite(58, 41, 12, 19, sprites));

		//Set the grass tiles
		sprites[darkGrass].x = 154;
		sprites[darkGrass].y = 0;
		sprites[darkGrass].w = 20;
		sprites[darkGrass].h = 20;

		//sprites.push_back(store_sprite(154, 0, 20, 20, sprites));

		//grass with edges on dirt
		sprites[grassDirtHorizontal].x = 94;
		sprites[grassDirtHorizontal].y = 60;
		sprites[grassDirtHorizontal].w = 20;
		sprites[grassDirtHorizontal].h = 20;

		//sprites.push_back(store_sprite(94, 60, 20, 20, sprites));

		sprites[grassDirtVertical].x = 114;
		sprites[grassDirtVertical].y = 60;
		sprites[grassDirtVertical].w = 20;
		sprites[grassDirtVertical].h = 20;

		//sprites.push_back(store_sprite(114, 60, 20, 20, sprites));

		sprites[grassDirtTopLeft].x = 94;
		sprites[grassDirtTopLeft].y = 80;
		sprites[grassDirtTopLeft].w = 20;
		sprites[grassDirtTopLeft].h = 20;

		//sprites.push_back(store_sprite(94, 80, 20, 20, sprites));

		sprites[grassDirtTopRight].x = 114;
		sprites[grassDirtTopRight].y = 80;
		sprites[grassDirtTopRight].w = 20;
		sprites[grassDirtTopRight].h = 20;

		//sprites.push_back(store_sprite(114, 80, 20, 20, sprites));

		sprites[grassDirtBottomLeft].x = 114;
		sprites[grassDirtBottomLeft].y = 100;
		sprites[grassDirtBottomLeft].w = 20;
		sprites[grassDirtBottomLeft].h = 20;

		//sprites.push_back(store_sprite(114, 100, 20, 20, sprites));

		sprites[grassDirtBottomRight].x = 94;
		sprites[grassDirtBottomRight].y = 100;
		sprites[grassDirtBottomRight].w = 20;
		sprites[grassDirtBottomRight].h = 20;

		//sprites.push_back(store_sprite(94, 100, 20, 20, sprites));

		sprites[grassDirtHoriVerLeft].x = 114;
		sprites[grassDirtHoriVerLeft].y = 120;
		sprites[grassDirtHoriVerLeft].w = 20;
		sprites[grassDirtHoriVerLeft].h = 20;

		//sprites.push_back(store_sprite(114, 120, 20, 20, sprites));

		sprites[grassDirtHoriVerRight].x = 94;
		sprites[grassDirtHoriVerRight].y = 120;
		sprites[grassDirtHoriVerRight].w = 20;
		sprites[grassDirtHoriVerRight].h = 20;

		//sprites.push_back(store_sprite(94, 120, 20, 20, sprites));

		sprites[grassDirtVerHoriDown].x = 94;
		sprites[grassDirtVerHoriDown].y = 160;
		sprites[grassDirtVerHoriDown].w = 20;
		sprites[grassDirtVerHoriDown].h = 20;

		//sprites.push_back(store_sprite(94, 160, 20, 20, sprites));

		sprites[grassDirtVerHoriUp].x = 94;
		sprites[grassDirtVerHoriUp].y = 140;
		sprites[grassDirtVerHoriUp].w = 20;
		sprites[grassDirtVerHoriUp].h = 20;

		//sprites.push_back(store_sprite(94, 140, 20, 20, sprites));

		sprites[grassDirtFourPaths].x = 114;
		sprites[grassDirtFourPaths].y = 140;
		sprites[grassDirtFourPaths].w = 20;
		sprites[grassDirtFourPaths].h = 20;

		//sprites.push_back(store_sprite(114, 140, 20, 20, sprites));

		//dirt tilset
		sprites[dirt].x = 134;
		sprites[dirt].y = 40;
		sprites[dirt].w = 20;
		sprites[dirt].h = 20;

		//sprites.push_back(store_sprite(134, 40, 20, 20, sprites));

		//door sets
		sprites[woodDoor].x = 194;
		sprites[woodDoor].y = 0;
		sprites[woodDoor].w = 20;
		sprites[woodDoor].h = 20;

		//sprites.push_back(store_sprite(194, 0, 20, 20, sprites));

		sprites[event].x = 380;
		sprites[event].y = 380;
		sprites[event].w = 20;
		sprites[event].h = 20;

		sprites[transport].x = 380;
		sprites[transport].y = 380;
		sprites[transport].w = 20;
		sprites[transport].h = 20;

		sprites[previous].x = 380;
		sprites[previous].y = 380;
		sprites[previous].w = 20;
		sprites[previous].h = 20;

		//sprites.push_back(store_sprite(380, 380, 20, 20, sprites));

		//wall sets
		sprites[wallfront].x = 74;
		sprites[wallfront].y = 40;
		sprites[wallfront].w = 20;
		sprites[wallfront].h = 20;

		//sprites.push_back(store_sprite(74, 40, 20, 20, sprites));

		sprites[wallvertical].x = 74;
		sprites[wallvertical].y = 20;
		sprites[wallvertical].w = 20;
		sprites[wallvertical].h = 20;

		//sprites.push_back(store_sprite(74, 20, 20, 20, sprites));

		sprites[wallfrontendless].x = 94;
		sprites[wallfrontendless].y = 0;
		sprites[wallfrontendless].w = 20;
		sprites[wallfrontendless].h = 20;

		//sprites.push_back(store_sprite(94, 0, 20, 20, sprites));

		sprites[wallhorizontal].x = 114;
		sprites[wallhorizontal].y = 0;
		sprites[wallhorizontal].w = 20;
		sprites[wallhorizontal].h = 20;

		//sprites.push_back(store_sprite(114, 0, 20, 20, sprites));

		sprites[wallLeftCorner].x = 154;
		sprites[wallLeftCorner].y = 20;
		sprites[wallLeftCorner].w = 20;
		sprites[wallLeftCorner].h = 20;

		//sprites.push_back(store_sprite(154, 20, 20, 20, sprites));

		sprites[wallRightCorner].x = 154;
		sprites[wallRightCorner].y = 40;
		sprites[wallRightCorner].w = 20;
		sprites[wallRightCorner].h = 20;

		//sprites.push_back(store_sprite(154, 40, 20, 20, sprites));

		sprites[wallBottomLeftCorner].x = 214;
		sprites[wallBottomLeftCorner].y = 0;
		sprites[wallBottomLeftCorner].w = 20;
		sprites[wallBottomLeftCorner].h = 20;

		//sprites.push_back(store_sprite(214, 0, 20, 20, sprites));

		sprites[wallBottomRightCorner].x = 214;
		sprites[wallBottomRightCorner].y = 20;
		sprites[wallBottomRightCorner].w = 20;
		sprites[wallBottomRightCorner].h = 20;

		//sprites.push_back(store_sprite(214, 20, 20, 20, sprites));

		sprites[wallTop].x = 234;
		sprites[wallTop].y = 0;
		sprites[wallTop].w = 20;
		sprites[wallTop].h = 20;

		//sprites.push_back(store_sprite(234, 0, 20, 20, sprites));

		//tree walls
		sprites[treeWallTopEndless].x = 134;
		sprites[treeWallTopEndless].y = 100;
		sprites[treeWallTopEndless].w = 20;
		sprites[treeWallTopEndless].h = 20;

		//sprites.push_back(store_sprite(134, 100, 20, 20, sprites));

		sprites[treeWallTopEnd].x = 154;
		sprites[treeWallTopEnd].y = 140;
		sprites[treeWallTopEnd].w = 20;
		sprites[treeWallTopEnd].h = 20;

		//sprites.push_back(store_sprite(154, 140, 20, 20, sprites));

		sprites[treeWallBottom].x = 134;
		sprites[treeWallBottom].y = 120;
		sprites[treeWallBottom].w = 20;
		sprites[treeWallBottom].h = 20;

		//sprites.push_back(store_sprite(134, 120, 20, 20, sprites));

		sprites[treeWallVertical].x = 134;
		sprites[treeWallVertical].y = 140;
		sprites[treeWallVertical].w = 20;
		sprites[treeWallVertical].h = 20;

		//sprites.push_back(store_sprite(134, 140, 20, 20, sprites));

		sprites[treeWallCornerTopLeft].x = 154;
		sprites[treeWallCornerTopLeft].y = 100;
		sprites[treeWallCornerTopLeft].w = 20;
		sprites[treeWallCornerTopLeft].h = 20;

		//sprites.push_back(store_sprite(154, 100, 20, 20, sprites));

		sprites[treeWallCornerTopRight].x = 174;
		sprites[treeWallCornerTopRight].y = 100;
		sprites[treeWallCornerTopRight].w = 20;
		sprites[treeWallCornerTopRight].h = 20;

		//sprites.push_back(store_sprite(174, 100, 20, 20, sprites));

		sprites[treeWallCornerBottomLeft].x = 154;
		sprites[treeWallCornerBottomLeft].y = 120;
		sprites[treeWallCornerBottomLeft].w = 20;
		sprites[treeWallCornerBottomLeft].h = 20;

		//sprites.push_back(store_sprite(154, 120, 20, 20, sprites));

		sprites[treeWallCornerBottomRight].x = 174;
		sprites[treeWallCornerBottomRight].y = 120;
		sprites[treeWallCornerBottomRight].w = 20;
		sprites[treeWallCornerBottomRight].h = 20;

		//sprites.push_back(store_sprite(174, 120, 20, 20, sprites));

		sprites[treeWallMiddle].x = 174;
		sprites[treeWallMiddle].y = 140;
		sprites[treeWallMiddle].w = 20;
		sprites[treeWallMiddle].h = 20;

		//sprites.push_back(store_sprite(174, 140, 20, 20, sprites));

		//water animation
		sprites[water].x = 100;
		sprites[water].y = 100;
		sprites[water].w = 100;
		sprites[water].h = 100;

		//sprites.push_back(store_sprite(100, 100, 100, 100, sprites));

		//the arrow image properties
		sprites[arrow].x = 0;
		sprites[arrow].y = 390;
		sprites[arrow].w = 13;
		sprites[arrow].h = 10;

		//sprites.push_back(store_sprite(0, 390, 13, 10, sprites));

		//graveyard stuff
		sprites[grave].x = 134;
		sprites[grave].y = 20;
		sprites[grave].w = 20;
		sprites[grave].h = 20;

		//sprites.push_back(store_sprite(134, 20, 20, 20, sprites));

		sprites[tombstone].x = 94;
		sprites[tombstone].y = 40;
		sprites[tombstone].w = 20;
		sprites[tombstone].h = 20;

		//sprites.push_back(store_sprite(94, 40, 20, 20, sprites));

		sprites[cross].x = 174;
		sprites[cross].y = 0;
		sprites[cross].w = 20;
		sprites[cross].h = 20;

		//trees
		sprites[treeShortTopLeft].x = 134;
		sprites[treeShortTopLeft].y = 60;
		sprites[treeShortTopLeft].w = 20;
		sprites[treeShortTopLeft].h = 20;

		sprites[treeShortTopRight].x = 154;
		sprites[treeShortTopRight].y = 60;
		sprites[treeShortTopRight].w = 20;
		sprites[treeShortTopRight].h = 20;

		sprites[treeShortBotLeft].x = 134;
		sprites[treeShortBotLeft].y = 80;
		sprites[treeShortBotLeft].w = 20;
		sprites[treeShortBotLeft].h = 20;

		sprites[treeShortBotRight].x = 154;
		sprites[treeShortBotRight].y = 80;
		sprites[treeShortBotRight].w = 20;
		sprites[treeShortBotRight].h = 20;

		Main::storeSprite(sprites);
	}

	return true;
}

bool ImageLoader::load_itemEvents(std::array<SDL_Rect, Main::total_sprites> &sprites, SDL_Texture *image, SDL_Renderer* renderer)
{
	ImageManager* manage = new ImageManager();

	// load the image file
	image = manage->loadTexture("images/IgnisSheet.png", image, renderer);
	_image  = image;
	_render = renderer;

	if (_image == NULL)
	{
		printf("image failed to load %s\n", SDL_GetError());

		return false;
	}
	else
	{
		//coins/collectables
		sprites[coinAnim1].x = 326;
		sprites[coinAnim1].y = 163;
		sprites[coinAnim1].w = 9;
		sprites[coinAnim1].h = 9;

		//sprites.push_back(store_sprite(357, 83, 9, 9, sprites));

		sprites[coinAnim2].x = 347;
		sprites[coinAnim2].y = 163;
		sprites[coinAnim2].w = 6;
		sprites[coinAnim2].h = 9;

		//sprites.push_back(store_sprite(369, 83, 6, 9, sprites));

		sprites[coinAnim3].x = 369;
		sprites[coinAnim3].y = 163;
		sprites[coinAnim3].w = 3;
		sprites[coinAnim3].h = 9;

		//sprites.push_back(store_sprite(378, 83, 3, 9, sprites));

		sprites[coinAnim4].x = 387;
		sprites[coinAnim4].y = 163;
		sprites[coinAnim4].w = 7;
		sprites[coinAnim4].h = 9;
	
		Main::storeSprite(sprites);

	}

	return true;
}

//load sprites for the world map
bool ImageLoader::load_worldSprites(std::array<SDL_Rect, Main::total_worldMapSprites> &worldSprites, SDL_Texture *image, SDL_Renderer* renderer)
{

	ImageManager manage;

	// load the image file
	image = manage.loadTexture("images/IgnisSheet.png", image, renderer);
	_image = image;
	_render = renderer;

	if (image == NULL)
	{
		printf("image failed to load %s\n", SDL_GetError());

		return false;
	}
	else
	{

		//Set the grass tiles
		worldSprites[World_darkGrass].x = 154;
		worldSprites[World_darkGrass].y = 0;
		worldSprites[World_darkGrass].w = 20;
		worldSprites[World_darkGrass].h = 20;

		////sprites.push_back(store_sprite(154, 0, 20, 20, sprites));

		////grass with edges on dirt
		//sprites[grassDirtHorizontal].x = 94;
		//sprites[grassDirtHorizontal].y = 60;
		//sprites[grassDirtHorizontal].w = 20;
		//sprites[grassDirtHorizontal].h = 20;

		////sprites.push_back(store_sprite(94, 60, 20, 20, sprites));

		//sprites[grassDirtVertical].x = 114;
		//sprites[grassDirtVertical].y = 60;
		//sprites[grassDirtVertical].w = 20;
		//sprites[grassDirtVertical].h = 20;

		////sprites.push_back(store_sprite(114, 60, 20, 20, sprites));

		//sprites[grassDirtTopLeft].x = 94;
		//sprites[grassDirtTopLeft].y = 80;
		//sprites[grassDirtTopLeft].w = 20;
		//sprites[grassDirtTopLeft].h = 20;

		////sprites.push_back(store_sprite(94, 80, 20, 20, sprites));

		//sprites[grassDirtTopRight].x = 114;
		//sprites[grassDirtTopRight].y = 80;
		//sprites[grassDirtTopRight].w = 20;
		//sprites[grassDirtTopRight].h = 20;

		////sprites.push_back(store_sprite(114, 80, 20, 20, sprites));

		//sprites[grassDirtBottomLeft].x = 114;
		//sprites[grassDirtBottomLeft].y = 100;
		//sprites[grassDirtBottomLeft].w = 20;
		//sprites[grassDirtBottomLeft].h = 20;

		////sprites.push_back(store_sprite(114, 100, 20, 20, sprites));

		//sprites[grassDirtBottomRight].x = 94;
		//sprites[grassDirtBottomRight].y = 100;
		//sprites[grassDirtBottomRight].w = 20;
		//sprites[grassDirtBottomRight].h = 20;

		////sprites.push_back(store_sprite(94, 100, 20, 20, sprites));

		//sprites[grassDirtHoriVerLeft].x = 114;
		//sprites[grassDirtHoriVerLeft].y = 120;
		//sprites[grassDirtHoriVerLeft].w = 20;
		//sprites[grassDirtHoriVerLeft].h = 20;

		////sprites.push_back(store_sprite(114, 120, 20, 20, sprites));

		//sprites[grassDirtHoriVerRight].x = 94;
		//sprites[grassDirtHoriVerRight].y = 120;
		//sprites[grassDirtHoriVerRight].w = 20;
		//sprites[grassDirtHoriVerRight].h = 20;

		////sprites.push_back(store_sprite(94, 120, 20, 20, sprites));

		//sprites[grassDirtVerHoriDown].x = 94;
		//sprites[grassDirtVerHoriDown].y = 160;
		//sprites[grassDirtVerHoriDown].w = 20;
		//sprites[grassDirtVerHoriDown].h = 20;

		////sprites.push_back(store_sprite(94, 160, 20, 20, sprites));

		//sprites[grassDirtVerHoriUp].x = 94;
		//sprites[grassDirtVerHoriUp].y = 140;
		//sprites[grassDirtVerHoriUp].w = 20;
		//sprites[grassDirtVerHoriUp].h = 20;

		////sprites.push_back(store_sprite(94, 140, 20, 20, sprites));

		//sprites[grassDirtFourPaths].x = 114;
		//sprites[grassDirtFourPaths].y = 140;
		//sprites[grassDirtFourPaths].w = 20;
		//sprites[grassDirtFourPaths].h = 20;

		//sprites.push_back(store_sprite(114, 140, 20, 20, sprites));

		//dirt tilset
		worldSprites[World_dirt].x = 134;
		worldSprites[World_dirt].y = 40;
		worldSprites[World_dirt].w = 20;
		worldSprites[World_dirt].h = 20;

		//sprites.push_back(store_sprite(380, 380, 20, 20, sprites));

		//wall sets
		worldSprites[World_wallfront].x = 74;
		worldSprites[World_wallfront].y = 40;
		worldSprites[World_wallfront].w = 20;
		worldSprites[World_wallfront].h = 20;

		//sprites.push_back(store_sprite(74, 40, 20, 20, sprites));

		worldSprites[World_wallvertical].x = 74;
		worldSprites[World_wallvertical].y = 20;
		worldSprites[World_wallvertical].w = 20;
		worldSprites[World_wallvertical].h = 20;

		//sprites.push_back(store_sprite(74, 20, 20, 20, sprites));

		worldSprites[World_wallfrontendless].x = 94;
		worldSprites[World_wallfrontendless].y = 0;
		worldSprites[World_wallfrontendless].w = 20;
		worldSprites[World_wallfrontendless].h = 20;

		//sprites.push_back(store_sprite(94, 0, 20, 20, sprites));

		worldSprites[World_wallhorizontal].x = 114;
		worldSprites[World_wallhorizontal].y = 0;
		worldSprites[World_wallhorizontal].w = 20;
		worldSprites[World_wallhorizontal].h = 20;

		//sprites.push_back(store_sprite(114, 0, 20, 20, sprites));

		worldSprites[World_wallLeftCorner].x = 154;
		worldSprites[World_wallLeftCorner].y = 20;
		worldSprites[World_wallLeftCorner].w = 20;
		worldSprites[World_wallLeftCorner].h = 20;

		//sprites.push_back(store_sprite(154, 20, 20, 20, sprites));

		worldSprites[World_wallRightCorner].x = 154;
		worldSprites[World_wallRightCorner].y = 40;
		worldSprites[World_wallRightCorner].w = 20;
		worldSprites[World_wallRightCorner].h = 20;

		//sprites.push_back(store_sprite(154, 40, 20, 20, sprites));

		worldSprites[World_wallBottomLeftCorner].x = 214;
		worldSprites[World_wallBottomLeftCorner].y = 0;
		worldSprites[World_wallBottomLeftCorner].w = 20;
		worldSprites[World_wallBottomLeftCorner].h = 20;

		//sprites.push_back(store_sprite(214, 0, 20, 20, sprites));

		worldSprites[World_wallBottomRightCorner].x = 214;
		worldSprites[World_wallBottomRightCorner].y = 20;
		worldSprites[World_wallBottomRightCorner].w = 20;
		worldSprites[World_wallBottomRightCorner].h = 20;

		//sprites.push_back(store_sprite(214, 20, 20, 20, sprites));

		worldSprites[World_wallTop].x = 234;
		worldSprites[World_wallTop].y = 0;
		worldSprites[World_wallTop].w = 20;
		worldSprites[World_wallTop].h = 20;

		//sprites.push_back(store_sprite(174, 140, 20, 20, sprites));

		//water animation
		worldSprites[World_water].x = 100;
		worldSprites[World_water].y = 100;
		worldSprites[World_water].w = 100;
		worldSprites[World_water].h = 100;

		//sprites.push_back(store_sprite(100, 100, 100, 100, sprites));

		Main::storeWorldSprite(worldSprites);
	}
		
	return true;
}


bool ImageLoader::load_msg(std::array<SDL_Rect, Main::total_msgtiles>& msgSprites, SDL_Texture *image, SDL_Renderer* renderer)
{
	ImageManager* manage = new ImageManager();

	// load the image file
	image	  = manage->loadTexture("images/gamemenu.png", image, renderer);
	_msgImage = image;
	_render   = renderer;

	if (_image == NULL)
	{
		printf("image failed to load %s\n", SDL_GetError());

		return false;
	}
	else
	{
		//message box sprite
		msgSprites[txtMsgBox].x = 192;
		msgSprites[txtMsgBox].y = 0;
		msgSprites[txtMsgBox].w = 208;
		msgSprites[txtMsgBox].h = 78;

		
		Main::store_msgsprite(msgSprites);

	}

	return true;
}

//bool ImageLoader::load_msg(std::array<SDL_Rect, Main::total_msgtiles>& msgSprites, SDL_Texture *image, SDL_Renderer* renderer)
//{
//	ImageManager* manage = new ImageManager();
//
//	// load the image file
//	image = manage->loadTexture("images/gamemenu.png", image, renderer);
//	_msgImage = image;
//	_render = renderer;
//
//	if (_image == NULL)
//	{
//		printf("image failed to load %s\n", SDL_GetError());
//
//		return false;
//	}
//	else
//	{
//		//message box sprite
//		msgSprites[msgtopleft].x = 240;
//		msgSprites[msgtopleft].y = 272;
//		msgSprites[msgtopleft].w = 16;
//		msgSprites[msgtopleft].h = 16;
//
//		msgSprites[msgmiddletop].x = 266;
//		msgSprites[msgmiddletop].y = 272;
//		msgSprites[msgmiddletop].w = 16;
//		msgSprites[msgmiddletop].h = 16;
//
//		//sprites.push_back(store_sprite(369, 83, 6, 9, sprites));
//
//		msgSprites[msgtopright].x = 288;
//		msgSprites[msgtopright].y = 272;
//		msgSprites[msgtopright].w = 16;
//		msgSprites[msgtopright].h = 16;
//
//		//sprites.push_back(store_sprite(378, 83, 3, 9, sprites));
//
//		msgSprites[msgbottomleft].x = 240;
//		msgSprites[msgbottomleft].y = 320;
//		msgSprites[msgbottomleft].w = 16;
//		msgSprites[msgbottomleft].h = 16;
//
//		msgSprites[msgmiddlebottom].x = 266;
//		msgSprites[msgmiddlebottom].y = 320;
//		msgSprites[msgmiddlebottom].w = 16;
//		msgSprites[msgmiddlebottom].h = 16;
//
//		msgSprites[msgbottomright].x = 288;
//		msgSprites[msgbottomright].y = 320;
//		msgSprites[msgbottomright].w = 16;
//		msgSprites[msgbottomright].h = 16;
//
//		msgSprites[msgfill].x = 261;
//		msgSprites[msgfill].y = 356;
//		msgSprites[msgfill].w = 16;
//		msgSprites[msgfill].h = 16;
//
//		msgSprites[msgmiddleleft].x = 240;
//		msgSprites[msgmiddleleft].y = 291;
//		msgSprites[msgmiddleleft].w = 16;
//		msgSprites[msgmiddleleft].h = 16;
//
//		msgSprites[msgmiddleright].x = 288;
//		msgSprites[msgmiddleright].y = 291;
//		msgSprites[msgmiddleright].w = 16;
//		msgSprites[msgmiddleright].h = 16;
//
//		Main::store_msgsprite(msgSprites);
//
//	}
//
//	return true;
//}

SDL_Texture* ImageLoader::setImage(SDL_Texture* image)
{
	image = _image;

	return image;
}

SDL_Texture* ImageLoader::setMsgImage(SDL_Texture* msgImage)
{
	msgImage = _msgImage;

	return _msgImage;
}


SDL_Renderer* ImageLoader::setRenderer(SDL_Renderer* render)
{
	render = _render;

	return render;
}