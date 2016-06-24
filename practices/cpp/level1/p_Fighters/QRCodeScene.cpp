//
// Created by wxdao on 16-5-14.
//


#include <string>
#include <codecvt>
#include "QRCodeScene.h"
#include "QRCodeHelper.h"

void QRCodeScene::init() {
    QRCodeHelper(content).render(texture);
    qrCode.setTexture(texture);
    qrCode.setScale(300.f / texture.getSize().x, 300.f / texture.getSize().y);
    qrCode.setPosition((windowWidth - 300) / 2.f, (windowHeight - 300) / 2.f);

    font.loadFromFile("res/fonts/shscn-el.otf");

    msgText.setFont(font);
    msgText.setCharacterSize(40);
    std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
    msgText.setString(converter.from_bytes(msg));
    {
        sf::FloatRect textRect = msgText.getLocalBounds();
        msgText.setOrigin(textRect.left + textRect.width / 2.0f,
                          textRect.top + textRect.height / 2.0f);
        msgText.setPosition(windowWidth / 2.f, (windowHeight - 300) / 2.f - 50);
    }
    msgText.setColor(sf::Color::Black);

    exitText.setFont(font);
    exitText.setCharacterSize(20);
    exitText.setString(L"按 ESC 返回");
    {
        sf::FloatRect textRect = exitText.getLocalBounds();
        exitText.setOrigin(textRect.left + textRect.width / 2.0f,
                           textRect.top + textRect.height / 2.0f);
        exitText.setPosition(windowWidth / 2.f, (windowHeight - 300) / 2.f + 350);
    }
    exitText.setColor(sf::Color::Black);
}

void QRCodeScene::handleEvent(sf::Event event) {
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Escape) {
            getContext().transform(-1, false, true);
        }
    }
}

void QRCodeScene::update(sf::Time) {

}


void QRCodeScene::draw() {
    getContext().getWindow().clear(sf::Color::White);

    getContext().getWindow().draw(qrCode);

    getContext().getWindow().draw(msgText);

    getContext().getWindow().draw(exitText);

}

