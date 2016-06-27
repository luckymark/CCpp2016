#pragma once
#include "Shape.h"
#include "Point.h"
class Rectangle :
	public Shape
{
public:
	Rectangle(int ID,Point LU,Point RD);
	Shape* clone();
	~Rectangle();
	void draw();
private:
	Point LU, RD;
};

