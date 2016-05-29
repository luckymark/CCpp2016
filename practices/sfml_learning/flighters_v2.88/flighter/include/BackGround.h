/**
 * Project Untitled
 */


#ifndef _BACKGROUND_H
#define _BACKGROUND_H
#include <SFML/Graphics.hpp>
#include "GameWindow.h"
class BackGround {
public:

    void load();

    void refresh(float);

    void draw();

    static BackGround* instance();

    void setIniPosition();
protected:
    BackGround();
private:
    static BackGround* _instance;
    float speed;
    //float partline;
    GameWindow* window;
    //sf::Sprite IniBackGround;
    sf::Sprite topBackGround;
    sf::Sprite bottomBackGround;
};

#endif //_BACKGROUND_H
