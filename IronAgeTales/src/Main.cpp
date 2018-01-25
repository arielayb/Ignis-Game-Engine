//include other class header files
#include <iostream>
#include <cstring>
#include <sstream>
#include <string>
#include <vld.h>
#include <stdio.h>
#include <stdlib.h>
#include "Main.h"
#include "ImageManager.h"
#include "ImageLoader.h"
#include "WorldInterface.h"
#include <SDL_mouse.h>
#include "Timer.h"
#include "MsgManager.h"
#include <Windows.h>

//  include std thread
#include <thread>

//opengl header
//#include <glew/glew.h>
#include <SDL_opengl.h>

Main::Main()
{
	//set window attributes
	screen_height = 850;
	screen_width  = 800;
	pausedGame    = false;
	pausePushed	  = true;
}

Main::~Main()
{
}

//create the window function for the launcher of this game
//void Main::create_window()
bool Main::mainLoop()
{
	//create some attributes for openGL:
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		printf("failed to initailize %s\n", SDL_GetError());
	}
	else
	{
		//Set texture filtering to linear
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			printf("Warning: Linear texture filtering not enabled!");
		}
	}

	//initialize the font stuff;
	if (TTF_Init() == -1)
	{
		printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
	}

	//Initialize SDL_mixer 
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) == -1)
	{
		printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
		quit = true;
	}

	//create the window
	window = SDL_CreateWindow("Ignis Game Engine 1.3v", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screen_width, screen_height, SDL_WINDOW_OPENGL);

	//create the openGL context
	mainGLContext = SDL_GL_CreateContext(window);
	if (mainGLContext == NULL)
	{
		printf("OpenGL context could not be created! SDL Error: %s\n", SDL_GetError());
	}


	//create the renderer
	_renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE | SDL_RENDERER_PRESENTVSYNC);

	//set up a font style
	fontTypes = TTF_OpenFont("images/CollegiateBlackFLF.ttf", 20);

	//load the image library
	ImageLoader* imagehandler = new ImageLoader(_image, _renderer);

	//load and create clipping of sprites.
	imagehandler->load_sprites(sprites, _image, _renderer);

	//load and create clipping of item sprites
	imagehandler->load_itemEvents(sprites, _image, _renderer);

	//load and create clipping of the message handler 
	imagehandler->load_msg(msgSprites, _msgImage, _renderer);

	if (window == NULL)
	{
		printf("the window failed to initialize %s\n", SDL_GetError());
	}

	_image = imagehandler->setImage(_image);
	_renderer = imagehandler->setRenderer(_renderer);
	_msgImage = imagehandler->setMsgImage(_msgImage);

	//clean the the stack and heap from the image loader pointer
	delete imagehandler;
	imagehandler = NULL;


	///*
	//	add a loading DLL libray
	//*/

	//Declare an HINSTANCE and load the library dynamically. Don’t forget 
	//to specify a correct path to the location of LoadMe.dll

	HINSTANCE LoadDLL = LoadLibrary("lib/LvlMgr.dll");

	// Check to see if the library was loaded successfully 
	if (!LoadDLL)
	{
		printf("LoadDLL library failed to load!\n");
		FreeLibrary(LoadDLL);
		return 1;

	}

	/*
	 *	add a loading DLL libray
	 */
	typedef WorldInterface* (__cdecl *Levelfn)();


	//declare a variable of type pointer to EntryPoint function, a name of 
	// which you will later use instead of EntryPoint
	Levelfn CreateModule = Levelfn(GetProcAddress(LoadDLL, (LPCSTR)"createLevel"));

	if (!CreateModule) {
		std::cerr << "Unable to load Create_Level from DLL!\n";
		std::cout << GetLastError() << std::endl;
		FreeLibrary(LoadDLL);
		return 1;
	}


	//Levels * funcLevel = (*CreateModule)();

	//  to count the frame rate
	Timer fps;

	//  load the textures
	ImageManager load; //= new ImageManager();

	//  the stream for the timer
	std::stringstream fpsFont;
	//std::string fpsFont;

	//  set the level variable for polymorphic process
	//WorldInterface * world = new Levels();
	
	WorldInterface * world = (*CreateModule)();

	//  ceate player handler event
	SDL_Event events;

	//  set the cursor
	cursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_CROSSHAIR);
	SDL_SetCursor(cursor);

	//  the timer for the fps
	int frame = 0;

	//  the x and y position of the arrow selection sprite
	int x = 380, y = 500;

	//  paused state boolean value
	bool showPausedState = false;

	//  give the font color
	SDL_Color fontColor = { 255, 255, 255 };

	//  create menu selection and image. quick explanation of the game
	std::string choices[] = { "The Crimson Stone", "Start", "Quit" };
	std::string inform[]  = { "This small short game is in the works", "and I wish to explain the story in more depth", "Thus, enjoy the small game!", "Press z to start the game" };

	//  the paused game string
	std::string pausestr = "PAUSE";

	SDL_Rect backgroundClip;
	backgroundClip.w = screen_width;
	backgroundClip.h = screen_height;

	SDL_Texture *title	    = load.loadFont(choices[0], fontTypes, fontColor, _renderer);
	SDL_Texture *choice1    = load.loadFont(choices[1], fontTypes, fontColor, _renderer);
	SDL_Texture *choice2    = load.loadFont(choices[2], fontTypes, fontColor, _renderer);
	SDL_Texture *background = load.loadTexture("images/Title.png", _image, _renderer);
	SDL_Texture *notice		= load.loadFont(inform[0], fontTypes, fontColor, _renderer);
	SDL_Texture *notice2	= load.loadFont(inform[1], fontTypes, fontColor, _renderer);
	SDL_Texture *notice3	= load.loadFont(inform[2], fontTypes, fontColor, _renderer);
	SDL_Texture *notice4	= load.loadFont(inform[3], fontTypes, fontColor, _renderer);

	//  paused game notice
	SDL_Texture *pauseNotice = load.loadFont(pausestr, fontTypes, fontColor, _renderer);

	//start the fps clock
	fps.startClock();

	//  Main Loop Thread:
	while (!quit)
	{
		
		//handle events and menu selector!
		while (SDL_PollEvent(&events))
		{
			//user game menu options below
			//user can quit the game on ESC key
			if (events.type == SDL_QUIT || events.key.keysym.sym == SDLK_ESCAPE)
			{
				quit = true;
			}

			//user can pause the game with the p key
			if (events.type == SDL_KEYDOWN && events.key.repeat == 0)
			{
				switch (events.key.keysym.sym)
				{
					case SDLK_p:
					{
						if (pausePushed)
						{
							pausedGame      = true;
							showPausedState = true;
							pausePushed		= false;
							break;
						}
						else if (!pausePushed)
						{
							pausedGame		= false;
							showPausedState = false;
							pausePushed		= true;
							break;
						}
						
						break; 
					}
				}
			}

			switch (menu)
			{			
				case true:
				{
					if (muteSound == false)
					{
						//load the music
						music = Mix_LoadMUS("sound/menu_test.wav");
						if(music == NULL)
						{
							printf("Failed to load music! SDL_mixer Error: %s\n", Mix_GetError());
							quit = true;
						}
					
						success = Mix_LoadWAV("sound/okay.wav");
						if (success == NULL)
						{
							printf("Failed to load soundFX! SDL_mixer Error: %s\n", Mix_GetError());
							quit = true;
						}

						choice = Mix_LoadWAV("sound/click.wav");
						if (choice == NULL)
						{
							printf("Failed to load soundFX! SDL_mixer Error: %s\n", Mix_GetError());
							quit = true;
						}

						//play the music
						if (Mix_PlayingMusic() == 0)
						{
							Mix_PlayMusic(music, -1);
						}
					}
						
					if (events.type == SDL_KEYDOWN)
					{
						if (events.key.keysym.sym == SDLK_UP)
						{
							Mix_PlayChannel(-1, choice, 0);
							load.renderTexture(x = 380, y = 500, _image, _renderer, &sprites[arrow]);
						}
						else if (events.key.keysym.sym == SDLK_DOWN)
						{
							Mix_PlayChannel(-1, choice, 0);
							load.renderTexture(x = 380, y = 550, _image, _renderer, &sprites[arrow]);
						}
						else if (events.key.keysym.sym == SDLK_RETURN)
						{
							if (x == 380 && y == 500)
							{
								Mix_PlayChannel(-1, success, 0);
								
								menu = false;
								start = true;
																
								SDL_DestroyTexture(title);
								SDL_DestroyTexture(choice1);
								SDL_DestroyTexture(choice2);
							
								//Stop the music 
								Mix_HaltMusic();
							}
							else if (x == 380 && y == 550)
							{
								//Stop the music 
								Mix_HaltMusic();
								
								quit = true;
							}
						}
					}
				}
				break;
				case false:
					world->playerInput(events);
				break;
			}
		}
	
		if (menu == true)
		{
			//clear the rendering so that we can re-render/update the screen
			SDL_RenderClear(_renderer);

			//create a background scrolling
			load.renderTexture(0, 0, background, _renderer, NULL);

			int scrollingOffset = 0;

			--scrollingOffset;
			if (scrollingOffset < backgroundClip.w)
			{
				scrollingOffset = 0;
			}

			//the arrow selector texture being loaded
			load.renderTexture(x, y, _image, _renderer, &sprites.at(arrow));

			//render the text of choices
			load.renderTexture(325, 400, title, _renderer, NULL);
			load.renderTexture(400, 500, choice1, _renderer, NULL);
			load.renderTexture(400, 550, choice2, _renderer, NULL);
		
			//update the screen
			SDL_RenderPresent(_renderer);
		}
		else if (start == true)
		{
			//clear the rendering so that we can re-render/update the screen
			SDL_RenderClear(_renderer);

			load.renderTexture(200, 210, notice, _renderer, NULL);
			load.renderTexture(200, 230, notice2, _renderer, NULL);
			load.renderTexture(200, 255, notice3, _renderer, NULL);
			load.renderTexture(200, 420, notice4, _renderer, NULL);

			if (events.key.keysym.sym == SDLK_z)
			{
				play = true;
				start = false;
			}

			//update the screen
			SDL_RenderPresent(_renderer);

		}
		else if (play == true)
		{
			//  Calculate and correct fps
			float avgFPS = frame / (fps.fetch_ticks() / 1000.f);
			if (avgFPS > 2000000)
			{
				avgFPS = 0;
			}

			fpsFont.str("");
			fpsFont << "FPS:" << avgFPS;

			//  this will load the fps font images
			SDL_Texture* fpsText = load.loadFont(fpsFont.str().c_str(), fontTypes, fontColor, _renderer);

			//  clear the rendering so that we can re-render/update the screen
			SDL_RenderClear(_renderer);

			//  render the fps font
			load.renderTexture(50, 816, fpsText, _renderer, NULL);

			if (!pausedGame)
			{
				//  testbed for box2d
				//world->testBed();

				world->loadTiles(_image, _renderer, sprites);
				world->loadItems(_image, /*msgEvent*/_msgImage, _renderer, sprites);
			
				//  update the screen
				SDL_RenderPresent(_renderer);
			}
			else if (pausedGame)
			{
				if (showPausedState)
				{
					//  clear the rendering so that we can re-render/update the screen
					SDL_RenderClear(_renderer);
					
					load.renderTexture(400, 400, pauseNotice, _renderer, NULL);
					
					//  update the screen
					SDL_RenderPresent(_renderer);
				}

				pausedGame = true;
			}

			frame++;

			//  If frame finished early
			int frameTicks = fps.fetch_ticks();
			if (frameTicks < fps.screenTick)
			{
				//  Wait remaining time
				SDL_Delay(fps.screenTick - frameTicks);
			}
		}
	}

	close(fontTypes, _image, _renderer);

	delete world;
	world = NULL;

	FreeLibrary(LoadDLL);

	return quit;
}

