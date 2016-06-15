#include "World.hpp"
#include "Aircraft.hpp"
#include "Entity.hpp"
#include "Pickup.hpp"

#include <iostream> // for debug
#include <cmath>
#include <limits>
#include <cstdlib>
#include <algorithm>

World::World(sf::RenderWindow & window,FontHolder &fonts) :
	mWindow(window),
	mWorldView(window.getDefaultView()),
	mFonts(fonts),
	mTextures(),
	mScenegraph(),
	mSceneLayers(),
	mWorldBounds(0,0,mWorldView.getSize().x,20000.f),
	mSpawnPosition(mWorldView.getSize().x / 2.f,mWorldBounds.height - mWorldView.getSize().y / 2.f),
	mScrollSpeed(-50.f),
	mPlayerAircraft(nullptr)
{
	loadTexture();
	buildScene();
	srand(0);
	mWindow.setMouseCursorVisible(false);
	mWorldView.setCenter(mSpawnPosition);
}

void World::update(sf::Time dt)
{
	destoryEntitiesOutsideView();

	mWorldView.move(0.f, mScrollSpeed * dt.asSeconds());
	mPlayerAircraft->setVelocity(0.f, 0.f);
	sf::Vector2f position = mPlayerAircraft->getPosition();
	sf::FloatRect viewBounds(mWorldView.getCenter() - mWorldView.getSize() / 2.f, mWorldView.getSize());
	const float borderDistance = 80.f;

	sf::Vector2i windowCenter(mWindow.getSize() / 2u);
	sf::Vector2i mousePosition = sf::Mouse::getPosition(mWindow);
	sf::Vector2i delta = windowCenter - mousePosition;
	position += sf::Vector2f(delta) * -1.f;

	position.x = std::max(position.x, viewBounds.left + borderDistance);
	position.x = std::min(position.x, viewBounds.left + viewBounds.width - borderDistance);
	position.y = std::max(position.y, viewBounds.top + borderDistance);
	position.y = std::min(position.y, viewBounds.top + viewBounds.height - borderDistance);

	mPlayerAircraft->setPosition(position);
	sf::Mouse::setPosition(windowCenter, mWindow);
	
	//debug
	const sf::Time missileDelta = sf::seconds(0.5f);
	static sf::Time pass = sf::Time::Zero;
	pass += dt;
	if (pass > missileDelta) {
		guideMissile();
		pass -= missileDelta;
	}
		

	while (!mCommandQueue.isEmpty()) {
		mScenegraph.onCommand(mCommandQueue.pop(), dt);
	}

	sf::Vector2f velocity = mPlayerAircraft->getVelocity();
	if (velocity.x != 0.f && velocity.y != 0) {
		mPlayerAircraft->setVelocity(velocity / std::sqrt(2.f));
	}
	mPlayerAircraft->accelerate(0.f, mScrollSpeed);

	const sf::Time collisionDelta = sf::seconds(0.2f);
	static sf::Time collisionChecktime = sf::Time::Zero;
	collisionChecktime += dt;
	if (collisionChecktime > collisionDelta) {
		handleCollisions();
		collisionChecktime -= collisionDelta;
	}
	
	mScenegraph.removeWrecks();
	spawnEnemies();

	//
	//std::cout << getBattlefieldBounds().top << std::endl;

	mScenegraph.update(dt,mCommandQueue);
	
}

void World::draw()
{
	mWindow.setView(mWorldView);
	mWindow.draw(mScenegraph);
}

CommandQueue& World::getCommandQueue()
{
	return mCommandQueue;
}

bool World::isPlayerAlive() const
{
	return !mPlayerAircraft->isMarkedForRemoval();
}

bool World::isPlayerReachEnd() const
{
	return !mWorldBounds.contains(mPlayerAircraft->getPosition());
}



