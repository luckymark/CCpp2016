#pragma once
class Point
{
protected:
	float x, y;
public:
	Point() {}
	Point(float x,float y):x(x),y(y){}
	Point(const Point &p);
	void setpointx(float x) { this->x = x; }
	void setpointy(float y) { this->y = y; }
};
class Circle :public Point
{
private:
	float r;
public:
	Circle(Point p, float r):Point(p),r(r) {}
	void setr(float xx, float yy);
};