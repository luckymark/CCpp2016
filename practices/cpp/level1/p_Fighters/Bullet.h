#ifndef BULLET_H
#define BULLET_H
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

class Bullet
{
private:
    int x,y,vx,vy;
    sf::Sprite BulletSprite;
public:
    Bullet(int x,int y,int vx,int vy);
    void move();
    bool IsOut();
    sf::Sprite GetSprite();
};

#endif // BULLET_H
