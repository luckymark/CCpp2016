#ifndef CANVA_CANVA_H
#define CANVA_CANVA_H
#include<vector>
#include"Shape.h"
class Canva {
private:
    std::vector<Shape *> allShape;
public:
    ~Canva();

    void show();

    void draw(Shape *shape);

};


#endif //CANVA_CANVA_H
