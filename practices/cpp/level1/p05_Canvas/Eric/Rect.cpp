#include "Rect.h"
void Rect::print() const
{
	std::cout << "Rect " << leftTop.getX() << "," << leftTop.getY() << " length : " << length << " width : " << width << std::endl;
}
