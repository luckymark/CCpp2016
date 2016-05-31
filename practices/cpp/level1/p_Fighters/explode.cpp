#include "explode.h"

Explode::Explode(Enemy & enemy)
{
	this->enemy = new Enemy(enemy);
	this->enemy->setx(this->enemy->getx() - 70);
	this->enemy->sety(this->enemy->gety() - 30);
	if (!tExplode.loadFromFile("D:\\±¬Õ¨(ÎÞ±³¾°).png"))
		exit(0);
	process = 0;
}

Explode::~Explode()
{
	delete enemy;
}

void Explode::drawExplode()
{
	sExplode.setTexture(tExplode);
	sExplode.setScale(sf::Vector2f(.2f, .2f));
	sExplode.setPosition(sf::Vector2f(enemy->getx(), enemy->gety()));
}

void Explode::carry_out()
{
	process++;
}

int Explode::getProcess()
{
	return process;
}
