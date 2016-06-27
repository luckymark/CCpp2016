/**
 * Project Untitled
 */


#ifndef _BACKGROUND_H
#define _BACKGROUND_H
#include <SFML/Graphics.hpp>
#include "GameWindow.h"
#include "Shader.h"
class BackGround{
public:

    void load();

    void refresh(float);

    void draw();

    static BackGround* instance();

    void setIniPosition();

    void setColor();
protected:
    BackGround();
private:
    static BackGround* _instance;
    float speed;
    GameWindow* window;
    sf::Sprite topBackGround;
    sf::Sprite bottomBackGround;
    Shader* shader;
};

#endif //_BACKGROUND_H
