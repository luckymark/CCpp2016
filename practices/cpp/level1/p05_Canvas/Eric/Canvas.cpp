#include "Canvas.h"
Canvas::~Canvas()
{
	for(auto it = shape.begin(); it != shape.end(); it++)
	{
		delete *it;
	}
}
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
	auto temp = new Circle(x, y, circleR);
	shape.push_back(temp);
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
	auto temp = new Rect(x, y, length, width);
	shape.push_back(temp);
	return 0;
}
void Canvas::printCanvas()
{
	for(auto it = shape.begin(); it != shape.end(); it++)
	{
		(*it)->print();
	}
	std::cout << "===END===" << std::endl;
}
void Canvas::clearCanvas()
{
	for(auto it = shape.begin(); it != shape.end(); it++)
	{
		delete *it;
	}
	shape.clear();
}