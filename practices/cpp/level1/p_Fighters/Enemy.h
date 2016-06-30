#ifndef ENEMY_H
#define ENEMY_H
#include"Plane.h"
#include<SFML/Graphics.hpp>

class Enemy{
public:
    void build();
    void draw_myself();
    void move();
    sf::Texture enemy;
    static sf::Sprite senemy;
    int ex,ey=0;
    int heartlife=0;
private:

};


#endif // ENEMY_H
