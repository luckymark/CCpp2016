#ifndef Victory_hpp
#define Victory_hpp
#include "Score.hpp"
#include "Texture.hpp"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <stdio.h>
class Victory : public sf::Sprite {
  private:
    Victory();
    sf::Text text;
    sf::Font font;
    sf::Clock clock;

  public:
    static Victory *getInstance() {
        static Victory *singleton;
        if (singleton == NULL) {
            singleton = new Victory();
        }
        return singleton;
    }
    int run(sf::RenderWindow &window);
    void pass();
};
#endif /* Victory_hpp */
