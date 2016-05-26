#include "Hero.h"
#include <SFML/Graphics.hpp>
#include "GameSprite.h"
#include "Game.h"
#include "GameWindow.h"
#include "HeroBullet.h"
Hero* Hero::_instance=0;
Hero::Hero(const sf::Vector2f& iniPosition)
{
    initializePlane(iniPosition);
    maxFlashTime = 5;
}
Hero* Hero::instance(const sf::Vector2f& u)
{
    if(_instance==0)
        _instance = new Hero(u);
    return _instance;
}
void Hero::fire() {

    //printf("shoot!\n");
    shootBullet();
}
void Hero::shootBullet()
{
    Game::heroBullet.push_back(new HeroBullet(sf::Vector2f(getX(),getTop())));
}
void Hero::beHited()
{
    _isBeHited=true;
    _flash=0.f;
    --life;
}
void Hero::refresh(float detalTime)
{
    changeStatus();
    //window->draw(getSprite());
}
float Hero::getBottom()
{
    return Plane::getBottom()-25.f;
}
void Hero::changeStatus()
{
    switch(status)
    {
        case 0:
            status=1;
            break;
        case 1:
            status=0;
            break;
    }
}
void Hero::appendToGame()
{
    //Game::plane.push_back(this);
}
void Hero::initializeSprite()
{
    planeSprite=GameSprite::Hero;
    for(auto& c:GameSprite::HeroBomb)
        planeSprite.push_back(c);
}
void Hero::initializeSpeed()
{
    speed = 400.f;
}
void Hero::initializeShootElapsed()
{
    //shootElapsed=0.33f;
}
void Hero::initializeLife()
{
    life = 3;
}
Plane* Hero::clone()
{
    return new Hero(*this);
}
void Hero::playBombSound()
{
    music->playHeroBomb();
}
void Hero::draw()
{
    if(checkBeHited())
    {
        ++_flash;
        if(_flash > maxFlashTime)
        {
            window->draw(getSprite());
            _flash = 0;
        }
    }
    else window->draw(getSprite());
}
