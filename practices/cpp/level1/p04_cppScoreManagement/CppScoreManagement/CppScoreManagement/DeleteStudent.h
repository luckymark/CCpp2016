#pragma once
#include "State.h"
#include <map>
#include "Student.h"
class DeleteStudent :
	public State
{
public:
	static DeleteStudent* instance();
	void showInformation(std::map<Student,int>&);
	void getInformation(std::map<Student, int>&, State*&);
	~DeleteStudent();
protected:
	DeleteStudent();
private:
	static DeleteStudent* _instance;
};

