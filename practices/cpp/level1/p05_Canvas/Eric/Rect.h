#ifndef RECT_H
#define RECT_H
#include <iostream>
#include "Shape.h"

class Rect : public Shape
{
public:
	Rect() = default;
	Rect(int x, int y, int len, int wid) : Shape(x, y), width(wid), length(len){}
	void print() const ;
private:
	int length = 0;
	int width  = 0;
};
#endif