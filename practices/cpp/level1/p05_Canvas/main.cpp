#include <iostream>
#include "Rect.h"
#include "Circle.h"
#include "Canva.h"
int main() {
    Canva canva;
    Shape *cir = new Circle(std::make_pair(1.0, 1.0));
    canva.draw(cir);
    Shape *rec = new Rect(std::make_pair(2.0, 3.0));
    canva.draw(rec);
    canva.show();
    return 0;
}
