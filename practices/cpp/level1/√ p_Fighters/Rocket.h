#pragma once

class Rocket 
{
public:
	sf::Sprite rocket;
	Rocket() {
		extern int height;
		sf::Texture texture;
		texture.loadFromFile("Rocket.png");
		rocket.setTexture(texture);
		rocket.setPosition(sf::Vector2f(378, height - 112));

	}

	void move();
	void Gun();
};

