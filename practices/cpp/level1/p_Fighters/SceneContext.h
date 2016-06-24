//
// Created by wxdao on 16-5-12.
//

#ifndef EVERFIGHTER_SCENECONTEXT_H
#define EVERFIGHTER_SCENECONTEXT_H


#include <SFML/Window/Event.hpp>
#include <vector>
#include <string>
#include <SFML/Graphics/RenderWindow.hpp>
#include <map>
#include "Scene.h"

class Scene;

class SceneContext {
private:
    sf::RenderWindow *window;
    std::vector<Scene *> sceneHierarchy;
    std::vector<Scene *> watcherScenes;
    int sceneIndex = -1;
public:
    void handleEvent(sf::Event event);

    void draw();

    void update(sf::Time);

    void transform(int offset, bool clearState = false, bool selfDestroy = false);

    void insertScene(Scene *, int offset = 1);

    void addWatcher(Scene *);

    void assignWindow(sf::RenderWindow &window) {
        this->window = &window;
    }

    sf::RenderWindow &getWindow() {
        return *window;
    }
};


#endif //EVERFIGHTER_SCENECONTEXT_H
