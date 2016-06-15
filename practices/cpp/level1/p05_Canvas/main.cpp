#include <iostream>

using namespace std;
#include "Circle.h"
#include "Rect.h"
#include "Canvas.h"
int main()
{
    Canvas canvas;

    Circle c1(10,20,5);
    Circle c2(20,30,10);

    Rect r1(10,20,5,3);

    canvas.append(&c1);
    canvas.append(&r1);
    canvas.append(&c2);

    cout<<canvas.totalArea()<<endl;
    return 0;
}
