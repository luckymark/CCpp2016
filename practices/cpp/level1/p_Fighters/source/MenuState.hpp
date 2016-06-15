#pragma once

#include <SFML\Graphics.hpp>

#include "State.hpp"
#include "StateStack.hpp"

class MenuState :public State {
public:
	MenuState(StateStack &stack, Context context);
	
	virtual void draw();
	virtual bool update(sf::Time dt);
	virtual bool handleEvent(const sf::Event &event);

	void updateOptionText();
private:
	enum OptionNames {
		Play,
		Exit,
		Setting,
	};
private:
	sf::Sprite mBackgroundSprite;
	std::vector<sf::Text> mOptions;
	std::size_t mOptionIndex;
};