#pragma once
#include "State.h"
#include <map>
class AddStudent :
	public State
{
public:
	static AddStudent* instance();
	void showInformation(std::map<Student, int>&);
	void getInformation(std::map<Student, int>&,State*&);
	~AddStudent();
protected:
	AddStudent();
private:
	static AddStudent* _instance;
};

