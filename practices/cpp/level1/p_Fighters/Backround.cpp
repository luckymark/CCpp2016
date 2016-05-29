#include "Backround.h"

Backround::Backround()
{
	if (!backround.loadFromFile("D:\\ÐÇ¿Õ.jpg"))
		exit(0);

}

void Backround::inibackround()
{
	sbackround.setTexture(backround);
	sbackround.setScale(sf::Vector2f(2.f, 2.f));
	sbackround.setPosition(sf::Vector2f(0, 0));
}
