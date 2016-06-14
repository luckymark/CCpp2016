#pragma once

class Enemy_bullet 

{
public:
	sf::Sprite enemy_bullet;
	Enemy_bullet() {
		sf::Texture texture_enemy_bullet;
		texture_enemy_bullet.loadFromFile("enemy_bullet.png");
		enemy_bullet.setTexture(texture_enemy_bullet);
	};

	void Gone();
	void Show();
};

