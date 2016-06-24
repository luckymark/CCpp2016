//
// Created by wxdao on 16-5-26.
//

#include "EnemyFighterObject.h"
#include "ResourceLoader.h"
#include "ShootTexturePack.h"

void EnemyFighterObject::setWindowSize(unsigned windowWidth, unsigned windowHeight) {
    this->windowWidth = windowWidth;
    this->windowHeight = windowHeight;
}

void EnemyFighterObject::init() {
    this->setTexture(ResourceLoader::getInstance()->loadTexture(ShootTexturePack::getFilePath()));
    switch (enemyType) {
        default:
        case 1:
            this->setTextureRect(ShootTexturePack::enemy1());
            break;
        case 2:
            this->setTextureRect(ShootTexturePack::enemy2());
            break;
    }

    this->setScale(0.5, 0.5);
    sf::FloatRect rect = this->getLocalBounds();
    this->setOrigin(rect.left + rect.width / 2.0f,
                    rect.top + rect.height / 2.0f);

}

void EnemyFighterObject::update(sf::Time) {

    auto &pos = this->getPosition();

    if (pos.y < windowHeight) {
        if (pos.x < 0) {
            xSpeed = -xSpeed;
            this->setPosition(0, pos.y);
        }
        if (pos.x > windowWidth) {
            xSpeed = -xSpeed;
            this->setPosition(windowWidth, pos.y);
        }
        this->move(xSpeed, ySpeed);
    }
}

bool EnemyFighterObject::isOutOfBound() {
    auto pos = this->getPosition();
    return (pos.y >= windowHeight);
}


void EnemyFighterObject::setEnemyType(int type) {
    enemyType = type;
}

void EnemyFighterObject::generateSpeed(float ratio) {
    std::uniform_real_distribution<float> dx(-5, 5);
    std::uniform_real_distribution<float> dy(1, 2);
    std::random_device rd;
    if (enemyType == 2) {
        ratio *= 0.8;
    }

    xSpeed = dx(rd) * ratio;
    ySpeed = dy(rd) * ratio;
}

