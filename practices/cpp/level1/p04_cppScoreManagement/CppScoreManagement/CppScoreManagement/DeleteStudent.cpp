#include "DeleteStudent.h"
#include <iostream>
#include <string>
#include "State.h"
#include "Mainmenu.h"
#include <conio.h>
DeleteStudent* DeleteStudent::_instance = 0;
DeleteStudent::DeleteStudent()
{
}


DeleteStudent * DeleteStudent::instance()
{
	if (_instance == 0)
		_instance = new DeleteStudent;
	return _instance;
}

void DeleteStudent::showInformation(std::map<Student, int>&studentList)
{
	if (isActive)
	{
		system("cls");
		std::cout << "已选学生名单：\n";
		std::cout << "学号            姓名               性别       成绩\n";
		for (auto stu : studentList)
			stu.first.showInformation();
		std::cout << "请输入要删除的学生的学号,输入back回到主菜单\n";
		isActive = false;
	}
}

void DeleteStudent::getInformation(std::map<Student, int>&studentList, State *&nowState)
{
	std::string stuID;
	std::cin >> stuID;
	if (stuID == "back")
	{
		nowState = Mainmenu::instance();
		nowState->setActive(true);
		return;
	}
	
	for (auto stu = studentList.begin();stu != studentList.end();stu++)
		if (stu->first.getStuID() == stuID)
		{
			studentList.erase(stu);
			std::cout << "删除成功，按任意键继续\n";
			_getch();
			setActive(true);
			return;
		}
	std::cout << "未找到该学生,请重新输入\n";
}

DeleteStudent::~DeleteStudent()
{
}
