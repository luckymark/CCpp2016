#include "Circle.h"
#include <cstdio>
Circle::Circle(std::pair<double, double> point, double radius):Shape(point) {
    this->radius = radius;
}
void Circle::draw() {
    printf("Circle: circle corner:%f %f radius %f\n", keyPoint.first, keyPoint.second, radius);
}
