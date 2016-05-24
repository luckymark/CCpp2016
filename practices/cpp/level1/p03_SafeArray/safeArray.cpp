#include "safeArray.h"
#include <iostream>
using namespace std;
SafeArray::SafeArray(int cap)
{
	data = new int[cap];
	size = cap;
}

int SafeArray::get(int location) {
	if (location > size) {
		std::cout << "outOfSize!!!" << std::endl;
	}
	else {
		return data[location];
	}
}

void SafeArray::set(int location, int num) {
	if (location > size) {
		std::cout << "outOfSize!!!" << std::endl;
		return;
	}
	else {
		data[location] = num;
	}
}