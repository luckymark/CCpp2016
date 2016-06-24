//
// Created by wxdao on 16-5-14.
//

#ifndef EVERFIGHTER_QRCODESCENE_H
#define EVERFIGHTER_QRCODESCENE_H


#include <SFML/Graphics.hpp>
#include "Scene.h"

class QRCodeScene : public Scene {
private:
    sf::Texture texture;
    sf::Sprite qrCode;
    sf::Font font;
    sf::Text msgText;
    sf::Text exitText;
    std::string content;
    std::string msg;

    unsigned windowWidth = getContext().getWindow().getSize().x;
    unsigned windowHeight = getContext().getWindow().getSize().y;
protected:
    virtual void init();

    virtual void destroy() { }

public:
    QRCodeScene(SceneContext *context, int options, std::string msg, std::string content) : Scene(context, options),
                                                                                            msg(msg),
                                                                                            content(content) { }

    virtual void handleEvent(sf::Event event);

    virtual void update(sf::Time);

    virtual void draw();

};


#endif //EVERFIGHTER_QRCODESCENE_H
