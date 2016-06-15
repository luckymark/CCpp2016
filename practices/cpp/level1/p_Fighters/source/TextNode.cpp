#include "TextNode.hpp"

TextNode::TextNode(const FontHolder & fonts, const sf::String & text)
{
	mText.setString(text);
	mText.setFont(fonts.get(Fonts::fMain));
	mText.setCharacterSize(20);
	mText.setColor(sf::Color::Black);
}

void TextNode::setString(const sf::String & text)
{
	mText.setString(text);
	setCenterOrigin(mText);
}

void TextNode::drawCurrent(sf::RenderTarget & target, sf::RenderStates status) const
{
	target.draw(mText, status);
}
