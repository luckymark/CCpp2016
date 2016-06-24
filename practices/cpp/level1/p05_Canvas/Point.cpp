#include "Point.hpp"

Point::Point(int x, int y) : m_x(x), m_y(y) {}

void Point::move(int x, int y) {
    m_x += x;
    m_y += y;
}

std::ostream& operator<<(std::ostream& output, Point& point) {
    std::cout << "(" << point.m_x << ", " << point.m_y << ")" << std::endl;
    return output;
}
