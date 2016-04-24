//
// Created by Administrator on 2016/4/21.
//
#include <iostream>
#include "shape.h"

using namespace std;

int main() {
    Shape *shapes[100];
    shapes[0] = new Circle(0, 0, 10);
    float totalArea = 0;
    totalArea += Shapes -> area();
    cout << totalArea;

    return 0;
}