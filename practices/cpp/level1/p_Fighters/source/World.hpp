#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>
#include <array>
#include "ResourceHolder.hpp"
#include "ResourceIdentifies.hpp"
#include "SceneNode.hpp"
#include "SpriteNode.hpp"
#include "Command.hpp"
#include "CommandQueue.hpp"
#include "Aircraft.hpp"

class World : private sf::NonCopyable {
public:
	explicit World(sf::RenderWindow & window, FontHolder &fonts);
	void update(sf::Time dt);
	void draw();
	CommandQueue& getCommandQueue();
	bool isPlayerAlive() const;
	bool isPlayerReachEnd() const;


private:
	void loadTexture();

	void buildScene();
	void spawnEnemies();
	void addEnemies();
	void addEnemy(Aircraft::Type type, float X, float Y);
	void guideMissile();
	void handleCollisions();
	void destoryEntitiesOutsideView();
	
	sf::FloatRect getViewBounds();
	sf::FloatRect getBattlefieldBounds();

private:
	enum Layer
	{
		Background,
		Air,
		LayerCount
	};

	struct SpawnPoint {
		SpawnPoint(Aircraft::Type type, float x, float y) :type(type), x(x), y(y) {}

		Aircraft::Type type;
		float x, y;
	};
private:
	sf::RenderWindow &mWindow; //Reference
	sf::View mWorldView;
	sf::FloatRect mWorldBounds;
	sf::Vector2f mSpawnPosition;

	TextureHolder mTextures;
	FontHolder& mFonts;
	SceneNode mScenegraph;
	
	float mScrollSpeed;
	Aircraft* mPlayerAircraft;
	CommandQueue mCommandQueue;

	std::vector<SpawnPoint> mEnemySpawnPoints;
	std::array<SceneNode*, LayerCount> mSceneLayers;
	std::vector<Aircraft*> mActiveEnemies;

};

bool matchesCategories(SceneNode::Pair& colliders, Category::Type type1, Category::Type type2);