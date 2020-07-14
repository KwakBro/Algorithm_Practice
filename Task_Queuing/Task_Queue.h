#pragma once
#include<iostream>
#include"task.h"
#include"DLL.h"
using namespace std;

class Task_Queue {
public:
	Task_Queue(ofstream* pFout) :
		out(pFout) {};		//포인터로 넘기면 가능.
	~Task_Queue() {};
	void enQueue_Task(Task t) {
		if (t.getPriority() <= 2) {
			Urgent_Task_Q.addFront(t);
		}
		else {
			Normal_Task_Q.addFront(t);
		}
	}
	Task deQueue_Task() {
		Task temp;
		if (!Urgent_Task_Q.empty()) {
			temp = Urgent_Task_Q.back();
			Urgent_Task_Q.removeBack();
		}
		else {
			temp = Normal_Task_Q.back();
			if(!Normal_Task_Q.empty())
				Normal_Task_Q.removeBack();
		}
		return temp;
	}
private:
	ofstream *out;
	T_DLL<Task> Urgent_Task_Q;
	T_DLL<Task> Normal_Task_Q;
};