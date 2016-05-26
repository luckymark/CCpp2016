#include "Warship.h"
#include "GameWindow.h"
#include "GameSprite.h"
#include "SFML/Graphics.hpp"
sf::Vector2f Warship::_iniPosition = sf::Vector2f(GameWindow::iniWidth,-258.f);
sf::Vector2f Warship::_iniDirection =sf::Vector2f(0.f,1.f);
bool Warship::isPlayFlyingSound=false;
Warship::Warship(sf::Vector2f iniPosition,sf::Vector2f iniDirection)
{
    initializePlane(iniPosition,iniDirection);
}
void Warship::initializeSprite()
{
    planeSprite = GameSprite::Warship;
    planeSprite.push_back(GameSprite::WarshipHit);
    for(auto& c:GameSprite::WarshipBomb)
        planeSprite.push_back(c);
}
void Warship::initializeShootElapsed()
{
    shootElapsed=0.6f;
}
void Warship::initializeLife()
{
    life=10;
}
void Warship::initializeSpeed()
{
    speed = 60.f;
}
void Warship::refresh(float detalTime)
{
    move(Direction*speed*detalTime);
}
void Warship::fire() {
    return;
}
Plane* Warship::clone()
{
    return new Warship(*this);
}
void Warship::changeStatus()
{
    switch(status)
    {
        case 0:
            ++status;
            break;
        case 1:
            --status;
            break;
        case 2:
            status = 0;
            break;
    }
}
void Warship::draw()
{
    if(isAlive())
    {
        if(_isBeHited)
        {
            status = 2;
            _isBeHited = false;
        }
        else changeStatus();
    }
    window->draw(getSprite());
}
void Warship::playFlyingSound()
{
    //printf("play!\n");
    if(isAlive())
        music->playWarshipFlying();
}
void Warship::playBombSound()
{
    music->playWarshipBomb();
}
