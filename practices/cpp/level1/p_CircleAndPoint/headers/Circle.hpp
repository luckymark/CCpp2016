#ifndef CIRCLE_HPP__
#define CIRCLE_HPP__

#include "Point.hpp"

class Circle {
private:
    Point m_center;
    int m_radius;
public:
    Circle(Point center, int radius);
};

#endif
