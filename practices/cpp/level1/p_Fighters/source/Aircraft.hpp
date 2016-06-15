#pragma once
#include <SFML\Graphics\Sprite.hpp>

#include <memory>

#include "Entity.hpp"
#include "TextNode.hpp"
#include "ResourceHolder.hpp"
#include "ResourceIdentifies.hpp"
#include "DataTables.hpp"
#include "Stringhelper.hpp"
#include "CommandQueue.hpp"
#include "Projectile.hpp"

class Aircraft : public Entity {
public:
	enum Type
	{
		Mycraft,
		Raptor,
		TypeCount,
	};
public:
	explicit Aircraft(Type type,const TextureHolder &textures,const FontHolder &fonts);
	virtual void drawCurrent(sf::RenderTarget &target, sf::RenderStates status) const;
	virtual void updateCurrent(sf::Time dt,CommandQueue &commands);
	virtual unsigned int getCategory() const;

	float getMaxSpeed() const;
	void updateTexts();
	void updateMovementPattern(sf::Time dt);

	void increaseFireRate();
	void increaseSpread();
	void collectMissile(unsigned int number);
	virtual sf::FloatRect getBoundingRect() const;

	bool isAllied() const;
	virtual bool isMarkedForRemoval() const;
	void checkPickupDrop(CommandQueue &commands);

	void creatBullet(SceneNode &node, const TextureHolder &textures);
	void creatPickup(SceneNode &node, const TextureHolder &textures);
	void creatProjectile(SceneNode &node, Projectile::Type type, float xOffset, float yOffset, const TextureHolder &textures);
	bool checkProjectileLaunch(sf::Time dt, CommandQueue &commands);
	
	void fire();
	void launchMissile();
private:
	Type mType;
	sf::Sprite mSprite;

	TextNode *mHealthDisplay;
	size_t mDirectionIndex;
	float mTravelledDistance;

	Command mFireCommand;
	Command mMissileCommand;
	Command mDropPickupCommand;
	bool mIsFiring;
	bool mIsLauchingMissile;
	bool mIsMarkedForRemoval;
	sf::Time mFireCountDown;

	int mFireRateLevel;
	int mSpriteLevel;
	int mMissionAmmo;
};