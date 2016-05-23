
#include "Plane.h"

float Plane::getLeft()
{
    return position.x;
}
float Plane::getTop()
{
    return position.y;
}
float Plane::getRight()
{
    return position.x+planeSprite[0].getGlobalBounds().width;
}
float Plane::getBottom()
{
    return position.y+planeSprite[0].getGlobalBounds().height;
}
float Plane::getX()
{
    return (getLeft()+getRight())/2.f;
}
float Plane::getY()
{
    return (getTop()+getBottom())/2.f;
}
void Plane::move(const float& offsetX,const float& offsetY)
{
    position.x+=offsetX;
    position.y+=offsetY;

    for(auto& sp:planeSprite)
        sp.move(offsetX,offsetY);

}
void Plane::move(const sf::Vector2f offset)
{
    move(offset.x,offset.y);
}
sf::Sprite& Plane::getSprite()
{
    //planeSprite[status].setPosition(position);
    return planeSprite[status];
}
bool Plane::isAlive()
{
    return (life > 0);
}
bool Plane::isBombing()
{
    ++status;
    int u=planeSprite.size();
    if(status<u)
    {
        //BombSsound
        ++status;
    }
    return (status<u);
}
void Plane::setDirection(const sf::Vector2f& u)
{
    Direction=u;
}
void Plane::setPosition(const sf::Vector2f& u)
{
    position=u;
    for(auto& itp:planeSprite)
        itp.setPosition(u);
}
sf::Vector2f Plane::getDirection()
{
    return Direction;
}
sf::Vector2f Plane::getPosition()
{
    return position;
}
float Plane::getSpeed()
{
    return speed;
}
void Plane::setSpeed(const float& u)
{
    speed=u;
}
bool Plane::intersects(const sf::Sprite& rhs)
{
    return getSprite().getGlobalBounds().intersects(rhs.getGlobalBounds());
}
bool Plane::isInside()
{
    return ((getDirection().x < 0.f && getLeft() > 0.f) || (getDirection().x > 0.f && getRight() < GameWindow::windowWidth)
       || (getDirection().y < 0.f && getTop() > 0.f ) || (getDirection().y > 0.f && getBottom() < GameWindow::windowHeight));
}
void Plane::moveLeft(const float& detalTime)
{
    if(getLeft()>0.f && status < 2)
        move(-detalTime*speed,0.f);
}
void Plane::moveRight(const float& detalTime)
{
    if(getRight() < GameWindow::windowWidth && status < 2)
        move(detalTime*speed,0.f);
}
void Plane::moveUp(const float& detalTime)
{
    if(getTop()>0.f && status < 2)
        move(0.f,-detalTime*speed);
}
void Plane::moveDown(const float& detalTime)
{
    if(getBottom() < GameWindow::windowHeight && status < 2)
        move(0.f,detalTime*speed);
}
void Plane::initializePlane(const sf::Vector2f& nowPosition,const sf::Vector2f& nowDirection)
{
    initializeWindow();
    initializeSprite();
    setPosition(nowPosition);
    setDirection(nowDirection);
    initializeLife();
    initializeStatus();
    initializeSpeed();
    initializeShootElapsed();
    initializeTime();
}
void Plane::initializeTime()
{
    //clock=new sf::Clock;
}
void Plane::initializeWindow()
{
    window=GameWindow::instance();
}
void Plane::setLife(int u)
{
    life=u;
}
void Plane::initializeStatus()
{
    status = 0;
}
void Plane::setStatus(int u)
{
    status = u;
}
int Plane::getLife()
{
    return life;
}
int Plane::getStatus()
{
    return status;
}
void Plane::setShootElapsed(int u)
{
    shootElapsed = u;
}
int Plane::getShootElapsed()
{
    return shootElapsed;
}
void Plane::draw()
{
    window->draw(getSprite());
}
void Plane::shootBullet()
{

}
void Plane::beHited()
{
    --life;
    isBeHited=true;
}
void Plane::fire()
{

}
void Plane::appendToGame()
{

}
