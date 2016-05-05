// CCPP_03_SafeArray.cpp : Defines the entry point for the console application.
//

#include "SafeArray.h"
#include <iostream>

using namespace std;
void menu();
int inputMark();
SafeArray *safeArray;


int main()
{
	cout << "请输入数组大小：";
	int size;
	cin >> size;
	safeArray = new SafeArray(size);
	menu();
	return 0;
}

void menu() {
	int choice;
	int mark;
	cout << "要做什么呢?" << endl;
	cout << "<1.新增>\t<2.查询>\t<3.修改>\t<4.退出>" << endl;
	cin >> choice;
	switch (choice)
	{
	case 1:
		if (!safeArray->isFull())
		{
			safeArray->add();
		}
		else
		{
			cout << "警告：数组已满!" << endl;
		}
		menu();
		break;
	case 2:
		mark = inputMark();
		if (!safeArray->isOver(mark))
		{
			safeArray->query(mark);
		}
		else
		{
			cout << "警告：输入的角标大于数组容量！" << endl;
		}
		menu();
		break;
	case 3:
		mark = inputMark();
		if (!safeArray->isOver(mark))
		{
			safeArray->edit(mark);
		}
		else
		{
			cout << "警告：输入的角标大于数组容量！" << endl;
		}
		menu();
		break;
	default:
		break;
	}
}

int inputMark() {
	cout << "请输入脚标：";
	int mark;
	cin >> mark;
	return mark;
}