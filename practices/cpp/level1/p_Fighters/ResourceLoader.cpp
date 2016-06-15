//
// Created by wxdao on 16-5-27.
//

#include "ResourceLoader.h"

ResourceLoader *ResourceLoader::instance = nullptr;

ResourceLoader *ResourceLoader::getInstance() {
    return instance == nullptr ? (instance = new ResourceLoader()) : instance;
}


sf::Texture &ResourceLoader::loadTexture(std::string fn) {
    if (textureCache.find(fn) == textureCache.end()) {
        sf::Texture texture;
        textureCache[fn] = texture;
        textureCache[fn].loadFromFile(fn);
        return textureCache[fn];
    } else {
        return textureCache[fn];
    }
}


sf::Font &ResourceLoader::loadFont(std::string fn) {
    if (fontCache.find(fn) == fontCache.end()) {
        sf::Font font;
        fontCache[fn] = font;
        fontCache[fn].loadFromFile(fn);
        return fontCache[fn];
    } else {
        return fontCache[fn];
    }
}


sf::SoundBuffer &ResourceLoader::loadSound(std::string fn) {
    if (soundCache.find(fn) == soundCache.end()) {
        sf::SoundBuffer soundBuffer;
        soundCache[fn] = soundBuffer;
        soundCache[fn].loadFromFile(fn);
        return soundCache[fn];
    } else {
        return soundCache[fn];
    }
}