void World::loadTexture() {
	mTextures.load(Textures::tBackground, "res/background.png");
	mTextures.load(Textures::tMyAircraft, "res/myaircraft.png");
	mTextures.load(Textures::tTitleScreen, "res/image.png");
	mTextures.load(Textures::tAirplane, "res/raptor.png");
	mTextures.load(Textures::tAlliedBullet, "res/AllidBullet.png");
	mTextures.load(Textures::tEnemyBullet, "res/EnemyBullet.png");
	mTextures.load(Textures::tMissile, "res/Missile.png");
	mTextures.load(Textures::tMissileRefill, "res/MissileRefill.png");
	mTextures.load(Textures::tHealthRefill, "res/HealthRefill.png");
	mTextures.load(Textures::tFireRate, "res/FireRate.png");
	mTextures.load(Textures::tFireSpread, "res/HealthRefill.png");
}

void World::buildScene()
{
	for (int i = 0; i < LayerCount; ++i) {
		SceneNode::Ptr layer(new SceneNode(i == Layer::Air ? Category::Scene : Category::None));
		mSceneLayers[i] = layer.get();
		mScenegraph.attachChild(std::move(layer));
	}
	//图层初始化

	sf::Texture& texture = mTextures.get(Textures::tBackground);
	sf::IntRect textureRect(mWorldBounds);
	texture.setRepeated(true); 
	//设置背景Texture

	std::unique_ptr<SpriteNode> backgroundSprite(new SpriteNode(texture,textureRect));
	backgroundSprite->setPosition(mWorldBounds.left, mWorldBounds.top);
	mSceneLayers[Background]->attachChild(std::move(backgroundSprite));
	//设置背景Sprite

	std::unique_ptr<Aircraft> myaircraftSprite(new Aircraft(Aircraft::Mycraft, mTextures,mFonts));
	mPlayerAircraft = myaircraftSprite.get();
	mPlayerAircraft->setPosition(mSpawnPosition);
	mPlayerAircraft->setVelocity(0, mScrollSpeed);
	mSceneLayers[Air]->attachChild(std::move(myaircraftSprite));
	//加入自己的飞机

	addEnemies();
}

void World::spawnEnemies()
{
	while (!mEnemySpawnPoints.empty() && mEnemySpawnPoints.back().y > getBattlefieldBounds().top) {
		SpawnPoint spawn = mEnemySpawnPoints.back();

		std::unique_ptr<Aircraft> enemy(new Aircraft(spawn.type, mTextures, mFonts));
		enemy->setPosition(spawn.x, spawn.y);
		//enemy->setRotation(-180.f);

		mSceneLayers[Air]->attachChild(std::move(enemy));


		mEnemySpawnPoints.pop_back();
	}
}

void World::addEnemies()
{
	addEnemy(Aircraft::Raptor, -200.f, 600.f);
	addEnemy(Aircraft::Raptor, 200.f, 600.f);
	addEnemy(Aircraft::Raptor, -200.f, 2700.f);
	addEnemy(Aircraft::Raptor, 300.f, 2700.f);
	addEnemy(Aircraft::Raptor, -200.f, 1700.f);
	addEnemy(Aircraft::Raptor, 200.f, 1700.f);
	addEnemy(Aircraft::Raptor, 10.f, 1000.f);
	addEnemy(Aircraft::Raptor, 0.f, 1300.f);
	addEnemy(Aircraft::Raptor, -300.f, 2300.f);
	addEnemy(Aircraft::Raptor, 0.f, 2400.f);
	addEnemy(Aircraft::Raptor, 300.f, 2500.f);
	addEnemy(Aircraft::Raptor, 100.f, 3000.f);
	addEnemy(Aircraft::Raptor, 0.f, 3100.f);
	addEnemy(Aircraft::Raptor, 100.f, 3300.f);


	std::sort(mEnemySpawnPoints.begin(),mEnemySpawnPoints.end(),
		[](SpawnPoint &lhs, SpawnPoint &rhs) {
		return lhs.y < rhs.y;
	});
}

void World::addEnemy(Aircraft::Type type, float X, float Y)
{
	SpawnPoint spawn(type, mSpawnPosition.x + X, mSpawnPosition.y - Y);
	mEnemySpawnPoints.push_back(spawn);
}

