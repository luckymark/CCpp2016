#pragma once
#include <SFML\Graphics.hpp>

#include "Entity.hpp"
#include "ResourceHolder.hpp"
#include "ResourceIdentifies.hpp"

class Aircraft;
class Pickup :public Entity {
public:
	enum Type {
		HealthRefill,
		MissileRefill,
		FireSpread,
		FireRate,
		TypeCount,
	};
public:
	Pickup(Type type, const TextureHolder &textures);
	virtual unsigned int getCategory() const;
	virtual sf::FloatRect getBoundingRect() const;
	void apply(Aircraft& player) const;

protected:
	virtual void drawCurrent(sf::RenderTarget &target, sf::RenderStates status) const;

private:
	sf::Sprite mSprite;
	Type mType;
};