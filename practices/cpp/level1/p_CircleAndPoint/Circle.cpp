#include "Circle.h"
#ifdef DEBUG
#include <iostream>
#endif
void Circle::move(int deltaX, int deltaY)
{
  center.move(deltaX, deltaY);
}
#ifdef DEBUG
void Circle::printStatus()
{
  center.printStatus();
}
#endif
