#include "CircleFactory.h"
#include <iostream>
Shape *CircleFactory::createShape()
{
  int x, y, radius;
  std::cout << "Location X:";
  std::cin >> x;
  std::cout << "Location Y:";
  std::cin >> y;
  std::cout << "Radius:";
  std::cin >> radius;
  return new Circle(x, y ,radius);
}
