//
// Created by wxdao on 16-5-14.
//

#ifndef EVERFIGHTER_TEXTSCENE_H
#define EVERFIGHTER_TEXTSCENE_H


#include <string>
#include <SFML/Graphics.hpp>
#include "Scene.h"

class TextScene : public Scene {
private:
    sf::Text text;
    sf::Text exitText;
    sf::Time time;
    bool fadeIn;

    unsigned windowWidth = getContext().getWindow().getSize().x;
    unsigned windowHeight = getContext().getWindow().getSize().y;

    std::string msg;

protected:
    virtual void init();

    virtual void destroy() { }

public:
    TextScene(SceneContext *context, int options, std::string msg, bool fadeIn = false) : Scene(context, options),
                                                                                          msg(msg), fadeIn(fadeIn) { }

    virtual void handleEvent(sf::Event event);

    virtual void update(sf::Time);

    virtual void draw();
};


#endif //EVERFIGHTER_TEXTSCENE_H
