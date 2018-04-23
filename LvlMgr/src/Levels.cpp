#include <iostream>
#include <fstream>
#include <algorithm>
#include "Levels.h"
#include "ImageManager.h"

//  testing
//#include "BoxDebugDraw.h"
//#include "DebugDraw.h"

Levels::Levels()
{
	coinIndex = 0;
	coinCount = 0;
	nextLevel = false;
	previousLevel = false;
	changedLevel = false;
	prevChangedLevel = false;

	//  set the level, items, and events
	_levelfile = "level/level1.ignismap";
	_eventfile = "level/event1.ignismap";

	//b2Vec2 gravity(0.0f, 0.0f);

	////  set the world and gravity
	//_world = new b2World(gravity);
	////_world->SetDebugDraw(&draw);

	////  create the player's collision box for box2d lib
	//_bodyDef.type = b2_dynamicBody;
	//_body = _world->CreateBody(&_bodyDef);

}

Levels::~Levels()
{
	delete coinCollected;
	coinCollected = NULL;

	/*delete _world;
	_world = NULL;*/

}


//load all the world sprites for the level.
bool Levels::loadWorldTiles(SDL_Texture* image, SDL_Renderer* renderer, std::array<SDL_Rect, total_worldMapSprites>& worldTileSet)
{
	//Do Nothing...
	return true;
}


