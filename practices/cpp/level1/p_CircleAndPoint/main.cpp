#include <iostream>
#include<Point.h>
#include<Circle.h>
using namespace std;

int main()
{
    Point p(1,1);
    Circle circle(p,3);
    circle.moveTo(4,30);

}
