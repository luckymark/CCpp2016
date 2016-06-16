#ifndef CIRCLE_HPP__
#define CIRCLE_HPP__

#include "Point.hpp"
#include "Drawable.hpp"

class Circle: public Drawable {
private:
    Point m_center;
    int m_radius;
public:
    Circle(Point center, int radius);
    virtual void draw();
};

#endif
