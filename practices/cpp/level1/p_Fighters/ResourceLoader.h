//
// Created by wxdao on 16-5-27.
//

#ifndef EVERFIGHTER_RESOURCELOADER_H
#define EVERFIGHTER_RESOURCELOADER_H

#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class ResourceLoader {
private:
    static ResourceLoader *instance;

    ResourceLoader() { }

    std::map<std::string, sf::Texture> textureCache;
    std::map<std::string, sf::Font> fontCache;
    std::map<std::string, sf::SoundBuffer> soundCache;

public:
    static ResourceLoader *getInstance();

    sf::Texture &loadTexture(std::string fn);

    sf::Font &loadFont(std::string fn);

    sf::SoundBuffer &loadSound(std::string fn);
};


#endif //EVERFIGHTER_TEXTURELOADER_H
