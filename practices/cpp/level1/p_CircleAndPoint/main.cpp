#include<iostream>
#include"Circle.h"

using namespace std;

int main()
{
	Circle circle(3, 4, 5);

	circle.getcenter().getPosition();
	circle.getrarius();

	circle.changerarius(5);
	circle.getcenter().movePosition(3, 4);

	circle.getcenter().getPosition();
	circle.getrarius();

	system("pause");

	return 0;
}