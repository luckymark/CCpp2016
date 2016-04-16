#include <iostream>
#include "Canvas.h"

int main()
{
	Canvas canvas(10000, 10000);
	canvas.creatCircle();
	canvas.creatRect();
	canvas.printCanvas();
	canvas.clearCanvas();
	canvas.printCanvas();
	return 0;
}