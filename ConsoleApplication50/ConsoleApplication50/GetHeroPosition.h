#pragma once
#include"Hero.h"
#include<SFML\Graphics.hpp>
class GetHeroPosition
{
public:
	friend void getposition(Hero *hero);
	static sf::Vector2f ff;
};

