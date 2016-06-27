#include "InputScore.h"
#include <iostream>
#include <string>
#include "Student.h"
#include "Mainmenu.h"
#include <conio.h>
InputScore* InputScore::_instance = 0;
InputScore::InputScore()
{
	
}


InputScore * InputScore::instance()
{
	if (_instance == 0)
		_instance = new InputScore;
	return _instance;
}

void InputScore::showInformation(std::map<Student, int>&studentList)
{
	if (isActive)
	{
		system("cls");
		isInputScoreFinish = false;
		for(auto stu:studentList)
			if (stu.first.getScore() == -1.0)
			{
				std::cout << "学号:" << stu.first.getStuID()
					<< "\n姓名:" << stu.first.getName()
					<< "\n性别:" << stu.first.getSex()
					<< "\n请确认后输入成绩,输入back返回主菜单\n";
				setActive(false);
				nowStudent = stu.first;
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
		_getch();
		nowState = Mainmenu::instance();
		nowState->setActive(true);
		return;
	}
	if (isActive)return;
	std::string op;
	std::cin >> op;
	if (op == "back")
	{
		nowState = Mainmenu::instance();
		nowState->setActive(true);
		return;
	}
	double score = atof(op.c_str());
	auto pos = studentList.find(nowStudent);
	studentList.erase(pos);
	studentList.insert(std::pair<Student, int>(*nowStudent.setScore(score), 1));
	std::cout << "成绩录入成功，按任意键继续录入\n";
	setActive(true);
	_getch();
}

InputScore::~InputScore()
{
}
