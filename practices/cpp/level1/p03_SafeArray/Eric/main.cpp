//p03_SafeArray
//author : Eric

#include <iostream>
#include "SafeArray.h"

int main()
{
    SafeArray safeArray(100);
    safeArray[0] = 100;
	safeArray[100] = 200;
    std::cout << "The index.1 " << safeArray[0] << std::endl;
    std::cout << "The index.100(wrong)" << safeArray[100] << std::endl;
    return 0;
}