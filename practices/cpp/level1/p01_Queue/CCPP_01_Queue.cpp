// CCPP_01_Queue.cpp : Defines the entry point for the console application.
//

#include "Queue.h"
#include <iostream>

using namespace std;
void menu();
Queue queue;

int main()
{
	menu();
	return 0;
}

void menu() {
	cout << "����Ҫ��ʲô��" << endl;
	cout << "<1.����>\t<2.����>\t<3.�˳�>" << endl;
	int choice;
	cin >> choice;
	switch (choice)
	{
	case 1:
		if (!queue.isFull()) {
			queue.append();
		}
		else
		{
			cout << "����������" << endl;
		}
		menu();
		break;
	case 2:
		if (!queue.isEmpty()) {
			queue.pop();
		}
		else
		{
			cout << "����Ϊ�գ�" << endl;
		}
		menu();
		break;
	case 3:
		break;
	default:
		break;
	}
}