//bool Levels::loadTiles(SDL_Texture* image, SDL_Renderer* renderer, std::array<SDL_Rect, total_sprites>& tileSet, std::string level)
bool Levels::loadTiles(SDL_Texture* image, SDL_Renderer* renderer, std::array<SDL_Rect, total_sprites>& tileSet)
{
	
	if (nextLevel)
	{
		SDL_Rect value = { 0, 0, 0, 0 };
		std::fill(std::begin(setOfWalls), std::end(setOfWalls), value);
		
		_prevLevelfile = _levelfile;
		setLevel(_levelfile);
	
	}
	else if (previousLevel)
	{
		SDL_Rect value = { 0, 0, 0, 0 };
		std::fill(std::begin(setOfWalls), std::end(setOfWalls), value);
		
		_levelfile = _prevLevelfile;
		setLevel(_levelfile);
				
	}

	//load the map file
	//std::ifstream map(level);
	std::ifstream map(_levelfile);

	ImageManager load;

	//set the indexes of the map
	float indexX = 0.0f;
	float indexY = 0.0f;

	if (map.fail())
	{
		printf("the map file is empty or missing!", SDL_GetError());
		return false;
	}

	//this char will be used to draw the map.
	char tile_type;
	char event_type;

	for (int i = 0; i <= total_tiles; i++)
	{
		//read the text file for the first layer
		map >> tile_type;

		switch (tile_type)
		{
		
			case '(':
				load.renderTexture(indexX, indexY, image, renderer, &tileSet.at(grassDirtTopLeft));
				break;

			case '-':
				load.renderTexture(indexX, indexY, image, renderer, &tileSet.at(grassDirtHorizontal));
				break;

			case ')':
				load.renderTexture(indexX, indexY, image, renderer, &tileSet.at(grassDirtTopRight));
				break;

			case ':':
				load.renderTexture(indexX, indexY, image, renderer, &tileSet.at(grassDirtVertical));
				break;

			case '}':
				load.renderTexture(indexX, indexY, image, renderer, &tileSet.at(grassDirtBottomRight));
				break;

			case '{':
				load.renderTexture(indexX, indexY, image, renderer, &tileSet.at(grassDirtBottomLeft));
				break;

			case '4':
				load.renderTexture(indexX, indexY, image, renderer, &tileSet.at(grassDirtHoriVerLeft));
				break;

			case '6':
				load.renderTexture(indexX, indexY, image, renderer, &tileSet.at(grassDirtHoriVerRight));
				break;

			case '5':
				load.renderTexture(indexX, indexY, image, renderer, &tileSet.at(grassDirtFourPaths));
				break;

			case '8':
				load.renderTexture(indexX, indexY, image, renderer, &tileSet.at(grassDirtVerHoriUp));
				break;

			case '2':
				load.renderTexture(indexX, indexY, image, renderer, &tileSet.at(grassDirtVerHoriDown));
				break;

			case 'x':
				load.renderTexture(indexX, indexY, image, renderer, &tileSet.at(darkGrass));
				break;

			case 'd':
				load.renderTexture(indexX, indexY, image, renderer, &tileSet.at(dirt));
				break;

			case '~':
				load.renderTexture(indexX, indexY, image, renderer, &tileSet.at(water));
				break;

			case 'g':
				load.renderTexture(indexX, indexY, image, renderer, &tileSet.at(grave));
				break;

			case '%':
				setOfWalls[i] = storeTiles(indexX, indexY, tileHeight_, tileWidth_, tileSet.at(treeWallBottom));
				load.renderTexture(indexX, indexY, image, renderer, &tileSet.at(treeWallBottom));
				break;

			case '=':
				setOfWalls[i] = storeTiles(indexX, indexY, tileHeight_, tileWidth_, tileSet.at(treeWallTopEndless));
				load.renderTexture(indexX, indexY, image, renderer, &tileSet.at(treeWallTopEndless));
				break;

			case '^':
				setOfWalls[i] = storeTiles(indexX, indexY, tileHeight_, tileWidth_, tileSet.at(treeWallTopEnd));
				load.renderTexture(indexX, indexY, image, renderer, &tileSet.at(treeWallTopEnd));
				break;

			case '|':
				setOfWalls[i] = storeTiles(indexX, indexY, tileHeight_, tileWidth_, tileSet.at(treeWallVertical));
				load.renderTexture(indexX, indexY, image, renderer, &tileSet.at(treeWallVertical));
				break;

			case 't':
				setOfWalls[i] = storeTiles(indexX, indexY, tileHeight_, tileWidth_, tileSet.at(tombstone));
				load.renderTexture(indexX, indexY, image, renderer, &tileSet.at(tombstone));
				break;

			case '<':
				setOfWalls[i] = storeTiles(indexX, indexY, tileHeight_, tileWidth_, tileSet.at(treeWallCornerTopLeft));
				load.renderTexture(indexX, indexY, image, renderer, &tileSet.at(treeWallCornerTopLeft));
				break;

			case '>':
				setOfWalls[i] = storeTiles(indexX, indexY, tileHeight_, tileWidth_, tileSet.at(treeWallCornerTopRight));
				load.renderTexture(indexX, indexY, image, renderer, &tileSet.at(treeWallCornerTopRight));
				break;

			case ',':
				setOfWalls[i] = storeTiles(indexX, indexY, tileHeight_, tileWidth_, tileSet.at(treeWallCornerBottomLeft));
				load.renderTexture(indexX, indexY, image, renderer, &tileSet.at(treeWallCornerBottomLeft));
				break;

			case '.':
				setOfWalls[i] = storeTiles(indexX, indexY, tileHeight_, tileWidth_, tileSet.at(treeWallCornerBottomRight));
				load.renderTexture(indexX, indexY, image, renderer, &tileSet.at(treeWallCornerBottomRight));
				break;

			case '#':
				setOfWalls[i] = storeTiles(indexX, indexY, tileHeight_, tileWidth_, tileSet.at(treeWallMiddle));
				load.renderTexture(indexX, indexY, image, renderer, &tileSet.at(treeWallMiddle));
				break;

			case 'c':
				setOfWalls[i] = storeTiles(indexX, indexY, tileHeight_, tileWidth_, tileSet.at(cross));
				load.renderTexture(indexX, indexY, image, renderer, &tileSet.at(cross));
				break;

			case '[':
				setOfWalls[i] = storeTiles(indexX, indexY, tileHeight_, tileWidth_, tileSet.at(woodDoor));
				load.renderTexture(indexX, indexY, image, renderer, &tileSet.at(woodDoor));
				break;

			case 'q':
				setOfWalls[i] = storeTiles(indexX, indexY, tileHeight_, tileWidth_, tileSet.at(treeShortTopLeft));
				load.renderTexture(indexX, indexY, image, renderer, &tileSet.at(treeShortTopLeft));
				break;

			case 'w':
				setOfWalls[i] = storeTiles(indexX, indexY, tileHeight_, tileWidth_, tileSet.at(treeShortTopRight));
				load.renderTexture(indexX, indexY, image, renderer, &tileSet.at(treeShortTopRight));
				break;

			case 'a':
				setOfWalls[i] = storeTiles(indexX, indexY, tileHeight_, tileWidth_, tileSet.at(treeShortBotLeft));
				load.renderTexture(indexX, indexY, image, renderer, &tileSet.at(treeShortBotLeft));
				break;

			case 's':
				setOfWalls[i] = storeTiles(indexX, indexY, tileHeight_, tileWidth_, tileSet.at(treeShortBotRight));
				load.renderTexture(indexX, indexY, image, renderer, &tileSet.at(treeShortBotRight));
				break;
		}

		indexX += tileWidth_;

		if (indexX >= levelWidth_)
		{
			indexX = 0;

			indexY += tileHeight_;
		}
	}

	map.close();

	//load the hero default sprite
	if (loaded_hero == false)
	{
		player			  = tileSet.at(herodown1);
		collectionStarted = true;
		overrideIndex	  = true;
		loaded_hero		  = true;
	}

	player = playerAnimation(player, tileSet);
	//player = playerSwordAttackAnimation(player, tileSet);

	//collisionManagement(player, setOfWalls, setOfEvents, setOfCoins);
	collisionManagement(player);
	

	/*load.renderTexture(0, 0, NULL, NULL, &camera);
	load.renderTexture(xPos - camera.x, yPos - camera.y, NULL, NULL, NULL);*/
	load.renderTexture(xPos, yPos, image, renderer, &player);
	/*load.renderTexture(0, 0, NULL, NULL, &camera);
	load.renderTexture(xPos - camera.x, yPos - camera.y, NULL, NULL, NULL);*/


	return true;
}

