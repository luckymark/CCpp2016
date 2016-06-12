#pragma once

#include<iostream>
#include<string>

class Shape
{
public:
	Shape();
	~Shape();
	void setname(std::string str);
	virtual void setshape() {};
	virtual void getshape() {};
	void setposition(float x, float y);
	std::string getname();
	void getposition();


private:
	std::string name;
	float x;
	float y;

};

Shape::Shape()
{
}

Shape::~Shape()
{
}

inline void Shape::setname(std::string str)
{
	name = str;
}

inline void Shape::setposition(float x, float y)
{
	Shape::x = x;
	Shape::y = y;
}

inline std::string Shape::getname()
{
	std::cout << name << std::endl;
	return name;
}

inline void Shape::getposition()
{
	std::cout << "(" << x << "," << y << ")" << std::endl;
}
