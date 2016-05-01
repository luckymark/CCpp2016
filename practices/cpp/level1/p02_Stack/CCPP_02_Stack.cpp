// CCPP_02_Stack.cpp : Defines the entry point for the console application.
//

#include "Stack.h"
#include <iostream>

using namespace std;
void menu();
Stack *stack;

int main()
{
	cout << "请输入栈的大小：";
	int size;
	cin >> size;
	stack = new Stack(size);
	menu();
    return 0;
}

void menu() {
	cout << "想要干什么?" << endl;
	cout << "<1.入栈>\t<2.出栈>\t<3.退出>" << endl;
	int choice;
	cin >> choice;
	switch (choice)
	{
	case 1:
		if (!stack->isFull())
		{
			stack->append();
		}
		else
		{
			cout << "堆栈已满" << endl;
		}
		menu();
		break;
	case 2:
		if (!stack->isEmpty()) {
			stack->pop();
		}
		else
		{
			cout << "堆栈为空" << endl;
		}
		menu();
		break;
	default:
		break;
	}
}

