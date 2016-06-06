#include<iostream>
#include<string>
#include"Fun.h"
#include"Light.h"

using namespace std;

int main()
{
	Switch swit;
	Fun fun;
	Light light;

	swit.set(1);
	fun.set(1);
	fun.set_speed(5);
	light.set(0);
	light.set_level(3);

	if (swit.get())
	{
		if (fun.get()) cout << "the fun is on." << endl;
		else cout << "the fun is off" << endl;
		if (light.get()) cout << "the light is on." << endl;
		else cout << "the light is off" << endl;
	}
	system("pause");
	return 0;
}