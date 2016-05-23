#ifndef GAMESPRITE_H
#define GAMESPRITE_H
#include <SFML/Graphics.hpp>
#include "GameTexture.h"
#include <list>
class GameSprite
{
public:
    //~GameSprite();
   // static std::list<sf::Sprite>plane;
  //  static std::list<sf::Sprite>bullet;
    static std::vector<sf::Sprite>Hero;
    static std::vector<sf::Sprite>HeroBomb;

    static sf::Sprite HeroBullet;
    static sf::Sprite EnemyBullet;

    static sf::Sprite Copter;
    static sf::Sprite CopterHit;
    static std::vector<sf::Sprite>CopterBomb;

    static sf::Sprite Warplane;
    static std::vector<sf::Sprite>WarplaneBomb;

    static std::vector<sf::Sprite>Warship;
    static sf::Sprite WarshipHit;
    static std::vector<sf::Sprite>WarshipBomb;

    static std::vector<sf::Sprite>ufo;

    static sf::Sprite background;
    static sf::Sprite gameover;
    static void load();
};

#endif // GAMESPRITE_H
