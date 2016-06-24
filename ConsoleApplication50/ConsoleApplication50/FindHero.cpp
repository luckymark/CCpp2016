#include "stdafx.h"
#include "FindHero.h"
sf::Vector2f FindHero::getposition(Hero * hero)
{
	sf::Vector2f ff;
	ff=hero->getPosition();
	return ff;
}
