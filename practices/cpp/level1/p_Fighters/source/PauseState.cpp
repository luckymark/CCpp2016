#include "PauseState.hpp"
#include "Stringhelper.hpp"

PauseState::PauseState(StateStack & stack, Context context):
	State(stack,context),
	mBackgroundSprite(),
	mPauseText()
{
	sf::Font& font = context.fonts->get(Fonts::fMain);
	sf::Vector2f viewSize = context.window->getView().getSize();
	
	mPauseText.setString("Paused");
	mPauseText.setFont(font);
	mPauseText.setColor(sf::Color::Yellow);
	mPauseText.setCharacterSize(70);
	setCenterOrigin(mPauseText);
	mPauseText.setPosition(context.window->getView().getSize() / 2.f);

	mBackgroundSprite.setTexture(context.textures->get(Textures::tTitleScreen));
}

void PauseState::draw()
{
	sf::RenderWindow& window = *getContext().window;

	window.setView(window.getDefaultView());
	window.draw(mBackgroundSprite);

	window.draw(mPauseText);
}

bool PauseState::update(sf::Time dt)
{
	return false;
}

bool PauseState::handleEvent(const sf::Event & event)
{
	if (event.type != sf::Event::KeyPressed)
		return false;
	if (event.key.code == sf::Keyboard::P) {
		requestStackPop();
	}
	if (event.key.code == sf::Keyboard::Escape) {
		requestStateClear();
		requestStackPush(States::Menu);
	}
	return false;
}
