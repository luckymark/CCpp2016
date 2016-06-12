#ifndef BULLET_H
#define BULLET_H

#include<SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>


#include <SFML/Config.hpp>
#include <SFML/Main.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include<Sprite.h>
class Bullet
{
    public:
        Bullet();
        Bullet(int x,int y);
        virtual ~Bullet();
        Sprite sprite;
        int moveBullet();
        int speed = -10;
    protected:

    private:
        sf::Texture texture;
};

#endif // BULLET_H
