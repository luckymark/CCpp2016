#include "Aircraft.hpp"
#include "Utility.hpp"
#include "Category.hpp"
#include "SceneNode.hpp"
#include "Pickup.hpp"

#include <cmath>
#include <memory>
#include <iostream>

namespace {
	const std::vector<AircraftData> Table = initializeAircraftData();
}

Textures::ID toTextureID(Aircraft::Type type)
{
	switch (type) {
		case Aircraft::Type::Mycraft:
			return Textures::tMyAircraft;
		case Aircraft::Type::Raptor:
			return Textures::tAirplane;
	}
	return Textures::tAirplane;
}
Aircraft::Aircraft(Type type, const TextureHolder &textures, const FontHolder &fonts) :Entity(Table[type].hitpoints), mType(type), mSprite(textures.get(Table[type].texture))
{
	setCenterOrigin(mSprite);

	mFireCommand.category = Category::Scene;
	mFireCommand.action = [this, &textures](SceneNode &node, sf::Time) {
		creatBullet(node, textures);
	};

	mMissileCommand.category = Category::Scene;
	mMissileCommand.action = [this, &textures](SceneNode &node, sf::Time) {
		creatProjectile(node, Projectile::Missile, 0.f, 0.5f, textures);
	};

	mDropPickupCommand.category = Category::Scene;
	mDropPickupCommand.action = [this, &textures](SceneNode &node, sf::Time) {
		creatPickup(node, textures);
	};

	std::unique_ptr<TextNode> healthyDisplay(new TextNode(fonts, "init text"));
	mHealthDisplay = healthyDisplay.get();
	attachChild(std::move(healthyDisplay));

	mSpriteLevel = 1; //Default Spread level
	mFireRateLevel = 1; //Default Fire Rate Level
	mIsMarkedForRemoval = false;
	mIsFiring = false;
	mIsLauchingMissile = false;

	mMissionAmmo = 5;
	
	updateTexts();
}

void Aircraft::drawCurrent(sf::RenderTarget & target, sf::RenderStates status) const
{
	target.draw(mSprite, status);
}

void Aircraft::updateCurrent(sf::Time dt,CommandQueue &commands)
{
	if (isDestoryed()) {
		checkPickupDrop(commands);
		mIsMarkedForRemoval = true;
		
	}
	checkProjectileLaunch(dt,commands); //发射子弹
	updateMovementPattern(dt); //改变移动
	Entity::updateCurrent(dt,commands);
	updateTexts();//更新文本信息
}

unsigned int Aircraft::getCategory() const
{
	if (mType == Mycraft)
		return Category::PlayerAircraft;
	else
		return Category::EnemyAircraft;
}

float Aircraft::getMaxSpeed() const
{
	return Table[mType].speed;
}

void Aircraft::updateTexts()
{
	mHealthDisplay->setString(toString(getHitpoints()) + "HP");
	mHealthDisplay->setPosition(0.f, 50.f);
	mHealthDisplay->setRotation(-getRotation());
	

}

void Aircraft::updateMovementPattern(sf::Time dt)
{
	const std::vector<Direction> &directions = Table[mType].directions;
	if (!directions.empty()) {
		float distanceToTravel = directions[mDirectionIndex].distance;
		if (mTravelledDistance > distanceToTravel) {
			mDirectionIndex = (mDirectionIndex + 1) % directions.size();
			mTravelledDistance = 0.f;
		}
		float radians = toRadian(directions[mDirectionIndex].angle + 90.f);
		float vx = getMaxSpeed() * std::cos(radians);
		float vy = getMaxSpeed() * std::sin(radians);
		setVelocity(vx, vy);
		mTravelledDistance += getMaxSpeed() * dt.asSeconds();
	}
}

void Aircraft::increaseFireRate()
{
	if (mFireRateLevel <= 3)
		++mFireRateLevel;
}

void Aircraft::increaseSpread()
{
	if (mSpriteLevel <= 3)
		++mSpriteLevel;
}

void Aircraft::collectMissile(unsigned int number)
{
	mMissionAmmo += number;
}

sf::FloatRect Aircraft::getBoundingRect() const
{
	return getWorldTransform().transformRect(mSprite.getGlobalBounds());
}



bool Aircraft::isAllied() const
{
	return mType == Mycraft;
}

bool Aircraft::isMarkedForRemoval() const
{
	return mIsMarkedForRemoval;
}

void Aircraft::checkPickupDrop(CommandQueue & commands)
{
	if (!isAllied())
		commands.push(mDropPickupCommand);
}

void Aircraft::creatBullet(SceneNode &node, const TextureHolder &textures)
{
	std::cout << (isAllied()?"Mycraft  ":"Enemy   ") << int((void*)(this))<<" " << "CreatBullet" << std::endl;
	Projectile::Type type = isAllied() ? Projectile::AlliedBullet : Projectile::EnemyBullet;

	switch (mFireRateLevel)
	{
	case 1:
		creatProjectile(node, type, 0.0f, 0.5f, textures);
		break;

	case 2:
		creatProjectile(node, type, -0.33f, 0.33f, textures);
		creatProjectile(node, type, 0.33f, 0.33f, textures);
		break;
	
	case 3:
		creatProjectile(node, type, -0.5f, 0.33f, textures);
		creatProjectile(node, type, 0.f, 0.5f, textures);
		creatProjectile(node, type, 0.5f, 0.33f, textures);
		break;
	default:
		break;
	}
	//TODO
}

void Aircraft::creatPickup(SceneNode & node, const TextureHolder & textures)
{
	auto type = static_cast<Pickup::Type>(rand() % Pickup::TypeCount);

	std::unique_ptr<Pickup> pickup(new Pickup(type, textures));
	pickup->setPosition(getWorldPosition());
	pickup->setVelocity(0.f, 1.f);
	node.attachChild(std::move(pickup));
}

void Aircraft::creatProjectile(SceneNode & node, Projectile::Type type, float xOffset, float yOffset, const TextureHolder & textures)
{
	std::unique_ptr<Projectile> projectile(new Projectile(type, textures));

	sf::Vector2f offset(xOffset * mSprite.getGlobalBounds().width, yOffset * mSprite.getGlobalBounds().height);
	sf::Vector2f velocity(0, projectile->getMaxSpeed());

	float sign = isAllied() ? -1.f : 1.f;
	projectile->setPosition(getWorldPosition() + offset * sign);
	projectile->setVelocity(velocity * sign);
	node.attachChild(std::move(projectile));
}

bool Aircraft::checkProjectileLaunch(sf::Time dt, CommandQueue & commands)
{
	if (!isAllied())
		fire(); //敌机一直发子弹
	if (mIsFiring && mFireCountDown <= sf::Time::Zero) {
		commands.push(mFireCommand);
		mFireCountDown += sf::seconds(1.f / (2 + 1));
		mIsFiring = false;
	}
	else if (mFireCountDown > sf::Time::Zero) {
		mFireCountDown -= dt;
		mIsFiring = false;
	}
	if (mIsLauchingMissile) {
		commands.push(mMissileCommand);
		mIsLauchingMissile = false;
	}
	return false;
}


void Aircraft::fire()
{
	if (Table[mType].fireInterval != sf::Time::Zero) {
		//std::cout << "Test Fire !!!" << std::endl;
		mIsFiring = true; // TODO
	}

}

void Aircraft::launchMissile()
{
	if (mMissionAmmo > 0 && !mIsLauchingMissile) {
		std::cout << "LaunchMissile" << std::endl;
		mIsLauchingMissile = true;
		--mMissionAmmo;
	}
}
