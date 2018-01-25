#ifndef _TIMER_H_
#define	_TIMER_H_

#include "Main.h"

class Timer : public Main
{
	private:
		bool paused;
		bool started;
		int startTicks;
		
		int pausedTicks;

		int screenFps;

public:
		Timer();

		~Timer();
		
		int screenTick;

		void startClock();

		void stopClock();

		void pauseClock();

		void unpause();

		bool clock_started();

		bool clock_paused();

		int fetch_ticks();
};
#endif
