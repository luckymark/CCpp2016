#ifndef PLANE_H
#define PLANE_H
#include<SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>


#include <SFML/Config.hpp>
#include <SFML/Main.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include<Sprite.h>
//#include<Bullet.h>


class Plane
{
    public:

        Plane();
        virtual ~Plane();
        Sprite sprite;
        void movePlane(sf::Event event);
        sf::Texture texture;
        void hited();
        void xu1s();
        int getLife();
    protected:

    private:
        int life = 3;
};

#endif // PLANE_H
