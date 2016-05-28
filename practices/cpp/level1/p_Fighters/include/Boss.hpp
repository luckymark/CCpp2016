#pragma once

#include"Flying.hpp"
#include"Enemyshoot.hpp"

class Boss:public Flying
{
public:
	Boss(int m_rand);
	~Boss();
	int times;
	void shoot(Enemyshoot * enemyshoot[], int i);
	sf::Time gettimeNow();

private:
	sf::Clock clock;
};
