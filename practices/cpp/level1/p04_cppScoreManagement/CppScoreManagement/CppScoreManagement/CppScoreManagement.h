#pragma once
#include "Student.h"
#include "State.h"
#include <map>
class CppScoreManagement
{
public:
	static CppScoreManagement* instance();
	CppScoreManagement* changeState(State* _state);
	void showInformation();
	void getInformation();
	void inputStudent();
	~CppScoreManagement();
protected:
	CppScoreManagement();
private:
	static CppScoreManagement* _instance;
	State* _state;
	std::map<Student, int>studentList;
};

