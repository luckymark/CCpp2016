#include "Enemyshoot.hpp"

Enemyshoot::Enemyshoot(float x, float y, float speedx, float speedy):Flying(x,y,speedx,speedy,5,5,5)
{
	times = 3;
}

Enemyshoot::~Enemyshoot()
{
}
