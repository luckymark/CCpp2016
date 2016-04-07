#include "StudentInfo.h"
#include "StudentList.h"
#include <vector>
#include <iostream>
#include <algorithm>

void StudentList::addStudent()
{
    studentList.push_back(getStudentInfo());
    std::sort(studentList.begin(), studentList.end(), compareId);
}
bool StudentList::deleteStudent(unsigned targetId)
{
    int studentPos = findStudent(targetId);
    if(studentPos == -1)
    {
        std::cerr << "ERROR : There is no No." << targetId << " student." << std::endl;
        return 1;
    }
    studentList.erase(studentList.begin() + studentPos);
    return 0;
}
bool StudentList::inputScore(unsigned targetId, unsigned sourceScore)
{
    int studentPos = findStudent(targetId);
    if(studentPos == -1)
    {
        std::cerr << "ERROR : There is no No." << targetId << " student." << std::endl;
        return 1;
    }
    studentList[studentPos].setScore(sourceScore);
    return 0;
}
void StudentList::showList()
{
    for(auto ite = studentList.begin(); ite != studentList.end(); ite++)
    {
        ite->printAllInfo();
    }
    std::cout << "========ALL=========" << std::endl;
}
int StudentList::findStudent(unsigned targetId)
{
    int count = 0;
    for(auto ite = studentList.begin(); ite != studentList.end(); ite++, count++)
    {
        if(ite->showId() == targetId)
        {
            return count;
        }
    }
    return -1;
}
StudentInfo StudentList::getStudentInfo()
{
    std::string sourceName;
    unsigned sourceId;
    std::cout << "student's name : ";
    std::getline(std::cin, sourceName);
    StudentInfo newStudentInfo(sourceId, sourceName);
    return newStudentInfo;
}
bool compareId(StudentInfo comp1, StudentInfo comp2)
{
    return comp1.showId() > comp2.showId();
}