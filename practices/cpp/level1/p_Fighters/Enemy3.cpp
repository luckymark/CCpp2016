#include"Sky.h"
#include "Enemy3.h"
#include<iostream>
#include<SFML/Graphics.hpp>
using namespace std;
sf::Sprite Enemy3::senemy;
void Enemy3::build(){
    this->heartlife=50;
}
void Enemy3::draw_myself(){
    this->enemy.loadFromFile("F:\\reso\\enemy3.png",sf::IntRect(0,10,90,90));
    this->senemy.setPosition(sf::Vector2f(this->ex,this->ey+0.6*Sky::game_time));
    this->senemy.setTexture(this->enemy);
}
void Enemy3::move(){
    this->ex=rand()%300;
}


