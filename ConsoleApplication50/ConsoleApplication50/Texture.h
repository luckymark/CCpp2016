#pragma once
#include<SFML/Graphics.hpp>
//#include<sfml/Audio.hpp>
class Texture {
public:
	  sf::Texture HERO;
	  sf::Texture ENEMY1;
	  sf::Texture ENEMY2;
	  sf::Texture ENEMY_DOWN_1;
	  sf::Texture ENEMY_DOWN_2;
	  sf::Texture ENEMY_DOWN_3;
	  sf::Texture ENEMY_DOWN_4;
	  sf::Texture BULLET;
	  sf::Texture SKY;
	  sf::Texture DONGPOINT;
	  sf::Texture POWERPOINT;
	  sf::Texture ENEMYBULLET;
	  sf::Texture BOSS;
	  sf::Texture LIGHT;
	  void load(int i);
	 Texture() {};
};//∏¥œ∞æ≤Ã¨¿‡
