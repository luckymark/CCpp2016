#include "Circle.hpp"

#include <iostream>

Circle::Circle(Point center, int radius): m_center(center), m_radius(radius) {}

void Circle::draw() {
    std::cout << "center is " << m_center <<
                 "radius is " << m_radius << std::endl;
}
