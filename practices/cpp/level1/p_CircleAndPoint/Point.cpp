#include "Point.h"
#include <algorithm>
void Point::move(int deltaX, int deltaY)
{
  coorX += deltaX;
  coorY += deltaY;
}
