
#include "Warship.h"
#include "GameWindow.h"
#include "GameSprite.h"
#include "SFML/Graphics.hpp"
sf::Vector2f Warship::_iniPosition = sf::Vector2f(GameWindow::iniWidth,0.f);
sf::Vector2f Warship::_iniDirection =sf::Vector2f(0.1,1.f);
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
    life=1;
}
void Warship::initializeSpeed()
{
    speed = 200.f;
}
void Warship::refresh(float detalTime)
{
    //float detalTime = clock->restart().asSeconds();
    move(Direction*speed*detalTime);
    //window->draw(getSprite());
}
void Warship::fire() {
    return;
}
