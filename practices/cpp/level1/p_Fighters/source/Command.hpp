#pragma once
#include <SFML\System.hpp>

#include <cassert>
#include <functional>

class SceneNode;

struct Command {
	std::function<void(SceneNode&, sf::Time)> action;
	unsigned int category;
};

template <typename GameObject,typename Function>
std::function<void(SceneNode&, sf::Time)> derivedAction(Function fn) {
	return [=](SceneNode &node, sf::Time dt) {
		assert(dynamic_cast<GameObject*>(&node) != nullptr); //��֤����ת���ĺϷ���
		return fn(static_cast<GameObject&>(node), dt);
	};
}