//
// Created by wxdao on 16-5-12.
//

#ifndef EVERFIGHTER_SCENE_H
#define EVERFIGHTER_SCENE_H


#include "SceneContext.h"

class SceneContext;

class Scene {
private:
    int options;
    SceneContext *context;
protected:
    Scene(SceneContext *context, int options) : options(options), context(context) { }

    virtual void init() = 0;

    virtual void destroy() = 0;

    friend class SceneContext;

public:
    static const int OPTION_NONE = 0;
    static const int OPTION_ALWAYS_UPDATE = 1;
    static const int OPTION_ALWAYS_HANDLE_EVENT = (1 << 1);
    static const int OPTION_ALWAYS_DRAW = (1 << 2);
    static const int OPTION_SELF_DESTROY = (1 << 3);

    int getOptions() { return options; }

    SceneContext &getContext() { return *context; }

    bool isSet(int option) { return (options & option) != 0; }

    virtual void handleEvent(sf::Event event) = 0;

    virtual void update(sf::Time) = 0;

    virtual void draw() = 0;
};


#endif //EVERFIGHTER_SCENE_H
