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
Plane* EnemyBullet::clone()
{
    return new EnemyBullet(*this);
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
