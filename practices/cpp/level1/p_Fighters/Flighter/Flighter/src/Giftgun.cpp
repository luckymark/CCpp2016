#include "Giftgun.hpp"

Giftgun::Giftgun(int m_rand, float speedy):Flying(m_rand % 544 + 28, -22, 0, 1, 28, 72, 28)
{
	times = 0;
	guntype = m_rand % 3 +1;
}

Giftgun::~Giftgun()
{
}

sf::Time Giftgun::gettimeNow()
{
	return clock.getElapsedTime();
}

int Giftgun::getGuntype()
{
	return guntype;
}
