
#ifndef _GAME_H
#define _GAME_H
#include "GameWindow.h"
#include "BackGround.h"
#include "Plane.h"
#include "GameMusic.h"
#include "Shader.h"
#include <SFML/Graphics.hpp>
#include <list>
#include "GameText.h"
class Game {
public:
    static std::list<Plane*>bombingPlane;

    static std::vector<Plane*>originEnemyPlane;

    static std::vector<Plane*>originUfo;

    static std::list<Plane*>existEnemyPlane;

    static std::list<Plane*>heroBullet;

    static std::list<Plane*>enemyBullet;

    static std::list<Plane*>existUfo;

    static void getBomb();

    static bool isPlaying;

    static bool isExitGame;

    void exitGame();

    void useBomb();

    void initializeGame();

    void GameStart();

    void GameExit();

    void GameOver();

    void restartGame();

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

    void loadText();

    void loadEnemyFlighter();

    void loadUfo();

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

    void loadLightShader();

    void drawLight(const sf::Vector2f& lightPosition,sf::Color,float lightAttenuation);

    void creatUfo();

    void getRandomCreatUfoTime();

    void checkHeroAlive();

    void checkHeroBulletAndEnemyCollision();

    void checkHeroAndUfoCollision();

    void checkEnemyBulletAndHeroCollision();

    void checkEnemyAndHeroCollision();

    void kill_a_plane(Plane*);

    void clearScreen();
protected:
    Game();
private:
    static Game* _instance;
    GameWindow* window;
    BackGround* background;
    Plane* hero;
    GameMusic* music;
    Shader* shader;
    sf::Texture lightTexture;
    sf::Sprite lightSprite;
    sf::Shader* lightShader;
    sf::RenderStates lightRenderState;
    sf::RenderTexture lightRenderTexture;
    //sf::Clock* drawClock;
    sf::Clock* gameClock;
    sf::Event event;
    GameText* text;
    static int sumBomb;
    int score = 0;
    bool isBombing = false;


    float tick;
    float detalPlayFlyingSoundTime;
    float detalHeroFire;
    float detalFlash;
    float detalMakeEnemy;
    float detalDraw;
    float detalMakeUfo;
    float bombTime;

    float sumPlayFlyingSound;
    float sumHeroFire;
    float sumFlash;
    float sumMakeEnemy;
    float sumDraw;
    float sumMakeUfo;
    float sumBombingTime;
};

#endif //_GAME_H
