#include "Plane_enemy.h"

Plane_enemy::Plane_enemy()
{
    texture.loadFromFile("resource/shoot.png",sf::IntRect(0, 0, 80, 100));
    sprite.setTexture(texture);
    sprite.setPosition(sf::Vector2f(20, 20));

    //texture.loadFromFile("resource/shoot.png",sf::IntRect(0, 0, 100, 100));

   //sprite.setTexture(texture);
    //sprite.setPosition(sf::Vector2f(20, 20));//ctor
}

Plane_enemy::~Plane_enemy()
{
    //dtor
}

int Plane_enemy::moveEnemyPlane(){
    sf::Vector2f bulletPosition = this->sprite.getPosition();
    if(bulletPosition.y>800){
        return 1;
    }
    this->sprite.move(sf::Vector2f(0, 2));
    return 0;
}

