//
// Created by wxdao on 16-5-13.
//

#include "LoginScene.h"
#include "QRCodeHelper.h"
#include "MainMenuScene.h"
#include "ResourceLoader.h"

void LoginScene::init() {
    state = 1;

    text.setFont(ResourceLoader::getInstance()->loadFont("res/fonts/shscn-el.otf"));

    loginUrl = "https://labxdao.vecsight.com/ef/login/";
    loginUrl += SessionService::getInstance()->getLoginToken();
    SessionService::getInstance()->startListen();
    QRCodeHelper(loginUrl.c_str()).render(qrCodeTexture);
}

void LoginScene::handleEvent(sf::Event event) {
    if (event.type == sf::Event::KeyPressed) {
        if (state < 3) {
            state = 3;
            elapsed = sf::seconds(0);
        }

        if (state == 3 && event.key.code == sf::Keyboard::P) {
            state = 4;
            elapsed = sf::seconds(0);
        }
    }

}

void LoginScene::update(sf::Time time) {
    if (state == 0) { // fade in first text
        elapsed += time;

        text.setString(L"欢迎");
        text.setCharacterSize(60);
        sf::FloatRect textRect = text.getLocalBounds();
        text.setOrigin(textRect.left + textRect.width / 2.0f,
                       textRect.top + textRect.height / 2.0f);
        text.setPosition(float(windowWidth) / 2.f,
                         float(windowHeight) / 2.f);
        sf::Color color = sf::Color::Black;

        if (elapsed.asMilliseconds() <= 2000) {
            color.a = (sf::Uint8) (elapsed.asMilliseconds() * 0.1275f);
            text.setColor(color);
        } else if (elapsed.asMilliseconds() <= 3000) {
            text.setColor(color);
        } else if (elapsed.asMilliseconds() <= 5000) {
            color.a = (sf::Uint8) (255 - (elapsed.asMilliseconds() - 3000) * 0.1275f);
            text.setColor(color);
        } else {
            text.setColor(sf::Color::Transparent);
            state = 1;
            elapsed = sf::seconds(0);
        }
    } else if (state == 1) {
        elapsed += time;

        text.setString(L"微信扫一扫登录以访问线上内容");
        text.setCharacterSize(40);
        sf::FloatRect textRect = text.getLocalBounds();
        text.setOrigin(textRect.left + textRect.width / 2.0f,
                       textRect.top + textRect.height / 2.0f);
        text.setPosition(float(windowWidth) / 2.f,
                         float(windowHeight) / 2.f);
        sf::Color color = sf::Color::Black;

        if (elapsed.asMilliseconds() <= 2000) {
            color.a = (sf::Uint8) (elapsed.asMilliseconds() * 0.1275f);
            text.setColor(color);
        } else if (elapsed.asMilliseconds() <= 3000) {
            text.setColor(color);
        } else if (elapsed.asMilliseconds() <= 5000) {
            color.a = (sf::Uint8) (255 - (elapsed.asMilliseconds() - 3000) * 0.1275f);
            text.setColor(color);
        } else {
            state = 3;
            elapsed = sf::seconds(0);
        }
    } else if (state == 2) {
        elapsed += time;

        text.setString(L"请用微信扫一扫之后显示的二维码");
        text.setCharacterSize(40);
        sf::FloatRect textRect = text.getLocalBounds();
        text.setOrigin(textRect.left + textRect.width / 2.0f,
                       textRect.top + textRect.height / 2.0f);
        text.setPosition(float(windowWidth) / 2.f,
                         float(windowHeight) / 2.f);
        sf::Color color = sf::Color::Black;

        if (elapsed.asMilliseconds() <= 2000) {
            color.a = (sf::Uint8) (elapsed.asMilliseconds() * 0.1275f);
            text.setColor(color);
        } else if (elapsed.asMilliseconds() <= 3000) {
            text.setColor(color);
        } else if (elapsed.asMilliseconds() <= 5000) {
            color.a = (sf::Uint8) (255 - (elapsed.asMilliseconds() - 3000) * 0.1275f);
            text.setColor(color);
        } else {
            state = 3;
            elapsed = sf::seconds(0);
        }
    } else if (state == 3) {
        elapsed += time;
        qrCode.setTexture(qrCodeTexture);
        qrCode.setScale(300.f / qrCodeTexture.getSize().x, 300.f / qrCodeTexture.getSize().y);
        qrCode.setPosition((windowWidth - 300) / 2.f, (windowHeight - 300) / 2.f);
        text.setString(L"或按 P 进入离线游戏");
        text.setCharacterSize(20);
        sf::FloatRect textRect = text.getLocalBounds();
        text.setOrigin(textRect.left + textRect.width / 2.0f,
                       textRect.top + textRect.height / 2.0f);
        text.setPosition(windowWidth / 2.f,
                         (windowHeight - 300) / 2.f + 300 + 40);
        sf::Color color = sf::Color::Black;

        if (elapsed.asMilliseconds() <= 2000) {
            color.a = (sf::Uint8) (elapsed.asMilliseconds() * 0.1275f);
            text.setColor(color);
            qrCode.setColor(sf::Color(255, 255, 255, (sf::Uint8) (elapsed.asMilliseconds() * 0.1275f)));
        } else {
            text.setColor(color);
            qrCode.setColor(sf::Color(255, 255, 255, 255));
        }

        if (SessionService::getInstance()->hasLoggedIn()) {
            state = 4;
            elapsed = sf::seconds(0);
        }
    } else if (state == 4) {
        elapsed += time;

        text.setString(L"US AGAINST THE WORLD");
        text.setCharacterSize(40);
        sf::FloatRect textRect = text.getLocalBounds();
        text.setOrigin(textRect.left + textRect.width / 2.0f,
                       textRect.top + textRect.height / 2.0f);
        text.setPosition(float(windowWidth) / 2.f,
                         float(windowHeight) / 2.f);
        sf::Color color = sf::Color::Black;

        if (elapsed.asMilliseconds() <= 2000) {
            color.a = (sf::Uint8) (elapsed.asMilliseconds() * 0.1275f);
            text.setColor(color);
        } else if (elapsed.asMilliseconds() <= 3000) {
            text.setColor(color);
        } else if (elapsed.asMilliseconds() <= 5000) {
            color.a = (sf::Uint8) (255 - (elapsed.asMilliseconds() - 3000) * 0.1275f);
            text.setColor(color);
        } else {
            getContext().insertScene(new MainMenuScene(&getContext(), Scene::OPTION_NONE), 1);
            getContext().transform(1);
        }
    }
}

void LoginScene::draw() {
    getContext().getWindow().clear(sf::Color::White);

    getContext().getWindow().draw(text);
    if (state == 3) {
        getContext().getWindow().draw(qrCode);
    }
}

