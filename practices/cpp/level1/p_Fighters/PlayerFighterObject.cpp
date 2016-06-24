//
// Created by wxdao on 16-5-23.
//

#include "PlayerFighterObject.h"
#include "ShootTexturePack.h"
#include "ResourceLoader.h"

void PlayerFighterObject::init() {
    this->setTexture(ResourceLoader::getInstance()->loadTexture(ShootTexturePack::getFilePath()));
    this->setTextureRect(ShootTexturePack::hero1());
    this->setScale(0.5, 0.5);
    sf::FloatRect rect = this->getLocalBounds();
    this->setOrigin(rect.left + rect.width / 2.0f,
                    rect.top + rect.height / 2.0f);

    modelElapsed = sf::seconds(0);
}

void PlayerFighterObject::update(sf::Time time) {
    modelElapsed += time;
    float speed = 5;
    auto pos = this->getPosition();
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) && pos.y > 0) {
        this->move(0, -1 * speed);
    }
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) &&
        pos.y < windowHeight) {
        this->move(0, 1 * speed);
    }
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) && pos.x > 0) {
        this->move(-1 * speed, 0);
    }
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) &&
        pos.x < windowWidth) {
        this->move(1 * speed, 0);
    }
    if (modelElapsed.asSeconds() >= 0.2) {
        if (flap) {
            this->setTextureRect(ShootTexturePack::hero2());
            this->setScale(0.5, 0.5);
        } else {
            this->setTextureRect(ShootTexturePack::hero1());
            this->setScale(0.5, 0.5);
        }
        flap = !flap;
        modelElapsed = sf::seconds(0);
    }
}


void PlayerFighterObject::setWindowSize(unsigned windowWidth, unsigned windowHeight) {
    this->windowWidth = windowWidth;
    this->windowHeight = windowHeight;
}

