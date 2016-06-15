#pragma once
#include <SFML\Graphics.hpp>

#include <functional>
#include <vector>
#include <string>
#include <memory>

#include "Component.hpp"
#include "ResourceHolder.hpp"
#include "ResourceIdentifies.hpp"
#include "Stringhelper.hpp"

namespace GUI {
	class Button :public Component {
	public:
		typedef std::shared_ptr<Button> Ptr;
		typedef std::function<void()> Callback;

	public:
		Button(const FontHolder& fonts, const TextureHolder &textures);
		void setCallback(Callback callback);
		void setText(const sf::String text);
		void setToggle(bool flag);

		virtual bool isSelectable() const;
		virtual void select();
		virtual void deselect();
		virtual void activate();
		virtual void deactivate();
		virtual void handleEvent(const sf::Event &event);

	private:
		virtual void draw(sf::RenderTarget &target, sf::RenderStates status)const;

	private:
		Callback mCallback;
		const sf::Texture& mNormalTexture;
		const sf::Texture& mSelectedTexture;
		const sf::Texture& mPressedTexture;
		sf::Sprite mSprite;
		sf::Text mText;
		bool mIsToggle;
	};
}