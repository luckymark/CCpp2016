#include "StudentInfo.h"

bool StudentInfo::inputScore(unsigned score)
{
    if(score > 100)
    {
        return 1;
    }
    StudentInfo::score = score;
    return 0;
}