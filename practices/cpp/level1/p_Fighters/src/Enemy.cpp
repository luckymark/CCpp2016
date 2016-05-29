#include "Enemy.hpp"

Enemy::Enemy(int m_rand, float speedy) :Flying(m_rand % 530 + 35, -43, 0, 1.5, 35, 43, 37)
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

void Enemy::shoot(Enemyshoot * enemyshoot[], int i,float x,float y, sf::Sound &shootSound)
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
				shootSound.play();
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

void Enemy::countdown(Load &load)
{
	if (clock.getElapsedTime() - getCountdown() <= sf::seconds(0.25))
	{
		this->setTexture(load.enemy2);
	}
	if (clock.getElapsedTime() - getCountdown() > sf::seconds(0.25) && clock.getElapsedTime() - getCountdown() <= sf::seconds(0.50))
	{
		this->setTexture(load.enemy3);
	}
	if (clock.getElapsedTime() - getCountdown() > sf::seconds(0.50) && clock.getElapsedTime() - getCountdown() <= sf::seconds(0.75))
	{
		this->setTexture(load.enemy4);
	}
}
