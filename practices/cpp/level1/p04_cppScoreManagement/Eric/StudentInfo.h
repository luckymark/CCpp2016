#ifndef STUDENT_INFO_H
#define SUTDENT_INFO_H

#include <string>

class StudentInfo
{
private:
    unsigned id;
    std::string name;
    unsigned score;
public:
    SutdentInfo(unsigned id, std::string name) : StudentInfo::id(id), 
        StudentInfo::name(name), score(0){};
    bool inputScore(unsigned score);
}
#endif