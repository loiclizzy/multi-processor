
#include <systemc>

#define TIMER_PERIOD 1000

using namespace sc_core;


class Timer: public sc_module{
public:
	
	//To be completed
	SC_HAS_PROCESS(Timer);
	Timer(sc_module_name name);
	void thRun();
	sc_out<bool> tick;

};
