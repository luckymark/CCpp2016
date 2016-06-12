#include<iostream>
#include<string>
#include"Circle.h"
#include"Point.h"
#include"Rect.h"

using namespace std;

int main()
{
	Circle circle(0, 0, 2);
	Point point(1, 1);
	Rect rect(-2, 2, 4, 4);

	circle.getname();
	circle.getposition();
	circle.getshape();

	point.getname();
	point.getposition();
	point.getshape();

	rect.getname();
	rect.getposition();
	rect.getshape();

	system("pause");

	return 0;
}