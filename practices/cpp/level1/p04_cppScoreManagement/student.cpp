#include<iostream>
using namespace std;
#include"student.h"
void Student::inputGrade()
{
	int grade;
	cout << "������"<<name<<"�ĳɼ�" << endl;
	cin >> grade;
	this->grade = grade;
}

int Student::getID()
{
	return ID;
}

string Student::getName()
{
	return name;
}

int Student::getGrade()
{
	return grade;
}

Student::~Student()
{
	cout << "ɾ���ɹ�" << endl;
}
