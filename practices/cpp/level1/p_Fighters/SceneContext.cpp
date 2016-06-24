//
// Created by wxdao on 16-5-12.
//

#include "SceneContext.h"

void SceneContext::handleEvent(sf::Event event) {
    if (sceneIndex >= 0) {
        sceneHierarchy[sceneIndex]->handleEvent(event);
    }
    for (Scene *scene : sceneHierarchy) {
        if (scene->isSet(Scene::OPTION_ALWAYS_HANDLE_EVENT)) {
            scene->handleEvent(event);
        }
    }
    for (Scene *scene : watcherScenes) {
        if (scene->isSet(Scene::OPTION_ALWAYS_HANDLE_EVENT)) {
            scene->handleEvent(event);
        }
    }
}

void SceneContext::addWatcher(Scene *scene) {
    watcherScenes.push_back(scene);
}


void SceneContext::draw() {
    if (sceneIndex >= 0) {
        sceneHierarchy[sceneIndex]->draw();
    }
    for (Scene *scene : sceneHierarchy) {
        if (scene->isSet(Scene::OPTION_ALWAYS_DRAW)) {
            scene->draw();
        }
    }
    for (Scene *scene : watcherScenes) {
        if (scene->isSet(Scene::OPTION_ALWAYS_DRAW)) {
            scene->draw();
        }
    }
}

void SceneContext::update(sf::Time time) {
    if (sceneIndex >= 0) {
        sceneHierarchy[sceneIndex]->update(time);
    }
    for (Scene *scene : sceneHierarchy) {
        if (scene->isSet(Scene::OPTION_ALWAYS_UPDATE)) {
            scene->update(time);
        }
    }
    for (Scene *scene : watcherScenes) {
        if (scene->isSet(Scene::OPTION_ALWAYS_UPDATE)) {
            scene->update(time);
        }
    }
}

void SceneContext::transform(int offset, bool clearState, bool selfDestroy) {
    if (sceneIndex + offset + 1 <= sceneHierarchy.size()) {
        if (sceneIndex >= 0 && (selfDestroy || sceneHierarchy[sceneIndex]->isSet(Scene::OPTION_SELF_DESTROY))) {
            sceneHierarchy[sceneIndex]->destroy();
            delete sceneHierarchy[sceneIndex];
            sceneHierarchy.erase(sceneHierarchy.begin() + sceneIndex);
            if (offset > 0) {
                sceneIndex += offset - 1;
            } else {
                sceneIndex += offset;
            }

        } else {
            sceneIndex += offset;
        }
        if (clearState) {
            sceneHierarchy[sceneIndex]->init();
        }
    }
}

void SceneContext::insertScene(Scene *scene, int offset) {
    sceneHierarchy.insert(sceneHierarchy.begin() + sceneIndex + offset, scene);
    scene->init();
}

