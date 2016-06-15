#ifndef RECT_H
#define RECT_H


#include "Shape.h"

class Rect:public Shape
{
    public:
        Rect(int x,int y,int wide,int height):x(x),y(y),wide(wide),height(height){
            type=1;
        };
        int getArea(){
            return wide*height;
        }
    protected:
    private:
        int x,y,wide,height;
};

#endif // RECT_H
