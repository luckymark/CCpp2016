#include "EnemyBullet.h"

EnemyBullet::EnemyBullet()
{
    texture.loadFromFile("resource/shoot.png",sf::IntRect(270, 250, 50, 50));
    sprite.setTexture(texture);
    sprite.setPosition(20,20);
}

EnemyBullet::~EnemyBullet()
{
    //dtor
}

int EnemyBullet::moveBullet(){
    sf::Vector2f bulletPosition = this->sprite.getPosition();
    if(bulletPosition.y<0){
        return 1;
    }
    sprite.move(sf::Vector2f(0, speed));
    return 0;
}
