#pragma once

#include"Flying.hpp"
#include"Enemyshoot.hpp"

class Enemy:public Flying
{
public:
	Enemy(int m_rand);
	~Enemy();
	sf::Time gettimeNow();
	int times;
	void shoot(Enemyshoot *enemyshoot[], int i,float x,float y);

private:
	sf::Clock clock;
};
