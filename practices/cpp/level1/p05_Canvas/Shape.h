#ifndef CANVA_SHAPE_H
#define CANVA_SHAPE_H

#include <iostream>
class Shape {
public:
    virtual void draw() = 0;

    Shape(std::pair<double, double> point);

protected:
    std::pair<double, double> keyPoint;
};


#endif //CANVA_SHAPE_H
