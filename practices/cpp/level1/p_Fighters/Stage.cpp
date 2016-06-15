#include "EnemyFactory.hpp"
#include "HealthUp.hpp"
#include "Hero.hpp"
#include "PickupFactory.hpp"
#include "Stage.hpp"
#include <cmath>
#define STAGE 1
#define VICTORY 98
#define MAIN_MENU 0
#define HELP 99
Stage::Stage() { setTexture(Texture::STAGE_BACK_GROUND); }
template <class T> void clear(std::list<T> &myList) {
    for (auto &i : myList) {
        i.reset();
    }
    myList.clear();
}
template <class T>
void drawSomething(std::list<T> myList, sf::RenderWindow &window) {
    for (auto &i : myList) {
        window.draw(*i);
    }
}
template <class T> void running(std::list<T> &myList) {
    for (auto i = myList.begin(); i != myList.end();) {
        auto &I = *i;
        I->move();
        if (I->out()) {
            I.reset();
            i = myList.erase(i);
        } else {
            i++;
        }
    }
}
void Stage::initial() {
    setPosition(0, 0);
    clock.restart();
    coolDown.restart();
    clear(allEnemy);
    clear(myBullet);
    clear(allPickup);
    clear(enemyBullet);
    for (auto &i : allEffect) {
        delete i;
        i = NULL;
    }
    allEffect.clear();
}
int Stage::run() {
    if (clock.getTime() > 65) {
        stage++;
        return VICTORY;
    }
    if (coolDown.getTime() > difficulty && clock.getTime() <= 60) {
        coolDown.restart();
        Enemy *enemy = EnemyFactory::createEnemy(stage + rand() % 2);
        creatEnemy(enemy);
    }
    running(myBullet);
    running(enemyBullet);
    running(allEnemy);
    running(allPickup);
    for (auto i = allEffect.begin(); i != allEffect.end();) {
        auto &I = *i;
        I->move();
        if (I->getOccurrenceTime() > I->getLast()) {
            delete I;
            I = NULL;
            i = allEffect.erase(i);
        } else {
            i++;
        }
    }
    for (auto &i : allEnemy) {
        i->fire();
    }
    return STAGE;
}
void Stage::draw(sf::RenderWindow &window) {
    move(-0.5, 0);
    window.draw(*this);
    drawSomething(allPickup, window);
    drawSomething(enemyBullet, window);
    drawSomething(myBullet, window);
    drawSomething(allEnemy, window);
    drawSomething(allEffect, window);
}
void Stage::creatParticle(Particle *particle) { allEffect.push_back(particle); }
void Stage::creatEnemy(Enemy *enemy) {
    allEnemy.push_back(std::shared_ptr<Enemy>(enemy));
}
void Stage::creatBullet(Bullet *bullet) {
    myBullet.push_back(std::shared_ptr<Bullet>(bullet));
}
void Stage::creatBullet(SecondaryObject *bullet) {
    enemyBullet.push_back(std::shared_ptr<SecondaryObject>(bullet));
}
void Stage::creatCloud(Cloud *cloud) { allEffect.push_back(cloud); }
void Stage::creatPickup(Pickup *pickup) {
    if (pickup == NULL) {
        return;
    }
    allPickup.push_back(std::shared_ptr<Pickup>(pickup));
}
std::weak_ptr<Object> Stage::getEnemy() {
    if (allEnemy.empty()) {
        return std::weak_ptr<Object>();
    }
    return std::weak_ptr<Object>(*allEnemy.begin());
}
int Stage::collision() {
    for (auto i = myBullet.begin(); i != myBullet.end();) {
        auto &I = *i;
        auto j = allEnemy.begin();
        for (; j != allEnemy.end();) {
            auto &J = *j;
            if (touch(J.get(), I.get())) {
                Particle::creatParticle(getTouch(J.get(), I.get()));
                J->hit(I.get());
                if (J->isDead()) {
                    creatCloud(new Cloud(J.get()->getPosition()));
                    creatPickup(PickupFactory::createPickup(
                        rand() % (19 - difficulty + stage -
                                  Hero::getInstance()->getLuck()),
                        J->getPosition().x + 10, J->getPosition().y + 10));
                    Score::getInstance()->getScore(J->point);
                    J.reset();
                    j = allEnemy.erase(j);
                }
                I.reset();
                i = myBullet.erase(i);
                break;
            } else {
                j++;
            }
        }
        if (j == allEnemy.end()) {
            i++;
        }
    }
    for (auto i = enemyBullet.begin(); i != enemyBullet.end();) {
        auto &I = *i;
        if (touch(Hero::getInstance(), I.get())) {
            Hero::getInstance()->hit();
            if (Hero::getInstance()->isDead()) {
                return MAIN_MENU;
            }
            I.reset();
            i = enemyBullet.erase(i);
        } else {
            i++;
        }
    }
    for (auto &i : allEnemy) {
        if (touch(i.get(), Hero::getInstance())) {
            Hero::getInstance()->hit();
            if (Hero::getInstance()->isDead()) {
                return MAIN_MENU;
            }
        }
    }
    for (auto i = allPickup.begin(); i != allPickup.end();) {
        auto &I = *i;
        if (touch(I.get(), Hero::getInstance())) {
            I->use();
            I.reset();
            i = allPickup.erase(i);
        } else {
            i++;
        }
    }
    return STAGE;
}