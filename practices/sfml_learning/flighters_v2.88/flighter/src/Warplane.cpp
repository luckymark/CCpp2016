
#include "Warplane.h"
#include "GameWindow.h"
#include "GameSprite.h"
#include "SFML/Graphics.hpp"
sf::Vector2f Warplane::_iniPosition = sf::Vector2f(GameWindow::iniWidth,0.f);
sf::Vector2f Warplane::_iniDirection =sf::Vector2f(0.1,1.f);
Warplane::Warplane(sf::Vector2f iniPosition,sf::Vector2f iniDirection)
{
    initializePlane(iniPosition,iniDirection);
}
void Warplane::initializeSprite()
{
    planeSprite.push_back(GameSprite::Warplane);
    for(auto& c:GameSprite::WarplaneBomb)
        planeSprite.push_back(c);
}
void Warplane::initializeShootElapsed()
{
    shootElapsed=0.6f;
}
void Warplane::initializeLife()
{
    life=1;
}
void Warplane::initializeSpeed()
{
    speed = 400.f;
}
void Warplane::refresh(float detalTime)
{
    //float detalTime = clock->restart().asSeconds();
    move(Direction*speed*detalTime);
    //window->draw(getSprite());
}
void Warplane::fire() {
    return;
}
