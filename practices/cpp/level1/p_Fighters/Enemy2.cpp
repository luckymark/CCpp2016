#include "Enemy2.h"
#include"Sky.h"
#include<iostream>
#include<SFML/Graphics.hpp>
using namespace std;
sf::Sprite Enemy2::senemy;
void Enemy2::build(){
    this->heartlife=2;
}
void Enemy2::draw_myself(){
    this->enemy.loadFromFile("F:\\reso\\enemy.png",sf::IntRect(0,3,40,40));
    this->senemy.setPosition(sf::Vector2f(this->ex-0.2*Sky::game_time,this->ey+Sky::game_time));
    this->senemy.setTexture(this->enemy);
}
void Enemy2::move(){
    this->ex=rand()%200+200;
}


