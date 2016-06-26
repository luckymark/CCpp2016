#include "ViewStudentList.h"
#include "KeyBoardValue.h"
#include "Mainmenu.h"
#include <conio.h>
#include <iostream>
ViewStudentList* ViewStudentList::_instance = 0;

ViewStudentList::ViewStudentList()
{
}


ViewStudentList * ViewStudentList::instance()
{
	if (_instance == 0)
		_instance = new ViewStudentList;
	return _instance;
}

void ViewStudentList::showInformation(std::map<Student, int>&studentList)
{
	if (isActive)
	{
		std::cout << "C++成绩表\n";
		for (auto stu :studentList)
			stu.first.showInformation();
		std::cout << "按5返回主菜单\n";
		isActive = false;
	}
}

void ViewStudentList::getInformation(std::map<Student, int>&studentList,State*& nowState)
{
	int op = getch();
	if (op == KeyBoardValue::_num5)
	{
		nowState = Mainmenu::instance();
		nowState->setActive(true);
}

	ViewStudentList::~ViewStudentList();
