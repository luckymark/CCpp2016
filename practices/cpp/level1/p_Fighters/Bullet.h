#ifndef BULLET_H
#define BULLET_H
#include"Thing.h"
#include<SFML/Graphics.hpp>
class Bullet{
public:
    Bullet(){};
    void build();
    void draw_myself();
    sf::Texture bullet;
    static sf::Sprite sbullet;
    int heartlife;
    void move();
    static int bullet_life;
    int a,b;

};

#endif // BULLET_H
