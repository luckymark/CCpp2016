#pragma once

#include<string>
using namespace std;
class Student
{
private:
	string name;
	int ID;
	string lesson;
	int grade;
public:
	Student(string name = " ", int ID = 0,string lesson="C++",int grade=0):name(name),ID(ID),lesson(lesson),grade(grade){}
	void inputGrade();
	int getID();
	string getName();
	int getGrade();
	~Student();
};