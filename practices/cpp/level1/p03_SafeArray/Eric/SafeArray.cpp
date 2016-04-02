#include "SafeArray.h"
#include <iostream>

int SafeArray::set(int number, int index)
{
    if(isSafe(index))
    {
        *(array + index) = number;
        return 0;
    }
    else
    {
        std::cout << "ERROR : FLOW." << std::endl;
        return 1;
    }
}
int SafeArray::get(int index)
{
    if(isSafe(index))
    {
        return *(array + index);
    }
    else
    {
        std::cout << "ERROR : FLOW." << std::endl;
        return -1;
    }
}
bool SafeArray::isSafe(int index)
{
    return index > arrayLessIndex && index < arrayMaxIndex;
}