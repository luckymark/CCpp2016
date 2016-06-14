#pragma once

class Bullet 
{
public:
	sf::Sprite bullet;
	Bullet() {
		sf::Texture texture_bullet;
		texture_bullet.loadFromFile("Bullet.png");
		bullet.setTexture(texture_bullet);
	};

	void Gone();
	void Show();
};

