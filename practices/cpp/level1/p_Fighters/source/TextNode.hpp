#pragma once
#include <SFML\Graphics.hpp>

#include "SceneNode.hpp"
#include "ResourceHolder.hpp"
#include "ResourceIdentifies.hpp"
#include "Stringhelper.hpp"

class TextNode :public SceneNode {
public:
	explicit TextNode(const FontHolder &fonts, const sf::String &text);
	void setString(const sf::String &text);

private:
	virtual void drawCurrent(sf::RenderTarget &target, sf::RenderStates status) const;

private:
	sf::Text mText;

};