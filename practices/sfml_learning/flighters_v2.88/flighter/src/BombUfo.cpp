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
    Game::existUfo.push_back(this);
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
Plane* BombUfo::setCollisonArea()
{
    collisonArea.setPointCount(4);
    collisonArea.setPoint(0, sf::Vector2f(10, 72));
    collisonArea.setPoint(1, sf::Vector2f(2, 90));
    collisonArea.setPoint(2, sf::Vector2f(45, 105));
    collisonArea.setPoint(3, sf::Vector2f(53, 87));
    collisonArea.setFillColor(sf::Color(255, 0, 0, 100));
    return this;
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

