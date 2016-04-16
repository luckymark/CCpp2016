#ifndef CIRCLE_H
#define CIRCEL_H
#include <iostream>
#include "Shape.h"
class Circle : public Shape
{
public:
	Circle() = default;
	Circle(int sourceX, int sourceY, int sourceR) : 
		Shape(sourceX, sourceY), radius(sourceR){}
	void print() const override;
private:
	int radius;
};
void Circle::print() const
{
	std::cout << "Circle " << locationX << "," << locationY << " R = " << radius << std::endl;
}
#endif