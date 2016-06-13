#include "Canva.h"

void Canva::show() {
    for (auto &i:allShape) {
        i->draw();
    }
}
void Canva::draw(Shape *shape) {
    allShape.push_back(shape);
}
Canva::~Canva() {
    for (auto &i:allShape) {
        delete i;
        i = NULL;
    }
    allShape.clear();
}
