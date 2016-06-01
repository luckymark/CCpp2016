#include "Warship.h"
#include "GameWindow.h"
#include "GameSprite.h"
#include <SFML/Graphics.hpp>
#include "EnemyBullet.h"
#include <cmath>
#include <Game.h>
sf::Vector2f Warship::_iniPosition = sf::Vector2f(GameWindow::iniWidth,-258.f);
sf::Vector2f Warship::_iniDirection =sf::Vector2f(0.f,1.f);
bool Warship::isPlayFlyingSound=false;
const float PI = acos(-1.0);
Warship::Warship(sf::Vector2f iniPosition,sf::Vector2f iniDirection)
{
    initializePlane(iniPosition,iniDirection);
}
void Warship::initializeSprite()
{
    planeSprite = GameSprite::Warship;
    planeSprite.push_back(GameSprite::WarshipHit);
    for(auto& c:GameSprite::WarshipBomb)
        planeSprite.push_back(c);
}
void Warship::initializeShootElapsed()
{
    shootElapsed=3.f;
}
void Warship::initializeLife()
{
    life=10;
}
void Warship::initializeSpeed()
{
    speed = 60.f;
}
void Warship::refresh(float detalTime)
{
    limit+=detalTime;
    sumChangeStatusTime+=detalTime;
    fire();
    if(isAlive())
    {
        if(_isBeHited)
        {
            status = 2;
            _isBeHited = false;
        }
        else if(sumChangeStatusTime > detalChangeStatusTime)
        {
            changeStatus();
            sumChangeStatusTime = 0.f;
        }
    }
    move(Direction*speed*detalTime);
}
void Warship::initializeBullet()
{
    setBullet(new EnemyBullet);
}
Plane* Warship::setCollisonArea()
{
    collisonArea.setPointCount(8);
    collisonArea.setPoint(0, sf::Vector2f(26, 130));
    collisonArea.setPoint(1, sf::Vector2f(26, 214));
    collisonArea.setPoint(2, sf::Vector2f(40, 230));
    collisonArea.setPoint(3, sf::Vector2f(130, 230));
    collisonArea.setPoint(4, sf::Vector2f(144, 214));
    collisonArea.setPoint(5, sf::Vector2f(144, 130));
    collisonArea.setPoint(6, sf::Vector2f(135, 120));
    collisonArea.setPoint(7, sf::Vector2f(35, 120));
    collisonArea.setFillColor(sf::Color(140,98,251,100));
    return this;
}
void Warship::fire() {
    if(limit>shootElapsed)
    {
        shootBullet();
        limit=0.f;
    }
}
void Warship::shootBullet()
{
    for(int i=0;i<5;i++)
    {
        float angle = (160+i*10)/180.f*PI;
        Game::enemyBullet.push_back(bullet->clone()->setPosition(sf::Vector2f(getX(),getBottom()))->rotate(angle));
    }
}
Plane* Warship::clone()
{
    return new Warship(*this);
}
void Warship::changeStatus()
{
    switch(status)
    {
        case 0:
            ++status;
            break;
        case 1:
            --status;
            break;
        case 2:
            status = 0;
            break;
    }
}
void Warship::draw()
{

    window->draw(getSprite());

}
void Warship::playFlyingSound()
{
    //printf("play!\n");
    if(isAlive())
        music->playWarshipFlying();
}
void Warship::playBombSound()
{
    music->playWarshipBomb();
}
