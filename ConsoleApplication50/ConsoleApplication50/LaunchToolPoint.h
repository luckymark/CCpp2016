#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>
class Plane;
class LaunchToolPoint
{
public:
	void setOwner(Plane*);
	void launch();
private:
	sf::Vector2f getPosition();
	Plane* owner;
};




