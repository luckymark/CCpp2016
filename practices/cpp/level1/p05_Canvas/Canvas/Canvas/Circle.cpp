#include "Circle.h"



Circle::Circle(int ID,Point center,int radius):center(center),radius(radius)
{
	this->ID = ID;
}

void Circle::draw()
{
	std::cout << "第" << ID << "个图形:\n"
		<< "名称:" << "圆\n"
		<< "圆心:";
	center.draw();
	std::cout << "半径:" << radius;
	std::cout << "\n\n";
}

Shape * Circle::clone()
{
	return new Circle(*this);
}


Circle::~Circle()
{
}
