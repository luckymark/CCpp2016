#pragma once
#include <iostream>
class Point
{
public:

	Point(int x,int y):x(x),y(y){}
	~Point(){}
	void draw();
	bool operator<(const Point&rhs)const
	{
		return (x < rhs.x) || (x == rhs.x && y < rhs.y);
	}
private:
	int x, y;
};

