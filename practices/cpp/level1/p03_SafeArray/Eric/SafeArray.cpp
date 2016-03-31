#include "SafeArray.h"
#include <iostream>

int SafeArray::set(int number, int location)
{
    if(isSafe(location))
    {
        *(array + location) = number;
        return 0;
    }
    else
    {
        std::cout << "ERROR : FLOW." << std::endl;
        return 1;
    }
}
int SafeArray::get(int location)
{
    if(isSafe(location))
    {
        return *(array + location);
    }
    else
    {
        std::cout << "ERROR : FLOW." << std::endl;
        return -1;
    }
}
bool SafeArray::isSafe(int location)
{
    return location > arrayLessLocation && location < arrayMaxLocation;
}