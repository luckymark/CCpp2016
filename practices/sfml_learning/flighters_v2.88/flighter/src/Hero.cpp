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
void Hero::initializeShootType()
{
    shootType = 0;
}
void Hero::fire() {

    //printf("shoot!\n");
    shootBullet();
}
void Hero::intensifyFire()
{
    if(shootType<3)
        ++shootType;
}
void Hero::useSkill()
{
    //Game::isUseBomb=true;
}
void Hero::shootBullet()
{
    if(shootType == 0)
    {
        sf::Vector2f nowPosition = sf::Vector2f(getX()-3,getY());
        Game::heroBullet.push_back(bullet->clone()->setPosition(nowPosition));
    }
    else if(shootType == 1)
    {
        sf::Vector2f nowPositionLeft = sf::Vector2f(getLeft()+15,getY());
        sf::Vector2f nowPositionRight = sf::Vector2f(getRight()-22,getY());
        Game::heroBullet.push_back(bullet->clone()->setPosition(nowPositionLeft));
        Game::heroBullet.push_back(bullet->clone()->setPosition(nowPositionRight));
    }
    else if(shootType == 2)
    {
        std::vector<sf::Vector2f>nowposition;
        nowposition.push_back(sf::Vector2f(getLeft()+15,getY()));
        nowposition.push_back(sf::Vector2f(getX()-3,getY()));
        nowposition.push_back(sf::Vector2f(getRight()-22,getY()));
        for(auto c:nowposition)
            Game::heroBullet.push_back(bullet->clone()->setPosition(c));
    }
    else if(shootType == 3)
    {
        std::vector<sf::Vector2f>nowposition;
        float x0 = getLeft()+15,xn=getRight()-22;
        float dx = (xn-x0)/4.f;
        for(int i=0;i<5;i++)
            nowposition.push_back(sf::Vector2f(x0+i*dx,getY()));
        for(auto c:nowposition)
            Game::heroBullet.push_back(bullet->clone()->setPosition(c));
    }
    //printf("shoot\n");
    //Game::heroBullet.push_back(new HeroBullet(sf::Vector2f(getX(),getTop())));
}
void Hero::beHited(int _harm)
{
    _isBeHited=true;
    _flash=0.f;
    life-=_harm;
}
void Hero::refresh(float detalTime)
{
    sumChangeStatusTime+=detalTime;
    if(sumChangeStatusTime >= detalChangeStatusTime)
    {
        changeStatus();
        sumChangeStatusTime = 0.f;
    }
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
void Hero::initializeBullet()
{
    bullet = new HeroBullet();
    //printf("initail")
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
Plane* Hero::setCollisonArea()
{
    //collisonArea.setOrigin((getRight()-getLeft())/2.f,(getBottom()-getTop())/2.f);
    collisonArea.setPointCount(3);
    collisonArea.setPoint(0, sf::Vector2f(53, 5));
	collisonArea.setPoint(1, sf::Vector2f(24, 85));
	collisonArea.setPoint(2, sf::Vector2f(80, 85));
	collisonArea.setFillColor(sf::Color(255, 0, 0, 100));
	return this;
}
void Hero::draw()
{
    if(checkBeHited())
    {
        ++_flash;
        if(_flash > maxFlashTime)
        {
            window->draw(getSprite());
            window->draw(collisonArea);
            _flash = 0;
        }
    }
    else
    {
        window->draw(getSprite());
        window->draw(collisonArea);
    }
}
