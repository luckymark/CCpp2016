//
// Created by Administrator on 2016/4/28.
//

#include "Student.h"
#include <iostream>

void Student::show() {
    cout << name << "\t" << id << "\t" << endl;
}

void Student::set_grade() {
    int x;
    std::cin>>x;
    grade=x;
}

void initial()