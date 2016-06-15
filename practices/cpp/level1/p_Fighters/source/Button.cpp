#include "Button.hpp"

GUI::Button::Button(const FontHolder & fonts, const TextureHolder & textures) :
	mCallback(),
	mNormalTexture(textures.get(Textures::tButtonNormal)),//Need add Textures
	mPressedTexture(textures.get(Textures::tButtonPressed)),
	mSelectedTexture(textures.get(Textures::tButtonSelected)),
	mSprite(),
	mText("", fonts.get(Fonts::fMain), 16),
	mIsToggle(false)
{
	mSprite.setTexture(mNormalTexture);

	sf::FloatRect bounds = mSprite.getLocalBounds();
	mText.setPosition(bounds.width / 2.f, bounds.height / 2.f);
}

void GUI::Button::setCallback(Callback callback)
{
	mCallback = std::move(callback);
}

void GUI::Button::setText(const sf::String text)
{
	mText.setString(text);
	setCenterOrigin(mText);
}

void GUI::Button::setToggle(bool flag)
{
	mIsToggle = flag;
}

bool GUI::Button::isSelectable() const
{
	return true;
}

void GUI::Button::select()
{
	Component::select();
	mSprite.setTexture(mSelectedTexture);
}

void GUI::Button::deselect()
{
	Component::deselect();
	mSprite.setTexture(mNormalTexture);
}

void GUI::Button::activate()
{
	Component::activate();
	if (mIsToggle)
		mSprite.setTexture(mPressedTexture);
	if (mCallback)
		mCallback();
	if (!mIsToggle)
		deactivate();
}

void GUI::Button::deactivate()
{
	Component::deactivate();
	if (mIsToggle) {
		if (isSelected())
			mSprite.setTexture(mSelectedTexture);
		else
			mSprite.setTexture(mNormalTexture);
	}
}

void GUI::Button::handleEvent(const sf::Event & event)
{
}

void GUI::Button::draw(sf::RenderTarget & target, sf::RenderStates status) const
{
	status.transform *= getTransform();
	target.draw(mSprite, status);
	target.draw(mText, status);
}
