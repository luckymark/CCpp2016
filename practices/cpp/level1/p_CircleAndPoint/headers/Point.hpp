#ifndef POINT_HPP
#define POINT_HPP

class Point {
private:
    int m_x;
    int m_y;
public:
    Point(int x, int y);
    void move(int x, int y);
};

#endif
