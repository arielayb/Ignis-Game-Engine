#ifndef _INIT_H_
#define _INIT_H_

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <SDL_timer.h>
#include <array>
#include <vector>

//initailize objects
class Main
{
	private:
		
		//The music and sound that will be played 
		Mix_Music *music;
		Mix_Music *music2;
		Mix_Chunk *success;
		Mix_Chunk *choice;

		//boolean variable to accept user input for quit, start, and menu.
		bool quit		  = false;
		bool menu		  = true;
		bool start		  = false;
		bool play		  = false;

		//mute the sound 
		bool muteSound = true;

		//load the level
		//std::string _levels;

		//load the items and events from the map
		//std::string _events;

		//variables for the texture and image
		SDL_Texture *_image;
		SDL_Texture *_msgImage;
		
		//variable for rendering
		SDL_Renderer* _renderer;
	
		//world was generated
		bool generateWorld;

	public:

		//variables for the window
		SDL_Window* window;
		
		//create sdl cursor
		SDL_Cursor* cursor;

		//variables to load openGL stuff...
		SDL_GLContext mainGLContext;

		//these variables represent text for the fps and normal text displays.
		SDL_Texture* text;
		
		//set camera 
		SDL_Rect camera;

		//variable for rendering
		//SDL_Renderer* _renderer;

		//variable for font
		TTF_Font* fontTypes;
	
		//set window attributes
		int screen_height;
		int screen_width;

		//the enum will have a list of sprites and tiles.
		enum tiles
		{
			herodown1,
			herodown2,
			herodown3,
			herodown4,
			herodown5,
			heroup1,
			heroup2,
			heroup3,
			heroup4,
			heroup5,
			heroright1,
			heroright2,
			heroright3,
			heroright4,
			heroright5,
			heroleft1,
			heroleft2,
			heroleft3,
			heroleft4,
			heroleft5,
			darkGrass,
			grassDirtHorizontal,
			grassDirtVertical,
			grassDirtTopLeft,
			grassDirtTopRight,
			grassDirtBottomLeft,
			grassDirtBottomRight,
			grassDirtHoriVerRight,
			grassDirtHoriVerLeft,
			grassDirtVerHoriUp,
			grassDirtVerHoriDown,
			grassDirtFourPaths,
			dirt,
			woodDoor,
			event,
			transport,
			previous,
			wallfront,
			wallvertical,
			wallfrontendless,
			wallhorizontal,
			wallLeftCorner,
			wallRightCorner,
			wallBottomLeftCorner,
			wallBottomRightCorner,
			wallTop,
			treeWallTopEndless,
			treeWallTopEnd,
			treeWallBottom,
			treeWallVertical,
			treeWallCornerTopLeft,
			treeWallCornerTopRight,
			treeWallCornerBottomLeft,
			treeWallCornerBottomRight,
			treeWallMiddle,
			water,
			arrow,
			grave,
			tombstone,
			cross,
			coinAnim1,
			coinAnim2,
			coinAnim3,
			coinAnim4,
			treeShortTopLeft,
			treeShortTopRight,
			treeShortBotLeft,
			treeShortBotRight,
			treeTall,
			heroAttackDown1,
			heroAttackDown2,
			heroAttackDown3,
			heroAttackDown4,
			heroAttackRight1,
			heroAttackRight2,
			heroAttackRight3,
			heroAttackRight4,
			heroAttackRight5,
			heroAttackLeft1,
			heroAttackLeft2,
			heroAttackLeft3,
			heroAttackLeft4,
			heroAttackLeft5,
			heroAttackUp1,
			heroAttackUp2,
			heroAttackUp3,
			heroAttackUp4
		};

		enum worldMapSprites
		{
			
			World_darkGrass,
			World_dirt,
			World_wallfront,
			World_wallvertical,
			World_wallfrontendless,
			World_wallhorizontal,
			World_wallLeftCorner,
			World_wallRightCorner,
			World_wallBottomLeftCorner,
			World_wallBottomRightCorner,
			World_wallTop,
			World_water
		};

		enum msgtile
		{
			msgtopleft,
			msgmiddletop,
			msgtopright,
			msgbottomleft,
			msgmiddlebottom,
			msgbottomright,
			msgfill,
			msgmiddleleft,
			msgmiddleright
		};

		enum txtMsg
		{
			txtMsgBox
		};

		//the total of sprites
		static const int total_sprites = 87;

		//the total of world map sprites
		static const int total_worldMapSprites = 12;

		//the total of message sprites
		static const int total_msgtiles = 1;
		
		//this is an array that will posses all sprites width and height
		std::array<SDL_Rect, total_sprites> sprites;

		//this is an array that will posses all world map tiles width and height
		std::array<SDL_Rect, total_worldMapSprites> worldMapTiles;

		//this will hold the sprites textures for messages
		std::array<SDL_Rect, total_msgtiles> msgSprites;

		//exit the application
		int close(TTF_Font* fontTypes, SDL_Texture *image, SDL_Renderer* render);

		//the constructor
		Main();

		//Main(std::string level, std::string events);

		//destructor
		~Main();

		//AA: render the world
		bool mainLoop();

		//this function creates the window and load the SDL2 properties
		void create_window();

		//pause the game when a message box appears
		void msgBoxEvent();

		//set the level string
		//std::string setLevel(std::string level);
		
		//set the event string
		//std::string setEvent(std::string events);

		//store every sprite for the world and setup the width and height.
		std::array<SDL_Rect, total_worldMapSprites> storeWorldSprite(std::array<SDL_Rect, total_worldMapSprites>& worldSpriteList);

		//store every sprite for the world and setup the width and height.
		std::array<SDL_Rect, total_sprites> storeSprite(std::array<SDL_Rect, total_sprites>& spriteList);

		//store the message sprite tile
		std::array<SDL_Rect, Main::total_msgtiles> Main::store_msgsprite(std::array<SDL_Rect, total_msgtiles>& spriteList);

		//load the level
		//std::string level;

		//load the level
		//std::string _levels;

		////load the items and events from the map
		//std::string _events;

		//guard for loading the game menu
		bool loadingGameMenu = false;
		bool loadingWorldSprite = false;

		//boolean variables used to pasue the game
		bool pausedGame;
		bool pausePushed;

};

#endif