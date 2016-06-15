#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>
#include <SFML\Window.hpp>
#include "Stringhelper.hpp"
#include "ResourceHolder.hpp"
#include "World.hpp"
#include "Player.hpp"
#include "Command.hpp"
#include "CommandQueue.hpp"

class Game : private sf::NonCopyable
{
public:
	Game();
	void run();


private:
	void processEvents();
	void update(sf::Time elapsedTime);
	void render();

	void updateStatistics(sf::Time elapsedTime);
	void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);


private:
	static const sf::Time	TimePerFrame;

	sf::RenderWindow mWindow;
	World mWorld;
	Player mPlayer;

	sf::Font mFont;
	sf::Text mStatisticsText;
	sf::Time mStatisticsUpdateTime;
	std::size_t mStatisticsNumFrames;

	bool mIsMovingUp, mIsMovingDown, mIsMovingLeft, mIsMovingRight;
};