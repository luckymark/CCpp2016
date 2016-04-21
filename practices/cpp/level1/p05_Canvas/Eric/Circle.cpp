#include "Circle.h"
#include <iostream>

void Circle::print() const
{
	std::cout << "Circle " << locationX << "," << locationY << " R = " << radius << std::endl;
}