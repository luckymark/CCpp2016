#ifndef CANVA_CIRCLE_H
#define CANVA_CIRCLE_H


#include "Shape.h"

class Circle: public Shape {
private:
    double radius;
public:
    Circle(std::pair<double, double> point, double radius = 10.0);

    void draw();
};


#endif //CANVA_CIRCLE_H
