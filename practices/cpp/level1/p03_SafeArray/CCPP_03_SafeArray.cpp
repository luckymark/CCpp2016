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
	cout << "�����������С��";
	int size;
	cin >> size;
	safeArray = new SafeArray(size);
	menu();
	return 0;
}

void menu() {
	int choice;
	int mark;
	cout << "Ҫ��ʲô��?" << endl;
	cout << "<1.����>\t<2.��ѯ>\t<3.�޸�>\t<4.�˳�>" << endl;
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
			cout << "���棺��������!" << endl;
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
			cout << "���棺����ĽǱ��������������" << endl;
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
			cout << "���棺����ĽǱ��������������" << endl;
		}
		menu();
		break;
	default:
		break;
	}
}

int inputMark() {
	cout << "������ű꣺";
	int mark;
	cin >> mark;
	return mark;
}