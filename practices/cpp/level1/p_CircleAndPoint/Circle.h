#pragma once

#include"Point.h"

class Circle
{
public:
	Circle(float x, float y, float r);
	~Circle();
	Point &getcenter();
	float getrarius();
	void setrarius(float r);
	void changerarius(float upr);
private:
	Point center;
	float r;
};

Circle::Circle(float x, float y, float r) :center(x, y)
{
	Circle::r = r;
}

Circle::~Circle()
{
}

inline Point &Circle::getcenter()
{
	return center;
}

inline float Circle::getrarius()
{
	std::cout << "r = " << r << std::endl;
	return r;
}

inline void Circle::setrarius(float r)
{
	Circle::r = r;
}

inline void Circle::changerarius(float upr)
{
	r += upr;
}
