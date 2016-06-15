//
// Created by wxdao on 16-5-23.
//

#ifndef EVERFIGHTER_PLAYERFIGHTEROBJECT_H
#define EVERFIGHTER_PLAYERFIGHTEROBJECT_H


#include "GameObject.h"

class PlayerFighterObject : public GameObject {
private:
    sf::Time modelElapsed;
    bool flap = true;

    unsigned windowWidth;
    unsigned windowHeight;
public:
    void setWindowSize(unsigned windowWidth, unsigned windowHeight);

    virtual void init();

    virtual void update(sf::Time);
};


#endif //EVERFIGHTER_PLAYERFIGHTEROBJECT_H