bool Levels::loadItems(SDL_Texture* image, SDL_Texture* msgEvent, SDL_Renderer* renderer, std::array<SDL_Rect, total_sprites>& tileSet)
{
	
	//  load the event file
	std::ifstream eventMap(_eventfile);

	ImageManager load;

//	MsgManager* msgwindow = new MsgManager(msgEvent, msgsprites);

	//set the indexes of the map
	float indexX = 0.0f;
	float indexY = 0.0f;

	if (eventMap.fail())
	{
		printf("the event map file is empty or missing!", SDL_GetError());
		return false;
	}

	//  this char will be used to draw the map.
	char event_type;
	
	for (itemIndex = 0; (itemIndex < setOfCoins.size()) || (itemIndex < setOfEvents.size()) || (itemIndex < setOfTransition.size()); itemIndex++)
	{
		//read the text file for the event layer
		eventMap >> event_type;

		switch (event_type)
		{
			case 'x':
				break;

			case 'n':
				setOfTransition.at(itemIndex) = storeTiles(indexX, indexY, tileHeight_, tileWidth_, tileSet.at(transport));
				if (nextLevel)
				{
					
					_levelfile = setLevel("level/level2.ignismap");
					_eventfile = setEvent("level/event2.ignismap");
				}
				break;

			case 'p':
				setOfTransition.at(itemIndex) = storeTiles(indexX, indexY, tileHeight_, tileWidth_, tileSet.at(previous));
				if (previousLevel)
				{
					//  find a solution to dynamically change the previous levels
					//std::string prevLevel = setLevel(_levelfile);
					_prevLevelfile = setLevel("level/level1.ignismap");
					_prevEventfile = setEvent("level/event1.ignismap");
					nextLevel	   = false;
					previousLevel  = false;

				}
				break;

			case 'e':
				//  testing
				setOfEvents.at(itemIndex) = storeTiles(indexX, indexY, tileHeight_, tileWidth_, tileSet.at(event));

				if (eventActive)
				{
					//msgwindow->loadMsgWindow("HOPE!", msgsprites, renderer);
										
					eventActive = false;
				}
				break;
			
			case 'c':
			{			
				coin = coinAnimation(coin, tileSet);

				coinCollected = new ItemManager("coin", coin);

				if (collectionStarted == true)
				{
					
					if (collectedObject == true)
					{
						overrideIndex = false;
						 
						if (overrideIndex == false)
						{
							SDL_Rect fcoin = { 0, 0, 0, 0 };
							itemIndex = 0;
							setOfCoins.at(coinIndex) = coinCollected->setItem(&storeTiles(0, 0, 0, 0, fcoin));
						
							collectedObject = false;

							delete coinCollected;
							coinCollected = NULL;

							coinIndex = 0;
						}
					}
			
					if (overrideIndex == true || !SDL_RectEquals(&setOfCoins.at(itemIndex), &setOfCoins.at(coinIndex)))
					{
						setOfCoins.at(itemIndex) = coinCollected->setItem(&storeTiles(indexX, indexY, tileHeight_, tileWidth_, coinCollected->getItem()));
						coinCollected->updateItem(indexX, indexY, image, renderer, &coin);
					}
				}
			}
			break;

			case '@':
			{

				if (changedLevel)
				{
					load.renderTexture(indexX, indexY, image, renderer, &tileSet.at(event));
					xPos		 = indexX;
					yPos		 = indexY;
					changedLevel = false;
				}
				else
					break;
			}
			break;

			case '!':
			{

				if (prevChangedLevel)
				{
					load.renderTexture(indexX, indexY, image, renderer, &tileSet.at(event));
					xPos			 = indexX;
					yPos			 = indexY;
					prevChangedLevel = false;
				}
				else
					break;
			}
			break;
		}

		indexX += tileWidth_;

		if (indexX >= levelWidth_)
		{
			indexX = 0;

			indexY += tileHeight_;
		}
	}

	eventMap.close();

	return true;
}

