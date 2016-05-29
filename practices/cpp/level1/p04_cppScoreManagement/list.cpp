#include "list.h"
#include<iostream>
using namespace std;
List* List::addInfo(List *bottom)
{
	string mname, lesson = "C++";
	int mID;
	cout << "���������ӵ�ѧ����" << endl;
	cin >> mname;
	cout << "�����������ѧ��ID"<<endl;
	cin >> mID;
	Student *middle;
	middle = new Student(mname, mID);
	bottom->pnext = new List;
	bottom = bottom->pnext;
	bottom->info = middle;
	bottom->pnext = NULL;
	if (List::head == NULL)
	{
		List::head = new List;
		List::head->info = new Student(" ", 0, " ");
		List::head->pnext = new List;
		List::head->pnext=bottom;
	}
	return bottom;
}

void List::deleteInfo()
{
	cout << "�������ɾ����ID" << endl;
	int mID;
	cin >> mID;
	List *middle;
	List *find = List::head->pnext;
	for (; find != NULL; find = find->pnext)
	{
		if (find->info->getID()==mID)
		{
			delete find->info;
			middle->pnext = find->pnext;
			delete find;
			break;
		}
		middle = find;
	}
}

List* showMenu(List *bottom)
{
	int n;
	cout << "1.����ѧ��" << endl << "2.��ӡ����" << endl << "3.ɾ��ѧ��" << endl;
	cout << "4.¼�����" << endl << "5.�˳�" << endl;
	cin >> n;
	switch (n)
	{
	case 1:
		bottom = bottom->addInfo(bottom);
		cout << "��ӳɹ�" << endl;
		return bottom;
	case 2:
		bottom->showList();
		break;
	case 3:
		bottom->deleteInfo();
		break;
	case 4:
		bottom->addGrade();
		break;
	case 5:
		exitMenu();
	default:
		cout << "error!!!" << endl;
	}
	return bottom;
}


void List::showList()
{
	List *find = List::head->pnext;
	for (; find != NULL; )
	{
		cout << find->info->getName() << "     " << find->info->getID() << "     " << find->info->getGrade() << endl;
		find = find->pnext;
	}
}

void exitMenu()
{
	exit(0);
}

void List::addGrade()
{
	char judge;
	int flag = 0;
	cout << "������ѧ��ID��" << endl;
	int mID;
	cin >> mID;
	List *find = List::head->pnext;
	for (; find != NULL; find = find->pnext)
	{
		if (find->info->getID() == mID)
		{
			flag = 1;
		}
		if (flag)
		{
			find->info->inputGrade();
			cout << "continue? y/n" << endl;
			cin >> judge;
			if (judge != 'y')
			{
				break;
			}
		}
	}
}



