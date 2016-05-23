#ifndef GAMEMUSIC_H
#define GAMEMUSIC_H
#include <SFML/Audio.hpp>
class GameMusic
{
public:
    static std::string path;
    void load();
    static GameMusic* instance();
protected:
    GameMusic();
private:
    static GameMusic* _instance;
    sf::Music BGM;
};

#endif // GAMEMUSIC_H
