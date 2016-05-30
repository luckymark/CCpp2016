#pragma once
#include<SFML\Graphics.hpp>
#include<string>
class Backround
{
private:
	std::string s;
public:
	sf::Texture backround;
	sf::Sprite sbackround;
	Backround();
	void inibackround();
	void drawBeginBackround();

};