#pragma once
#include<SFML\Graphics.hpp>
#include"Plane.h"
struct Deviation
{
	double x;
	double y;
};
class Boom
{
private:
	Plane plane;
	Deviation deviation;
public:
	Boom();
	Boom(double x, double y);
	Boom(Plane *plane);
	sf::Texture boom;
	sf::Sprite sboom;
	void move();
	double getx();
	double gety();
	bool isBoom();
	void sety();
	void iniBoom(double x);
	void getdeviation(Plane *plane1, Plane *plane2);
	Deviation* getDeviation();
	void changePosition(double x,double y);
	void iniBoom(double x,double y);
	bool BigBoom();
};