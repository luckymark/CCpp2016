#ifndef CANVAS_H
#define CANVAS_H


#include "Shape.h"

class Canvas
{
    public:
        Canvas(){};
        void append(Shape* shape){
            shapes[count++]=shape;
        };
        int totalArea(){
            int area=0;
            for(int i=0;i<count;i++){
                area+=shapes[i]->getArea();
            }
            return area;
        };
    protected:
    private:
        Shape* shapes[100];
        int count=0;
};

#endif // CANVAS_H
