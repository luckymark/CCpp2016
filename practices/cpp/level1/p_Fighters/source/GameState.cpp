#include "GameState.hpp"

GameState::GameState(StateStack & stack, Context context):
	State(stack,context),
	mWorld(*context.window,*context.fonts),
	mPlayer(*context.player)
{
}

void GameState::draw()
{
	mWorld.draw();
}

bool GameState::update(sf::Time dt)
{
	mWorld.update(dt);

	if (!mWorld.isPlayerAlive()) {

	}
	return true;
}

bool GameState::handleEvent(const sf::Event & event)
{
	CommandQueue &commands = mWorld.getCommandQueue();

	mPlayer.handleEvent(event, commands);

	if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::P) {
		requestStackPush(States::Pause);
	}
	if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Q) {
		requestStackPop();
	}

	mPlayer.handleRealtimeInput(commands);
	return true;
}
