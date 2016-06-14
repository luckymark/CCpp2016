#pragma once
#include <SFML/Graphics.hpp>
class Background
{
public:
	sf::Sprite background;
	
	Background() {
		sf::Texture texture_background;
		texture_background.loadFromFile("background.jpg");
		background.setTexture(texture_background);
	};

	void Show() {
		extern sf::RenderWindow window;
		window.draw(background);
	}
};

