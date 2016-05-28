#include "Myplane.hpp"

Myplane::Myplane():Flying(315,770,0,0,49,62,49)
{
	setScale(sf::Vector2f(.5f, .5f));//ด๓ะก
	setColor(sf::Color(0, 200, 100, 255));
	movespeed = 0.0056;
	times = 20;
	life = 3;
	invincible = 1;
}

Myplane::~Myplane()
{
}

void Myplane::moveMe()
{
	this->setPosition(getX(), getY());
}

float Myplane::getSpeed()
{
	return movespeed;
}

void Myplane::shoot(Myshoot * myshoot[], int i)
{
	for (size_t j = 0; j < i; j++)
	{
		if (myshoot[j] == NULL)
		{
			myshoot[j] = new Myshoot(getX() - 20, getY());
			break;
		}
	}
	for (size_t j = 0; j < i; j++)
	{
		if (myshoot[j] == NULL)
		{
			myshoot[j] = new Myshoot(getX() + 20, getY());
			break;
		}
	}
}

bool Myplane::getInvincible()
{
	return invincible;
}

void Myplane::beInvincible()
{
	invincible = 1;
}

void Myplane::outofInvincible()
{
	invincible = 0;
}
