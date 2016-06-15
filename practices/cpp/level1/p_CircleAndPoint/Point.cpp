#include "Point.h"
#include<iostream>
using namespace std;
Point::Point(int X,int Y)
{
    this->X=X;
    this->Y=Y;
}

Point::~Point()
{
    //dtor
}
void Point::move(int offX,int offY)
{
    X+=offX;
    Y+=offY;
}
void Point::ShowXY()
{
    cout<<"("<<X<<","<<Y<<")"<<endl;
}
