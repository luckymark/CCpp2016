#include "Myshoot.hpp"

Myshoot::Myshoot(float x, float y, int times) :Flying(x, y, 0, -5, 5, 5, 5)
{
	Myshoot::times = times;
}

Myshoot::~Myshoot()
{
}

sf::Time Myshoot::gettimeNow()
{
	return sf::Time();
}
