#include"shape.h"
#include<iostream>
using namespace std;
int main()
{
	shape *p[2];
	p[0] = new Circle(1);
	p[1] = new Rect(3, 4);
	cout << p[0]->area() << endl;
	cout << p[1]->area() << endl;
	
}