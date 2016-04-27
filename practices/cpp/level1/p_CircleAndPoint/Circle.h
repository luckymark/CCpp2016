#ifndef CIRCLE_H
#define CIRCLE_H
#include "Point.h"
class Circle
{
private:
  Point center;
  //a point on border
  Point border;
public:
  Circle(int x, int y, int r) : center(x, y), border(x, y + r)
  {
    center.bind(border.toBind());
  };
  void move(int deltaX, int deltaY);
#ifdef DEBUG
  void printStatus();
#endif
};
#endif
