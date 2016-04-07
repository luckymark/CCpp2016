#ifndef CLASS_LIST_H
#define CLASS_LIST_H

#include <vector>
#include <string>
#include "StudentInfo.h"

class ClassList
{
private:
    std::vector<StudentInfo> student;
public:
    bool addStudent();
    bool inputScore(unsigned score);
};
#endif