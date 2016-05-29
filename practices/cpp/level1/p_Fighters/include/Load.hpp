#pragma once

#include"SFML\Graphics.hpp"
#include<iostream>
#include<string>
#include"SFML\Audio.hpp"

class Load
{
public:
	Load();
	sf::Texture background;
	sf::Texture enemy;
	sf::Texture enemy2;
	sf::Texture enemy3;
	sf::Texture enemy4;
	sf::Texture boss;
	sf::Texture boss2;
	sf::Texture boss3;
	sf::Texture boss4;
	sf::Texture myplane;
	sf::Texture myplane2;
	sf::Texture myplane3;
	sf::Texture myplane4;
	sf::Texture enemyshoot;
	sf::Texture myshoot;
	sf::Texture gun1;
	sf::Texture gun2;
	sf::Texture gun3;
	sf::Font font;
	sf::Music bgm;
	sf::SoundBuffer buffer;
	sf::SoundBuffer bossshootSound;
	sf::SoundBuffer myshootSound;
	sf::SoundBuffer enemyBoom;
	void load();
};
