#ifndef ENEMYBULLET_H
#define ENEMYBULLET_H


#include <stdlib.h>
#include <SFML/Graphics.hpp>
#include <Sprite.h>

class EnemyBullet
{
    public:
        EnemyBullet();
        virtual ~EnemyBullet();
        int moveBullet();
        int speed = 10;
        Sprite sprite;
    protected:
    private:
        sf::Texture texture;
};

#endif // ENEMYBULLET_H
