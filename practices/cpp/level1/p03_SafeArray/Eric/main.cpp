//p03_SafeArray
//author : Eric

#include <iostream>
#include "SafeArray.h"

int main()
{
    SafeArray safeArray(100);
    safeArray.set(1, 0);
    safeArray.set(2, 100);
    std::cout << "The loc.1 " << safeArray.get(1) << std::endl;
    std::cout << "The loc.100(wrong)" << safeArray.get(100) << std::endl;
    
    return 0;
}