#include "HeroBullet.h"
#include "GameSprite.h"
#include "Game.h"
HeroBullet::HeroBullet(const sf::Vector2f& iniPosition,const sf::Vector2f& iniDirection)
{
    initializePlane(iniPosition,iniDirection);
}
void HeroBullet::refresh(float detalTime)
{
    //float detalTime=clock->restart().asSeconds();
    move(Direction*speed*detalTime);
    //printf("dx=%f dy=%f\n",position.x,position.y);
    //window->draw(getSprite());
}
void HeroBullet::draw()
{
    window->draw(getSprite());
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
void HeroBullet::initializeShootElapsed()
{

}
void HeroBullet::initializeLife()
{

}
void HeroBullet::playBombSound()
{

}
