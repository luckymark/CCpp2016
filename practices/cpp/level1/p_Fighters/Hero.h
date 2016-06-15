#ifndef HERO_H
#define HERO_H
#include <list>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include "Bullet.h"
#include "Enemys.h"
#include "Font.h"

class Hero
{
public:
    Hero();
    void MoveLeft();
    void MoveRight();
    void MoveUp();
    void MoveDown();
    void show(sf::RenderWindow& window);
    void ResetText();
    void fire();
    void BulletClear();
    void BulletMove();
    void hit();
    void IncreaseScore(int get_score);
    void DecreaseHealth();
    void turn(sf::RenderWindow& window);
    int GetScore();
    int GetHealth();
    static std::list <Bullet> HeroBullets;
private:
    sf::Sprite hero_sprite;
    sf::Text text;
    int score;
    int level;
    int health;
    int move_dis;
    int x,y;
};

#endif // HERO_H
