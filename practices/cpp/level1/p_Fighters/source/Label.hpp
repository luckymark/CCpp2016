#pragma once
#include <SFML\Graphics.hpp>

#include <memory>

#include "Component.hpp"
#include "ResourceHolder.hpp"
#include "ResourceIdentifies.hpp"

namespace GUI {
	class Label :public Component {
	public:
		typedef std::shared_ptr<Label> Ptr;

	public:
		Label(const sf::String &text, const FontHolder& fonts);
		virtual bool isSelectable() const;
		void setText(const sf::String &text);
		virtual void handleEvent(const sf::Event &event);

	private:
		void draw(sf::RenderTarget &target, sf::RenderStates states)const;

	private:
		sf::Text mText;
	};
}