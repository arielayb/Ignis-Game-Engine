#ifndef ENEMYCONTROLLER_H
#define ENEMYCONTROLLER_H

#include <SDL.h>

class EnemyController
{
	private:
		int _enemyXpos;
		int _enemyYpos;
		SDL_Rect _enemyCollision;
	
	public:
		void enemyMovement();

};

#endif