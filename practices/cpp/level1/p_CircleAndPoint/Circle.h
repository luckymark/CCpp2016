#ifndef CIRCLE_H
#define CIRCLE_H
#include<Point.h>

class Circle
{
    public:
        Circle();
        Circle(Point center,int r);
        void moveTo(int x,int y);
        virtual ~Circle();
    protected:
    private:
        Point center;
        int r;
};

#endif // CIRCLE_H
