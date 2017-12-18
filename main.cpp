#include <string>
#include "top.h"

#include "processes.h"

int sc_main (int, char**)
{

	// create some CPUs and add some processes (tasks) on them

       	// instantiate the global trace file
	g_trace_file = sc_create_vcd_trace_file("trace");         // create a trace file
	g_trace_file->set_time_unit(1,SC_NS);
        
	Top top("top");

	IntHandler par1(1);
	IntHandler par2(2);
	IntHandler par3(3);
	IntHandler par6(6);
	IntHandler par7(7);
	IntHandler par8(8);
	IntChaineHandler par4(1,2,'a');
	IntChaineHandler par5(2,3,'b');
        top.cpu1.AddInitialTask (proc1, (void*) &par1, "cpu1 - proc1");
        top.cpu1.AddInitialTask (proc2, (void*) &par2, "cpu1 - proc2");
	
	top.cpu2.AddInitialTask (proc6, (void*) &par6, "cpu2 - proc6");
	top.cpu2.AddInitialTask (proc7, (void*) &par7, "cpu2 - proc7");
	top.cpu2.AddInitialTask (proc8, (void*) &par8, "cpu2 - proc8");

        top.cpu2.AddInitialTask (proc3, (void*)&par3, "cpu2 - proc3");
	top.cpu2.AddInitialTask (proc4, (void*)&par4, "cpu2 - proc4");
	
	//top.cpu2.AddInitialTask (proc5, (void*)&par5, "cpu2 - proc5");

	sc_start (200000, SC_NS);

        sc_close_vcd_trace_file(g_trace_file);             

	return 0;
}
