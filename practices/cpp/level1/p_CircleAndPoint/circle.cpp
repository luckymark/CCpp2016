#include "ciecle.h"

void Circle::setr(float xx, float yy)
{
	setpointx(xx);
	setpointy(yy);
}

Point::Point(const Point & p)
{
	this->x = x;
	this->y = y;
}
