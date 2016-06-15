#include "Circle.h"
#include "Point.h"
#include<iostream>
using namespace std;
Circle::Circle(Point CircleCentre,int radius) : centre(CircleCentre)
{

    this->radius=radius;
}
void Circle::ShowRadius()
{
    cout<<radius<<endl;
}
Circle::~Circle()
{
    //dtor
}
