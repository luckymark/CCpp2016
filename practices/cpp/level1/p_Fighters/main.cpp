#include <iostream>
#include <SFML/Graphics.hpp>
#include "SceneContext.h"
#include "SplashScene.h"
#include "MainMenuScene.h"

using namespace std;

int main() {
    sf::ContextSettings settings;
    settings.antialiasingLevel = 4;
    sf::RenderWindow window(sf::VideoMode(800, 600), "Ever Fighter", sf::Style::Titlebar | sf::Style::Close, settings);
    window.setFramerateLimit(60);

    SceneContext context;
    context.assignWindow(window);
    context.insertScene(new SplashScene(&context, Scene::OPTION_SELF_DESTROY));
    context.transform(1);

    sf::Clock clock;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            context.handleEvent(event);
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        context.update(clock.restart());
        context.draw();
        window.display();
    }

    return 0;
}