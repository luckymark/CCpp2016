#pragma once

#include"Flying.hpp"
#include"Enemyshoot.hpp"
#include"SFML\Audio.hpp"
#include"Load.hpp"

class Enemy:public Flying
{
public:
	Enemy(int m_rand, float speedy);
	~Enemy();
	sf::Time gettimeNow();
	int times;
	void shoot(Enemyshoot *enemyshoot[], int i, float x, float y, sf::Sound &shootSound, float multiple1);
	void countdown(Load &load);

private:
	sf::Clock clock;
};
