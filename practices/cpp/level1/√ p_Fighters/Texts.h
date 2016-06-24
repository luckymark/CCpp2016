#pragma once
#include <SFML/Graphics.hpp>
class Texts
{
private:
	sf::Text text;
	sf::Font font;
public:
	Texts() {
		font.loadFromFile("SourceCodePro.ttf");
		text.setFont(font);
		text.setCharacterSize(20);
		text.setColor(sf::Color::White);
	};
	void ShowScore() {
		char s1[30];
		extern int level,score,life;
		extern sf::RenderWindow window;
		sprintf(s1, "level: %d\nscore: %d\nlife: %d", level, score, life);
		text.setString(s1);
		window.draw(text);
	}
};

