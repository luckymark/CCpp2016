#include "GameOverState.hpp"

GameOverState::GameOverState(StateStack & stack, Context context) :mGGText(), mElapsedTime(sf::Time::Zero), State(stack, context)
{
	sf::Font &font = context.fonts->get(Fonts::fMain);
	sf::Vector2f windowSize(context.window->getSize());

	mGGText.setString("Finished!!!");
}

void GameOverState::draw()
{
	
}

bool GameOverState::update(sf::Time dt)
{
	return false;
}

bool GameOverState::handleEvent(const sf::Event & event)
{
	return false;
}
