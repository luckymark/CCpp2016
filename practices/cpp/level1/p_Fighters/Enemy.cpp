#include "Enemy.h"



Enemy::Enemy(int x, int y) :Plane(x, y)
{
	std::random_device rd;
	int a = rd()%5;
	switch (a)
	{
	case 1:
		if (!host.loadFromFile("D://·ï»Ë(ÎÞ±³¾°).png"))
		{
			exit(0);
		}
		break;
	case 2:
		if (!host.loadFromFile("D://º½Ä¸(ÎÞ±³¾°).png"))
		{
			exit(0);
		}
		break;
	case 3:
		if (!host.loadFromFile("D://Å®Ñý£¨ÎÞ±³¾°£©.png"))
		{
			exit(0);
		}
		break;
	case 4:
		if (!host.loadFromFile("D://Ðé¿Õ»Ô¹â½¢(ÎÞ±³¾°).png"))
		{
			exit(0);
		}
		break;
	case 5:
		if (!host.loadFromFile("D://½â·ÅÕß(ÎÞ±³¾°).png"))
		{
			exit(0);
		}
		break;
	default:
		break;
	}
	
}

Enemy::Enemy(const Enemy & enemy)
{
	this->x = enemy.x;
	this->y = enemy.y;
	this->host = enemy.host;
}

int Enemy::getposition()
{
	std::random_device rd;
	int a = rd();
	return double(abs(a) % 750);
}



void Enemy::move()
{
	y += 0.1;
}
void Enemy::iniEnemy()
{
	shost.setTexture(host);
	shost.setScale(sf::Vector2f(.3f, .3f));
	shost.setPosition(sf::Vector2f(getx(), gety()));
}

int Enemy::isBoom()
{
	std::random_device rd;
	int a = rd() % 4;
	return a;
}

void Enemy::randomMove()
{
	std::random_device rd;
	int a = rd();
	a %= 5;
	switch (a)
	{
	case 1:
		x -= 1;
		break;
	case 4:
		x += 1;
		break;
	default:
		break;
	}
}

