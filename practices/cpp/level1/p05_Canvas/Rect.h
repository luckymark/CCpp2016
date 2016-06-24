#pragma once

#include"Shape.h"

class Rect :public Shape
{
public:
	Rect(float x, float y, float width, float height);
	~Rect();
	virtual void setshape(float width, float height);
	virtual void getshape();

private:
	float width;
	float height;
};

Rect::Rect(float x,float y, float width, float height)
{
	setname("rect");
	setposition(x, y);
	setshape(width, height);
}

Rect::~Rect()
{
}

inline void Rect::setshape(float width, float height)
{
	Rect::width = width;
	Rect::height = height;
}

inline void Rect::getshape()
{
	std::cout << "width = " << width << std::endl << "height = " << height << std::endl;
}
