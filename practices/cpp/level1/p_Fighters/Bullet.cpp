#include "Bullet.h"
#include"Hero.h"
#include"Sky.h"
sf::Sprite Bullet::sbullet;
int Bullet::bullet_life=0;
void Bullet::draw_myself(){
    if(this->bullet_life>2){
    this->a=Hero::hx;
    this->bullet.loadFromFile("F:\\reso\\bullet1.png",sf::IntRect(0,10,15,15));
    this->sbullet.setPosition(sf::Vector2f(a+12,b-12));
    this->sbullet.setTexture(this->bullet);
    }
}
void Bullet::build(){
    this->heartlife=1;
}
void Bullet::move(){
    this->b=Hero::hy-30*Bullet::bullet_life;
}

