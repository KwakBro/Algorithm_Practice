#include<windows.h>
#include<conio.h>
#include"Multi-Thread.h"
using namespace std;
#define NUM_TASKS 10
unsigned long WINAPI Thread_TaskGenerator(void* pParam) {
	ThreadParam *pThrParam;
	UINT32 srcAddr;
	ofstream *pFout;
	int p;
	int task_id, task_priority, urgency_code;
	string task_name, task_type;
	Task *pTask, task;
	Task_Queue *pTask_Q;
	int num_tasks;
	CRITICAL_SECTION *pCS;
	int delay = 0;
	
	pThrParam = (ThreadParam*)pParam;
	pTask_Q = pThrParam->pTaskQ;
	pFout = pThrParam->pOfstr;
	num_tasks = pThrParam->num_tasks;
	pCS = pThrParam->pCS_TASK_Q;

	EnterCriticalSection(pCS);
	*pFout <<endl<< " >> Thread_Task_Generator Activated" << endl;
	LeaveCriticalSection(pCS);

	for (int i = 0; i < num_tasks; i++) {
		task_id = i;
		task_name = "Task_" + to_string(i);
		task_priority = rand() % 10;
		if (task_priority <= 2) {
			urgency_code = rand() % 100;
			task_type = "Urgent_task_" + to_string(rand() % 10);
		}
		else {
			urgency_code = rand() % 100 + 500;
			task_type = "Normal_task_" + to_string(rand() % 40 + 50);
		}
		pTask = new Task(task_id, task_name, task_priority, urgency_code, task_type);
		EnterCriticalSection(pCS);
		pTask_Q->enQueue_Task(*pTask);
		*pFout << " >> Enqueuing task : " << *pTask;
		LeaveCriticalSection(pCS);
		delay = 30+rand() % 10;
		Sleep(delay);
	}
	return 0;
}

unsigned long WINAPI Thread_TaskHandler(void* pParam) {
	ThreadParam *pThrParam;
	Task task;
	Task_Queue *pTask_Q;
	int num_task, count_task;
	ofstream *pFout;
	CRITICAL_SECTION *pCS;
	int delay = 0;
	
	pThrParam = (ThreadParam*)pParam;
	pTask_Q = pThrParam->pTaskQ;
	pFout = pThrParam->pOfstr;
	num_task = pThrParam->num_tasks;
	pCS = pThrParam->pCS_TASK_Q;
	
	count_task = 0;
	*pFout << endl << " << Dequeuing Tasks from Task_Queue according to Priority";
	*pFout << " ( Urgent Task First ) . . . " << endl;
	do {
		EnterCriticalSection(pCS);
		task = pTask_Q->deQueue_Task();	// 디큐하고 시작. 오류발생여지
		if (task.getTaskid() == -1) {
			*pFout << "    << Task_Queue ( both Urgent_Task and Normal_Task ) is empty !! " << endl;
			LeaveCriticalSection(pCS);
			Sleep(10);
			continue;
		}
		count_task++;
		*pFout << "    << Dequeuing task : " << task;
		LeaveCriticalSection(pCS);
		delay = rand() % 10;
		Sleep(delay);
	} while (count_task < num_task);
	return 0;
}

void main() {
	ofstream fout;
	ThreadParam *pThrTskHndlrParam, *pThrTskGenParam;
	CRITICAL_SECTION cs_Task_Q;
	HANDLE hThreadTaskGen, hTreadTaskHandler;
	
	fout.open("out.txt");
	if (fout.fail()) {
		cout << " FILE CANT OPEN.";
		exit(1);
	}

	Task_Queue task_Q(&fout); 
	InitializeCriticalSection(&cs_Task_Q);
	fout << endl << " Creation of Task Handler Thread in main() .... " << endl;
	
	pThrTskHndlrParam = new ThreadParam;
	pThrTskHndlrParam->addr = (UINT32)0;
	pThrTskHndlrParam->role = TASK_HANDLER;
	pThrTskHndlrParam->pCS_TASK_Q = &cs_Task_Q;
	pThrTskHndlrParam->pTaskQ = &task_Q;
	pThrTskHndlrParam->max_queue = NUM_TASKS;
	pThrTskHndlrParam->duration = 30;
	pThrTskHndlrParam->num_tasks = NUM_TASKS;
	pThrTskHndlrParam->pOfstr = &fout;

	hTreadTaskHandler = CreateThread(NULL,0, Thread_TaskHandler, pThrTskHndlrParam, 0, NULL);
	
	fout << endl << " Creation of Task Generation Thread in main() .... " << endl;

	pThrTskGenParam = new ThreadParam;
	pThrTskGenParam->addr = (UINT32)1;
	pThrTskGenParam->role = TASK_GEN;
	pThrTskGenParam->pCS_TASK_Q = &cs_Task_Q;
	pThrTskGenParam->pTaskQ = &task_Q;
	pThrTskGenParam->max_queue = NUM_TASKS;
	pThrTskGenParam->duration = 30;
	pThrTskGenParam->num_tasks = NUM_TASKS;
	pThrTskGenParam->pOfstr = &fout;

	hThreadTaskGen = CreateThread(NULL, 0, Thread_TaskGenerator, pThrTskGenParam, 0, NULL);

	cout << "Press any key to terminate.. " << endl;
	_getch();

	CloseHandle(hThreadTaskGen);
	fout << " Thread Task Generator closed." << endl;
	CloseHandle(hTreadTaskHandler);
	fout << " Thread Task Handler closed." << endl;
	DeleteCriticalSection(&cs_Task_Q);
	fout << " All critical sections deleted. " << endl;
	delete pThrTskGenParam;
	delete pThrTskHndlrParam;
	fout.close();
}