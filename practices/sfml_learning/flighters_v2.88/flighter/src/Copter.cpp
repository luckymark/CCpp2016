#include "Copter.h"
#include "GameWindow.h"
#include "GameSprite.h"
#include "SFML/Graphics.hpp"
#include <cmath>
sf::Vector2f Copter::_iniPosition = sf::Vector2f(GameWindow::iniWidth,-99.f);
sf::Vector2f Copter::_iniDirection =sf::Vector2f(0.f,1.f);
const float sqrt_3=sqrt(3.0);
Copter::Copter(sf::Vector2f iniPosition,sf::Vector2f iniDirection)
{
    initializePlane(iniPosition,iniDirection);
}
void Copter::initializeSprite()
{
    planeSprite.push_back(GameSprite::Copter);
    planeSprite.push_back(GameSprite::CopterHit);
    for(auto& c:GameSprite::CopterBomb)
        planeSprite.push_back(c);
}
void Copter::initializeShootElapsed()
{
    shootElapsed= 50;
}
void Copter::initializeLife()
{
    life=6;
}
void Copter::initializeSpeed()
{
    speed = 100.f;
}
void Copter::refresh(float detalTime)
{
    ++limit;
    move(Direction*speed*detalTime);
}
void Copter::fire() {

    return;
}
Plane* Copter::clone()
{
    return new Copter(*this);
}
void Copter::playBombSound()
{
    music->playCopterBomb();
}
void Copter::draw()
{
    if(isAlive())
    {
        if(isBeHited)
        {
            status = 1;
            isBeHited = false;
        }
        else status = 0;
    }
    window->draw(getSprite());
}
