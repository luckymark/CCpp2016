#ifndef SPRITE_H
#define SPRITE_H

#include <iostream>

#include <SFML/Graphics.hpp>

class Sprite : public sf::Sprite
{
    public:
        Sprite();
        virtual ~Sprite();
        bool intersects(Sprite other);
    protected:
    private:
};

#endif // SPRITE_H
