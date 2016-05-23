#include "GameMusic.h"
#include <SFML/Audio.hpp>
std::string GameMusic::path="resources/sound/";
GameMusic* GameMusic::_instance=0;
GameMusic* GameMusic::instance()
{
    if(_instance==0)
        _instance=new GameMusic;
    return _instance;
}
void GameMusic::load()
{
    if(!BGM.openFromFile("resources/sound/th07_01.ogg"))
        return ;
    BGM.play();
    BGM.setLoop(true);
}
GameMusic::GameMusic()
{

}
