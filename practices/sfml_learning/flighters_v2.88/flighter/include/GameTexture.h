#ifndef GAMETEXTURE_H
#define GAMETEXTURE_H
#include <SFML/Graphics.hpp>

class GameTexture
{
    public:
        static std::string path;
        static sf::Texture background;
        static sf::Texture shoot;
        static sf::Texture gameover;
        static void load();
    protected:

    private:
};

#endif // GAMETEXTURE_H
