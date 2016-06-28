#pragma once
#include "Shape.h"
#include <set>
#include <cstdlib>
class Canvas
{
public:
	static Canvas* instance();
	Canvas* draw();
	Canvas* addShape(Shape*);
	Canvas* deleteShape(int);
protected:
	Canvas();
private:
	std::set<Shape*>allShape;
	static Canvas* _instance;
};

