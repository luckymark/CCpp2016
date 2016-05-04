#ifndef CANVAS_H
#define CANVAS_H
#include <vector>
#include <iostream>
#include "Shape.h"
class Canvas
{
private:
	int canvasLength = 100;
	int canvasWidth = 100;
	std::vector<Shape *> Shapes;
public:
	Canvas() = default;
	Canvas(int length, int width) : canvasLength(length), canvasWidth(width){}
	~Canvas();
	void addShape(Shape *);
	void printCanvas();
	void clearCanvas();
};
#endif
