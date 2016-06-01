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
    Game::existUfo.push_back(this);
}
void ShootUfo::getSkill(Plane*)
{

}
void ShootUfo::initializeSpeed()
{
    speed = 100.f;
}
void ShootUfo::initializeSprite()
{
    planeSprite.push_back(GameSprite::ufo[0]);
}
Plane* ShootUfo::clone()
{
    return new ShootUfo(*this);
}
sf::Color ShootUfo::getLightColor()
{
    return sf::Color::Red;
}
Plane* ShootUfo::setCollisonArea()
{
    collisonArea.setPointCount(4);
    collisonArea.setPoint(0, sf::Vector2f(15, 65));
    collisonArea.setPoint(1, sf::Vector2f(20, 85));
    collisonArea.setPoint(2, sf::Vector2f(54, 75));
    collisonArea.setPoint(3, sf::Vector2f(49, 55));
    return this;
}
void ShootUfo::initializeShootElapsed()
{

}
void ShootUfo::initializeLife()
{

}
void ShootUfo::playBombSound()
{
    music ->playGetWeapon();
}
