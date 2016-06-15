#include "Sound.h"

sf::Music Sound::button_music;
sf::Music Sound::bullet_music;
sf::Music Sound::enemy1_down_music;
sf::Music Sound::enemy2_down_music;
sf::Music Sound::enemy3_down_music;
sf::Music Sound::game_music;
sf::Music Sound::game_over;
sf::Music Sound::big_ship_music;

void Sound::LoadSounds()
{
    button_music.openFromFile("button.ogg");
    bullet_music.openFromFile("bullet.ogg");
    enemy1_down_music.openFromFile("enemy1_down.ogg");
    enemy2_down_music.openFromFile("enemy2_down.ogg");
    enemy3_down_music.openFromFile("enemy3_down.ogg");
    big_ship_music.openFromFile("big_spaceship_flying.ogg");
    game_music.openFromFile("game_music.ogg");
    game_over.openFromFile("game_over.ogg");
}

void Sound::PlayBackgroundMusic()
{
    if (Sound::game_music.getStatus()==sf::Music::Stopped) Sound::game_music.play();
}
