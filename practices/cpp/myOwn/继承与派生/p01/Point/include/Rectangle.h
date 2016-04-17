#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Point.h"

class Rectangle:public Point
{
    public:
        Rectangle(int x1,int y1,int x2,int y2):Point(x1,y1)
        {
            this->x2=x2;
            this->y2=y2;
        }
        int area();
        void move(int offx,int offy);
        void showXY();
    protected:

    private:
        int x2,y2;
};

#endif // RECTANGLE_H
