#include <windows.h>
#include <winuser.h>
#include <SFML/Graphics.hpp>

void Result() {
	extern int level, score, life;
	sf::Event event;
	sf::Font font;
	font.loadFromFile("SourceCodePro.ttf");
	sf::Text text2;
	text2.setFont(font);
	text2.setCharacterSize(20);
	text2.setColor(sf::Color::Black);
	if (life <= 0) {

		sf::RenderWindow window2(sf::VideoMode(300, 80), "Game Over!");
		while (window2.isOpen()) {
			while (window2.pollEvent(event)) {
				if (event.type == sf::Event::Closed)
					window2.close();
			}
			window2.display();
			char s2[30];
			sprintf(s2, "Your Score: %d\nYour level: Level %d", score, level);
			text2.setString(s2);
			window2.clear(sf::Color::White);
			window2.draw(text2);
		}
	}
	if (score == 7500) {
		sf::RenderWindow window3(sf::VideoMode(300, 80), "You Win!");
		while (window3.isOpen()) {
			while (window3.pollEvent(event)) {
				if (event.type == sf::Event::Closed)
					window3.close();
			}
			window3.display();
			char s2[30];
			sprintf(s2, "Your Score: %d\nYour level: Level %d", score, level);
			text2.setString(s2);
			window3.clear(sf::Color::White);
			window3.draw(text2);
		}
	}
}