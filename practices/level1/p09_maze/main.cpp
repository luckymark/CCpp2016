#include <iostream>

using namespace std;

struct Maze {
    char *maze;
    int width;
    int playerX;
    int playerY;
};

Maze *generateMaze(int width);

void printMaze(Maze *maze);

bool movePlayer(Maze *maze, int direction);

void clearMazeState(Maze *maze);

void clearConsole();

int main(int argc, char *argv[]) {
    int width;
    cout << "Set the width of maze (odd): ";
    cin >> width;
    cout << "Generating a maze...";
    Maze *maze = generateMaze(width);
    cout << "Press any key to start the game";
    cin.get();
    clearConsole();
    while (1) {
        printMaze(maze);
        cout << endl;
        char direction;
        cin >> direction;
        clearConsole();
        if (movePlayer(maze, direction)) {
            break;
        }
    }
    printMaze(maze);
    cout << "You win!";
}

