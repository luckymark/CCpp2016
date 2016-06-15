//
// Created by wxdao on 16-5-23.
//

#include "BattleScene.h"
#include "ShootTexturePack.h"
#include "ResourceLoader.h"
#include "TextScene.h"

void BattleScene::init() {
    sf::Color textColor = sf::Color::Blue;
    textColor.a = 128;

    scoreText.setFont(ResourceLoader::getInstance()->loadFont("res/fonts/shscn-el.otf"));
    scoreText.setColor(textColor);
    scoreText.setStyle(sf::Text::Bold);
    scoreText.setCharacterSize(15);
    scoreText.setPosition(3, 3);

    timerText.setFont(ResourceLoader::getInstance()->loadFont("res/fonts/shscn-el.otf"));
    timerText.setColor(textColor);
    timerText.setStyle(sf::Text::Bold);
    timerText.setCharacterSize(15);
    timerText.setPosition(3, 30);

    livesText.setFont(ResourceLoader::getInstance()->loadFont("res/fonts/AndroidEmoji.ttf"));
    livesText.setColor(textColor);
    livesText.setStyle(sf::Text::Bold);
    livesText.setCharacterSize(15);
    livesText.setPosition(3, 57);

    sf::Texture &texture = ResourceLoader::getInstance()->loadTexture("res/textures/background.png");
    texture.setRepeated(true);
    background.setTexture(texture);
    background.setTextureRect(sf::IntRect(0, 0, windowWidth, windowHeight));

    battleSound.setBuffer(ResourceLoader::getInstance()->loadSound("res/sound/battle.ogg"));
    battleSound.setLoop(true);
    hitSound.setBuffer(ResourceLoader::getInstance()->loadSound("res/sound/hit.ogg"));
    hitSound.setVolume(30);
    exp1Sound.setBuffer(ResourceLoader::getInstance()->loadSound("res/sound/exp1.ogg"));
    recoverSound.setBuffer(ResourceLoader::getInstance()->loadSound("res/sound/recover.ogg"));
    evolveSound.setBuffer(ResourceLoader::getInstance()->loadSound("res/sound/evolve.ogg"));
    beepSound.setBuffer(ResourceLoader::getInstance()->loadSound("res/sound/beep.ogg"));

    playerObject.setWindowSize(windowWidth, windowHeight);
    playerObject.init();
    playerObject.setPosition(windowWidth / 2.f, windowHeight - 100);
    lastShoot = sf::seconds(0);
    lastSpawn = sf::seconds(0);
    lastEShoot = sf::seconds(0);
    evolveTimer = sf::seconds(0);
    shoot = false;

    enemySpeedRatio = 1;
    totalHealth = health = sessionService->getInitialHealth();
    score = 0;
    level = 1;
    lives = sessionService->getMaxLives();
    down = false;
    downTimer = sf::seconds(0);

    shootType = sessionService->getShootingType();

    pause = false;

    loading = false;
    battleSound.play();
}

void BattleScene::handleEvent(sf::Event event) {
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Space) {
            shoot = !shoot;
            beepSound.play();
        }
        if (event.key.code == sf::Keyboard::Escape) {
            pause = !pause;
        }
    }
}

