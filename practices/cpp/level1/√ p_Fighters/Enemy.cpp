#include <SFML/Graphics.hpp>
#include "Enemy.h"
#include <SFML/Window.hpp>
#define SPEED 0.15

void Enemy::Show() {
	extern sf::RenderWindow window;
	extern int level;
	window.draw(enemy);
	enemy.move(0, 0.5 * level *SPEED);
}

void Enemy::Gone() {
	enemy.setPosition(sf::Vector2f(-400, 0));
}