#include "Mainmenu.h"
#include <iostream>
#include <conio.h>
#include <cstdlib>
#include "ViewStudentList.h"
#include "AddStudent.h"
#include "DeleteStudent.h"
#include "InputScore.h"
#include "KeyBoardValue.h"
Mainmenu* Mainmenu::_instance = 0;
void Mainmenu::showInformation(std::map<Student,int>&studentList)
{
	if (isActive)
	{
		system("cls");
		std::cout << "----------C/CPP成绩管理器-----------\n"
			<< "1:查看成绩单\n"
			<< "2:添加学生\n"
			<< "3:删除学生\n"
			<< "4:录入成绩\n"
			<< "5:退出\n";
		isActive = false;
	}
	
}

void Mainmenu::getInformation(std::map<Student, int>&StudentList,State*&nowState)
{
	if (isActive)return;
	int op = _getch();
	std::cout << "op=" << op << std::endl;
	if (op == _num1)
		nowState = ViewStudentList::instance();
	else if (op == _num2)
		nowState = AddStudent::instance();
	else if (op == _num3)
		nowState = DeleteStudent::instance();
	else if (op == _num4)
		nowState = InputScore::instance();
	else if (op == _num5 || op == _Esc)
	{
		outputStudent(StudentList);
		exit(0);
	}
	nowState->setActive(true);
}

Mainmenu * Mainmenu::instance()
{
	if (_instance == 0)
		_instance = new Mainmenu();
	return _instance;
}
void Mainmenu::outputStudent(std::map<Student, int>&studentList)
{
	outputData.open("StudentList.txt");
	for (auto stu : studentList)
		outputData << stu.first.getStuID() << ' ' << stu.first.getName() << ' ' << stu.first.getSex() << ' ' << stu.first.getScore() << std::endl;
}
Mainmenu::Mainmenu()
{
	alternativeStates.push_back(ViewStudentList::instance());
	alternativeStates.push_back(AddStudent::instance());
	alternativeStates.push_back(DeleteStudent::instance());
	alternativeStates.push_back(InputScore::instance());
}


Mainmenu::~Mainmenu()
{
}
