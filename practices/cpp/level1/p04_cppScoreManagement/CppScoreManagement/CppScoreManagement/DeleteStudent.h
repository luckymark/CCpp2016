#pragma once
#include "State.h"
#include <map>
#include "Student.h"
class DeleteStudent :
	public State
{
public:
	static DeleteStudent* instance();
	void showInformation()
	~DeleteStudent();
protected:
	DeleteStudent();
private:
	static DeleteStudent* _instance;
};

