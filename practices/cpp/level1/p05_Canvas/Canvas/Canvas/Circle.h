#pragma once
#include "Shape.h"
#include <iostream>
class Circle :
	public Shape
{
public:
	Circle(int ID,Point center,int radius);
	void draw();
	Shape* clone();
	~Circle();
private:
	Point center;
	int radius;
};

