//
// Created by Administrator on 2016/6/7.
//
#include <iostream>
#include <string>
using namespace std;

#ifndef P04_CPPSCOREMANAGEMENT_STUDENT_H
#define P04_CPPSCOREMANAGEMENT_STUDENT_H


class Student {
private:
    string name;
    int score;
public:
    Student(string Name){
        name=Name;
        score=0;
    }
    int Get_score();
    string Get_name();
    void Set_name();
    void Set_name(string Name);
    void Set_score();
};


#endif //P04_CPPSCOREMANAGEMENT_STUDENT_H
