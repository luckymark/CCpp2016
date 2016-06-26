#include "Mainmenu.h"
#include <iostream>
#include <conio.h>
#include <cstdlib>
/*
#include "ViewStudentList"
#include "AddStudent"
#include "DeleteStudent"
#include "InputScore"
*/
Mainmenu* Mainmenu::_instance = 0;
void Mainmenu::showInformation(std::map<Student,int>&studentList)
{
	if (isActive)
	{
		std::cout << "----------C/CPP成绩管理器-----------\n"
			<< "1:查看成绩单\n"
			<< "2:添加学生\n"
			<< "3:删除学生\n"
			<< "4:录入成绩\n";
			<< "5:退出\n"
		isActive = false;
	}
	
}

void Mainmenu::getInformation(std::map<Student, int>&)
{
	if (isActive)return;
	int op
}

Mainmenu * Mainmenu::instance()
{
	if (_instance == 0)
		_instance = new Mainmenu;
	return _instance;
}

Mainmenu::Mainmenu()
{
	alternativeStates.push_back();

}


Mainmenu::~Mainmenu()
{
}
