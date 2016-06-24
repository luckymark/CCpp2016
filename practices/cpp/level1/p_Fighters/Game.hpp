#ifndef Game_hpp
#define Game_hpp
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <stdio.h>
class Game {
  private:
    Game() {}

  public:
    static Game *getInstance() {
        static Game *singleton;
        if (singleton == NULL) {
            singleton = new Game();
        }
        return singleton;
    }
    void run(sf::RenderWindow &window);
    int state = 0;
};
#endif
