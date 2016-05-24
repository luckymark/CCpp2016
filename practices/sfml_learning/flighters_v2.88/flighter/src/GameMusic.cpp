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
    BGM.openFromFile(path+"th07_01.ogg");
    //WarShipFlying.openFromFile(path+"big_spaceship_flying.ogg");
    Shoot.loadFromFile(path+"bullet.ogg");
    WarPlaneBomb.loadFromFile(path+"enemy1_down.ogg");
    CopterBomb.loadFromFile(path+"enemy2_down.ogg");
    WarShipBomb.loadFromFile(path+"enemy3_down.ogg");
    WarShipFlying.loadFromFile(path+"big_spaceship_flying.ogg");
    HeroBomb.loadFromFile(path+"game_over.ogg");
    BeHited.loadFromFile(path+"button.ogg");
    s_CopterBomb.setBuffer(CopterBomb);
    s_Shoot.setBuffer(Shoot);
    s_WarPlaneBomb.setBuffer(WarPlaneBomb);
    s_WarShipBomb.setBuffer(WarPlaneBomb);
    s_WarShipFlying.setBuffer(WarShipFlying);
    s_HeroBomb.setBuffer(HeroBomb);
    s_BeHited.setBuffer(BeHited);
    //BGM.play();
    //BGM.setLoop(true);
}
void GameMusic::playShoot()
{
    s_Shoot.play();
}
void GameMusic::playWarPlaneBomb()
{
    s_WarPlaneBomb.play();
}
void GameMusic::playWarshipFlying()
{
    s_WarShipFlying.play();
}
void GameMusic::playWarshipBomb()
{
    s_WarPlaneBomb.play();
}
void GameMusic::playHeroBomb()
{
    s_HeroBomb.play();
}
void GameMusic::playCopterBomb()
{
    s_CopterBomb.play();
}
void GameMusic::playBeHited()
{
    s_BeHited.play();
}
GameMusic::GameMusic()
{

}
