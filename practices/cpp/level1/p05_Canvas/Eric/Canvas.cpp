#include "Canvas.h"
Canvas::~Canvas()
{
	for(auto it = Shapes.begin(); it != Shapes.end(); it++)
	{
		delete *it;
	}
}
void Canvas::addShape(Shape *newShape)
{
	Shapes.push_back(newShape);
}
void Canvas::printCanvas()
{
	for(auto it = Shapes.begin(); it != Shapes.end(); it++)
	{
		(*it)->print();
	}
	std::cout << "===END===" << std::endl;
}
void Canvas::clearCanvas()
{
	for(auto it = Shapes.begin(); it != Shapes.end(); it++)
	{
		delete *it;
	}
	Shapes.clear();
}
