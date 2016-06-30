#ifndef SKY_H
#define SKY_H
#include<SFML/Graphics.hpp>
#include<unordered_set>
#include"Hero.h"
#include"Enemy.h"
class Sky{
public:
    Sky();
    sf::RenderWindow *window;
    sf::RenderWindow *win;

    void refresh();   c
    static int game_time;
    static int game_time2;
private:
    sf::Texture background;
    sf::Sprite sbackground;


};

#endif // SKY_H
