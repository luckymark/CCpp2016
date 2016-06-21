#include "Boss.hpp"

Boss::Boss(int m_rand) :Flying(m_rand % 434 + 83, -124, 0, 1, 83, 124, 83)
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

void Boss::shoot(Enemyshoot * enemyshoot[], int i)
{
	if (this != NULL && this->gettimeNow() % sf::seconds(2) < sf::seconds(0.01))
	{
		float shootspeed = 3;
		for (size_t j = 0; j < i; j++)
		{
			if (enemyshoot[j] == NULL)
			{
				enemyshoot[j] = new Enemyshoot(getX(), getY(), shootspeed*sin(-0.28), shootspeed*cos(-0.28));
				break;
			}
		}
		for (size_t j = 0; j < i; j++)
		{
			if (enemyshoot[j] == NULL)
			{
				enemyshoot[j] = new Enemyshoot(getX(), getY(), shootspeed*sin(-0.14), shootspeed*cos(-0.14));
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
				enemyshoot[j] = new Enemyshoot(getX(), getY(), shootspeed*sin(0.14), shootspeed*cos(0.14));
				break;
			}
		}
		for (size_t j = 0; j < i; j++)
		{
			if (enemyshoot[j] == NULL)
			{
				enemyshoot[j] = new Enemyshoot(getX(), getY(), shootspeed*sin(0.28), shootspeed*cos(0.28));
				break;
			}
		}

	}
}
