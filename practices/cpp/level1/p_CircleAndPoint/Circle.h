#ifndef CIRCLE_H
#define CIRCLE_H
#include "Point.h"

class Circle
{
    public:
        Circle(Point CircleCentre,int radius);
        ~Circle();
        void ShowRadius();
    protected:
    private:
        Point centre;
        int radius;
};

#endif // CIRCLE_H
