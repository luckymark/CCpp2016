/**
 * Project Untitled
 */


#ifndef _TEACHER_H
#define _TEACHER_H

#include "Person.h"
#include "date.h"
#include <string>
#include <iostream>
using namespace std;

class Teacher: public Person {
public:
    Teacher(string name,string ID, int age, int sex, date bir,string title):Person(name,ID,age,sex,bir)
    {
        this->title=title;
    }
    string getTitle();
private:
    string title;
};

#endif //_TEACHER_H
