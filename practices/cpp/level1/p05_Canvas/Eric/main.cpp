#include <iostream>
#include "Canvas.h"
#include "CircleFactory.h"
#include "RectFactory.h"

int main()
{
	Canvas canvas(10000, 10000);
	CircleFactory circleFactory;
	RectFactory rectFactory;
	canvas.addShape(circleFactory.createShape());
	canvas.addShape(rectFactory.createShape());
	canvas.printCanvas();
	canvas.clearCanvas();
	canvas.printCanvas();
	return 0;
}
