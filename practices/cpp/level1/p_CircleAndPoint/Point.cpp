#include "headers/Point.hpp"

Point::Point(int x, int y) : m_x(x), m_y(y) {}

void Point::move(int x, int y) {
    m_x += x;
    m_y += y;
}