void BattleScene::update(sf::Time time) {
    if (pause) {

    } else {
        if (!down) {
            playerObject.update(time);
        }

        lastShoot += time;
        lastSpawn += time;
        lastEShoot += time;
        evolveTimer += time;

        if (lastShoot.asSeconds() >= 0.2 * std::exp(-0.05f * (level - 1)) && shoot) {
            sf::Vector2f playerPos = playerObject.getPosition();
            switch (shootType) {
                default:
                case 1: {
                    {
                        Bullet bullet;
                        bullet.hostile = false;
                        bullet.obj.setBulletType(1);
                        bullet.obj.setDirection(sf::Vector2f(0, -1));
                        bullet.obj.setWindowSize(windowWidth, windowHeight);
                        bullet.obj.init();
                        bullet.obj.setPosition(playerPos.x - 15, playerPos.y - 3);
                        bullets.push_back(bullet);
                    }
                    {
                        Bullet bullet;
                        bullet.hostile = false;
                        bullet.obj.setBulletType(1);
                        bullet.obj.setDirection(sf::Vector2f(0, -1));
                        bullet.obj.setWindowSize(windowWidth, windowHeight);
                        bullet.obj.init();
                        bullet.obj.setPosition(playerPos.x + 15, playerPos.y - 3);
                        bullets.push_back(bullet);
                    }
                    break;
                }
                case 2: {
                    {
                        Bullet bullet;
                        bullet.hostile = false;
                        bullet.obj.setBulletType(1);
                        bullet.obj.setDirection(sf::Vector2f(0, -1));
                        bullet.obj.setWindowSize(windowWidth, windowHeight);
                        bullet.obj.init();
                        bullet.obj.setPosition(playerPos.x - 15, playerPos.y - 3);
                        bullets.push_back(bullet);
                    }
                    {
                        Bullet bullet;
                        bullet.hostile = false;
                        bullet.obj.setBulletType(1);
                        bullet.obj.setDirection(sf::Vector2f(0, -1));
                        bullet.obj.setWindowSize(windowWidth, windowHeight);
                        bullet.obj.init();
                        bullet.obj.setPosition(playerPos.x + 15, playerPos.y - 3);
                        bullets.push_back(bullet);
                    }
                    {
                        Bullet bullet;
                        bullet.hostile = false;
                        bullet.obj.setBulletType(1);
                        bullet.obj.setDirection(sf::Vector2f(0, -1));
                        bullet.obj.setWindowSize(windowWidth, windowHeight);
                        bullet.obj.init();
                        bullet.obj.setPosition(playerPos.x, playerPos.y - 20);
                        bullets.push_back(bullet);
                    }
                    break;
                }
            }
            lastShoot = sf::seconds(0);
        }

        if (lastSpawn.asSeconds() >= std::exp(-0.2f * (level - 1))) {
            std::uniform_int_distribution<int> si(1, 3);
            Enemy enemy;
            int drop = si(rd);
            if (1 <= drop && drop <= 2) {
                std::uniform_int_distribution<int> e1h(20, 30);
                enemy.health = enemy.totalHealth = e1h(rd);
                enemy.obj.setEnemyType(1);
            } else if (3 <= drop && drop <= 3) {
                std::uniform_int_distribution<int> e2h(50, 100);
                enemy.health = enemy.totalHealth = e2h(rd);
                enemy.obj.setEnemyType(2);
            }
            enemy.obj.setWindowSize(windowWidth, windowHeight);
            enemy.obj.init();
            enemy.obj.generateSpeed(enemySpeedRatio);
            std::uniform_int_distribution<int> px(10, windowWidth - 10);
            enemy.obj.setPosition(px(rd), 10);
            enemies.push_back(enemy);

            lastSpawn = sf::seconds(0);
        }

        bullets.erase(std::remove_if(bullets.begin(), bullets.end(), [&](Bullet &bullet) {
            bullet.obj.update(time);
            if (bullet.obj.isOutOfBound()) {
                return true;
            }
            if (!bullet.hostile) {
                for (Enemy &enemy : enemies) {
                    if (bullet.obj.getGlobalBounds().intersects(enemy.obj.getGlobalBounds())) {
                        enemy.health -= 10;
                        score += 10 + level;
                        hitSound.play();
                        return true;
                    }
                }
            } else {
                if (bullet.obj.getGlobalBounds().intersects(playerObject.getGlobalBounds())) {
                    health -= 10;
                    hitSound.play();
                    return true;
                }
            }
            return false;
        }), bullets.end());
        enemies.erase(std::remove_if(enemies.begin(), enemies.end(), [&](Enemy &enemy) {
            enemy.obj.update(time);
            if (enemy.obj.getGlobalBounds().intersects(playerObject.getGlobalBounds())) {
                int dh = std::min(enemy.health, health);
                health -= dh;
                enemy.health -= dh;
                score += dh + level;
            }
            if (enemy.obj.isOutOfBound()) {
                return true;
            }
            if (enemy.health <= 0) {
                DownEnemy downEnemy;
                downEnemy.sprite = enemy.obj;
                downEnemy.enemyType = enemy.obj.getEnemyType();
                switch (downEnemy.enemyType) {
                    default:
                    case 1: {
                        downEnemy.sprite.setTextureRect(ShootTexturePack::enemy1_down1());
                        break;
                    }
                    case 2: {
                        downEnemy.sprite.setTextureRect(ShootTexturePack::enemy2_down1());
                        break;
                    }
                }
                downEnemy.stage = 1;
                downEnemy.timer = sf::seconds(0);
                downEnemies.push_back(downEnemy);
                exp1Sound.play();
                return true;
            }
            return false;
        }), enemies.end());

        if (enemies.size() > 0 && lastEShoot.asSeconds() >= 0.3 * std::exp(-0.5f * (level - 1))) {
            std::uniform_int_distribution<int> si(0, (int) (enemies.size() - 1));
            int index = si(rd);
            sf::Vector2f enemyPos = enemies[index].obj.getPosition();
            {
                if (enemies[index].obj.getEnemyType() == 1) {
                    Bullet bullet;
                    bullet.hostile = true;
                    bullet.obj.setBulletType(2);
                    bullet.obj.setDirection(sf::Vector2f(0, 1));
                    bullet.obj.setWindowSize(windowWidth, windowHeight);
                    bullet.obj.init();
                    bullet.obj.setPosition(enemyPos.x, enemyPos.y + 1);
                    bullets.push_back(bullet);
                } else if (enemies[index].obj.getEnemyType() == 2) {
                    {
                        Bullet bullet;
                        bullet.hostile = true;
                        bullet.obj.setBulletType(2);
                        bullet.obj.setDirection(sf::Vector2f(0, 1));
                        bullet.obj.setWindowSize(windowWidth, windowHeight);
                        bullet.obj.init();
                        bullet.obj.setPosition(enemyPos.x + 10, enemyPos.y + 3);
                        bullets.push_back(bullet);
                    }
                    {
                        Bullet bullet;
                        bullet.hostile = true;
                        bullet.obj.setBulletType(2);
                        bullet.obj.setDirection(sf::Vector2f(0, 1));
                        bullet.obj.setWindowSize(windowWidth, windowHeight);
                        bullet.obj.init();
                        bullet.obj.setPosition(enemyPos.x - 10, enemyPos.y + 3);
                        bullets.push_back(bullet);
                    }
                }
            }
            lastEShoot = sf::seconds(0);
        }

        downEnemies.erase(std::remove_if(downEnemies.begin(), downEnemies.end(), [&](DownEnemy &downEnemy) {
            downEnemy.timer += time;
            if (downEnemy.timer.asSeconds() >= 0.1) {
                ++downEnemy.stage;
                if (downEnemy.enemyType == 1) {
                    switch (downEnemy.stage) {
                        case 1: {
                            downEnemy.sprite.setTextureRect(ShootTexturePack::enemy1_down1());
                            break;
                        }
                        case 2: {
                            downEnemy.sprite.setTextureRect(ShootTexturePack::enemy1_down2());
                            break;
                        }
                        case 3: {
                            downEnemy.sprite.setTextureRect(ShootTexturePack::enemy1_down3());
                            break;
                        }
                        default:
                        case 4: {
                            downEnemy.sprite.setTextureRect(ShootTexturePack::enemy1_down4());
                            break;
                        }
                    }
                } else if (downEnemy.enemyType == 2) {
                    switch (downEnemy.stage) {
                        case 1: {
                            downEnemy.sprite.setTextureRect(ShootTexturePack::enemy2_down1());
                            break;
                        }
                        case 2: {
                            downEnemy.sprite.setTextureRect(ShootTexturePack::enemy2_down2());
                            break;
                        }
                        case 3: {
                            downEnemy.sprite.setTextureRect(ShootTexturePack::enemy2_down3());
                            break;
                        }
                        default:
                        case 4: {
                            downEnemy.sprite.setTextureRect(ShootTexturePack::enemy2_down4());
                            break;
                        }
                    }
                }
                downEnemy.timer = sf::seconds(0);
            }

            return downEnemy.stage > 4;
        }), downEnemies.end());

        if (down) {
            downTimer += time;
            if (downTimer.asSeconds() >= 0.5) {
                ++downStage;
                switch (downStage) {
                    case 1: {
                        downSprite.setTextureRect(ShootTexturePack::hero_blowup_n1());
                        break;
                    }
                    case 2: {
                        downSprite.setTextureRect(ShootTexturePack::hero_blowup_n2());
                        break;
                    }
                    case 3: {
                        downSprite.setTextureRect(ShootTexturePack::hero_blowup_n3());
                        break;
                    }
                    default:
                    case 4: {
                        downSprite.setTextureRect(ShootTexturePack::hero_blowup_n4());
                        break;
                    }
                }
                downTimer = sf::seconds(0);
            }
            if (downStage > 4) {
                down = false;
                playerObject.setPosition(windowWidth / 2.f, windowHeight - 100);
            }
        }

        if (health <= 0) {
            if (--lives < 1) {
                SessionService::getInstance()->recordScore(score);
                getContext().insertScene(new TextScene(&getContext(), Scene::OPTION_SELF_DESTROY,
                                                       std::string("本次得分：") + std::to_string(score), true));
                getContext().insertScene(new TextScene(&getContext(), Scene::OPTION_SELF_DESTROY, "Game Over", true),
                                         2);
                getContext().transform(2, false, true);
            } else {
                health = totalHealth;
                downSprite = playerObject;
                downTimer = sf::seconds(0);
                downStage = 1;
                downSprite.setTextureRect(ShootTexturePack::hero_blowup_n1());
                down = true;
                playerObject.setPosition(-100, -100);
                recoverSound.setPlayingOffset(sf::seconds(1.5f));
                recoverSound.play();
            }
        }


        float evolveCounter = 30 - evolveTimer.asSeconds();

        if (evolveCounter <= 0) {
            totalHealth += 100;
            health = totalHealth;
            ++level;
            evolveTimer = sf::seconds(0);
            evolveSound.play();
        }

        std::string scoreStr = "当前得分：";
        scoreStr += std::to_string(score);
        scoreText.setString(converter.from_bytes(scoreStr));

        std::string timerStr = "秒后晋级";
        timerStr =
                std::to_string(int(evolveCounter >= 0 ? evolveCounter : 0)) + timerStr + "(" + std::to_string(level) +
                "->" + std::to_string(level + 1) + ")";
        timerText.setString(converter.from_bytes(timerStr));

        std::string livesStr = "";
        for (int i = 1; i <= lives; ++i) {
            livesStr += "❤";
        }
        livesText.setString(converter.from_bytes(livesStr));
    }
}

