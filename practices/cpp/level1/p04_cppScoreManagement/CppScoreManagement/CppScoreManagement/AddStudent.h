#pragma once
#include "State.h"
class AddStudent :
	public State
{
public:
	static AddStudent* instance();
	~AddStudent();
protected:
	AddStudent();
private:
	static AddStudent* _instance;
};

