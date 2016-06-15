#include "LoadState.hpp"
#include "Stringhelper.hpp"

LoadState::LoadState(StateStack & stack, Context context):
	State(stack,context)
{
	sf::RenderWindow& window = *getContext().window;
	sf::Font& font = context.fonts->get(Fonts::fMain);
	sf::Vector2f viewSize = window.getView().getSize();

	mLoadingText.setString("Loading...");
	mLoadingText.setFont(font);
	setCenterOrigin(mLoadingText);
	mLoadingText.setPosition(viewSize.x / 2.f, viewSize.y / 2.f + 50.f);

	mProgressBarBackground.setFillColor(sf::Color::White);
	mProgressBarBackground.setSize(sf::Vector2f(viewSize.x - 100.f, 20.f));
	mProgressBarBackground.setPosition(20.f, mLoadingText.getPosition().y + 40.f);

	mProgressBar.setFillColor(sf::Color(100, 100, 100));
	mProgressBar.setSize(sf::Vector2f(200, 20));
	mProgressBar.setPosition(20.f, mLoadingText.getPosition().y + 40.f);

	setCompletion(0.f);

	mLoadingTask.exectute();

}

void LoadState::draw()
{
	sf::RenderWindow& window = *getContext().window;

	window.setView(window.getDefaultView());

	window.draw(mLoadingText);
	window.draw(mProgressBarBackground);
	window.draw(mProgressBar);
}

bool LoadState::update(sf::Time dt)
{
	if (mLoadingTask.isFinished()) {
		requestStackPop();
		requestStackPush(States::Game);
	}
	else {
		setCompletion(mLoadingTask.getCompletion());
	}
	return true;
}

bool LoadState::handleEvent(const sf::Event & event)
{
	return true;
}

void LoadState::setCompletion(float percent)
{
	if (percent > 1.f)
		percent = 1.f;
	mProgressBar.setSize(sf::Vector2f(mProgressBarBackground.getSize().x * percent, mProgressBar.getSize().y));

}
