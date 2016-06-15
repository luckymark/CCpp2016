#pragma once

#include <SFML\Graphics.hpp>

#include <memory>
#include <array>

#include "Player.hpp"
#include "State.hpp"
#include "StateStack.hpp"
#include "Button.hpp"
#include "Label.hpp"
#include "Container.hpp"
#include "State.hpp"
#include "StateStack.hpp"
#include "StateIdentifiers.hpp"

class SettingState :public State {
public:
	SettingState(StateStack &stack, Context context);

	virtual void draw();
	virtual bool update(sf::Time dt);
	virtual bool handleEvent(const sf::Event &event);

private:
	void updateLabels();
	void addButtonLabel(Player::Action action, float y, const sf::String &text, Context context);
private:
	sf::Sprite mBackgroundSprite;
	GUI::Container mContainer;
	std::array<GUI::Button::Ptr, Player::ActionCount> mBindingButtons;
	std::array<GUI::Label::Ptr, Player::ActionCount> mBindingLabels;
};