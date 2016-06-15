#include "MenuState.hpp"
#include "Stringhelper.hpp"

MenuState::MenuState(StateStack & stack, Context context):
	State(stack,context),
	mOptions(),
	mOptionIndex(0)
{
	sf::Texture &texture = context.textures->get(Textures::tTitleScreen);
	sf::Font &font = context.fonts->get(Fonts::fMain);
	mBackgroundSprite.setTexture(texture);
	//
	sf::Text playOption;
	playOption.setFont(font);
	playOption.setString("PLAY");
	setCenterOrigin(playOption);
	playOption.setPosition(context.window->getView().getSize() / 2.f + sf::Vector2f(0.f, -60.f));
	mOptions.push_back(playOption);
	//
	sf::Text exitOption;
	exitOption.setFont(font);
	exitOption.setString("EXIT");
	setCenterOrigin(exitOption);
	exitOption.setPosition(playOption.getPosition() + sf::Vector2f(0.f, 60.f));
	mOptions.push_back(exitOption);
	//
	sf::Text settingOption;
	settingOption.setFont(font);
	settingOption.setString("SETTING");
	setCenterOrigin(settingOption);
	settingOption.setPosition(exitOption.getPosition() + sf::Vector2f(0.f, 60.f));
	mOptions.push_back(settingOption);
	//
	updateOptionText();

}

void MenuState::draw()
{
	sf::RenderWindow& window = *getContext().window;

	window.setView(window.getDefaultView());
	window.draw(mBackgroundSprite);

	for (auto &text : mOptions) {
		window.draw(text);
	}
}

bool MenuState::update(sf::Time dt)
{
	return true;
}

bool MenuState::handleEvent(const sf::Event & event)
{
	if (event.type != sf::Event::KeyPressed)
		return false;

	if (event.key.code == sf::Keyboard::Up) {
		mOptionIndex = (mOptionIndex - 1 + mOptions.size()) % mOptions.size();
		//更新选项重新绘图
		updateOptionText();
	}
	else if (event.key.code == sf::Keyboard::Down) {
		mOptionIndex = (mOptionIndex + 1) % mOptions.size();
		//更新选项重新绘图
		updateOptionText();
	}
	else if (event.key.code == sf::Keyboard::Return) {
		if (mOptionIndex == Play) {
			requestStackPop();
			requestStackPush(States::Game);
		}
		else if (mOptionIndex == Exit) {
			requestStackPop();
		}
		else if (mOptionIndex == Setting) {
			//requestStackPop();
			requestStackPush(States::Setting);
		}
	}
	return true;
}

void MenuState::updateOptionText()
{
	if (mOptions.empty())
		return;

	for (auto &text : mOptions) { //设置未选中颜色
		text.setColor(sf::Color::White);
	}

	mOptions[mOptionIndex].setColor(sf::Color::Cyan); // 设置选中颜色
}
