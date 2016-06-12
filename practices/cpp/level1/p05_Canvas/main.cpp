#include <iostream>
#include<Shape.h>
#include<Canva.h>
#include<Circle.h>
#include<Rect.h>
using namespace std;

int main()
{
    Canva canva;
    Circle circle1(1,1,1);
    Circle circle2(7,8,9);
    Rect rect1(2,3,4,5);
    canva.draw(circle1);
    canva.draw(circle2);
    canva.draw(rect1);
    canva.showAllShape();
    return 0;
}
