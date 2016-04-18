#include<iostream>
#include<cstdlib>
#include"list.h"
#include<cstdlib>
using namespace std;
Student* Student::head = NULL;
int main()
{
	int grade = 0;
	string student, lesson;
	Student *phead;
	phead = new Student("", "", grade);
	while (1)
	{
		phead=phead->showmenu();
		system("cls");
	}
}