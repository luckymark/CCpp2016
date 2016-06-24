//
// Created by wxdao on 16-5-26.
//

#ifndef EVERFIGHTER_BULLETOBJECT_H
#define EVERFIGHTER_BULLETOBJECT_H


#include "GameObject.h"

class BulletObject : public GameObject {
private:
    int bulletType = 1;
    sf::Vector2f direction = sf::Vector2f(0, -1);

    unsigned windowWidth;
    unsigned windowHeight;
public:
    void setWindowSize(unsigned windowWidth, unsigned windowHeight);

    void setDirection(sf::Vector2f);

    void setBulletType(int type);

    bool isOutOfBound();

    virtual void init();

    virtual void update(sf::Time);
};


#endif //EVERFIGHTER_BULLETOBJECT_H
