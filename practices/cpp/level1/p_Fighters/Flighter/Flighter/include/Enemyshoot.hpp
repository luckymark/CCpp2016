#pragma once

#include"Flying.hpp"

class Enemyshoot:public Flying
{
public:
	Enemyshoot(float x, float y, float speedx, float speedy);
	~Enemyshoot();
	int times;
	sf::Time gettimeNow();
private:

};
