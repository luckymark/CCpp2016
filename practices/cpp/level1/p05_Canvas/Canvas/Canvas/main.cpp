#include "Point.h"
#include "Canvas.h"
#include "Rectangle.h"
#include "Circle.h"
int main()
{
	Canvas* aCanvas = Canvas::instance();
	aCanvas->addShape(Circle(1, Point(1, 1), 2).clone());
	aCanvas->addShape(Rectangle(2, Point(1, 4), Point(5, -1)).clone());
	aCanvas->addShape(Circle(3, Point(1, 1), 2).clone());
	aCanvas->draw();
	return 0;
}