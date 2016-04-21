#ifndef CIRCLE_H
#define CIRCLE_H
#include "Shape.h"
class Circle : public Shape
{
public:
	Circle() = default;
	Circle(int sourceX, int sourceY, int sourceR) : 
		Shape(sourceX, sourceY), radius(sourceR){}
	virtual void print() const override;
private:
	int radius;
};


#endif