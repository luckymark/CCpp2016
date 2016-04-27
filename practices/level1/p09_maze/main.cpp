#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

struct Maze {
    char *mazeMap;
    int width;
    int startX;
    int startY;
    int endX;
    int endY;
    int playerX;
    int playerY;
};

Maze *generateMaze(int width);

void printMaze(Maze *maze);

bool movePlayer(Maze *maze, char direction);

void clearPlayerState(Maze *maze);

void clearConsole();

int main(int argc, char *argv[]) {
    int width;
    cout << "Set the width of maze (odd): ";
    cin >> width;
    if (width % 2 == 0) {
        ++width;
        cout << "Width set to " << width << endl;
    }
    cout << "Generating a maze...";
    Maze *maze = generateMaze(width);
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

Maze *generateMaze(int width) {
    static char m[] = {
        '#', '#', '#', '#', '#',
        '#', ' ', '#', '#', '#',
        ' ', ' ', ' ', '#', '#',
        '#', '#', ' ', ' ', '#',
        '#', '#', ' ', '#', '#',
        };
    Maze *maze = (Maze *)malloc(sizeof(Maze));
    maze->mazeMap = m;
    maze->width = 5;
    maze->endX = 3;
    maze->endY = 3;
    maze->startX = 1;
    maze->startY = 1;
    clearPlayerState(maze);
    return maze;
}

void printMaze(Maze *maze) {
    for (int y = 0; y < maze->width; ++y) {
        for (int x = 0; x < maze->width; ++x) {
            if (maze->playerX == x && maze->playerY == y) {
                cout << 'X';
            } else if (maze->startX == x && maze->startY == y) {
                cout << 'S';
            } else if (maze->endX == x && maze->endY == y) {
                cout << 'E';
            } else {
                cout << maze->mazeMap[y * maze->width + x];
            }
        }
        cout << endl;
    }
}

bool movePlayer(Maze *maze, char direction) {
    switch (direction) {
    case 'w': // up
        if (maze->playerY > 0 && maze->mazeMap[(maze->playerY - 1) * maze->width + maze->playerX] != '#') {
            --(maze->playerY);
        }
        break;
    case 'a': // left
        if (maze->playerX > 0 && maze->mazeMap[(maze->playerY) * maze->width + maze->playerX - 1] != '#') {
            --(maze->playerX);
        }
        break;
    case 's': // down
        if (maze->playerY < (maze->width - 1) && maze->mazeMap[(maze->playerY + 1) * maze->width + maze->playerX] != '#') {
            ++(maze->playerY);
        }
        break;
    case 'd': // right
        if (maze->playerX < (maze->width - 1) && maze->mazeMap[(maze->playerY) * maze->width + maze->playerX + 1] != '#') {
            ++(maze->playerX);
        }
        break;
    }
    return maze->playerX == maze->endX && maze->playerY == maze->endY;
}

void clearPlayerState(Maze *maze) {
    maze->playerX = maze->startX;
    maze->playerY = maze->startY;
}

void clearConsole() {
#ifdef __WIN32
    system("cls");
#else
    system("clear");
#endif // __WIN32
}
