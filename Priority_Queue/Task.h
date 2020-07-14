#ifndef TASK_H
#define TASK_H
#include<iostream>
#include<string>
using namespace std;

class Task {
	friend ostream& operator << (ostream& out, Task& right) {
		out << "Task - name ( " << right.taskName <<
			" ) , pri ( " << right.priority << " ) , duration ( " <<
			right.duration << " ) ";
		return out;
	}
private:
	string taskName;
	int priority;
	int duration;
public:
	Task() {}
	Task(string Name, int pri, int dur) :
		taskName(Name), priority(pri), duration(dur) {}
	string getTaskName() { return taskName; }
	int getPriority() { return priority; }
	int getDuration() { return duration; }
	void setTaskName(string n) { taskName = n; }
	void setPriority(int pri) { priority = pri; }
	void setDuration(int dur) { duration = dur; }
	bool operator > (Task& t) { return (priority > t.priority); }
	bool operator < (Task& t) { return (priority < t.priority); }
};

#endif