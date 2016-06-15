#include <SFML/Graphics.hpp>
#include "Enemy_bullet.h"
#define SPEED 0.15




void Enemy_bullet::Gone() {
	enemy_bullet.setPosition(sf::Vector2f(1000, 0));
}

void Enemy_bullet::Show() {
	extern int level;
	extern sf::RenderWindow window;
	window.draw(enemy_bullet);
	enemy_bullet.move(0, 2 * level  * SPEED);
}