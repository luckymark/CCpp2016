#include "Boss.hpp"

Boss::Boss(int m_rand, float speedy) :Flying(m_rand % 434 + 83, -124, 0, 1, 83, 124, 83)
{
	times = 100;
	setAcceleration(0, -0.0018);
}

Boss::~Boss()
{
}

sf::Time Boss::gettimeNow()
{
	return clock.getElapsedTime();
}

void Boss::countdown(Load & load)
{
	if (clock.getElapsedTime() - getCountdown() <= sf::seconds(0.25))
	{
		this->setTexture(load.boss2);
	}
	if (clock.getElapsedTime() - getCountdown() > sf::seconds(0.25) && clock.getElapsedTime() - getCountdown() <= sf::seconds(0.50))
	{
		this->setTexture(load.boss3);
	}
	if (clock.getElapsedTime() - getCountdown() > sf::seconds(0.50) && clock.getElapsedTime() - getCountdown() <= sf::seconds(0.75))
	{
		this->setTexture(load.boss4);
	}
}

void Boss::shoot(Enemyshoot * enemyshoot[], int i, sf::Sound &sound, float multiple1)
{
	if (this != NULL && this->gettimeNow() % sf::seconds(2 * multiple1) < sf::seconds(0.01))
	{
		sound.play();

		float shootspeed = 3;
		for (size_t j = 0; j < i; j++)
		{
			if (enemyshoot[j] == NULL)
			{
				enemyshoot[j] = new Enemyshoot(getX(), getY(), shootspeed*sin(-0.4), shootspeed*cos(-0.4));
				break;
			}
		}
		for (size_t j = 0; j < i; j++)
		{
			if (enemyshoot[j] == NULL)
			{
				enemyshoot[j] = new Enemyshoot(getX(), getY(), shootspeed*sin(-0.2), shootspeed*cos(-0.2));
				break;
			}
		}
		for (size_t j = 0; j < i; j++)
		{
			if (enemyshoot[j] == NULL)
			{
				enemyshoot[j] = new Enemyshoot(getX(), getY(), shootspeed*sin(0), shootspeed*cos(0));
				break;
			}
		}
		for (size_t j = 0; j < i; j++)
		{
			if (enemyshoot[j] == NULL)
			{
				enemyshoot[j] = new Enemyshoot(getX(), getY(), shootspeed*sin(0.2), shootspeed*cos(0.2));
				break;
			}
		}
		for (size_t j = 0; j < i; j++)
		{
			if (enemyshoot[j] == NULL)
			{
				enemyshoot[j] = new Enemyshoot(getX(), getY(), shootspeed*sin(0.4), shootspeed*cos(0.4));
				break;
			}
		}

	}
}
