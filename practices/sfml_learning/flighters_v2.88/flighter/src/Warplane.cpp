
#include "Warplane.h"
#include "GameWindow.h"
#include "GameSprite.h"
#include "EnemyBullet.h"
#include "Game.h"
#include "SFML/Graphics.hpp"
sf::Vector2f Warplane::_iniPosition = sf::Vector2f(GameWindow::iniWidth,-43.f);
sf::Vector2f Warplane::_iniDirection =sf::Vector2f(0.f,1.f);
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
    shootElapsed=1.8f;
}
void Warplane::initializeLife()
{
    life=1;
}
void Warplane::initializeSpeed()
{
    speed = 110.f;
}
void Warplane::refresh(float detalTime)
{
    limit+=detalTime;
    fire();
    if(isAlive())
        move(Direction*speed*detalTime);
}
void Warplane::fire() {
    if(limit>shootElapsed)
    {
        shootBullet();
        limit = 0.f;
    }
}
Plane* Warplane::clone()
{
    return new Warplane(*this);
}
void Warplane::playBombSound()
{
    music->playWarPlaneBomb();
}
void Warplane::shootBullet()
{
    Game::enemyBullet.push_back(new EnemyBullet(sf::Vector2f(getX(),getBottom())));
}
