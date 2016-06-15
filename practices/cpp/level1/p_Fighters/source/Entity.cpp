#include "Entity.hpp"

Entity::Entity(int hitpoints) :mVelocity(), mHitpoint(hitpoints)
{
}

void Entity::setVelocity(sf::Vector2f velocity) 
{
	mVelocity = velocity;
}
void Entity::setVelocity(float vx, float vy) 
{
	mVelocity.x = vx;
	mVelocity.y = vy;
}
void Entity::accelerate(sf::Vector2f velocity) 
{
	mVelocity += velocity;
}
void Entity::accelerate(float vx, float vy)
{
	mVelocity.x += vx;
	mVelocity.y += vy;
}
sf::Vector2f Entity::getVelocity() const 
{
	return mVelocity;
}

void Entity::repair(int points)
{
	assert(points >= 0);
	mHitpoint += points;
}

void Entity::damage(int points)
{
	assert(points >= 0);
	mHitpoint -= points;
}

void Entity::destory()
{
	mHitpoint = 0;
}

int Entity::getHitpoints() const
{
	return mHitpoint;
}

bool Entity::isDestoryed() const
{
	return mHitpoint <= 0;
}

void Entity::updateCurrent(sf::Time dt,CommandQueue &commands)
{
	move(mVelocity * dt.asSeconds());
}
