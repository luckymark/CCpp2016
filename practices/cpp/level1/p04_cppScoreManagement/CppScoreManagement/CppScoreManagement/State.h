#pragma once
#include "Student.h"
#include <map>
class State
{
public:

	State()
	{
	}
	virtual void showInformation(std::map<Student,int>&) = 0;
	virtual void getInformation(std::map<Student, int>&,State*&) = 0;
	void setActive(bool);
	virtual ~State()
	{
	}
protected:
	bool isActive = true;
};

