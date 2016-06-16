#include "Canvas.hpp"

void Canvas::add(Drawable *shape) {
    m_shapes.push_back(shape);
}

void Canvas::draw_all() {
    for (auto s : m_shapes) {
        s->draw();
    }
}
