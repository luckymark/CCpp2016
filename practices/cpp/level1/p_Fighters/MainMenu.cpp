#include "Hero.hpp"
#include "MainMenu.hpp"
#include "Score.hpp"
#include "Stage.hpp"
#include "Texture.hpp"
#include "Victory.hpp"
#define STAGE 1
#define CHOOSE_DIFFICULTY 97
#define VICTORY 98
#define MAIN_MENU 0
#define HELP 99
#define LOW 860
#define MID 920
#define HIGH 980
#define UP 0
#define DOWN 1
int MainMenu::run(sf::RenderWindow &window) {
    sf::Event event;
    while (window.pollEvent(event)) {
        // Close window: exit
        switch (event.type) {
        case sf::Event::KeyPressed:
            switch (event.key.code) {
            case sf::Keyboard::Up:
                MainMenu::move(UP);
                break;
            case sf::Keyboard::Down:
                MainMenu::move(DOWN);
                break;
            case sf::Keyboard::Return:
                if (arrow.getPosition().y == LOW) {
                    Hero::getInstance()->initial();
                    Score::getInstance()->initial();
                    Stage::getInstance()->stage = 0;
                    Victory::getInstance()->pass();
                    return CHOOSE_DIFFICULTY;
                }
                if (arrow.getPosition().y == MID) {
                    return HELP;
                }
                if (arrow.getPosition().y == HIGH) {
                    window.close();
                }
                break;
            default:
                break;
            }
            break;

        default:
            break;
        }
    }
    return MAIN_MENU;
}
MainMenu::MainMenu() {
    font.loadFromFile(resourcePath() + "STHUPO.TTF");
    backGround = sf::Sprite(Texture::MAIN_MENU_BACK_GROUND);
    arrow = sf::Text(L">", font, 60);
    arrow.setColor(sf::Color::Black);
    arrow.move(835, LOW);
}
void MainMenu::draw(sf::RenderWindow &window) {
    window.draw(backGround);
    window.draw(arrow);
}
void MainMenu::move(bool operation) {
    if (arrow.getPosition().y > LOW && operation == UP) {
        arrow.move(0, -60);
    }
    if (arrow.getPosition().y < HIGH && operation == DOWN) {
        arrow.move(0, 60);
    }
}