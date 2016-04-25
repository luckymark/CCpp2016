#pragma once
#include"student.h"
#include<string>
using namespace std;
class List
{
	static List *head;
	Student *info;
	List *pnext;
public:
	List* addInfo(List *bottom);
	void deleteInfo();
	friend List* showMenu(List *bottom);
	void showList();
	friend void exitMenu();
	void addGrade();
};
