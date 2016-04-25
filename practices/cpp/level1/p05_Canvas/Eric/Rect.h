#ifndef RECT_H
#define RECT_H
#include <iostream>
#include "Shape.h"
#include "Position.h"
class Rect : public Shape
{
public:
	Rect() = default;
	Rect(int x, int y, int len, int wid) : leftTop(x, y), width(wid), length(len){}
	void print() const ;
private:
	int length = 0;
	int width  = 0;
	Position leftTop;
};
#endif
