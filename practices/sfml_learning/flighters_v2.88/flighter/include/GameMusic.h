#ifndef GAMEMUSIC_H
#define GAMEMUSIC_H
#include <SFML/Audio.hpp>
class GameMusic
{
public:
    static std::string path;

    void load();

    static GameMusic* instance();

    void playShoot();

    void playWarPlaneBomb();

    void playCopterBomb();

    void playWarshipBomb();

    void playWarshipFlying();

    void playHeroBomb();

    void playBeHited();

    void playGetWeapon();

    void playGetBomb();

    void playUseBomb();
protected:
    GameMusic();
private:
    static GameMusic* _instance;
    sf::Music BGM;
    //sf::Music WarShipFlying;

    sf::SoundBuffer Shoot;
    sf::SoundBuffer WarPlaneBomb;
    sf::SoundBuffer CopterBomb;
    sf::SoundBuffer WarShipFlying;
    sf::SoundBuffer WarShipBomb;
    sf::SoundBuffer HeroBomb;
    sf::SoundBuffer BeHited;
    sf::SoundBuffer getWeapon;
    sf::SoundBuffer getBomb;
    sf::SoundBuffer useBomb;

    sf::Sound s_Shoot;
    sf::Sound s_WarPlaneBomb;
    sf::Sound s_CopterBomb;
    sf::Sound s_WarShipFlying;
    sf::Sound s_WarShipBomb;
    sf::Sound s_HeroBomb;
    sf::Sound s_BeHited;
    sf::Sound s_getWeapon;
    sf::Sound s_getBomb;
    sf::Sound s_useBomb;
};

#endif // GAMEMUSIC_H
