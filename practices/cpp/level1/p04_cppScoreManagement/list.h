#pragma once
#include<string>
using namespace std;
class Student
{
private:
	static Student *head;
	string name;
	string lesson;
	int grade;
public:
	Student *pnext;
	Student (string name=NULL, string lesson=NULL, int grade=0) ;
	Student(const Student &p);
	void showlist();
	Student * showmenu();
	Student* addlesson(Student *p);
	void deletelesson();
	void inputgrade();
	void exitmenu() { exit(0); };
	~Student();
};
