
#include "all_header.hpp"
#include "ResourcePath.hpp"
#include <time.h>
#include "Texture.hpp"
using namespace std;
int main()
{
    sf::Music music;
    music.openFromFile(resourcePath() + "BGM3.ogg");
    music.setLoop(true);
    music.play();
    Texture texture;
    texture.load();
    srand(time(NULL));
    Game game;
    game.run();
    return EXIT_SUCCESS;
}
