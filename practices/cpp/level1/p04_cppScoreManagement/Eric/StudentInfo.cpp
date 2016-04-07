#include <iostream>
#include <string>
#include "StudentInfo.h"

void StudentInfo::printAllInfo()
{
    std::cout << id << " " << name << " " << score << std::endl;
}