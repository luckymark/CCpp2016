#ifndef ENEMY3_H
#define ENEMY3_H
#include<SFML/Graphics.hpp>

class Enemy3{
public:
    void build();
    void draw_myself();
    void move();
    sf::Texture enemy;
    static sf::Sprite senemy;
    int ex,ey=0;
    int heartlife;
};


#endif // ENEMY3_H
