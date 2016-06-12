#ifndef SOUND_H
#define SOUND_H
#include <SFML/Audio.hpp>

class Sound
{
    public:
        Sound();
        virtual ~Sound();
        sf::Music BACK_GROUND;
        sf::Music ENEMY_DOWN;
        sf::Music SHOOT;

        void load();
    protected:
    private:
};

#endif // SOUND_H
