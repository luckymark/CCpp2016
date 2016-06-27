/**
 * Project Untitled
 */


#ifndef _STUTECH_H
#define _STUTECH_H

#include "Student.h"
#include "Teacher.h"
#include "date.h"
#include <string>
#include <iostream>
using namespace std;

class StuTech: public Student, public Teacher {
public:
    StuTech(string name,string ID, int age, int sex, date bir,string stuID,int score,string title):Student(name,ID,age,sex,bir,stuID,score),Teacher(name,ID,age,sex,bir,title){ }
};

#endif //_STUTECH_H
