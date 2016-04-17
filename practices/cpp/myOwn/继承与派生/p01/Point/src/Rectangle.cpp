#include "Rectangle.h"
#include <cstdio>
int Rectangle::area()
{
    return (x2-x)*(y2-y);
}
void Rectangle::move(int offx,int offy)
{
    x+=offx;
    x2+=offx;
    y+=offy;
    y2+=offy;
}
void Rectangle::showXY()
{
    printf("The leftDown is (%d,%d)\nThe rightUp is (%d,%d)\n",x,y,x2,y2);
}
