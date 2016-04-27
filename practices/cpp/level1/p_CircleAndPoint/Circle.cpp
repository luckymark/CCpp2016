#include "Circle.h"
#ifdef DEBUG
#include <iostream>
#endif
void Circle::move(int deltaX, int deltaY)
{
  center.move(deltaX, deltaY, BY_HUMAN);
}
#ifdef DEBUG
void Circle::printStatus()
{
  center.printStatus();
  border.printStatus();
}
#endif
