
#include "Warplane.h"
#include "GameWindow.h"
#include "GameSprite.h"
#include "EnemyBullet.h"
#include "Game.h"
#include "SFML/Graphics.hpp"
#include "cmath"
sf::Vector2f Warplane::_iniPosition = sf::Vector2f(GameWindow::iniWidth,-43.f);
sf::Vector2f Warplane::_iniDirection =sf::Vector2f(0.f,1.f);
const float PI=acos(-1.0);
Warplane::Warplane(sf::Vector2f iniPosition,sf::Vector2f iniDirection)
{
    initializePlane(iniPosition,iniDirection);
}
void Warplane::initializeSprite()
{
    planeSprite.push_back(GameSprite::Warplane);
    for(auto& c:GameSprite::WarplaneBomb)
        planeSprite.push_back(c);
}
void Warplane::initializeScore()
{
    score = 100;
}
void Warplane::initializeShootElapsed()
{
    shootElapsed=1.8f;
}
void Warplane::initializeLife()
{
    life=1;
}
void Warplane::initializeSpeed()
{
    speed = 110.f;
}
void Warplane::refresh(float detalTime)
{
    limit+=detalTime;
    fire();
    if(isAlive())
        move(Direction*speed*detalTime);
}
void Warplane::fire() {
    if(limit>shootElapsed)
    {
        shootBullet();
        limit = 0.f;
    }
}
void Warplane::draw()
{
    window->draw(getSprite());
    //window->draw(collisonArea);
}
Plane* Warplane::clone()
{
    return new Warplane(*this);
}
Plane* Warplane::setCollisonArea()
{
    collisonArea.setPointCount(3);
    collisonArea.setPoint(0, sf::Vector2f(10, 17));
    collisonArea.setPoint(1, sf::Vector2f(31, 38));
    collisonArea.setPoint(2, sf::Vector2f(52, 17));
    collisonArea.setFillColor(sf::Color(140,98,251,100));
    return this;
}
void Warplane::initializeBullet()
{
    setBullet(new EnemyBullet);
}
void Warplane::playBombSound()
{
    music->playWarPlaneBomb();
}
void Warplane::shootBullet()
{
    Game::enemyBullet.push_back(bullet->clone()->setPosition(sf::Vector2f(getX(),getBottom()))->rotate(PI));
}