//  the function that returns each tile data;
std::array<SDL_Rect, Main::total_sprites> Main::store_sprite(std::array<SDL_Rect, Main::total_sprites>& spriteList)
{
	sprites = spriteList;
	
	return sprites;
}

//  the function that returns each message tile data;
std::array<SDL_Rect, Main::total_msgtiles> Main::store_msgsprite(std::array<SDL_Rect, total_msgtiles>& spriteList)
{
	msgSprites = spriteList;

	return msgSprites;
}

//  the message box event will pause the game until the player completes the message dialog
void Main::msgBoxEvent()
{
	//  clear the rendering so that we can re-render/update the screen
	SDL_RenderClear(_renderer);

	//  update the screen
	SDL_RenderPresent(_renderer);
}

//  clean up ALL the SDL process
int Main::close(TTF_Font* fontTypes, SDL_Texture *image, SDL_Renderer* render)
{
	//  Deallocate surface
	SDL_DestroyTexture(image);

	//  destroy render
	SDL_DestroyRenderer(render);

	//  delete the openGL context
	SDL_GL_DeleteContext(mainGLContext);

    //  Destroy window
    SDL_DestroyWindow(window);
 
	//  close the font
	TTF_CloseFont(fontTypes);
	
	SDL_FreeCursor(cursor);

	//  free the music pointers
	Mix_FreeMusic(music);
	Mix_FreeMusic(music2);
	music = NULL;
	music2 = NULL;

	//  free soundFX pointers
	Mix_FreeChunk(choice);
	Mix_FreeChunk(success);
	choice = NULL;
	success = NULL;

	//  quit font/text system
	TTF_Quit();

	//  quit image systems
	IMG_Quit();

	//  quit the sound system
	Mix_Quit();

    //  Quit SDL subsystems
    SDL_Quit();

	return 0;
}

//  run some methods
int main(int argc, char* argv[])
{
	// initialize the settings for the window 
	//   and run the launcher.

	Main * launch = new Main();

	//  create the window and set render and texture
	//launch.create_window();

	std::thread worldThread(&Main::mainLoop, launch);
	worldThread.join();

	//  start the main thread to draw the levels and events
	//launch.mainLoop();
	
	delete launch;

	return 0;
}