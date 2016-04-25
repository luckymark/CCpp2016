#include<iostream>
#include"list.h"
#include<conio.h>
using namespace std;
Student::Student(string name, string lesson, int grade)
{
	this->name = name;
	this->lesson = lesson;
	this->grade = grade;
	this->pnext = NULL;
}
Student::Student(const Student & p)
{
	this->name = p.name;
	this->lesson = p.lesson;
	this->grade = p.grade;
	this->pnext = NULL;
}
void Student::showlist()
{
	Student *show(Student::head->pnext);
	for (; show != NULL; show = show->pnext)
	{
		cout << show->name<<"  ";
		if (show->grade != 0)
		{
			cout << show->grade << endl;
		}
		else
		{
			cout << endl;
		}
	}
}
Student::~Student() 
{
	cout << "ɾ���ɹ�" << endl;
}
Student* Student::showmenu()
{
	Student *list;
	list = new Student("", "", 0);
	int num;
	cout << "������ѡ��" << endl << endl;
	cout << "1.�鿴ѧ������" << endl;
	cout << "2.ѡ��(���ѧ��)" << endl;
	cout << "3.�˿�(ɾ��ѧ��)" << endl;
	cout << "4.¼��ɼ�" << endl;
	cout << "5.�˳�ϵͳ" << endl;
	cin >> num;
	switch (num)
	{
	case 1:
			showlist();
			getch();
		break;
	case 2:
		list = addlesson(list->pnext);
		cout << "��ӳɹ�" << endl;
		break;
	case 3:
		deletelesson();
		break;
	case 4:
		inputgrade();
		break;
	case 5:
		exitmenu();
		break;
	default:
		cout << "error!!" << endl;
	}
	return list;
}
Student* Student::addlesson(Student *list)
{
	int grade = 0;
	string name, lesson = "C++";
	cin >> name;
	list = new Student(name, lesson, grade);
	if (head == NULL)
	{
		head = new Student("", "", 0);
		head->pnext = list;
	}
	else
	{
		this->pnext = list;
	}
	return list;
}

void Student::deletelesson()
{
	string name;
	cin >> name;
	Student *middle(Student::head);
	Student *cut((Student::head)->pnext);
	for (; cut->pnext != NULL;cut=cut->pnext)
	{
		if (cut->name == name)
		{
			middle->pnext = cut->pnext;
			delete cut;
			break;
		}
		middle = cut;
	}
}

void Student::inputgrade()
{
	char s;
	int score;
	Student *input(Student::head->pnext);
	for (; input != NULL; input = input->pnext)
	{
		cout << input->name << endl;
		cin >> score;
		input->grade = score;
		cout << "��ӷ����ɹ�" << endl;
		cout << "do you want to continue?y/n";
		cin >> s;
		if (s == 'n')
		{
			break;
		}
	}
}
