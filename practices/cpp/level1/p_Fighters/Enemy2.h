#ifndef ENEMY2_H
#define ENEMY2_H
#include<SFML/Graphics.hpp>
class Enemy2{
public:
    void build();
    void draw_myself();
    void move();
    sf::Texture enemy;
    static sf::Sprite senemy;
    int ex,ey=100;
    int heartlife;
};


#endif // ENEMY2_H
