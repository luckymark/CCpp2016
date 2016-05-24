#ifndef CIRCLE_H
#define CIRCLE_H
#include "Point.h"
class Circle
{
private:
  Point center;
  int radius;
public:
  Circle(int x, int y, int r) : center(x, y), radius(r) {}
  void move(int deltaX, int deltaY);
#ifdef DEBUG
  void printStatus();
#endif
};
#endif
