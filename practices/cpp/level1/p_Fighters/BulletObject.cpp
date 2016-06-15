//
// Created by wxdao on 16-5-26.
//

#include "BulletObject.h"
#include "ShootTexturePack.h"
#include "ResourceLoader.h"


void BulletObject::init() {
    this->setTexture(ResourceLoader::getInstance()->loadTexture(ShootTexturePack::getFilePath()));
    switch (bulletType) {
        default:
        case 1:
            this->setTextureRect(ShootTexturePack::bullet1());
            break;
        case 2:
            this->setTextureRect(ShootTexturePack::bullet2());
            break;
    }
    this->setScale(0.5, 0.5);
    sf::FloatRect rect = this->getLocalBounds();
    this->setOrigin(rect.left + rect.width / 2.0f,
                    rect.top + rect.height / 2.0f);
}

void BulletObject::update(sf::Time time) {
    float speed = 6;
    auto pos = this->getPosition();

    if (pos.y > 0 && pos.y < windowHeight && pos.x > 0 && pos.x < windowWidth) {
        this->move(direction * speed);
    }
}


void BulletObject::setBulletType(int type) {
    bulletType = type;
}

bool BulletObject::isOutOfBound() {
    auto pos = this->getPosition();
    return pos.y <= 0 || pos.y >= windowHeight;
}

void BulletObject::setWindowSize(unsigned windowWidth, unsigned windowHeight) {
    this->windowWidth = windowWidth;
    this->windowHeight = windowHeight;
}


void BulletObject::setDirection(sf::Vector2f vec) {
    direction = vec;
}

