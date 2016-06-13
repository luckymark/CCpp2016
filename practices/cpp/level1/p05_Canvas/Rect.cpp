#include "Rect.h"
#include <cstdio>
Rect::Rect(std::pair<double, double> point, double width, double height):Shape(point) {
    this->width = width;
    this->height = height;
}
void Rect::draw() {
    printf("Rect: top right corner:%f %f width:%f height: %f\n", keyPoint.first, keyPoint.second, width, height);
}
