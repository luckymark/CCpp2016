#include "DeleteStudent.h"
#include <iostream>
#include <string>
#include "State.h"
#include "Mainmenu.h"
DeleteStudent::DeleteStudent()
{
}


void DeleteStudent::showInformation(std::map<Student, int>&studentList)
{
	if (isActive)
	{
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
			getchar();
			setActive(true);
			return;
		}
	cout<<
}

DeleteStudent::~DeleteStudent()
{
}
