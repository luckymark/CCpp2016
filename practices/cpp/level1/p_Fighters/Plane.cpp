#include"Plane.h"
#include<conio.h>
Plane::Plane(Plane & plane)
{
	this->x = plane.getx();
	this->y = plane.gety();

}
Plane::~Plane()
{

}


void Plane::move()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		// left key is pressed: move our character
		if(x>0)
			this->x -= PLANESPEED;
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		// left key is pressed: move our character
		if(x<720)
			this->x += PLANESPEED;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		// left key is pressed: move our character
		if(y>0)
			this->y -= PLANESPEED;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		// left key is pressed: move our character
		if(y<720)
			this->y += PLANESPEED;
	}

}

float Plane::getx()
{
	return x;
}

float Plane::gety()
{
	return y;
}

void Plane::drawplane()
{
	shost.setPosition(sf::Vector2f(x, y));
	shost.setTexture(host);
	shost.setScale(sf::Vector2f(0.3f, 0.3f));
}

void Plane::iniPlane()
{
	if (!host.loadFromFile("D://Î¬¾©£¨ÎÞ±³¾°£©.png"))
		exit(0);
}

void Plane::getini()
{
	x = 335;
	y = 607;
}

void Plane::sety(double s)
{
	y = s;
}

void Plane::setx(double s)
{
	x = s;
}

