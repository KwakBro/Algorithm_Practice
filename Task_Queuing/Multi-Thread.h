#pragma once
#include<iostream>
#include<thread>
#include<windows.h>
#include<fstream>
#include"Task_Queue.h"
using namespace std;

enum THREAD_ROLE { TASK_GEN , TASK_HANDLER };

typedef struct ThreadParam {
	CRITICAL_SECTION *pCS_TASK_Q;
	THREAD_ROLE role;
	Task_Queue *pTaskQ;
	UINT32 addr;
	int max_queue;
	int duration;
	int num_tasks;
	ofstream *pOfstr;
} ThreadParam;