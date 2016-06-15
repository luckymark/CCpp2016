#pragma once
#include <SFML\Graphics.hpp>

#include <vector>
#include <cassert>

#include "Entity.hpp"
#include "ResourceHolder.hpp"
#include "ResourceIdentifies.hpp"
#include "Stringhelper.hpp"
#include "DataTables.hpp"


class Projectile :public Entity {
public:
	enum Type {
		AlliedBullet,
		EnemyBullet,
		Missile,
		TypeCount,
	};
public:
	Projectile(Type type, const TextureHolder &textures);
	void guideTowards(sf::Vector2f position);
	bool isGuided() const;

	float getMaxSpeed() const;
	int getDamage() const;
	virtual unsigned int getCategory() const;
	virtual sf::FloatRect getBoundingRect() const;

private:
	virtual void drawCurrent(sf::RenderTarget &target, sf::RenderStates status) const;
	virtual void updateCurrent(sf::Time dt,CommandQueue &commands);

private:
	Type mType;
	sf::Sprite mSprite;
	sf::Vector2f mTargetDirection;

};