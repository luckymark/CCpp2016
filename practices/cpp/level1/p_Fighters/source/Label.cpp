#include "Label.hpp"

GUI::Label::Label(const sf::String & text, const FontHolder & fonts) :mText(text, fonts.get(Fonts::fMain), 18)
{
}

bool GUI::Label::isSelectable() const
{
	return false;
}

void GUI::Label::setText(const sf::String & text)
{
	mText.setString(text);
}

void GUI::Label::handleEvent(const sf::Event & event)
{
}

void GUI::Label::draw(sf::RenderTarget & target, sf::RenderStates states)const
{
	states.transform *= getTransform();
	target.draw(mText, states);
}

