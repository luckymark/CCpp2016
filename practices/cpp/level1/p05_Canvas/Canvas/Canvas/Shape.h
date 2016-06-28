#pragma once
#include "Point.h"
class Shape
{
public:
	Shape(){}
	virtual ~Shape(){}
	virtual void draw() = 0;
	virtual Shape* clone()=0;
	int getID()const;
	bool operator<(const Shape&rhs)const
	{
		return ID < rhs.ID;
	}
	bool operator ==(const Shape&rhs)const
	{
		return ID == rhs.ID;
	}
protected:
	int ID;
};

