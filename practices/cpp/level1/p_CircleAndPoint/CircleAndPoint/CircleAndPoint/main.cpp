#include "Point.h"
#include "Circle.h"
int main()
{
	Circle cir(Point(0, 0), 1);
	cir.draw();
	cir.move(2, 3);
	cir.draw();
	return 0;
}