void BattleScene::draw() {
    getContext().getWindow().clear(sf::Color::White);
    if (loading) {
        getContext().getWindow().draw(loadingText);
    } else {
        getContext().getWindow().draw(background);

        getContext().getWindow().draw(scoreText);
        getContext().getWindow().draw(timerText);
        getContext().getWindow().draw(livesText);

        if (down) {
            getContext().getWindow().draw(downSprite);
        } else {
            float redRate = float(health) / float(totalHealth);
            if (redRate < 0) {
                redRate = 0;
            }
            sf::Color color(255, sf::Uint8(255 * redRate), sf::Uint8(255 * redRate));
            playerObject.setColor(color);
            getContext().getWindow().draw(playerObject);
        }

        for (auto &bullet : bullets) {
            getContext().getWindow().draw(bullet.obj);
        }

        for (auto &enemy : enemies) {
            float enemyRedRate = float(enemy.health) / float(enemy.totalHealth);
            if (enemyRedRate < 0) {
                enemyRedRate = 0;
            }
            sf::Color enemyColor(255, sf::Uint8(255 * enemyRedRate), sf::Uint8(255 * enemyRedRate));
            enemy.obj.setColor(enemyColor);
            getContext().getWindow().draw(enemy.obj);
        }

        for (auto &downEnemy : downEnemies) {
            getContext().getWindow().draw(downEnemy.sprite);
        }
    }
}

