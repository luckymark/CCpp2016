#pragma once
class shape
{
private:
public:
	virtual void show() = 0;
	virtual float area() = 0;
};
class Circle :public shape
{
private:
	float r;
public:
	Circle(float r):r(r){}
	void show() {}
	float area() { return 3.14*r*r; };
};
class Rect :public shape
{
private:
	float l, h;
public:
	Rect(int l, int h):l(l),h(h) {}
	void show(){}
	float area() { return l*h; }
};