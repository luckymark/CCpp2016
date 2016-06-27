#include "Rectangle.h"



Rectangle::Rectangle(int ID, Point LU, Point RD):LU(LU),RD(RD)
{
	this->ID = ID;
}

Shape * Rectangle::clone()
{
	return new Rectangle(*this);
}


Rectangle::~Rectangle()
{
}

void Rectangle::draw()
{
	std::cout << "第" << ID << "个图形:\n"
		<< "名称:" << "矩形\n"
		<< "左上角:";
	LU.draw();
	std::cout << "右下角:";
	RD.draw();
	std::cout << "\n\n";
}
