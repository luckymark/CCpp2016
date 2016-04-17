#include <iostream>
#include <cstdio>
#include <cmath>
#include "Point.h"
#include "Rectangle.h"
#include "Circle.h"
using namespace std;
int main()
{
    Rectangle rec(0,0,4,5);
    printf("area=%d\n",rec.area());
    rec.move(1,2);
    rec.showXY();
    Circle cir(1,1,4);
    printf("area=%g\n",cir.area());
    cir.move(3,4);
    cir.showXY();
    return 0;
}
