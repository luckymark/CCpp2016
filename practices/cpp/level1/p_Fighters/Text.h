#pragma once
#include<SFML\Graphics.hpp>
#include<string>
#include<cstdlib>
extern int n;
extern int life;
extern int bigBoom;
class Text
{
public:
	sf::Font font;
	sf::Text text;
	Text();
	void iniText();
	void drawBeginText();
	void drawFail();
};