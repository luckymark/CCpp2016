#include "Boom.h"

Boom::Boom()
{
	plane.setx(0);
	plane.sety(0);
}

Boom::Boom(double x, double y)
{
	plane.setx(x);
	plane.sety(y);
	if (!boom.loadFromFile("D://graphics-sprites-color(无背景).png", sf::IntRect(0, 0, 130, 130)))
	{
		exit(0);

	}
	boom.setSmooth(true);
	
}

Boom::Boom(Plane *plane):plane(*plane)
{
	if (!boom.loadFromFile("D://graphics-sprites-color(无背景).png", sf::IntRect(0, 0, 130, 130)))
	{
		exit(0);

	}
	boom.setSmooth(true);
}

void Boom::move()
{
	sety();
}

double Boom::getx()
{
	return plane.getx();
}

double Boom::gety()
{
	return plane.gety();
}

bool Boom::isBoom()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		return true;
	return false;
}

void Boom::sety()
{
	plane.sety(plane.gety() - 01);
}

void Boom::iniBoom(double x)
{
	sboom.setTexture(boom);
	sboom.setScale(sf::Vector2f(.1f, .1f));
	sboom.setPosition(sf::Vector2f(x + 25, plane.gety()));
}

void Boom::getdeviation(Plane *plane1, Plane *plane2)
{
	deviation.x = plane1->getx() - plane2->getx();
	deviation.y = plane1->gety() - plane2->gety();
	
}

Deviation * Boom::getDeviation()
{
	return &deviation;
	// TODO: 在此处插入 return 语句
}

void Boom::changePosition(double x, double y)
{
	plane.setx(x);
	plane.sety(y);
	
}

void Boom::iniBoom(double x, double y)
{
	sboom.setTexture(boom);
	sboom.setColor(sf::Color(255, 255, 0));
	sboom.setScale(sf::Vector2f(.1f, .1f));
	sboom.setPosition(sf::Vector2f(x, y));

}

bool Boom::BigBoom()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt)|| sf::Keyboard::isKeyPressed(sf::Keyboard::RAlt))
		return true;
	return false;
}
