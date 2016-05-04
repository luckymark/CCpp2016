#include "RectFactory.h"
#include <iostream>

Shape *RectFactory::createShape()
{
  int x, y, rectLength, rectWidth;
  	std::cout << "Location X:";
  	std::cin >> x;
  	std::cout << "Location Y:";
  	std::cin >> y;
  	std::cout << "length :";
  	std::cin >> rectLength;
  	std::cout << "width :";
  	std::cin >> rectWidth;
  	return new Rect(x, y, rectLength, rectWidth);
}
