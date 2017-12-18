#include "processes.h"



/* file containing the functions implementing the processes (also called tasks) */

IntChaineHandler par5(2,3,'b');

bool proc1 (Task* task, void* p)
{

	static int pas=0;
	IntHandler* par=(IntHandler*)p;

	cout << task->m_name << " "<< par->i << endl;

	CONSUME(par->i * 100);

	if(++pas==5)task->m_os->RegisterTask(proc5,&par5, "cpu1 - proc5",4,false);
	//Task (OS *os, task_h h, void *arg,const char *name, int index, int priority, bool resetTask); 

	return true;
}

bool proc2 (Task* task,void* p)
{
	IntHandler* par=(IntHandler*)p;

	cout << task->m_name << " "<< par->i << endl;

	CONSUME(par->i * 100);

	return true;
}

bool proc3 (Task* task,void* p)
{
	IntHandler* par=(IntHandler*)p;

	cout << task->m_name << " "<< par->i << endl;

	CONSUME(par->i * 100);

	return true;
}


bool proc4 (Task* task,void* p)
{
	//To be completed
	IntChaineHandler* par=(IntChaineHandler*)p;	
	task->m_os->ChanOut(0,"Heihei",6);
	//cout << task->m_name << " "<<"somme: "<< par->h <<"char: "<< par->a<<endl;
	cout<< task->m_name<<": "<<"envoi: Heihei"<<endl;
	CONSUME(200);
	return true;
}

bool proc5 (Task* task,void* p)
{
	//To be completed	
	IntChaineHandler* par=(IntChaineHandler*)p;	
	cout << task->m_name << " "<<"somme: "<< par->h <<" char: "<< par->a<<endl;

	CONSUME(par->i * 100);
	//Do not restart the process
	return false;
}

bool proc6 (Task* task,void* p)
{
	//To be completed	
	IntHandler* par=(IntHandler*)p;
	task->m_os->ChanOut(2,"Bonjour",7);
	cout<< task->m_name<<": "<<"envoi: Bonjour"<<endl;
	CONSUME(200);
	//Do not restart the process
	return true;
}

bool proc7 (Task* task,void* p)
{
	//To be completed
	IntHandler* par=(IntHandler*)p;	
	char str[100];
	int size;
	int channels[3];
	channels[0]=0;
	channels[1]=1;
	channels[2]=2;
	int fromChannel;
	task->m_os->AltIn(3, channels, str, size, fromChannel);
	task->m_os->ChanIn(fromChannel,str,size);
	CONSUME(100);
	cout<< task->m_name<<str<<endl;
	//Do not restart the process
	return true;
}

bool proc8 (Task* task,void* p)
{
	//To be completed	
	IntHandler* par=(IntHandler*)p;
	task->m_os->ChanOut(1,"Bonsoir",7);
	cout<< task->m_name<<": "<<"envoi: Bonsoir"<<endl;
	CONSUME(200);
	
	return true;
}

