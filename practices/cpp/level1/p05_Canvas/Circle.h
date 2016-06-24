#pragma once

#include"Shape.h"

class Circle :public Shape
{
public:
	Circle(float x, float y, float rarius);
	~Circle();
	virtual void setshape(float rarius);
	virtual void getshape();//output rarius
private:
	float rarius;
};

Circle::Circle(float x, float y, float rarius)
{
	setname("circle");
	setposition(x, y);
	setshape(rarius);
}

Circle::~Circle()
{
}

inline void Circle::setshape(float rarius)
{
	Circle::rarius = rarius;
}

inline void Circle::getshape()
{
	std::cout << "r = " << rarius << std::endl;
}
