#pragma once
#include "State.h"
#include <map>
#include "Student.h"
class ViewStudentList :
	public State
{
public:
	static ViewStudentList* instance();
	void showInformation(std::map<Student,int>&);
	void getInformation(std::map<Student, int>&,State*&);
	~ViewStudentList();
protected:
	ViewStudentList();
private:
	static ViewStudentList* _instance;
};

