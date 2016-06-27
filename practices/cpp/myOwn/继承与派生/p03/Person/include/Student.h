/**
 * Project Untitled
 */


#ifndef _STUDENT_H
#define _STUDENT_H

#include "Person.h"
#include "date.h"
#include <string>
#include <iostream>
using namespace std;

class Student: public Person {
public:
    Student(string name,string ID, int age, int sex, date bir,string stuID,int score):Person(name,ID,age,sex,bir)
    {
        this->studentID=stuID;
        this->score=score;
    }
    string getStuID();

    int getScore();
private:
    string studentID;
    int score;
};

#endif //_STUDENT_H
