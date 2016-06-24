//
// Created by wxdao on 16-5-23.
//

#ifndef EVERFIGHTER_BATTLESCENE_H
#define EVERFIGHTER_BATTLESCENE_H


#include <SFML/Graphics.hpp>
#include <memory>
#include <codecvt>
#include <SFML/Audio.hpp>
#include "Scene.h"
#include "SessionService.h"
#include "PlayerFighterObject.h"
#include "BulletObject.h"
#include "EnemyFighterObject.h"

class BattleScene : public Scene {
    struct Bullet {
        BulletObject obj;
        bool hostile;
    };

    struct Enemy {
        EnemyFighterObject obj;
        int health;
        int totalHealth;
    };

    struct DownEnemy {
        sf::Sprite sprite;
        sf::Time timer;
        int stage;
        int enemyType;
    };

    sf::Sprite background;

    float enemySpeedRatio;
    int score;
    int level;
    sf::Text scoreText;
    sf::Text loadingText;
    sf::Text timerText;
    sf::Text livesText;
    bool loading;
    PlayerFighterObject playerObject;
    std::vector<Bullet> bullets;
    std::vector<Enemy> enemies;
    std::vector<DownEnemy> downEnemies;
    sf::Time lastShoot;
    sf::Time lastEShoot;
    sf::Time lastSpawn;
    sf::Time evolveTimer;
    std::random_device rd;
    bool shoot;
    int totalHealth;
    int health;
    int lives;
    int shootType;

    bool pause = false;

    bool down;
    int downStage;
    sf::Time downTimer;
    sf::Sprite downSprite;

    sf::Sound battleSound;
    sf::Sound hitSound;
    sf::Sound exp1Sound;
    sf::Sound recoverSound;
    sf::Sound evolveSound;
    sf::Sound beepSound;

    SessionService *sessionService = sessionService->getInstance();

    std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;

    unsigned windowWidth = getContext().getWindow().getSize().x;
    unsigned windowHeight = getContext().getWindow().getSize().y;
protected:
    virtual void init();

    virtual void destroy() {
        battleSound.stop();
    }

public:
    BattleScene(SceneContext *context, int options) : Scene(context, options) { }

    virtual void handleEvent(sf::Event event);

    virtual void update(sf::Time);

    virtual void draw();
};


#endif //EVERFIGHTER_BATTLESCENE_H
