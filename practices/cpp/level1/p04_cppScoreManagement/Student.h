//
// Created by Administrator on 2016/4/28.
//

#ifndef P04_CPPSCOREMANAGEMENT_STUDENT_H
#define P04_CPPSCOREMANAGEMENT_STUDENT_H
#include <iostream>

class Student {
public:
    void show();
    void set_grade();
    void initial();
    void dele();
private:
    std::string name;
    long id;
    int grade;
};


#endif //P04_CPPSCOREMANAGEMENT_STUDENT_H
