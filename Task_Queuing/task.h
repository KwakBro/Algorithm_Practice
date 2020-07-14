#pragma once
#include<iostream>
#include<string>
using namespace std;

class Task {
	friend ostream& operator << (ostream& out, const Task& right) {
		out << " Task [ id ( " << right.task_id << " ) , name ( " <<
			right.task_name << " ) , priority ( " << right.task_priority <<
			" ) , u_code ( " << right.urgency_code << " ) , type ( " <<
			right.task_type << " ) ] "<< endl;
		return out;
	}
public:
	Task() :
		task_id(-1), task_name("NULL"), task_priority(0),
		urgency_code(0), task_type("NULL") {}
	Task(int t_id, string t_name, int t_pri, int u_code, string t_type):
		task_id(t_id), task_name(t_name), task_priority(t_pri),
		urgency_code(u_code), task_type(t_type) {}
	int getTaskid() {
		return task_id;
	}
	int getPriority() {
		return task_priority;
	}
	string getTaskname() {
		return task_name;
	}
private:
	int task_id;
	string task_name;
	int task_priority;
	int urgency_code;
	string task_type;
};
