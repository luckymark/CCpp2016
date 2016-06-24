#pragma once

#include"Flying.hpp"

class Giftplus:public Flying
{
public:
	Giftplus(int m_rand, float speedy);
	~Giftplus();
	sf::Time gettimeNow();
	int times;
	int getGuntype();
private:
	sf::Clock clock;
	int guntype;
};
