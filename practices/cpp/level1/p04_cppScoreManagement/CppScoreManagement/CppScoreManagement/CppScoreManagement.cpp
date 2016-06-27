#include "CppScoreManagement.h"
#include "Mainmenu.h"
#include <iostream>
CppScoreManagement* CppScoreManagement::_instance = 0;

CppScoreManagement::CppScoreManagement()
{
	_state = Mainmenu::instance();
}


CppScoreManagement * CppScoreManagement::instance()
{
	if (_instance == 0)
		_instance = new CppScoreManagement;
	return _instance;
}

CppScoreManagement * CppScoreManagement::changeState(State * _state)
{
	this->_state = _state;
	return this;
}

void CppScoreManagement::showInformation()
{
	_state->showInformation(studentList);
}

void CppScoreManagement::getInformation()
{
	_state->getInformation(studentList,_state);
}

void CppScoreManagement::inputStudent()
{
	inputData.open("StudentList.txt");
	std::string temp;
	std::stringstream line;
	std::string stuID, name, sex;
	double score;
	while(getline(inputData,temp))
	{
		score = -1.0;
		line.clear();
		line << temp;
		line >> stuID >> name >> sex >> score;
		studentList.insert(std::pair<Student, int>(Student(stuID, sex, name,score), 1));
	}
}



CppScoreManagement::~CppScoreManagement()
{
}
