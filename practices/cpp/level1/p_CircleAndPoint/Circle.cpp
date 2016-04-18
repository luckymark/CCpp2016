#include "Circle.h"
#include <glut.h>
#include <math.h>
#define PI acos(-1)
Circle::Circle()
{
    tran.x=0;
    tran.y=0;
}
Circle::Circle(Point center,int r)
{
    tran.x=0;
    tran.y=0;
    this->center=center;
    this->r=r;
}
void Circle::draw()
{
    glBegin(GL_LINE_LOOP);
    for(int i=0;i<72;++i)
    {
        glVertex2f(center.x+tran.x+r*cos(2*PI/72*i),center.y+tran.y+r*sin(2*PI/72*i));
    }
    glEnd();
    glFlush();
}
void Circle::trans(int x,int y)
{
    tran.x=x;
    tran.y=y;
}
Circle::~Circle()
{
    //dtor
}
void Circle::put_trans(int x,int y)
{
    center.x+=x;
    center.y+=y;
    tran.x=0;
    tran.y=0;
}
