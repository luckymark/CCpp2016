#include "HeroBullet.h"
#include "GameSprite.h"
#include "Game.h"
HeroBullet::HeroBullet(const sf::Vector2f& iniPosition,const sf::Vector2f& iniDirection)
{
    initializePlane(iniPosition,iniDirection);
}
void HeroBullet::refresh(float detalTime)
{
    move(Direction*speed*detalTime);
}
void HeroBullet::draw()
{
    window->draw(getSprite());
    //window->draw(collisonArea);
}
void HeroBullet::appendToGame()
{
    Game::heroBullet.push_back(this);
}
void HeroBullet::initializeSpeed()
{
    speed = 800.f;
}
void HeroBullet::initializeSprite()
{
    planeSprite.push_back(GameSprite::HeroBullet);
}
Plane* HeroBullet::clone()
{
    return new HeroBullet(*this);
}
Plane* HeroBullet::setCollisonArea()
{
    collisonArea.setPointCount(4);
    collisonArea.setPoint(0, sf::Vector2f(2, 0));
	collisonArea.setPoint(1, sf::Vector2f(2, 20));
	collisonArea.setPoint(2, sf::Vector2f(7, 20));
	collisonArea.setPoint(3, sf::Vector2f(7, 0));
	collisonArea.setFillColor(sf::Color(255, 0, 0, 100));
	return this;
}
sf::Color HeroBullet::getLightColor()
{
    return sf::Color::Red;
}
void HeroBullet::initializeShootElapsed()
{

}
void HeroBullet::initializeLife()
{

}
void HeroBullet::playBombSound()
{

}
