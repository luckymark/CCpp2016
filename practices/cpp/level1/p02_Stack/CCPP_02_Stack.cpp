// CCPP_02_Stack.cpp : Defines the entry point for the console application.
//

#include "Stack.h"
#include <iostream>

using namespace std;
void menu();
Stack *stack;

int main()
{
	cout << "������ջ�Ĵ�С��";
	int size;
	cin >> size;
	stack = new Stack(size);
	menu();
	return 0;
}

void menu() {
	cout << "��Ҫ��ʲô?" << endl;
	cout << "<1.��ջ>\t<2.��ջ>\t<3.�˳�>" << endl;
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
			cout << "��ջ����" << endl;
		}
		menu();
		break;
	case 2:
		if (!stack->isEmpty()) {
			stack->pop();
		}
		else
		{
			cout << "��ջΪ��" << endl;
		}
		menu();
		break;
	default:
		break;
	}
}

