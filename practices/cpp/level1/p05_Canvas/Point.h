#pragma once

#include"Shape.h"

class Point :public Shape
{
public:
	Point(float x, float y);
	~Point();
	virtual void setshape();
	virtual void getshape();

private:

};

Point::Point(float x, float y)
{
	setname("point");
	setposition(x, y);
}

Point::~Point()
{
}

inline void Point::setshape()
{
	
}

inline void Point::getshape()
{
	std::cout << "none" << std::endl;
}
