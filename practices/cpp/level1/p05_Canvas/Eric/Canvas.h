#ifndef CANVAS_H
#define CANVAS_H
#include <vector>
#include <iostream>
#include "Rect.h"
#include "Circle.h"
class Canvas
{
private:
	int canvasLength = 100;
	int canvasWidth = 100;
	std::vector<Shape *> shape;
public:
	Canvas() = default;
	Canvas(int length, int width) : canvasLength(length), canvasWidth(width){}
	~Canvas();
	bool creatCircle();
	bool creatCircle(int x, int y, int circleR);
	bool creatRect();
	bool creatRect(int x, int y, int length, int width);
	void printCanvas();
	void clearCanvas();
};
#endif