#include "Enemy.hpp"

Enemy::Enemy(int m_rand) :Flying(m_rand % 530 + 35, -43, 0, 1.5, 35, 43, 37)
{
	times = 10;
}

Enemy::~Enemy()
{
}

sf::Time Enemy::gettimeNow()
{
	return clock.getElapsedTime();
}

void Enemy::shoot(Enemyshoot * enemyshoot[], int i,float x,float y)
{
	sf::Time iftime = sf::seconds(3);
	sf::Time maxvalue = sf::seconds(0.01);
	float shootspeed = 3;
	if (y < getY())
	{
		shootspeed = -shootspeed;
	}
	if (this != NULL && this->gettimeNow() % iftime < maxvalue)
	{
		for (size_t j = 0; j < i; j++)
		{
			if (enemyshoot[j] == NULL)
			{
				enemyshoot[j] = new Enemyshoot(getX() - 20, getY(), shootspeed * sin(atan((x - getX() + 10) / (y - getY() + 10))), shootspeed * cos(atan((x - getX() + 10) / (y - getY() + 10))));
				break;
			}
		}
		for (size_t j = 0; j < i; j++)
		{
			if (enemyshoot[j] == NULL)
			{
				enemyshoot[j] = new Enemyshoot(getX() + 20, getY(), shootspeed * sin(atan((x - getX() - 10) / (y - getY() - 10))), shootspeed * cos(atan((x - getX() - 10) / (y - getY() - 10))));
				break;
			}
		}
	}
}
