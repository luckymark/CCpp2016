#include "Sound.h"

Sound::Sound()
{
    //ctor
}

Sound::~Sound()
{
    //dtor
}

void Sound::load(){
    BACK_GROUND.openFromFile("resource/sound/game_music.ogg");
    ENEMY_DOWN.openFromFile("resource/sound/enemy1_down.ogg");
    SHOOT.openFromFile("resource/sound/bullet.ogg");
}
