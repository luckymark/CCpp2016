#include "BoomPlane.h"

BoomPlane::BoomPlane()
{
    font.loadFromFile("resource/font/STHeiti Light.ttc");
    text.setCharacterSize(24);
    text.setColor(sf::Color::Red);
    text.setPosition(350,700);
    text.setFont(font);
    text.setString("Boom!");//ctor
}

BoomPlane::~BoomPlane()
{
    //dtor
}

void BoomPlane::stateChange(){
    state ++;
}
