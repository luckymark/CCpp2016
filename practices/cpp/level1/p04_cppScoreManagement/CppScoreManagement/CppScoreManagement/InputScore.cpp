#include "InputScore.h"
#include <iostream>
#include <string>
#include "Student.h"
#include "Mainmenu.h"
InputScore::InputScore()
{
}


void InputScore::showInformation(std::map<Student, int>&studentList)
{
	if (isActive)
	{
		isInputScoreFinish = false;
		for(auto stu:studentList)
			if (stu.first.getScore == -1.0)
			{
				std::cout << "学号:" << stu.first.getStuID
					<< "\n姓名:" << stu.first.getName
					<< "\n性别:" << stu.first.getSex
					<< "\n请确认后输入成绩,输入back然后主菜单\n";
				setActive(false);
				return;
			}
		isInputScoreFinish = true;
	}
}

void InputScore::getInformation(std::map<Student, int>&studentList, State *&nowState)
{
	if (isInputScoreFinish)
	{
		std::cout << "所有学生的成绩都已录入完毕，按任意键回到主菜单\n";
		getchar();
		nowState = Mainmenu::instance();
		return;
	}
	if (isActive)return;
	std::string op;
	std::getline(std::cin, op);
	if (op == "back")
	{
		nowState = Mainmenu::instance();
		nowState->setActive(true);
	}
}

InputScore::~InputScore()
{
}
