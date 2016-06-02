#include "Giftplus.hpp"

Giftplus::Giftplus(int m_rand, float speedy) :Flying(m_rand % 544 + 28, -22, 0, speedy, 28, 66, 28)
{
	times = 10;	
	guntype = 0;
}

Giftplus::~Giftplus()
{
}

sf::Time Giftplus::gettimeNow()
{
	return clock.getElapsedTime();
}

int Giftplus::getGuntype()
{
	return guntype;
}
