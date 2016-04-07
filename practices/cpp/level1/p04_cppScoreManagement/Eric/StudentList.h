#ifndef STUDENT_LIST_H
#define STUDENT_LIST_H
#include "StudentInfo.h"
#include <vector>

class StudentList
{
public:
    void addStudent();
    bool deleteStudent(unsigned targetId);
    bool inputScore(unsigned targetId, unsigned sourceScore);
    void showList();
private:
    std::vector<StudentInfo> studentList;
    int findStudent(unsigned targetId);
    StudentInfo getStudentInfo();
};
bool compareId(StudentInfo comp1, StudentInfo comp2);
#endif