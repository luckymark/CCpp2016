#include "Backround.h"

Backround::Backround()
{
	if (!backround.loadFromFile("D:\\�ǿ�.jpg"))
		exit(0);

}

void Backround::inibackround()
{
	sbackround.setTexture(backround);
	sbackround.setScale(sf::Vector2f(2.f, 2.f));
	sbackround.setPosition(sf::Vector2f(0, 0));
}

void Backround::drawBeginBackround()
{
	backround.loadFromFile("D://����ͼƬ.jpg");
	sbackround.setTexture(backround);
	sbackround.setScale(sf::Vector2f(1.f, 1.f));
	sbackround.setPosition(sf::Vector2f(0, 0));
}
