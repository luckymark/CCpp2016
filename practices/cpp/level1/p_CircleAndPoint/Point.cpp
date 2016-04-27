#include "Point.h"
#include <algorithm>
void Point::move(int deltaX, int deltaY, bool isCenter)
{
  coorX += deltaX;
  coorY += deltaY;
  if(isCenter == BY_HUMAN)
  {
    for(auto it = childPoint.begin(); it != childPoint.end(); it++)
    {
      (*it)->move(deltaX, deltaY);
    }
  }
}
void Point::bind(Point *target)
{
  if(childPoint.end() == std::find_if(childPoint.begin(), childPoint.end(), [target](auto source){return source == target;}))
  {
    //bind the target-point
    childPoint.push_back(target);
    //bind self to target-point
    target->bind(this);
    //bind target to all point
    for(auto it = childPoint.begin(); it != childPoint.end(); ++it)
    {
      if(*it != target)
      {
        (*it)->bind(target);
      }
    }
  }
}
Point *Point::toBind()
{
  return this;
}
