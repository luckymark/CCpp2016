#include "Circle.h"
#include "Point.h"
#include <cmath>
#include <cstdio>
const double PI=acos(-1.0);
double Circle::area()
{
    return r*r*PI;
}
void Circle::showXY()
{
    Point::showXY();
    printf("r=%d\n",r);
}
