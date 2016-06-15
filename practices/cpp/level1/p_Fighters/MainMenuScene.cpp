//
// Created by wxdao on 16-5-13.
//

#include "MainMenuScene.h"
#include "TextScene.h"
#include "BattleScene.h"
#include "ResourceLoader.h"
#include "QRCodeScene.h"

void MainMenuScene::init() {
    selected = 0;

    title.setFont(ResourceLoader::getInstance()->loadFont("res/fonts/shscn-el.otf"));
    title.setString("Ever Fighter");
    title.setCharacterSize(40);
    title.setColor(sf::Color::Black);
    sf::FloatRect titleRect = title.getLocalBounds();
    title.setOrigin(titleRect.left + titleRect.width / 2.0f,
                    titleRect.top + titleRect.height / 2.0f);
    title.setPosition(windowWidth / 2.f, windowHeight / 4.f / 2.f);

    line[0] = sf::Vertex(sf::Vector2f(windowWidth / 8.f, windowHeight / 4.f / 2.f + 40), sf::Color::Black);
    line[1] = sf::Vertex(sf::Vector2f(windowWidth * 7 / 8.f, windowHeight / 4.f / 2.f + 40), sf::Color::Black);

    subTitle.setFont(ResourceLoader::getInstance()->loadFont("res/fonts/shscn-el.otf"));
    std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
    subTitle.setString(
            converter.from_bytes("Welcome back! " + onlineService->getPlayerName()));
    subTitle.setCharacterSize(24);
    subTitle.setColor(sf::Color::Black);
    sf::FloatRect subTitleRect = subTitle.getLocalBounds();
    subTitle.setOrigin(subTitleRect.left + subTitleRect.width / 2.0f,
                       subTitleRect.top + subTitleRect.height / 2.0f);
    subTitle.setPosition(windowWidth / 2.f, windowHeight / 4.f / 2.f + 80);

    mainMenuSound.setBuffer(ResourceLoader::getInstance()->loadSound("res/sound/mainMenu.ogg"));
    mainMenuSound.setLoop(true);

    {
        sf::Text text;
        text.setFont(ResourceLoader::getInstance()->loadFont("res/fonts/shscn-el.otf"));
        text.setString(L"开始");
        text.setCharacterSize(40);
        text.setColor(sf::Color::Black);
        sf::FloatRect textRect = text.getLocalBounds();
        text.setOrigin(textRect.left + textRect.width / 2.0f,
                       textRect.top + textRect.height / 2.0f);
        text.setPosition(windowWidth / 2.f, windowHeight / 3.f + 40);
        subTexts.push_back(text);
    }

    {
        sf::Text text;
        text.setFont(ResourceLoader::getInstance()->loadFont("res/fonts/shscn-el.otf"));
        text.setString(L"后勤中心");
        text.setCharacterSize(40);
        text.setColor(sf::Color::Black);
        sf::FloatRect textRect = text.getLocalBounds();
        text.setOrigin(textRect.left + textRect.width / 2.0f,
                       textRect.top + textRect.height / 2.0f);
        text.setPosition(windowWidth / 2.f, windowHeight / 3.f + 40 + 100);
        subTexts.push_back(text);
    }

    {
        sf::Text text;
        text.setFont(ResourceLoader::getInstance()->loadFont("res/fonts/shscn-el.otf"));
        text.setString(L"退出");
        text.setCharacterSize(40);
        text.setColor(sf::Color::Black);
        sf::FloatRect textRect = text.getLocalBounds();
        text.setOrigin(textRect.left + textRect.width / 2.0f,
                       textRect.top + textRect.height / 2.0f);
        text.setPosition(windowWidth / 2.f, windowHeight / 3.f + 40 + 200);
        subTexts.push_back(text);
    }
    mainMenuSound.play();
}

void MainMenuScene::handleEvent(sf::Event event) {
    if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            for (int i = 0; i < subTexts.size(); ++i) {
                sf::FloatRect rect = subTexts[i].getGlobalBounds();
                if (rect.contains(event.mouseButton.x, event.mouseButton.y)) {
                    switch (i) {
                        case 0: // start
                            getContext().insertScene(
                                    new BattleScene(&getContext(), Scene::OPTION_NONE));
                            getContext().transform(1);
                            break;
                        case 1: // shop
                            if (SessionService::getInstance()->hasLoggedIn()) {
                                getContext().insertScene(
                                        new QRCodeScene(&getContext(), Scene::OPTION_SELF_DESTROY, "微信扫一扫进入后勤中心",
                                                        "https://labxdao.vecsight.com/ef/getInfo"));
                            } else {
                                getContext().insertScene(
                                        new TextScene(&getContext(), Scene::OPTION_SELF_DESTROY, "离线模式不可访问后勤中心"));
                            }
                            getContext().transform(1);
                            break;
                        case 2: // exit
                            getContext().getWindow().close();
                            break;
                        default:
                            break;
                    }
                    mainMenuSound.stop();
                }
            }
        }
    }
}

void MainMenuScene::update(sf::Time) {
    if (mainMenuSound.getStatus() != sf::SoundSource::Playing) {
        mainMenuSound.play();
    }
}

void MainMenuScene::draw() {
    getContext().getWindow().clear(sf::Color::White);

    getContext().getWindow().draw(title);

    getContext().getWindow().draw(line, 2, sf::Lines);

    getContext().getWindow().draw(subTitle);

    for (sf::Text &text : subTexts) {
        getContext().getWindow().draw(text);
    }
}
