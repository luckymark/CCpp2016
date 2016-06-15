#include "Application.hpp"
#include "Stringhelper.hpp"

#include "GameState.hpp"
#include "LoadState.hpp"
#include "PauseState.hpp"
#include "TitleState.hpp"
#include "MenuState.hpp"
#include "SettingState.hpp"

#include "State.hpp"
#include "StateIdentifiers.hpp"
#include "StateStack.hpp"

const sf::Time Application::TimePerFrame = sf::seconds(1.f / 60.f);

Application::Application()
	: mWindow(sf::VideoMode(1024, 768), "World", sf::Style::Close)
	, mTextures()
	, mFont()
	, mPlayer()
	, mStatisticsText()
	, mStatisticsUpdateTime()
	, mStatisticsNumFrames(0)
	, mStateStack(State::Context(mWindow,mTextures,mFont,mPlayer))
{
	mFont.load(Fonts::fMain,"res/Sansation.ttf");
	mTextures.load(Textures::tTitleScreen, "res/loading.jpg");
	mTextures.load(Textures::tButtonNormal, "res/button.png");
	mTextures.load(Textures::tButtonPressed, "res/button2.png");
	mTextures.load(Textures::tButtonSelected, "res/button3.png");
	
	mStatisticsText.setFont(mFont.get(Fonts::fMain));
	mStatisticsText.setColor(sf::Color::Black);
	mStatisticsText.setPosition(5.f, 5.f);
	mStatisticsText.setCharacterSize(14);

	registerStates();
	mStateStack.pushState(States::Title);
}


void Application::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	while (mWindow.isOpen()) {
		sf::Time dt = clock.restart();
		timeSinceLastUpdate += dt;
		while (timeSinceLastUpdate >= TimePerFrame) {
			timeSinceLastUpdate -= TimePerFrame;

			processInput();
			update(TimePerFrame);

			if (mStateStack.isEmpty()) {
				mWindow.close();
			}
		}
		updateStatistics(dt);
		render();
	}
	
}

void Application::processInput()
{
	sf::Event event;
	while (mWindow.pollEvent(event)) {
		mStateStack.handleEvent(event);

		if (event.type == sf::Event::Closed) {
			mWindow.close();
		}
	}
}

void Application::update(sf::Time dt)
{
	mStateStack.update(dt);
}

void Application::render()
{
	mWindow.clear();

	mStateStack.draw();

	mWindow.setView(mWindow.getDefaultView());
	mWindow.draw(mStatisticsText);

	mWindow.display();
}

void Application::updateStatistics(sf::Time dt)
{
	mStatisticsUpdateTime += dt;
	mStatisticsNumFrames += 1;

	if (mStatisticsUpdateTime >= sf::seconds(1.f))
	{
		mStatisticsText.setString(
			"Frames / Second = " + toString(mStatisticsNumFrames) + "\n" +
			"Time / Update = " + toString(mStatisticsUpdateTime.asMicroseconds() / mStatisticsNumFrames) + "us");

		mStatisticsUpdateTime -= sf::seconds(1.f);
		mStatisticsNumFrames = 0;
	}
}

void Application::registerStates()
{
	mStateStack.registerState<TitleState>(States::Title);
	mStateStack.registerState<GameState>(States::Game);
	mStateStack.registerState<LoadState>(States::Loading);
	mStateStack.registerState<MenuState>(States::Menu);
	mStateStack.registerState<PauseState>(States::Pause);
	mStateStack.registerState<SettingState>(States::Setting);
}
