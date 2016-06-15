#ifndef SPRITES_H
#define SPRITES_H
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

class Sprites
{
public:
    static sf::Texture shoot;
    static sf::Sprite hero;
    static sf::Sprite bullet;
    static sf::Sprite enemy1;
    static sf::Sprite enemy2;
    static sf::Sprite enemy2_hit;
    static sf::Sprite enemy3_n2;
    static sf::Sprite enemy3_n1;
    static sf::Sprite enemy3_hit;
    static sf::Sprite enemy1_down1;
    static sf::Sprite enemy1_down2;
    static sf::Sprite enemy1_down3;
    static sf::Sprite enemy1_down4;
    static sf::Sprite enemy2_down1;
    static sf::Sprite enemy2_down2;
    static sf::Sprite enemy2_down3;
    static sf::Sprite enemy2_down4;
    static sf::Sprite enemy3_down1;
    static sf::Sprite enemy3_down2;
    static sf::Sprite enemy3_down3;
    static sf::Sprite enemy3_down4;
    static sf::Sprite enemy3_down5;
    static sf::Sprite enemy3_down6;
    static void LoadSprites();
};

#endif // SPRITES_H
