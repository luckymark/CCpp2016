#ifndef CIRCLE_H
#define CIRCLE_H

#include <Shape.h>


class Circle : public Shape
{
    public:
        Circle();
        Circle(int x,int y,int r);
        virtual ~Circle();
        int r;
    protected:
    private:

};

#endif // CIRCLE_H
