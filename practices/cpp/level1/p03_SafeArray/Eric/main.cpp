#include <iostream>
#include "SafeArray.h"

int main()
{
	SafeArray safeArray1(100);
	std::cout << "1[1] = 100    ";
	safeArray1[1] = 100;
	std::cout << safeArray1[1] << std::endl;
	std::cout << "const 2[1] = 100";
	const SafeArray safeArray2(safeArray1);
	std::cout << safeArray2[1] << std::endl;
	
	return 0;
}