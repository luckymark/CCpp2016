#include "Sky.h"
#include<SFML/Graphics.hpp>
#include"Hero.h"
#include"Enemy.h"
#include"Enemy2.h"
#include"Enemy3.h"
#include"Bullet.h"
int Sky::game_time=0;
int Sky::game_time2=0;
Sky::Sky(){

    this->window=new sf::RenderWindow(sf::VideoMode(480, 600), "飞机大战");
    background.loadFromFile("F:\\reso\\background1.jpg");
    sbackground.setTexture(background);
}
void Sky::refresh(){
    window->draw(this->sbackground);
    window->draw(Hero::shero);
    window->draw(Enemy::senemy);
    window->draw(Enemy2::senemy);
    window->draw(Enemy3::senemy);
    window->draw(Bullet::sbullet);
    window->display();
}


