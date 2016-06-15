#include "SettingState.hpp"
#include "Stringhelper.hpp"

SettingState::SettingState(StateStack & stack, Context context) :State(stack, context), mContainer()
{
	mBackgroundSprite.setTexture(context.textures->get(Textures::tTitleScreen));

	addButtonLabel(Player::MoveDown, 150.f, "Move Down", context);
	addButtonLabel(Player::MoveUp, 200.f, "Move Up", context);
	addButtonLabel(Player::MoveLeft, 250.f, "Move Left", context);
	addButtonLabel(Player::MoveRight, 300.f, "Move Right", context);
	addButtonLabel(Player::Fire, 350.f, "Fire", context);
	addButtonLabel(Player::Bomb, 400.f, "Bomb", context);

	updateLabels();

	auto backButton = std::make_shared<GUI::Button>(*context.fonts, *context.textures);
	backButton->setPosition(480.f, 380.f);
	backButton->setText("Back");
	backButton->setCallback(std::bind(&SettingState::requestStackPop, this));

	mContainer.pack(backButton);

}

void SettingState::draw()
{
	sf::RenderWindow &window = *getContext().window;

	window.draw(mBackgroundSprite);
	window.draw(mContainer);
}

bool SettingState::update(sf::Time dt)
{
	return true;
}

bool SettingState::handleEvent(const sf::Event & event)
{
	bool isKeyBinding = false;

	for (std::size_t action = 0; action < Player::ActionCount; ++action) {
		if (mBindingButtons[action]->isActivate()) {
			isKeyBinding = true;
			if (event.type == sf::Event::KeyReleased) {
				getContext().player->assignKey(static_cast<Player::Action>(action), event.key.code);
				mBindingButtons[action]->deactivate();
			}
			break;
		}
	}

	if (isKeyBinding)
		updateLabels();
	else
		mContainer.handleEvent(event);

	return false;
}

void SettingState::updateLabels()
{
	Player &player = *getContext().player;

	for (std::size_t i = 0; i < Player::ActionCount; ++i) {
		sf::Keyboard::Key key = player.getAssignKey(static_cast<Player::Action>(i));
		mBindingLabels[i]->setText(toString(key));
	}
}

void SettingState::addButtonLabel(Player::Action action, float y, const sf::String & text, Context context)
{
	mBindingButtons[action] = std::make_shared<GUI::Button>(*context.fonts, *context.textures);
	mBindingButtons[action]->setPosition(80.f, y);
	mBindingButtons[action]->setText(text);
	mBindingButtons[action]->setToggle(true);

	mBindingLabels[action] = std::make_shared<GUI::Label>("", *context.fonts);
	mBindingLabels[action]->setPosition(300.f, y + 15.f);

	mContainer.pack(mBindingButtons[action]);
	mContainer.pack(mBindingLabels[action]);
}