//the function that holds each tile data;
SDL_Rect Levels::storeTiles(int x, int y, int tileHeight, int tileWidth, SDL_Rect tile)
{

	tile.x = x;
	tile.y = y;

	tile.h = tileHeight;
	tile.w = tileWidth;

	return tile;
}

//  the collision management and set of wall detection for the player.
void Levels::collisionManagement(SDL_Rect playerBox)
{
	//float32 timeStep = 1.0f / 60.0f;
	
	//  set the player's collision box
	collision.h = playerBox.h;
	collision.w = playerBox.w;

	/********Trying to set the box2d library*******/
	
	//_playerShape.SetAsBox((float)collision.w, (float)collision.h);
	//_body->CreateFixture(&_playerShape, 1);//shape, density

	//_body->SetUserData(this);

	/*********************************************/

	//  set the exact position of the box from box2d library
	/*float32 angle	= _body->GetAngle();
	b2Vec2 position = _body->GetPosition();*/

	//  move the player right on the x, y plane
	xPos += velX;
	collision.x = xPos;

	//position.x = (float)collision.x;

	//if the dot goes to far off the screen.
	if ((xPos < 0) || (collision.x + collision.w >= levelWidth_) || loadWalls(collision, setOfWalls))
	{
		//move the player from the left side of the x, y plane.
		xPos -= velX;
		collision.x = xPos;
	}

	//  move the player up on the x, y plane
	yPos += velY;
	collision.y = yPos;

	//position.y = (float)collision.y;

	//  if the dot goes to far off the screen.
	if ((yPos < 0) || (collision.y + collision.h >= levelHeight_) || loadWalls(collision, setOfWalls))
	{
		//move the player down on the x, y plane
		yPos -= velY;
		collision.y = yPos;
	}

	//printf("player position: x: %d, y: %d\n", collision.x, collision.y);

	//printf("%4.2f %4.2f %4.2f\n", position.x, position.y, angle);

	//  set of events that have interaction with the player
	if (eventsEnabled == true)
	{
		loadEvents(collision, setOfEvents);
		loadCoins(collision, setOfCoins);
		loadTransition(collision, setOfTransition);
	}

}

//load the collision for this world
bool Levels::loadWalls(SDL_Rect collision, std::array<SDL_Rect, total_tiles> wall)
{
	for (int i = 0; i <= wall.size(); i++)
	{
		if (checkingCollisions(collision, wall[i]))
		{
			return true;
		}
	}

	return false;
}

