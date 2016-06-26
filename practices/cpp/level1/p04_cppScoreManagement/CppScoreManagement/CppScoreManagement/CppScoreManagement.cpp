#include "CppScoreManagement.h"
#include "Mainmenu.h"
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

CppScoreManagement::~CppScoreManagement()
{
}
