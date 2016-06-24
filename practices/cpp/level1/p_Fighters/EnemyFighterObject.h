//
// Created by wxdao on 16-5-26.
//

#ifndef EVERFIGHTER_ENEMYFIGHTEROBJECT_H
#define EVERFIGHTER_ENEMYFIGHTEROBJECT_H

#include "GameObject.h"

class EnemyFighterObject : public GameObject {
private:
    int enemyType = 1;
    float xSpeed, ySpeed;

    unsigned windowWidth;
    unsigned windowHeight;
public:
    void setWindowSize(unsigned windowWidth, unsigned windowHeight);

    virtual void init();

    void setEnemyType(int type);

    int getEnemyType() { return enemyType; };

    virtual void update(sf::Time);

    bool isOutOfBound();

    void generateSpeed(float ratio);
};


#endif //EVERFIGHTER_ENEMYFIGHTEROBJECT_H
