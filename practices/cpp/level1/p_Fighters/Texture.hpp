#ifndef Texture_hpp
#define Texture_hpp
#include "ResourcePath.hpp"
#include <SFML/Graphics.hpp>
#define PICKUP_NUMBER 6
class Texture {
  public:
    static sf::Texture VICTORY_BACK_GROUND;
    static sf::Texture HELP_BACK_GROUND;
    static sf::Texture HERO;
    static sf::Texture ENEMY_1;
    static sf::Texture ENEMY_2;
    static sf::Texture ENEMY_3;
    static sf::Texture ENEMY_4;
    static sf::Texture ENEMY_5;
    static sf::Texture CHOOSE_DIFFICULTY;
    static sf::Texture PICKUP[PICKUP_NUMBER];
    static sf::Texture BULLET;
    static sf::Texture ENEMY_BULLET;
    static sf::Texture ENEMY_BULLET_2;
    static sf::Texture MAIN_MENU_BACK_GROUND;
    static sf::Texture BLOOD[4];
    static sf::Texture STAGE_BACK_GROUND;
    static sf::Texture PARTICLE;
    static sf::Texture CLOUD;
    static void load();
};
#endif