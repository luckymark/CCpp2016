#include <string>
#include "scoreManagement.h"
#include "StudentInfo.h"

StudentInfo getNewStudent()
{
    std::string name;
    unsigned id;
    std::cout << "Please input the student-id:";
    std::cin >> id;
    std::cout << std::endl;
    std::cout << "Please input the student's name:";
    std::cin >> name;
    StudentInfo newStudent(id, name);
    return StudentInfo;
}