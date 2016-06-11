#include "Plane.h"
#include<iostream>
Plane::Plane(){
    texture.loadFromFile("resource/shoot.png",sf::IntRect(0, 100, 100, 100));
    sprite.setTexture(texture);
    sprite.setPosition(sf::Vector2f(250, 700));
}

void Plane::movePlane(sf::Event event){
                if(event.key.code == sf::Keyboard::W){
                    if(sprite.getPosition().y>0)
                    sprite.move(sf::Vector2f(0, -10));
                }

                if(event.key.code == sf::Keyboard::S){
                       if(sprite.getPosition().y<700)
                    sprite.move(sf::Vector2f(0, 10));
                }

                if(event.key.code == sf::Keyboard::D){
                    if(sprite.getPosition().x<400)
                    sprite.move(sf::Vector2f(10, 0));
                }

                if(event.key.code == sf::Keyboard::A){
                    if(sprite.getPosition().x>0)
                    sprite.move(sf::Vector2f(-10, 0));
                }
                if(event.key.code == sf::Keyboard::J){
                    this->xu1s();
                }
}

Plane::~Plane()
{


 //dtor
}

void Plane::hited(){
    if(this->life>0){
        this->life--;
    }
}

int Plane::getLife(){
    return this->life;
}

void Plane::xu1s(){
    this->life++;
}
