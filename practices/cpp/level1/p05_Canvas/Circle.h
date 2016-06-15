#ifndef CIRCLE_H
#define CIRCLE_H


#include "Shape.h"

class Circle:public Shape
{
    public:
        Circle(int x,int y,int r):x(x),y(y),r(r){
            type=0;
        };
        int getArea(){
            return 3*r*r;
        }
    protected:
    private:
        int x,y,r;
};

#endif // CIRCLE_H