//load the collision for events from a specific index
bool Levels::loadEvents(SDL_Rect collision, std::array<SDL_Rect, total_tiles> event)
{
	//location of the coin
	int eventLocation = 0;

	for (SDL_Rect eventStack : event)
	{
		eventIndex = eventLocation++;

		if ((checkingCollisions(collision, eventStack)))
		{
			std::cout << "what is the event position? " << eventLocation << std::endl;

			if (eventTouch)
			{
				eventActive = true;
				eventTouch  = false;
			}

			return eventActive;
		}

	}

	return false;
}

//  load the collision for the transition of levels
bool Levels::loadTransition(SDL_Rect collision, std::array<SDL_Rect, total_tiles> transition)
{
	//  location of the transition event
	int transitionLocation = 0;

	for (SDL_Rect transitionTile : transition)
	{
		transitionIndex = transitionLocation++;

		if ((checkingCollisions(collision, transitionTile)))
		{
			std::cout << "changing level? " << transitionLocation << std::endl;
						
			if (!previousLevel)
			{
				nextLevel	  = true;
				changedLevel  = true;
				previousLevel = true;
				return nextLevel;
			}
			else if (previousLevel)
			{
				prevChangedLevel = true;
				previousLevel	 = false;
				return previousLevel;
			}

		}
	}

	return false;
}

//load the collision for coins
bool Levels::loadCoins(SDL_Rect collision, std::array<SDL_Rect, total_tiles>& coins)
{
	
	//location of the coin
	int coinLocation = 0;

	for (SDL_Rect coinStack : coins)
	{
		coinIndex = coinLocation++;

		if ((checkingCollisions(collision, coinStack)))
		{			
			collectedObject = true;
						
			std::cout << "what is the coin position? " << coinLocation << std::endl;
			int coinCollected = +1;
			
			return collectedObject;
		}
		
	}

	return false;
}

//set the level string
std::string Levels::setLevel(std::string level)
{
	_levelfile = level;
	return _levelfile;
}

//set the events in the level
std::string Levels::setEvent(std::string events)
{
	_eventfile = events;
	return _eventfile;
}


//void Levels::testBed()
//{
//	
//	//_bodyDef.type = b2_dynamicBody; //this will be a dynamic body
//	//_bodyDef.position.Set(0, 20); //set the starting position
//	//_bodyDef.angle = 0; //set the starting angle
//
//	//_world->CreateBody(&_bodyDef);
//
//	//
//	//_boxTest.SetAsBox(1, 1);
//
//	//b2FixtureDef boxFixtureDef;
//	//_fixtureDef.shape = &_boxTest;
//	//_fixtureDef.density = 1;
//	//_fixtureDef->CreateFixture(&_bodyDef);
//
//	b2PolygonShape boxShape;
//	boxShape.SetAsBox(1.0f, 1.0f);
//
//	_bodyDef.type = b2_dynamicBody;
//	_body = _world->CreateBody(&_bodyDef);
//
//	b2FixtureDef boxFixtureDef;
//	boxFixtureDef.shape = &boxShape;
//	boxFixtureDef.density = 1.0f;
//	_body->CreateFixture(&boxFixtureDef);
//
//	b2Color color;
//	color.Set(12.0f, 3.0f, 11.0f, 0.0f);
//
//	draw.DrawSolidPolygon(_boxTest.m_vertices, _boxTest.m_count, color);
//
//	draw.SetFlags(BoxDebugDraw::e_shapeBit);
//
//	_world->DrawDebugData();
//
//}

//the collision detection fucntion
bool Levels::checkingCollisions(SDL_Rect playerBox, SDL_Rect object)
{
	//calculate the rectangle side A
	int checkLeftA	 = playerBox.x;
	int checkRightA  = playerBox.x + playerBox.w;
	int checkTopA	 = playerBox.y;
	int checkBottomA = playerBox.y + playerBox.h;

	//calculate the rectangle side B
	int checkLeftB   = object.x;
	int checkRightB  = object.x + object.w;
	int checkTopB	 = object.y;
	int checkBottomB = object.y + object.h / 2;

	if (checkLeftA >= checkRightB)
	{
		return false;
	}

	if (checkRightA <= checkLeftB)
	{
		return false;
	}

	if (checkTopA >= checkBottomB)
	{
		return false;
	}

	if (checkBottomA <= checkTopB)
	{
		return false;
	}

	return true;
}