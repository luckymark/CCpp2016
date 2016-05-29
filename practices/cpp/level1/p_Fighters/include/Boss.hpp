#pragma once

#include"Flying.hpp"
#include"Enemyshoot.hpp"
#include"SFML\Audio.hpp"
#include"Load.hpp"

class Boss:public Flying
{
public:
	Boss(int m_rand, float speedy);
	~Boss();
	int times;
	void shoot(Enemyshoot * enemyshoot[], int i,sf::Sound &sound);
	sf::Time gettimeNow();
	void countdown(Load &load);

private:
	sf::Clock clock;
};
