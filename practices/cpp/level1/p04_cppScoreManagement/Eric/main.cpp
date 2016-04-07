//p04_cppScoreManagement
//author : Eric
#include "StudentList.h"

int main()
{
    StudentList newClass;
    newClass.showList();
    newClass.addStudent();
    newClass.showList();
    newClass.inputScore(001, 90);
    newClass.showList();
    newClass.deleteStudent(001);
    newClass.showList();
    
    return 0;
}