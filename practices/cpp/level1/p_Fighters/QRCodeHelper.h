//
// Created by wxdao on 16-5-13.
//

#ifndef EVERFIGHTER_QRCODEHELPER_H
#define EVERFIGHTER_QRCODEHELPER_H


#include <SFML/Graphics.hpp>

class QRCodeHelper {
private:
    std::string content;
public:
    QRCodeHelper(std::string content);

    void setContent(std::string content);

    void render(sf::Texture &);
};


#endif //EVERFIGHTER_QRCODEHELPER_H
