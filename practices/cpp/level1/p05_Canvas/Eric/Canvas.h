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
	std::vector<Rect> rect;
	std::vector<Circle> circle;
public:
	Canvas() = default;
	Canvas(int length, int width) : canvasLength(length), canvasWidth(width){}
	bool creatCircle();
	bool creatCircle(int x, int y, int circleR);
	bool creatRect();
	bool creatRect(int x, int y, int length, int width);
	void printCanvas();
	void clearCanvas();
};
bool Canvas::creatCircle()
{
	int x, y, radius;
	std::cout << "Location X:";
	std::cin >> x;
	std::cout << "Location Y:";
	std::cin >> y;
	std::cout << "Radius:";
	std::cin >> radius;
	return creatCircle(x, y, radius);
}
bool Canvas::creatCircle(int x, int y, int circleR)
{
	Circle tempCircle(x, y, circleR);
	circle.push_back(tempCircle);
	return 0;
}
bool Canvas::creatRect()
{
	int x, y, rectLength, rectWidth;
	std::cout << "Location X:";
	std::cin >> x;
	std::cout << "Location Y:";
	std::cin >> y;
	std::cout << "length :";
	std::cin >> rectLength;
	std::cout << "width :";
	std::cin >> rectWidth;
	return creatRect(x, y, rectLength, rectWidth);
}
bool Canvas::creatRect(int x, int y, int length, int width)
{
	Rect tempRect(x, y, length, width);
	rect.push_back(tempRect);
	return 0;
}
void Canvas::printCanvas()
{
	for(auto it = rect.begin(); it != rect.end(); it++)
	{
		it->print();
	}
	for(auto it = circle.begin(); it != circle.end(); it++)
	{
		it->print();
	}
	std::cout << "===END===" << std::endl;
}
void Canvas::clearCanvas()
{
	rect.clear();
	circle.clear();
}
#endif