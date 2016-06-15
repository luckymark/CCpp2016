#ifndef ENEMYPLANE_H
#define ENEMYPLANE_H
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

class EnemyPlane
{
private:
    double vx,vy,x,y;
    int health;
    int flag;
    int FireCounter;
    int FireFrequence;
    int ResetCounter;
    int ResetFrequence;
    bool DestoryFlag;
    sf::Sprite EnemyPlaneSprite;
public:
    EnemyPlane(int flag);
    bool fire();
    void move();
    void DecreaseHealth();
    void ResetSprite();
    int GetHealth();
    int GetFlag();
    bool IsOut();
    bool IsDestoryed();
    sf::Sprite GetSprite();
};

#endif // ENEMYPLANE_H
