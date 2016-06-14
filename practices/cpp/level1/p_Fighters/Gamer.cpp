#include "Gamer.h"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#define SPEED 0.15
Gamer::Gamer()
{
}


void Gamer::run() {
	sf::RenderWindow window(sf::VideoMode(600, 900), "Fighter");
	sf::Texture texture;
	sf::Font font;
	font.loadFromFile("SourceCodePro.ttf");
	sf::Text text1;
	text1.setFont(font);
	text1.setCharacterSize(20);;
	text1.setColor(sf::Color::White);
	int level = 1, score = 0;
	texture.loadFromFile("Rocket.png");
	sf::Sprite sprite;
	sprite.setTexture(texture);
	sprite.setPosition(sf::Vector2f(278, 788));
	sf::Music music;
	music.openFromFile("BGM.wav");
	music.play();
	music.setLoop(true);
	sf::Event event;
	while (window.isOpen())
	{
		
		while (window.pollEvent(event)) 
		{
			// "close requested" event: we close the window
		if (event.type == sf::Event::Closed)
		window.close();
		}
		window.clear(sf::Color::Black);
		window.draw(sprite);
		char s1[30];
		sprintf(s1, "level: %d\nscore: %d", level, score);
		text1.setString(s1);
		window.draw(text1); 
		sf::Vector2f v1 = sprite.getPosition();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			if (v1.x>0.15f) {
				sprite.move(-SPEED, 0);
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			if (v1.x<547.85f) {
				sprite.move(SPEED, 0);
			}
		}
		window.display();
	}
	

}