void World::guideMissile()
{
	Command enemyCollector;
	enemyCollector.category = Category::EnemyAircraft;
	enemyCollector.action = derivedAction<Aircraft>([this](Aircraft &enemy, sf::Time) {
		if (!enemy.isDestoryed())
			mActiveEnemies.push_back(&enemy);
		if (mActiveEnemies.size()) {
			std::cout << "Found " << mActiveEnemies.size() << " enemy" << std::endl;
		}
	});

	Command missileGuider;
	missileGuider.category = Category::AlliedProjectile;
	missileGuider.action = derivedAction<Projectile>([this](Projectile &missile, sf::Time) {
		if (!missile.isGuided())
			return;
		float minDistance = std::numeric_limits<float>::max();
		Aircraft* closestEnemy = nullptr;

		for (auto enemy : mActiveEnemies) {
			float enemyDistance = distance(missile, *enemy);
			if (enemyDistance < minDistance) {
				closestEnemy = enemy;
				minDistance = enemyDistance;
			}
		}
		if (closestEnemy)
			missile.guideTowards(closestEnemy->getWorldPosition());
	});

	mCommandQueue.push(enemyCollector);
	mCommandQueue.push(missileGuider);
	mActiveEnemies.clear();
}

void World::handleCollisions()
{
	std::set<SceneNode::Pair> collisionPairs;
	mScenegraph.checkSceneCollision(mScenegraph, collisionPairs);

	for (auto pair : collisionPairs) {
		if (matchesCategories(pair, Category::PlayerAircraft, Category::EnemyAircraft)) {
			std::cout << "PlayerAircraft Crash EnemyAircraft" << std::endl;
			auto &player = static_cast<Aircraft&>(*pair.first);
			auto &enemy = static_cast<Aircraft&>(*pair.second);

			player.damage(enemy.getHitpoints());
			enemy.destory();
		}
		else if (matchesCategories(pair, Category::PlayerAircraft, Category::Pickup)) {
			std::cout << "PlayerAircraft Crash Pickup" << std::endl;
			auto &player = static_cast<Aircraft&>(*pair.first);
			auto &pickup = static_cast<Pickup&>(*pair.second);

			pickup.apply(player);
			pickup.destory();
		}
		else if (matchesCategories(pair, Category::EnemyAircraft, Category::AlliedProjectile) || matchesCategories(pair, Category::PlayerAircraft, Category::EnemyProjectile)) {
			std::cout << "Aircraft Crash Projectile" << std::endl;
			auto &aircraft = static_cast<Aircraft&>(*pair.first);
			auto &projectile = static_cast<Projectile&>(*pair.second);

			aircraft.damage(projectile.getDamage());
			projectile.destory();
		}
	}
}

void World::destoryEntitiesOutsideView()
{
	Command command;
	command.category = Category::Projectile | Category::EnemyAircraft;
	command.action = derivedAction<Entity>([this](Entity &e, sf::Time) {
		if (!getBattlefieldBounds().intersects(e.getBoundingRect())) {
			std::cout << (void*)(this) << "   Destory !" << std::endl;
			e.destory();
		}
	});
	mCommandQueue.push(command);
}

sf::FloatRect World::getViewBounds()
{
	return sf::FloatRect(mWorldView.getCenter() - mWorldView.getSize() / 2.f, mWorldView.getSize());
}

sf::FloatRect World::getBattlefieldBounds()
{
	sf::FloatRect bounds = getViewBounds();
	bounds.top -= 50.f;
	bounds.height += 50.f;

	return bounds;
}

bool matchesCategories(SceneNode::Pair& colliders, Category::Type type1, Category::Type type2) {
	unsigned int category1 = colliders.first->getCategory();
	unsigned int category2 = colliders.second->getCategory();
	
	if ((type1 & category1) && (type2 & category2)) {
		return true;
	}
	else if ((type2 & category1) && (type1 & category2)) {
		std::swap(colliders.first, colliders.second);
		return true;
	}
	else {
		return false;
	}
		
}
