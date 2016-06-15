#include "DataTables.hpp"
#include "Aircraft.hpp"
#include "Projectile.hpp"
#include "Pickup.hpp"

std::vector<AircraftData> initializeAircraftData()
{
	std::vector<AircraftData> data(Aircraft::TypeCount);

	data[Aircraft::Mycraft].hitpoints = 1000;
	data[Aircraft::Mycraft].speed = 300.f;
	data[Aircraft::Mycraft].fireInterval = sf::seconds(1.f);
	data[Aircraft::Mycraft].texture = Textures::tMyAircraft;

	data[Aircraft::Raptor].hitpoints = 100;
	data[Aircraft::Raptor].speed = 100.f;
	data[Aircraft::Raptor].fireInterval = sf::seconds(1.f);
	data[Aircraft::Raptor].texture = Textures::tAirplane;
	data[Aircraft::Raptor].directions.push_back(Direction(105.f, 100.f));
	data[Aircraft::Raptor].directions.push_back(Direction(-105.f, 200.f));
	data[Aircraft::Raptor].directions.push_back(Direction(45.f, 120.f));
	data[Aircraft::Raptor].directions.push_back(Direction(-400.f, 300.f));

	return data;
}

std::vector<ProjectileData> initializeProjectileData()
{
	std::vector<ProjectileData> data(Projectile::TypeCount);

	data[Projectile::AlliedBullet].speed = 200.f;
	data[Projectile::AlliedBullet].damage = 20;
	data[Projectile::AlliedBullet].textureID = Textures::tAlliedBullet;

	data[Projectile::EnemyBullet].speed = 300.f;
	data[Projectile::EnemyBullet].damage = 10;
	data[Projectile::EnemyBullet].textureID = Textures::tEnemyBullet;

	data[Projectile::Missile].speed = 150.f;
	data[Projectile::Missile].damage = 100;
	data[Projectile::Missile].textureID = Textures::tMissile;

	return data;
}

std::vector<PickupData> initializePickupData()
{
	std::vector<PickupData> data(Pickup::TypeCount);

	data[Pickup::HealthRefill].textureID = Textures::tHealthRefill;
	data[Pickup::HealthRefill].action = [](Aircraft &node) { node.repair(50); };
	
	data[Pickup::MissileRefill].textureID = Textures::tMissileRefill;
	data[Pickup::MissileRefill].action = std::bind(&Aircraft::collectMissile, std::placeholders::_1, 3);

	data[Pickup::FireRate].textureID = Textures::tFireRate;
	data[Pickup::FireRate].action = std::bind(&Aircraft::increaseFireRate, std::placeholders::_1);

	data[Pickup::FireSpread].textureID = Textures::tFireSpread;
	data[Pickup::FireSpread].action = std::bind(&Aircraft::increaseSpread, std::placeholders::_1);

	return data;
}

Direction::Direction(float angle, float distance) :angle(angle), distance(distance)
{
}
