#include "Point.h"

Point::Point()
{
    //ctor
}

Point::Point(int x,int y)
{
    this->x = x;
    this->y = y;//ctor
}

Point::~Point()
{
    //dtor
}

void Point::moveTo(int x,int y){
    this->x = x;
    this->y = y;
}
