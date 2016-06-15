#include <SFML/Graphics.hpp>
#include "Rocket.h"
#include "Bullet.h"
#define SPEED 0.15


void Rocket::move() {
	extern int level;
	extern sf::RenderWindow window;
	sf::Vector2f rocket_position = rocket.getPosition();
	window.draw(rocket);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		if (rocket_position.x >= 0.15f) {
			rocket.move(0.8*level* SPEED, 0);
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		if (rocket_position.x < 647.85f) {
			rocket.move(0.8*level * SPEED, 0);
		}
	}

}

void Rocket::Gun() {
	extern Bullet bullet;
	extern int height;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		bullet.bullet.setPosition(sf::Vector2f(rocket.getPosition().x + 10, height - 150));;
	}
}