//
// Created by wxdao on 16-5-28.
//

#ifndef EVERFIGHTER_GAMEOVERSCENE_H
#define EVERFIGHTER_GAMEOVERSCENE_H


#include "Scene.h"

class GameOverScene : Scene {
protected:
    virtual void destroy() { }

public:
    GameOverScene(SceneContext *context, int options) : Scene(context, options) { }


};


#endif //EVERFIGHTER_GAMEOVERSCENE_H
