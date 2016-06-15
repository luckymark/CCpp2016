#pragma once
#include <SFML\Graphics.hpp>

#include "State.hpp"
#include "Container.hpp"

class GameOverState :public State {
public:
	GameOverState(StateStack& stack, Context context);
	virtual void draw();
	virtual bool update(sf::Time dt);
	virtual bool handleEvent(const sf::Event &event);

private:
	sf::Text mGGText;
	sf::Time mElapsedTime;
};