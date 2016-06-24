#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>

class Point {
private:
    int m_x;
    int m_y;
public:
    Point(int x, int y);
    void move(int x, int y);
    friend std::ostream& operator<<(std::ostream& output, Point& point);
};

#endif
