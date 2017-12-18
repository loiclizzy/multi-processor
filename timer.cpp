#include "timer.h"

Timer::Timer(sc_module_name name):sc_module(name)
{
	SC_THREAD(thRun);
}

void Timer::thRun()
{
	while (true)
	{
		tick=false;
		wait(TIMER_PERIOD-10,SC_NS);
		tick=true;
		wait(10,SC_NS);
	}
}
