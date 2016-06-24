#ifndef CANVAS_HPP__
#define CANVAS_HPP__

#include <vector>
#include "Drawable.hpp"

class Canvas {
private:
    std::vector<Drawable *> m_shapes;
public:
    void add(Drawable *shape);
    void draw_all();
};

#endif
