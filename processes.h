#include "os.h"


#include <string>


//functions implementing the simulated processes. 
//Parameters are:
//- Task*: a pointer to the process Task object, used for OS method and attribute reference
//- void*: a generic argument for process customization
//Return value is a boolean. If false, the process is stopped. Otherwise, the process is restarted immediately 
bool proc1 (Task*,void*);
bool proc2 (Task*,void*);
bool proc3 (Task*,void*);
bool proc4 (Task*,void*);
bool proc5 (Task*,void*);
bool proc6 (Task* task,void*);
bool proc7 (Task* task,void*);
bool proc8 (Task* task,void*);
//Structure used for transfering an  integer parameter through void pointer (without worrying the compiler)
struct IntHandler{
	IntHandler(int i):i(i)
	{}

	int i;

};

struct IntChaineHandler{
	IntChaineHandler(int i,int j, char a):i(i),j(j),a(a)
	{
		h=i+j;
	}

	int i;
	int j;
	int h;
	char a;
};


//Utility macro for tasks readability
#define CONSUME(t)  (task->m_os->Consume(task, t )); 


