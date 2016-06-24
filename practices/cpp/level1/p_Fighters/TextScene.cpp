//
// Created by wxdao on 16-5-14.
//

#include <codecvt>
#include "TextScene.h"
#include "ResourceLoader.h"

void TextScene::init() {
    text.setFont(ResourceLoader::getInstance()->loadFont("res/fonts/shscn-el.otf"));
    text.setCharacterSize(40);
    std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
    text.setString(converter.from_bytes(msg));
    {
        sf::FloatRect textRect = text.getLocalBounds();
        text.setOrigin(textRect.left + textRect.width / 2.0f,
                       textRect.top + textRect.height / 2.0f);
        text.setPosition(windowWidth / 2.f, windowHeight / 2.f);
    }
    if (!fadeIn) {
        text.setColor(sf::Color::Black);
    } else {
        text.setColor(sf::Color::Transparent);
    }

    exitText.setFont(ResourceLoader::getInstance()->loadFont("res/fonts/shscn-el.otf"));
    exitText.setCharacterSize(20);
    exitText.setString(L"按 ESC 返回");
    {
        sf::FloatRect textRect = exitText.getLocalBounds();
        exitText.setOrigin(textRect.left + textRect.width / 2.0f,
                           textRect.top + textRect.height / 2.0f);
        exitText.setPosition(windowWidth / 2.f, windowHeight / 2.f + 100);
    }
    if (!fadeIn) {
        exitText.setColor(sf::Color::Black);
    } else {
        exitText.setColor(sf::Color::White);
    }

    time = sf::seconds(0);
}

void TextScene::handleEvent(sf::Event event) {
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Escape) {
            getContext().transform(-1, false, true);
        }
    }
}

void TextScene::update(sf::Time time1) {
    if (fadeIn) {
        time += time1;
        sf::Color color = sf::Color::Black;
        if (time <= sf::milliseconds(1000)) {
            color.a = sf::Uint8(time.asMilliseconds() * 0.255f);
            text.setColor(color);
            exitText.setColor(color);
        } else {
            text.setColor(color);
            exitText.setColor(color);
        }
    }
}

void TextScene::draw() {
    getContext().getWindow().clear(sf::Color::White);

    getContext().getWindow().draw(text);

    getContext().getWindow().draw(exitText);
}

