#ifndef CIRCLE_H
#define CIRCLE_H
#include "Point.h"
class Circle:public Point
{
    public:
        Circle(int x,int y,int r):Point(x,y)
        {
            this->r=r;
        }
        void showXY();
        double area();
    protected:

    private:
        int r;
};

#endif // CIRCLE_H
