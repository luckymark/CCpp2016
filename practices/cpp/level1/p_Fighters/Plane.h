#pragma once
#include<SFML\Graphics.hpp>

#define PLANESPEED 20
class Plane
{
protected:
	double x;
	double y;
	
public:
	sf::Texture host;
	sf::Sprite shost;
	Plane(double x = 0, double y = 0)
	{
		this->x = x;
		this->y = y;
	}
	Plane(Plane  &plane);
	~Plane();
    
	void move();
	float getx();
	float gety();
	void sety(double s);
	void setx(double s);
	void drawplane();
	void iniPlane();
	void getini();
};