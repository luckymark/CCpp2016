//
// Created by wxdao on 16-5-13.
//

#ifndef EVERFIGHTER_SPLASHSCENE_H
#define EVERFIGHTER_SPLASHSCENE_H


#include <SFML/Graphics.hpp>
#include "Scene.h"

class SplashScene : public Scene {
private:
    sf::Texture logoTexture;
    sf::Sprite logo;
    sf::Time elapsed;
    sf::Text text;
protected:
    virtual void init();

    virtual void destroy() { }

public:
    SplashScene(SceneContext *context, int options) : Scene(context, options) { }

    virtual void handleEvent(sf::Event event);

    virtual void update(sf::Time);

    virtual void draw();
};


#endif //EVERFIGHTER_SPLASHSCENE_H
