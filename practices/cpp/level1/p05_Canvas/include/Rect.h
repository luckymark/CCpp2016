#ifndef RECT_H
#define RECT_H

#include <Shape.h>

class Rect: public Shape
{
    public:
        Rect();
        Rect(int x,int y,int length,int width);
        virtual ~Rect();
        int length=10,width=10;
    protected:
    private:
};

#endif // RECT_H
