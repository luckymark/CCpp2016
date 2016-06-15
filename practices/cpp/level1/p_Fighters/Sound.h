#ifndef SOUND_H
#define SOUND_H
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
class Sound
{
public:
    static sf::Music background_music;
    static sf::Music button_music;
    static sf::Music bullet_music;
    static sf::Music enemy1_down_music;
    static sf::Music enemy2_down_music;
    static sf::Music enemy3_down_music;
    static sf::Music game_music;
    static sf::Music game_over;
    static sf::Music big_ship_music;
    static void LoadSounds();
    static void PlayBackgroundMusic();
};

#endif // SOUND_H
