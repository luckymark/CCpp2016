//
// Created by wxdao on 16-5-23.
//

#ifndef EVERFIGHTER_GAMEOBJECT_H
#define EVERFIGHTER_GAMEOBJECT_H


#include <SFML/Graphics.hpp>

class GameObject : public sf::Sprite {
public:
    virtual void init() { };

    virtual void update(sf::Time) { };
};


#endif //EVERFIGHTER_GAMEOBJECT_H
