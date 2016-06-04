#include"circuit.h"
#include<iostream>
using namespace std;
int main()
{
	Button *button;
	Fan fan;
	Door door;
	Light light;
	button = &fan;
	button->on();
	button->off();
	button = &door;
	button->on();
	button->off();
	button = &light;
	button->on();
	button->off();
}