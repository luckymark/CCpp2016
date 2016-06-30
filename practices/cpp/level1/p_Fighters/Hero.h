#ifndef HERO_H
#define HERO_H
#include"Plane.h"
#include<SFML/Graphics.hpp>
class Hero:public Plane
{
public:
    void build();
    void move();
    void draw_myself();
    sf::Texture hero;
   static sf::Sprite shero;
    static int hx,hy,heartlife;
private:




};

#endif // HERO_#include"Plane.h"H
