#include"HeapPriorityQueue.h"
#include<fstream>
#define NUM_DATA 10

void main() {
	ofstream fout;
	string tName = "";
	char tmp[10];
	int priority = -1;
	int duration = 0;
	Task tsk;
	
	fout.open("out.txt");
	if (fout.fail()) {
		cout << "File open ERROR !! ";
		exit(1);
	}
	Task* pTask;
	HeapPriorityQueue<Task> taskHeapPriQ;
	Array_CompleteTree<Task> *pacT = taskHeapPriQ.getacTree();
	
	cout << " Insert " << NUM_DATA << " Tasks into HeapPriorityQueue<Task> . . . . " << endl;
	for (int i = NUM_DATA; i > 0; i--) {
		_itoa_s(i, tmp, NUM_DATA);
		tName = "task_" + string(tmp);
		priority = i;
		duration = i;
		pTask = new Task(tName, priority, duration);
		taskHeapPriQ.insert(*pTask);
		fout << endl << " Size of task heap Priority Queue ( After insertion of task ( ";
		fout << tName << " , " << priority << " , " <<
			duration << " ) : ";
		fout << taskHeapPriQ.size() << endl;
		fout << " Heap Priority Queue Architecture : " << endl;
		pacT->printArrayCompleteTreeByLevel(pacT->getRoot(), 0, fout);
		fout << endl;
	}

	cout << " GetMin( ) and removeMin() " << NUM_DATA <<
		" Tasks from HeapPriorityQueue<Task> . . . . " << endl;
	for (int i = 0; i < NUM_DATA; i++) {
		tsk = taskHeapPriQ.getMin();
		fout << " Top priority Task in Heap Priority Queue : " << tsk;
		fout << endl;
		fout << "     removeMin( ) . . . ";
		taskHeapPriQ.removeMin();
		fout << " , size after remove Min( ):" <<
			taskHeapPriQ.size() << endl;
	}
	cout << " Operation results are stored in out.txt file" << endl;
	fout.close();
}