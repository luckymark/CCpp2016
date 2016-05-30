#include "EnemyBullet.h"
#include "GameSprite.h"
#include "Game.h"
EnemyBullet::EnemyBullet(const sf::Vector2f& iniPosition,const sf::Vector2f& iniDirection)
{
    initializePlane(iniPosition,iniDirection);
}
void EnemyBullet::refresh(float detalTime)
{
    move(Direction*speed*detalTime);
}
void EnemyBullet::draw()
{
    window->draw(getSprite());
    window->draw(collisonArea);
}
void EnemyBullet::appendToGame()
{
    Game::enemyBullet.push_back(this);
}
void EnemyBullet::initializeSpeed()
{
    speed = 400.f;
}
void EnemyBullet::initializeSprite()
{
    planeSprite.push_back(GameSprite::EnemyBullet);
}
Plane* EnemyBullet::setCollisonArea()
{
    collisonArea.setPointCount(4);
    collisonArea.setPoint(0, sf::Vector2f(2, 0));
	collisonArea.setPoint(1, sf::Vector2f(2, 20));
	collisonArea.setPoint(2, sf::Vector2f(7, 20));
	collisonArea.setPoint(3, sf::Vector2f(7, 0));
	collisonArea.setFillColor(sf::Color(255, 0, 0, 100));
	return this;
}
Plane* EnemyBullet::clone()
{
    return new EnemyBullet(*this);
}
sf::Color EnemyBullet::getLightColor()
{
    return sf::Color::Blue;
}
void EnemyBullet::initializeShootElapsed()
{

}
void EnemyBullet::initializeLife()
{

}
void EnemyBullet::playBombSound()
{

}
