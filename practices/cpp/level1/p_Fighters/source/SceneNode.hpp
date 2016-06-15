#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>

#include <vector>
#include <memory>
#include <set>

#include "Category.hpp"
#include "Command.hpp"
#include "CommandQueue.hpp"

class SceneNode : public sf::Drawable, public sf::Transformable,private sf::NonCopyable{
public:
	typedef std::unique_ptr<SceneNode> Ptr;
	typedef std::pair<SceneNode*, SceneNode*> Pair;
public:
	explicit SceneNode(Category::Type type = Category::None);
	void attachChild(Ptr child);
	Ptr detachChild(const SceneNode& node);

	void update(sf::Time dt,CommandQueue &commands);

	sf::Transform getWorldTransform() const;
	sf::Vector2f getWorldPosition() const;
	virtual sf::FloatRect getBoundingRect() const;

	void checkNodeCollision(SceneNode &node, std::set<Pair> & collisionPairs);
	void checkSceneCollision(SceneNode &node, std::set<Pair> & collisionPairs);
	void removeWrecks();


	virtual unsigned int getCategory() const;
	virtual bool isDestoryed() const;
	virtual bool isMarkedForRemoval() const;
	void onCommand(const Command &command, sf::Time dt);

private:
	virtual void updateCurrent(sf::Time dt,CommandQueue &commands);
	void updateChildren(sf::Time dt,CommandQueue &commands);

	virtual void draw(sf::RenderTarget &target, sf::RenderStates status)const;
	virtual void drawCurrent(sf::RenderTarget &target, sf::RenderStates status)const;
	void drawBoundingRect(sf::RenderTarget& target, sf::RenderStates) const;

private:
	std::vector<Ptr> mChildren;
	SceneNode* mParent;
	Category::Type mDefaultCategory;
};

bool collision(const SceneNode& lhs, const SceneNode &rhs);
float distance(const SceneNode& lhs, const SceneNode &rhs);