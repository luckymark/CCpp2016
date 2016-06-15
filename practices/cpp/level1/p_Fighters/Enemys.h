#ifndef ENEMYS_H
#define ENEMYS_H
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <list>
#include "EnemyPlane.h"
#include "Bullet.h"
#include "Hero.h"
#include "Sound.h"

class Enemys
{
private:
    int BasicCreatFrequence;
    int CreatFrequency;
    int CreatCounter;
    int score;
    sf::Text text;
public:
    Enemys();
    static std::list<EnemyPlane> EnemyPlanes;
    static std::list<Bullet> EnemyBullets;
    void CreatCounterProgress();
    void CreatNewEnemy(int random_number);
    void EnemyPlanesFire();
    void EnemyPlanesMove();
    void EnemyPlanesClear();
    void EnemyPlanesHit();
    void EnemyPlanesResetSprite();
    void BulletsMove();
    void BulletsClear();
    void LevelControl();
    void ResetText();
    void show(sf::RenderWindow& window);
    void turn(sf::RenderWindow& window);
};

#endif // ENEMYS_H
