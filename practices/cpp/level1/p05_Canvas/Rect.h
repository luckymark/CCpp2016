#ifndef CANVA_RECT_H
#define CANVA_RECT_H
#include "Shape.h"
#include<iostream>
class Rect: public Shape {
private:
    double width, height;
public:
    Rect(std::pair<double, double> point, double width = 10.0, double height = 10.0);

    void draw();
};


#endif //CANVA_RECT_H
