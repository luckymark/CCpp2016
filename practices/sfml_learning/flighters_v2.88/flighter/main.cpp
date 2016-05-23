#include <Game.h>
int main()
{
    Game* aGame=Game::instance();
    aGame->initializeGame();
    aGame->GameStart();
}
