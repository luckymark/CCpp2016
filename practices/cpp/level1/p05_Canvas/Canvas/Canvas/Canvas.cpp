#include "Canvas.h"
#include <iostream>
Canvas* Canvas::_instance = 0;

Canvas * Canvas::instance()
{
	if (_instance == 0)
		_instance = new Canvas;
	return _instance;
}

Canvas * Canvas::draw()
{
	system("cls");
	for (auto aShape : allShape)
		aShape->draw();
	return this;
}

Canvas * Canvas::addShape(Shape* aShape)
{
	allShape.insert(aShape);
	return this;
}

Canvas * Canvas::deleteShape(int ID)
{
	for (auto it = allShape.begin();it != allShape.end();it++)
		if ((*it)->getID() ==ID)
		{
			allShape.erase(it);
			return this;
		}
	return this;
}

Canvas::Canvas()
{
}


