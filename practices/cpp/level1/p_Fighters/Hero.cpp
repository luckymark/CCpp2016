//
//  Hero.cpp
//  plane
//
//  Created by mac on 16/5/1.
//  Copyright © 2016年 CCPP. All rights reserved.
//
#include "AutoBullet.hpp"
#include "Hero.hpp"
#include "HeroBullet.hpp"
#include "Stage.hpp"
#include "Texture.hpp"
bool Hero::isDead() { return (life <= 0); };
Hero::Hero() {
    deviation.x = 100;
    deviation.y = 100;
    radius = 30;
    setTexture(Texture::HERO);
    blood.setPosition(20.0, 20.0);
};
void Hero::healthUp() { life = std::min(life + 1, 4); }
void Hero::luckUp() { luck = std::min(luck + 1, 5); }
int Hero::getLuck() { return luck; }
void Hero::draw(sf::RenderWindow &window) {
    blood.setTexture(Texture::BLOOD[life - 1]);
    double time = clock.getTime();
    if (blooding) {
        if (time < 1) {
            setColor(sf::Color(255 - 50 * time, 255 - 200 * time,
                               255 - 200 * time, 255));
        }
        if (time >= 1 && time < 2) {
            setColor(sf::Color(155 + 50 * time, 200 * time - 145,
                               200 * time - 145, 255));
        }
        if (time >= 2) {
            setColor(sf::Color(255, 255, 255, 255));
        }
    } else {
        setColor(sf::Color(255, 255, 255, 255));
    }
    window.draw(blood);
    Score::getInstance()->draw(window);
    window.draw(*this);
}
void Hero::hit() {
    if (blooding && clock.getTime() < 2) {
        return;
    }
    blooding = true;
    life--;
    clock.restart();
}
void Hero::initial() {
    gun_1.clock.restart();
    gun_2.clock.restart();
    magnetic = false;
    damage_1 = 1;
    damage_2 = 0;
    luck = 0;
    life = 4;
    speed = 5.0;
    blooding = false;
    memset(direction, 0, sizeof(direction));
    onFire = false;
    setColor(sf::Color(255, 255, 255, 255));
}
void Hero::damageUp() { damage_1 = std::min(4.0, damage_1 + 0.3); }
void Hero::autoFire() { damage_2 = std::min(1.0, damage_2 + 0.1); }
double Hero::getDamage_1() { return damage_1; }
double Hero::getDamage_2() { return damage_2; }
void Hero::speedUp() { speed = std::min(speed + 0.5, 10.0); }
void Hero::move() {
    for (int i = 0; i < 4; ++i) {
        if (!direction[i])
            continue;
        switch (i) {
        case UP:
            if (getPosition().y >= -50)
                sf::Sprite::move(0, -speed);
            break;
        case DOWN:
            if (getPosition().y <= 1050)
                sf::Sprite::move(0, speed);
            break;
        case LEFT:
            if (getPosition().x >= -50)
                sf::Sprite::move(-speed, 0);
            break;
        case RIGHT:
            if (getPosition().x <= 1770)
                sf::Sprite::move(speed, 0);
            break;
        default:
            break;
        }
    }
}
void Hero::setMagnetic() { magnetic = true; }
bool Hero::getMagnetic() { return magnetic; }
void Hero::fire() {
    if (!onFire) {
        return;
    }
    if (gun_1.clock.getTime() >= 0.5) {
        gun_1.clock.restart();
        Stage::getInstance()->creatBullet(
            new HeroBullet(getPosition().x + 65, getPosition().y + 50));
    }
    if (damage_2 > 0 && gun_2.clock.getTime() >= 0.7) {
        gun_2.clock.restart();
        auto object = Stage::getInstance()->getEnemy();
        if (!object.expired()) {
            Stage::getInstance()->creatBullet(new AutoBullet(
                getPosition().x + 50, getPosition().y + 50, object));
        }
    }
}
void Hero::run(sf::RenderWindow &window) {
    sf::Event event;
    while (window.pollEvent(event)) {
        switch (event.type) {
        case sf::Event::KeyPressed:
            switch (event.key.code) {
            case sf::Keyboard::Up:
                direction[UP] = true;
                break;
            case sf::Keyboard::Down:
                direction[DOWN] = true;
                break;
            case sf::Keyboard::Left:
                direction[LEFT] = true;
                break;
            case sf::Keyboard::Right:
                direction[RIGHT] = true;
                break;
            case sf::Keyboard::Space:
                onFire = true;
                break;
            case sf::Keyboard::Escape:
                window.close();
                break;
            default:
                break;
            }
            break;
        case sf::Event::KeyReleased:
            switch (event.key.code) {
            case sf::Keyboard::Up:
                direction[UP] = false;
                break;
            case sf::Keyboard::Down:
                direction[DOWN] = false;
                break;
            case sf::Keyboard::Left:
                direction[LEFT] = false;
                break;
            case sf::Keyboard::Right:
                direction[RIGHT] = false;
                break;
            case sf::Keyboard::Space:
                onFire = false;
            default:
                break;
            }
            break;
        default:
            break;
        }
    }
    Hero::move();
    Hero::fire();
}
