#include "Circle.h"

Circle::Circle()
{
    //ctor
}

Circle::Circle(Point center,int r)
{
    this->center = center;
    this->r = r;
}

Circle::~Circle()
{
    //dtor
}

void Circle::moveTo(int x,int y){
    center.moveTo(x,y);
}
