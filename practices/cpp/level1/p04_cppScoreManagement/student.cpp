#include<iostream>
using namespace std;
#include"student.h"
void Student::inputgrade()
{
	int grade;
	cout << "请输入"<<name<<"的成绩" << endl;
	cin >> grade;
	this->grade = grade;
}

int Student::getID()
{
	return ID;
}

string Student::getname()
{
	return name;
}

int Student::getgrade()
{
	return grade;
}

Student::~Student()
{
	cout << "删除成功" << endl;
}
