#include "AddStudent.h"



AddStudent::AddStudent()
{
}


AddStudent * AddStudent::instance()
{
	if (_instance == 0)
		_instance = new AddStudent;
	return _instance;
}

AddStudent::~AddStudent()
{
}
