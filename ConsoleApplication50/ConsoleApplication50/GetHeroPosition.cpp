#include "stdafx.h"
#include "GetHeroPosition.h"

void getposition(Hero * hero)
{
	GetHeroPosition::ff =hero->getPosition();
}
/*
sf::Vector2f Gun::getPosition() {
	sf::Vector2f ff;
	return ff;//不做任何操作？
}*/
