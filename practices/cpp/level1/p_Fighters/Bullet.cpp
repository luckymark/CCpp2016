#include "Bullet.h"

Bullet::Bullet()
{
//ctor
}

Bullet::Bullet(int x,int y){
    texture.loadFromFile("resource/shoot.png",sf::IntRect(270, 250, 50, 50));
    sprite.setTexture(texture);
    sprite.setPosition(sf::Vector2f(x,y));
}

Bullet::~Bullet()
{
    //dtor
}
//返回是否因出界要去掉子弹
int Bullet::moveBullet(){
    sf::Vector2f bulletPosition = this->sprite.getPosition();
    if(bulletPosition.y<0){
        return 1;
    }
    sprite.move(sf::Vector2f(0, speed));
    return 0;
}
