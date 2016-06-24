#include "Game.hpp"
#include "Texture.hpp"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <ctime>
int main(int, char const **) {
    srand(time(NULL));
    Texture::load();
    sf::RenderWindow window(sf::VideoMode(1920, 1200), "plane",
                            sf::Style::None);
    window.setFramerateLimit(65);
    Game::getInstance()->run(window);
    return EXIT_SUCCESS;
}
