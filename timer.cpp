#include "common.h"

// GameTimer -----------------------------------------------------------------
// Last Updated (06/13/03)
// Quick Timer functions using Performance Counters
// This is the only timer I use for now, which is of course
// dumb. I will need to have a fall back solution to more standard timers
// But for Dev reasons, this is fine.
// NOTE: seems to divide all values by 2 on P4M
// ---------------------------------------------------------------------------
GameTimer::GameTimer() {
	if(!QueryPerformanceFrequency((LARGE_INTEGER *)&freq))
	{
		sprintf(this->errorbuffer,"Performance Timer not available %d",GetLastError());
		MessageBox(NULL,this->errorbuffer,"My Window", MB_OK);
	}
	this->time_factor = 1.0/freq;
	//QueryPerformanceCounter(&tick);
}
// Tick -----------------------------------------------------------------------
// Last Updated (06/13/03)
// Get the elapsed time since the last call to savetick
// ----------------------------------------------------------------------------
void GameTimer::tick() {
	QueryPerformanceCounter((LARGE_INTEGER *)&now);
	this->time_span = (this->now - this->then)*this->time_factor;
}

// Savetick -------------------------------------------------------------------
// Last Updated (06/13/03)
// Saves the time for future reference
// ----------------------------------------------------------------------------
void GameTimer::savetick() {
	this->then = this->now;
}