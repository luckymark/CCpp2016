#include "SpriteNode.hpp"

SpriteNode::SpriteNode(const sf::Texture & texture)
:mSprite(texture)
{

}

SpriteNode::SpriteNode(const sf::Texture & texture, const sf::IntRect & rect)
: mSprite(texture, rect)
{
}

void SpriteNode::drawCurrent(sf::RenderTarget & target, sf::RenderStates status) const
{
	target.draw(mSprite,status);
}
