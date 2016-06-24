#pragma once

#include"Flying.hpp"

class Giftgun:public Flying
{
public:
	Giftgun(int m_rand, float speedy);
	~Giftgun();
	sf::Time gettimeNow();
	int times;
	int getGuntype();
private:
	sf::Clock clock;
	int guntype;
};
