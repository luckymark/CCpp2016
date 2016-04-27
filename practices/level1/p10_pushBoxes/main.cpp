#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <algorithm>
#include <vector>
#include <fstream>

using namespace std;

struct Maze {
    char *mazeMap;
    int width;
    int startX;
    int startY;
    int *endPoints;
    int n_endPoints;
    int playerX;
    int playerY;
};

Maze *generateMaze(string fn);

void printMaze(Maze *maze);

bool movePlayer(Maze *maze, char direction);

void clearPlayerState(Maze *maze);

void clearConsole();

int main(int argc, char *argv[]) {
    string fn;
    cout << "Maze: ";
    cin >> fn;
    Maze *maze = generateMaze(fn);
    clearConsole();
    int score = 1000;
    while (1) {
        printMaze(maze);
        cout << endl;
        char direction;
        cin >> direction;
        clearConsole();
        --score;
        if (movePlayer(maze, direction)) {
            break;
        }
    }
    printMaze(maze);
    int highest;
    cout << "Your score: " << score << endl;
    cout << "Previous highest score: " << highest << endl;

}

Maze *generateMaze(string fn) {
    Maze *maze = (Maze *) malloc(sizeof(Maze));
    ifstream ifs(fn);
    string line;
    getline(ifs, line);
    int width = line.length();
    char *m = (char *) malloc(line.length() * line.length() * sizeof(char));
    memcpy(m, line.c_str(), width);
    for (int i = 1; i < width; ++i) {
        getline(ifs, line);
        memcpy(m + i * width, line.c_str(), line.length());
    }
    maze->mazeMap = m;
    maze->width = width;

    ifs >> maze->startX;
    ifs >> maze->startY;
    ifs >> maze->n_endPoints;
    maze->endPoints = (int *) malloc(2 * maze->n_endPoints * sizeof(int));
    for (int i = 0; i < maze->n_endPoints; i += 2) {
        ifs >> maze->endPoints[i];
        ifs >> maze->endPoints[i + 1];
    }
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
            } else {
                bool flag = false;
                for (int i = 0; i < maze->n_endPoints; i += 2) {
                    if (maze->endPoints[i] == x && maze->endPoints[i + 1] == y) {
                        if (maze->mazeMap[y * maze->width + x] != '0') {
                            cout << 'E';
                        } else {
                            cout << 'F';
                        }
                        flag = true;
                        break;
                    }
                }
                if (!flag) {
                    cout << maze->mazeMap[y * maze->width + x];
                }
            }
        }
        cout << endl;
    }
}

bool movePlayer(Maze *maze, char direction) {
    switch (direction) {
        case 'w': // up
            if (maze->playerY > 0 && maze->mazeMap[(maze->playerY - 1) * maze->width + maze->playerX] != '#') {
                if (maze->mazeMap[(maze->playerY - 1) * maze->width + maze->playerX] == '0') {
                    if (maze->playerY - 2 > 0 &&
                        (maze->mazeMap[(maze->playerY - 2) * maze->width + maze->playerX] != '#' &&
                         maze->mazeMap[(maze->playerY - 2) * maze->width + maze->playerX] != '0')) {
                        maze->mazeMap[(maze->playerY - 2) * maze->width + maze->playerX] = '0';
                        maze->mazeMap[(maze->playerY - 1) * maze->width + maze->playerX] = ' ';
                        --(maze->playerY);
                    }
                } else {
                    --(maze->playerY);
                }
            }
            break;
        case 'a': // left
            if (maze->playerX > 0 && maze->mazeMap[(maze->playerY) * maze->width + maze->playerX - 1] != '#') {
                if (maze->mazeMap[(maze->playerY) * maze->width + maze->playerX - 1] == '0') {
                    if (maze->playerX - 2 > 0 &&
                        (maze->mazeMap[(maze->playerY) * maze->width + maze->playerX - 2] != '#' &&
                         maze->mazeMap[(maze->playerY) * maze->width + maze->playerX - 2] != '0')) {
                        maze->mazeMap[(maze->playerY) * maze->width + maze->playerX - 2] = '0';
                        maze->mazeMap[(maze->playerY) * maze->width + maze->playerX - 1] = ' ';
                        --(maze->playerX);
                    }
                } else {
                    --(maze->playerX);
                }
            }
            break;
        case 's': // down
            if (maze->playerY < (maze->width - 1) &&
                maze->mazeMap[(maze->playerY + 1) * maze->width + maze->playerX] != '#') {
                if (maze->mazeMap[(maze->playerY + 1) * maze->width + maze->playerX] == '0') {
                    if (maze->playerY + 2 > 0 &&
                        (maze->mazeMap[(maze->playerY + 2) * maze->width + maze->playerX] != '#' &&
                         maze->mazeMap[(maze->playerY + 2) * maze->width + maze->playerX] != '0')) {
                        maze->mazeMap[(maze->playerY + 2) * maze->width + maze->playerX] = '0';
                        maze->mazeMap[(maze->playerY + 1) * maze->width + maze->playerX] = ' ';
                        ++(maze->playerY);
                    }
                } else {
                    ++(maze->playerY);
                }
            }
            break;
        case 'd': // right
            if (maze->playerX < (maze->width - 1) &&
                maze->mazeMap[(maze->playerY) * maze->width + maze->playerX + 1] != '#') {
                if (maze->mazeMap[(maze->playerY) * maze->width + maze->playerX + 1] == '0') {
                    if (maze->playerX + 2 > 0 &&
                        (maze->mazeMap[(maze->playerY) * maze->width + maze->playerX + 2] != '#' &&
                         maze->mazeMap[(maze->playerY) * maze->width + maze->playerX + 2] != '0')) {
                        maze->mazeMap[(maze->playerY) * maze->width + maze->playerX + 2] = '0';
                        maze->mazeMap[(maze->playerY) * maze->width + maze->playerX + 1] = ' ';
                        ++(maze->playerX);
                    }
                } else {
                    ++(maze->playerX);
                }
            }
            break;
    }
    bool win = true;
    for (int i = 0; i < maze->n_endPoints; i += 2) {
        if (maze->mazeMap[(maze->endPoints[i + 1]) * maze->width + maze->endPoints[i]] != 0) {
            win = false;
            break;
        }
    }
    return win;
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
