//
// Created by wxdao on 16-5-13.
//

#include "SplashScene.h"
#include "LoginScene.h"
#include "ResourceLoader.h"

void SplashScene::handleEvent(sf::Event event) {
    if (event.type == sf::Event::KeyPressed) {
        getContext().insertScene(new LoginScene(&getContext(), Scene::OPTION_SELF_DESTROY), 1);
        getContext().transform(1);
    }
}

void SplashScene::update(sf::Time time) {
    elapsed += time;
    if (elapsed <= sf::milliseconds(3000)) {
        logo.setColor(sf::Color(255, 255, 255, sf::Uint8(elapsed.asMilliseconds() * 0.085f)));
    } else {
        logo.setColor(sf::Color(255, 255, 255, 255));
    }

    sf::Color color = sf::Color::Black;
    if (elapsed >= sf::milliseconds(3200) && elapsed <= sf::milliseconds(4200)) {
        color.a = sf::Uint8((elapsed - sf::milliseconds(3200)).asMilliseconds() * 0.255f);
        text.setColor(color);
    } else if (elapsed >= sf::milliseconds(4200)) {
        text.setColor(color);
    }

    if (elapsed >= sf::milliseconds(5200)) {
        getContext().insertScene(new LoginScene(&getContext(), Scene::OPTION_SELF_DESTROY), 1);
        getContext().transform(1);
    }
}

void SplashScene::draw() {
    getContext().getWindow().clear(sf::Color::White);
    getContext().getWindow().draw(logo);

    getContext().getWindow().draw(text);
}

void SplashScene::init() {
    logoTexture.loadFromFile("res/textures/labxdao.png");
    logoTexture.setSmooth(true);

    logo.setTexture(logoTexture);
    unsigned logoWidth = logoTexture.getSize().x;
    unsigned logoHeight = logoTexture.getSize().y;
    unsigned windowWidth = getContext().getWindow().getSize().x;
    unsigned windowHeight = getContext().getWindow().getSize().y;
    logo.setColor(sf::Color::Transparent);
    logo.setPosition((windowWidth - logoWidth) / 2.f, (windowHeight - logoHeight) / 2.f);

    text.setFont(ResourceLoader::getInstance()->loadFont("res/fonts/shscn-el.otf"));
    text.setCharacterSize(24);
    text.setString("Powered by LabXdao and VectorSight Facilities");
    text.setColor(sf::Color::Transparent);
    sf::FloatRect textRect = text.getLocalBounds();
    text.setOrigin(textRect.left + textRect.width / 2.0f,
                   textRect.top + textRect.height / 2.0f);
    text.setPosition(windowWidth / 2.f,
                     (windowHeight - logoHeight) / 2.f + logoHeight + 40);
}