#include "Timer.h"

Timer::Timer()
{
	paused = false;

	started = false;
	
	startTicks  = 0;

	pausedTicks = 0;
	
	screenFps   = 60;

	screenTick = 1000 / screenFps;
}

Timer::~Timer()
{
}

void Timer::startClock()
{
	started = true;

	paused = false;

	startTicks = SDL_GetTicks();
}

void Timer::stopClock()
{
	started = false;

	paused = false;
}

int Timer::fetch_ticks()
{
	 //If the timer is running
    if( started == true )
    {
        //If the timer is paused
        if( paused == true )
        {
            //Return the number of ticks when the timer was paused
            return pausedTicks;
        }
		else if (paused == false)
        {
            //Return the current time minus the start time
            return SDL_GetTicks() - startTicks;
        }
    }

    //If the timer isn't running
    return 0;
}

void Timer::pauseClock()
{
	if(started == true && paused == false)
	{
		paused = true;
	
		pausedTicks = SDL_GetTicks() - startTicks;
	}
}

void Timer::unpause()
{
	if(paused == true)
	{
		paused = false;

		startTicks = SDL_GetTicks() - pausedTicks;

		pausedTicks = 0;
	}
}

bool Timer::clock_started()
{
	return started;
}

bool Timer::clock_paused()
{
	return paused && started;
}