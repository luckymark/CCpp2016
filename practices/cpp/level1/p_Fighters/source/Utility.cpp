#include "Utility.hpp"
#include <cassert>

float toDegree(float radian)
{
	return 180.f / 3.141592653589793238462643383f * radian;
}

float toRadian(float degree)
{
	return 3.141592653589793238462643383f / 180.f * degree;
}


float length(sf::Vector2f vector)
{
	return std::sqrt(vector.x * vector.x + vector.y * vector.y);
}

sf::Vector2f toUnitVector(sf::Vector2f Origin) {
	assert(Origin != sf::Vector2f(0.f, 0.f));
	return Origin / sqrt(Origin.x * Origin.x + Origin.y*Origin.y);
}