#include "Point.h"
#include <cstdio>
void Point::move(int offx,int offy)
{
    x+=offx;
    y+=offy;
}
void Point::showXY()
{
    printf("x=%d y=%d\n",x,y);
}
