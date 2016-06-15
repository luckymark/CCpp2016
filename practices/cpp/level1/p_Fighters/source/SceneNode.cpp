#include "SceneNode.hpp"
#include <cassert>
#include <iostream>
SceneNode::SceneNode(Category::Type type) :mParent(nullptr), mChildren(), mDefaultCategory(type){

}

void SceneNode::attachChild(Ptr child) {
	child->mParent = this;
	mChildren.push_back(std::move(child));
}

SceneNode::Ptr SceneNode::detachChild(const SceneNode& node) {
	auto found = std::find_if(mChildren.begin(), mChildren.end(),
		[&](Ptr& p) -> bool {return p.get() == &node; });
	assert(found != mChildren.end());
	Ptr result = std::move(*found);
	result->mParent = nullptr;
	mChildren.erase(found);
	return result;
}

void SceneNode::update(sf::Time dt,CommandQueue &commands)
{
	updateCurrent(dt,commands);
	updateChildren(dt,commands);
}

sf::Transform SceneNode::getWorldTransform() const
{
	sf::Transform transform = sf::Transform::Identity;
	for (const SceneNode* node = this; node != nullptr; node = node->mParent) {
		transform = node->getTransform() * transform;
	}
	return transform;
}

sf::Vector2f SceneNode::getWorldPosition() const
{
	return getWorldTransform() * sf::Vector2f();
}

sf::FloatRect SceneNode::getBoundingRect() const
{
	return sf::FloatRect();
}

void SceneNode::checkNodeCollision(SceneNode & node, std::set<Pair>& collisionPairs)
{
	if (this != &node && collision(*this, node) && !isDestoryed() && !node.isDestoryed())
		collisionPairs.insert(std::minmax(this, &node));

	for (auto &child : mChildren) {
		child->checkNodeCollision(node, collisionPairs);
	}
}

void SceneNode::checkSceneCollision(SceneNode & node, std::set<Pair>& collisionPairs)
{
	checkNodeCollision(node, collisionPairs);

	for (auto &child : node.mChildren) {
		checkSceneCollision(*child, collisionPairs);
	}
}

void SceneNode::removeWrecks()
{
	auto wreckfieldBegin = std::remove_if(mChildren.begin(), mChildren.end(), std::mem_fn(&SceneNode::isMarkedForRemoval));
	
	if (wreckfieldBegin != mChildren.end()) {
		std::cout << "remove sth" << std::endl;
	}
	mChildren.erase(wreckfieldBegin, mChildren.end());

	std::for_each(mChildren.begin(), mChildren.end(), std::mem_fn(&SceneNode::removeWrecks));
}

unsigned int SceneNode::getCategory() const
{
	return mDefaultCategory;
	// Default value
}

bool SceneNode::isDestoryed() const
{
	return false; //Default
}

bool SceneNode::isMarkedForRemoval() const
{
	return isDestoryed(); //Default
}

void SceneNode::onCommand(const Command & command, sf::Time dt)
{
	if (command.category & getCategory()) {
		command.action(*this, dt);
	}
	for (auto it = mChildren.begin(); it != mChildren.end(); ++it) {
		(*it)->onCommand(command, dt);
	}
}

void SceneNode::updateCurrent(sf::Time dt,CommandQueue &)
{
}

void SceneNode::updateChildren(sf::Time dt,CommandQueue &commands)
{
	for (auto it = mChildren.begin(); it != mChildren.end(); ++it) {
		(*it)->update(dt,commands);
	}
}

void SceneNode::draw(sf::RenderTarget & target, sf::RenderStates status) const
{
	status.transform *= getTransform();
	
	//drawBoundingRect(target, status);
	
	drawCurrent(target, status);
	for (auto it = mChildren.begin(); it != mChildren.end(); ++it) {
		(*it)->draw(target, status);
	}
}

void SceneNode::drawCurrent(sf::RenderTarget & target, sf::RenderStates status) const
{
	//Do nothing default
}

void SceneNode::drawBoundingRect(sf::RenderTarget & target, sf::RenderStates) const
{
	sf::FloatRect rect = getBoundingRect();

	sf::RectangleShape shape;
	shape.setPosition(sf::Vector2f(rect.left, rect.top));
	shape.setSize(sf::Vector2f(rect.width, rect.height));
	shape.setFillColor(sf::Color::Transparent);
	shape.setOutlineColor(sf::Color::Red);
	shape.setOutlineThickness(1.f);

	target.draw(shape);
}

bool collision(const SceneNode & lhs, const SceneNode & rhs)
{
	return lhs.getBoundingRect().intersects(rhs.getBoundingRect());
}

float distance(const SceneNode & lhs, const SceneNode & rhs)
{
	sf::Vector2f vDistance = lhs.getWorldPosition() - rhs.getWorldPosition();
	return std::sqrt(vDistance.x * vDistance.x + vDistance.y * vDistance.y);
}
