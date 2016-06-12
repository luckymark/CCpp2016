#pragma once

#include<iostream>

class Point
{
public:
	Point(float x, float y);
	~Point();
	void setPosition(float x, float y);
	void movePosition(float upx, float upy);
	void getPosition();

private:
	float x;
	float y;
};

Point::Point(float x, float y)
{
	setPosition(x, y);
}

Point::~Point()
{
}

inline void Point::setPosition(float x, float y)
{
	Point::x = x;
	Point::y = y;
}

inline void Point::movePosition(float upx, float upy)
{
	x += upx;
	y += upy;
}

inline void Point::getPosition()
{
	std::cout << "( " << x << " , " << y << " )" << std::endl;
}
