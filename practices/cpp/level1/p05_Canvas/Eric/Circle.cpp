#include "Circle.h"
#include <iostream>

void Circle::print() const
{
	std::cout << "Circle " << centerPoint.getX() << "," << centerPoint.getY() << " R = " << radius << std::endl;
}
