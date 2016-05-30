#include "BombUfo.h"
#include "Game.h"
#include "GameSprite.h"
BombUfo::BombUfo(const sf::Vector2f& iniPosition,const sf::Vector2f& iniDirection)
{
    initializePlane(iniPosition,iniDirection);
}
void BombUfo::refresh(float detalTime)
{
    move(Direction*speed*detalTime);
}
void BombUfo::draw()
{
    window->draw(getSprite());
}
void BombUfo::appendToGame()
{
    Game::ufo.push_back(this);
}
void BombUfo::getSkill(Plane*)
{

}
void BombUfo::initializeSpeed()
{
    speed = 200.f;
}
void BombUfo::initializeSprite()
{
    planeSprite.push_back(GameSprite::ufo[1]);
}
Plane* BombUfo::clone()
{
    return new BombUfo(*this);
}
void BombUfo::initializeShootElapsed()
{

}
void BombUfo::initializeLife()
{

}
void BombUfo::playBombSound()
{

}

