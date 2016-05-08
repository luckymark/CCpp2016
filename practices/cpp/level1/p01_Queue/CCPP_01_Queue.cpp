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
	cout << "你想要做什么？" << endl;
	cout << "<1.入列>\t<2.出列>\t<3.退出>" << endl;
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
			cout << "队列已满！" << endl;
		}
		menu();
		break;
	case 2:
		if (!queue.isEmpty()) {
			queue.pop();
		}
		else
		{
			cout << "队列为空！" << endl;
		}
		menu();
		break;
	case 3:
		break;
	default:
		break;
	}
}

