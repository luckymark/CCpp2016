#include <iostream>
#include "Point.h"
#include "Circle.h"
using namespace std;
int main()
{
    Point centre(10,20);
    Circle circle(centre,5);
    centre.move(30,20);
    centre.ShowXY();
    circle.ShowRadius();
    return 0;
}
