#include <SFML/Graphics.hpp>
#include "Bullet.h"
#define SPEED 0.15


void Bullet::Gone() {
	bullet.setPosition(sf::Vector2f(1000, 0));
}

void Bullet::Show() {
	extern sf::RenderWindow window;
	window.draw(bullet);
	bullet.move(0, -10 * SPEED);
}