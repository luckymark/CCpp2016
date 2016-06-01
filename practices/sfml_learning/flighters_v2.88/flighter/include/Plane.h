#ifndef _PLANE_H
#define _PLANE_H
#include <SFML/Graphics.hpp>
#include "GameWindow.h"
#include "GameMusic.h"
#include "Shader.h"
class Plane {
public:
    static void initializeAngle();

    virtual float getLeft();

    virtual float getRight();

    virtual float getX();

    virtual float getY();

    virtual void move(const float&,const float&);

    virtual void move(const sf::Vector2f);

    virtual void moveLeft(const float&);

    virtual void moveRight(const float&);

    virtual void moveUp(const float&);

    virtual void moveDown(const float&);

    virtual void fire() ;

    virtual bool isAlive();

    virtual bool isBombing(float);

    virtual void beHited(int) ;

    virtual sf::Sprite& getSprite();

    virtual float getBottom();

    virtual float getTop();

    virtual bool intersects(const sf::FloatRect&) ;

    virtual Plane* setDirection(const sf::Vector2f&);

    virtual void setSpeed(const float&);

    virtual sf::Vector2f getDirection();

    virtual sf::Vector2f getPosition();

    virtual Plane* setPosition(const sf::Vector2f& u);

    virtual bool isInside();

    virtual float getSpeed();

    virtual void appendToGame();

    virtual void shootBullet() ;

    virtual void initializePlane(const sf::Vector2f&nowPosition = sf::Vector2f(0.f,0.f),const sf::Vector2f&nowDirection = sf::Vector2f(0,0));

    virtual void initializeWindow();

    virtual void initializeStatus();

    virtual void setLife(int);

    virtual void setStatus(int);

    virtual int getLife();

    virtual int getStatus();

    virtual void initializeSound();

    virtual void setShootElapsed(int);

    virtual int getShootElapsed();

    virtual void initializeTime();

    virtual void draw();

    virtual void playFlyingSound();

    virtual bool checkBeHited();

    virtual void recoverNormal();

    virtual void initializeHarm();

    virtual void initializeBullet();

    virtual void initializeShader();

    virtual Plane* setBullet(Plane*);

    virtual Plane* getBullet();

    virtual Plane* setHarm(int);

    virtual int getHarm();

    virtual void getSkill(Plane*);

    virtual Plane* setCollisonArea();

    virtual Plane* rotate(float);

    virtual sf::FloatRect getCollisionArea();

    virtual sf::Color getLightColor();

    virtual void refresh(float) = 0;

    virtual void initializeSpeed() = 0;

    virtual void initializeShootElapsed() = 0;

    virtual void initializeSprite() = 0;

    virtual void initializeLife() = 0;

    virtual Plane* clone() = 0;

    virtual void playBombSound() = 0;
protected:
    GameWindow* window;
    std::vector<sf::Sprite>planeSprite;
    bool _isBeHited=false;
    int status,life,harm;
    float speed;
    float shootElapsed,limit,detalChangeStatusTime,sumChangeStatusTime;
    Plane* bullet;
    Shader* shader;
    sf::ConvexShape collisonArea;
    sf::Vector2f position,Direction;
    GameMusic* music;
};

#endif //_PLANE_H
