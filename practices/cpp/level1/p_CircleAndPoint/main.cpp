#include "Circle.h"

int main()
{
  Circle circle(1, 1, 1);
#ifdef DEBUG
  circle.printStatus();
#endif
  circle.move(1, 1);
#ifdef DEBUG
  circle.printStatus();
#endif
  return 0;
}
