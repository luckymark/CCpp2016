
#ifndef _GAME_H
#define _GAME_H
#include "GameWindow.h"
#include "BackGround.h"
#include "Plane.h"
#include "GameMusic.h"
#include "Shader.h"
#include <list>
class Game {
public:
    static std::list<Plane*>bombingPlane;

    static std::vector<Plane*>originEnemyPlane;

    static std::list<Plane*>existEnemyPlane;

    static std::list<Plane*>heroBullet;

    static std::list<Plane*>enemyBullet;

    void initializeGame();

    void GameStart();

    void GameExit();

    void GameOver();

    static Game* instance();

    void checkCollison();

    void getKeyBoard(float);

    void refresh(float);

    void loadBGM();

    void loadWindow();

    void loadTexture();

    void loadSprite();

    void loadBackGround();

    void loadHero();

    void loadEnemyFlighter();

    void loadTime();

    void loadShader();

    void creatEnemy();

    sf::Vector2f getRandomPosition(Plane*);

    sf::Vector2f getRandomDirection();

    int getRandomType();

    void draw();

    void checkInside();

    void doPlayFlyingSound();

    void heroFlash();

    void getRandomCreatEnemyTime();

    void updateSumTime();
protected:
    Game();
private:
    static Game* _instance;
    GameWindow* window;
    BackGround* background;
    Plane* hero;
    GameMusic* music;
    Shader* shader;
    //sf::Clock* drawClock;
    sf::Clock* gameClock;
    float tick;
    float detalPlayFlyingSoundTime;
    float detalHeroFire;
    float detalFlash;
    float detalMakeEnemy;
    float detalDraw;

    float sumPlayFlyingSound;
    float sumHeroFire;
    float sumFlash;
    float sumMakeEnemy;
    float sumDraw;
};

#endif //_GAME_H
