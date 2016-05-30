#pragma once
#include<SFML\Graphics.hpp>
#include"Enemy.h"
class Explode
{
	int process;
	Enemy *enemy;
public:
	Explode(Enemy &enemy);
	sf::Texture tExplode;
	sf::Sprite sExplode;
	~Explode();
	void drawExplode();
	void carry_out();
	int getProcess();

};