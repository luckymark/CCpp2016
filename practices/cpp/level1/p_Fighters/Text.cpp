#include "Text.h"

Text::Text()
{
	if (!font.loadFromFile("D://STKAITI.TTF"))
		exit(0);
}



void Text::iniText()
{
	std::string s1 = "Score: ";
	std::string s2 = std::to_string(n);
	s1 = s1 + s2;
	s1 = s1 + "\n";
	s2 = "Life: ";
	std::string s3 = std::to_string(life);
	s1 = s1 + s2 + s3;
	s1 = s1 + "\n";
	s1 = s1 + "BigBoom: ";
	s3 = std::to_string(bigBoom);
	s1 = s1 + s3;
	text.setFont(font);
	text.setString(s1);
	text.setCharacterSize(24);
	text.setColor(sf::Color::Red);
	text.setStyle(sf::Text::Bold | sf::Text::Underlined);
}
