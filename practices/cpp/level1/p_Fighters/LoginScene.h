//
// Created by wxdao on 16-5-13.
//

#ifndef EVERFIGHTER_LOGINSCENE_H
#define EVERFIGHTER_LOGINSCENE_H


#include <SFML/Graphics.hpp>
#include "Scene.h"

class LoginScene : public Scene {
private:
    int state;
    sf::Time elapsed;
    sf::Text text;
    sf::Texture qrCodeTexture;
    sf::Sprite qrCode;
    std::string loginUrl;

    unsigned windowWidth = getContext().getWindow().getSize().x;
    unsigned windowHeight = getContext().getWindow().getSize().y;
protected:
    virtual void init();

    virtual void destroy() { }

public:
    LoginScene(SceneContext *context, int options) : Scene(context, options) { }

    virtual void handleEvent(sf::Event event);

    virtual void update(sf::Time);

    virtual void draw();
};


#endif //EVERFIGHTER_LOGINSCENE_H
