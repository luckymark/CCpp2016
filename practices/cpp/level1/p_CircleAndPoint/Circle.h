
#ifndef CIRCLE_H
#define CIRCLE_H
#include "Point.h"

class Circle
{
    public:
        Circle();
        virtual ~Circle();
        Circle(Point center,int r);
        void draw();
        void trans(int x,int y);
        void put_trans(int x,int y);
    protected:
    private:
        Point center;
        Point tran;
        int r;
};

#endif // CIRCLE_H

