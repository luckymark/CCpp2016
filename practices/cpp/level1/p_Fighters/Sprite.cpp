#include "Sprite.h"

#include <iostream>

#include <SFML/Graphics.hpp>

Sprite::Sprite()
{
    //ctor
}

Sprite::~Sprite()
{
    //dtor
}

bool Sprite::intersects(Sprite other){
    bool t = this->getGlobalBounds().intersects(other.getGlobalBounds());
    return t;
}
