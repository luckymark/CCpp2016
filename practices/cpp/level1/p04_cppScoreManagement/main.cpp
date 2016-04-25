#include<iostream>
#include<list>
#include"list.h"
#include"student.h"
#include<cstdlib>
List *List::head = NULL;
using namespace std;
int main()
{
	List *p;
	List *student = new List;
	while (1)
	{
		student = showMenu(student);
		system("pause");
		system("cls");
	}
}
