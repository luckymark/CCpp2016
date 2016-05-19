#pragma once
#include <SFML\Graphics.hpp>
//Mean to control enemy plane
class Enemy
{
public:
	Enemy();
	void show();
	void fly();
	void boom();
private:
	bool alive;
	sf::Vector2f enemy_position;
	sf::Sprite enemy;
};

