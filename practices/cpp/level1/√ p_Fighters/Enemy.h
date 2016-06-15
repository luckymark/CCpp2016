#pragma once
#include <SFML/Graphics.hpp>
#include <random>
class Enemy {
public:
	sf::Sprite enemy;
	Enemy() {
		sf::Texture texture_enemy;
		texture_enemy.loadFromFile("enemy.png");
		enemy.setTexture(texture_enemy);

		std::random_device rd;
		std::default_random_engine e(rd());
		std::uniform_int_distribution <> u(0, 650);
		enemy.setPosition(sf::Vector2f(u(e), -30));
	}
		
	void Show();
	void Gone();
};

