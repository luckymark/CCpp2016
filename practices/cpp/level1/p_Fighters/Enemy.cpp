#include "Enemy.h"
#include"Sky.h"
#include<iostream>
#include<SFML/Graphics.hpp>
using namespace std;
sf::Sprite Enemy::senemy;
void Enemy::build(){
    this->heartlife=2;
}
void Enemy::draw_myself(){
    this->enemy.loadFromFile("F:\\reso\\enemy.png",sf::IntRect(0,3,40,40));
    this->senemy.setPosition(sf::Vector2f(this->ex+0.2*Sky::game_time,this->ey+Sky::game_time));
    this->senemy.setTexture(this->enemy);
}
void Enemy::move(){
    Enemy::build();
    this->ex=rand()%200;
}

