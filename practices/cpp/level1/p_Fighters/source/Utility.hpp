#pragma once
#include <SFML\System.hpp>
#include <random>

float toDegree(float radian);

float toRadian(float degree);

float length(sf::Vector2f vector);

sf::Vector2f toUnitVector(sf::Vector2f Origin);