#ifndef STUDENT_INFO_H
#define STUDENT_INFO_H
#include <string>
class StudentInfo
{
public:
    StudentInfo(unsigned id, std::string name)
    {
        this->id = id;
        this->name = name;
        score = 0;
    }
    unsigned showId()
    {
        return id;
    }
    void setScore(unsigned sourceScore)
    {
        score = sourceScore;
    }
    void printAllInfo();
private:
    unsigned id;
    std::string name;
    unsigned score;
};
#endif