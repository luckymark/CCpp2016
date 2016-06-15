#include "Bullet.h"
#include "Sprites.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

Bullet::Bullet(int x,int y,int vx,int vy)
{
    BulletSprite=Sprites::bullet;
    this->x=x;
    this->y=y;
    this->vx=vx;
    this->vy=vy;
    BulletSprite.setPosition(x,y);
}

void Bullet::move()
{
    x=x+vx;
    y=y+vy;
    BulletSprite.setPosition(x,y);
}

sf::Sprite Bullet::GetSprite()
{
    return BulletSprite;
}

bool Bullet::IsOut()
{
    if (y>600 || y<0)
    {
         return true;
    }
    return false;
}
