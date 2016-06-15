#pragma once
#include <SFML\Graphics.hpp>

#include "SceneNode.hpp"
#include "CommandQueue.hpp"

class Entity : public SceneNode{
public:
	explicit Entity(int hitpoints);
	void setVelocity(sf::Vector2f velocity);
	void setVelocity(float vx, float vy);
	void accelerate(sf::Vector2f velocity);
	void accelerate(float vx, float vy);
	sf::Vector2f getVelocity() const;

	void repair(int points);
	void damage(int points);
	void destory();

	int getHitpoints() const;
	virtual bool isDestoryed() const;

protected:
	virtual void updateCurrent(sf::Time dt,CommandQueue &commands);

private:
	sf::Vector2f mVelocity;
	int mHitpoint;
};