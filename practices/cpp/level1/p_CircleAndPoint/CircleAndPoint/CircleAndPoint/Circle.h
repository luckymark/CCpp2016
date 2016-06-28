#pragma once
#include <iostream>
#include "Point.h"
class Circle 
{
public:
	Circle(Point center, int radius);
	void move(int x,int y);
	void draw();
	~Circle();
private:
	Point center;
	int radius;
};

