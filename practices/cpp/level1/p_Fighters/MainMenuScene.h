//
// Created by wxdao on 16-5-13.
//

#ifndef EVERFIGHTER_MAINMENUSCENE_H
#define EVERFIGHTER_MAINMENUSCENE_H


#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include "Scene.h"
#include "SessionService.h"

class MainMenuScene : public Scene {
    int selected;
    sf::Text title;
    sf::Text subTitle;
    std::vector<sf::Text> subTexts;
    sf::Vertex line[2];

    sf::Sound mainMenuSound;

    SessionService *onlineService = onlineService->getInstance();

    unsigned windowWidth = getContext().getWindow().getSize().x;
    unsigned windowHeight = getContext().getWindow().getSize().y;
protected:
    virtual void init();

    virtual void destroy() { }

public:
    MainMenuScene(SceneContext *context, int options) : Scene(context, options) { }

    virtual void handleEvent(sf::Event event);

    virtual void update(sf::Time);

    virtual void draw();
};


#endif //EVERFIGHTER_MAINMENUSCENE_H
