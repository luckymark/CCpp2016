#pragma once
#include <SFML\Graphics.hpp>

#include <vector>
#include <functional>

#include "ResourceHolder.hpp"
#include "ResourceIdentifies.hpp"

class Aircraft;

struct Direction {
	Direction(float angle, float distance);
	float angle;
	float distance;
};

struct AircraftData {
	int hitpoints;
	float speed;
	Textures::ID texture;
	sf::Time fireInterval;
	std::vector<Direction> directions;
};

struct ProjectileData {
	float speed;
	int damage;
	Textures::ID textureID;
};

struct PickupData {
	std::function<void(Aircraft&)> action;
	Textures::ID textureID;
};
std::vector<AircraftData> initializeAircraftData();
std::vector<ProjectileData> initializeProjectileData();
std::vector<PickupData> initializePickupData();