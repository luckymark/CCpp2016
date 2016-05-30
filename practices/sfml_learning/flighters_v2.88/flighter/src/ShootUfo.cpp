#include "ShootUfo.h"
#include "Game.h"
#include "GameSprite.h"
ShootUfo::ShootUfo(const sf::Vector2f& iniPosition,const sf::Vector2f& iniDirection)
{
    initializePlane(iniPosition,iniDirection);
}
void ShootUfo::refresh(float detalTime)
{
    move(Direction*speed*detalTime);
}
void ShootUfo::draw()
{
    window->draw(getSprite());
}
void ShootUfo::appendToGame()
{
    Game::ufo.push_back(this);
}
void ShootUfo::getSkill(Plane*)
{

}
void ShootUfo::initializeSpeed()
{
    speed = 200.f;
}
void ShootUfo::initializeSprite()
{
    planeSprite.push_back(GameSprite::ufo[0]);
}
Plane* ShootUfo::clone()
{
    return new ShootUfo(*this);
}
void ShootUfo::initializeShootElapsed()
{

}
void ShootUfo::initializeLife()
{

}
void ShootUfo::playBombSound()
{

}
