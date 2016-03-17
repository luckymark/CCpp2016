#include<cstdio>
#include<ctime>
#include<cstdlib>
#include <conio.h>
#define MAXN 10
//MAXN must be more than one
//0~MAXN is contained in maze in fact
#define MAZE maze[][MAXN+10]
#define QIUT 'q'
//if you cannot arrive in exit,please press 'q' to give up 
#define UP 72
#define DOWN 80
#define LETF 75
#define RIGHT 77
using namespace std;
struct Point {
    int x, y;

    void operator=(const Point &X) {
        x = X.x;
        y = X.y;
    }

    bool operator==(const Point &X) const {
        return x == X.x && y == X.y;
    }
};
void createMaze(char MAZE,const int width);
void printMaze(char MAZE,const int width);
void initialMaze(char MAZE,const int width);
void createPeople(Point &hero,char MAZE,const int width);
void createExit(Point &out,Point &hero,char MAZE,const int width);
void game(Point &hero,Point &out,char MAZE,const int width);
void moveHero(Point &hero,Point &out,char MAZE,const int width,int direction);
Point getPosition(int &width);
int main() {
    char maze[MAXN + 10][MAXN + 10];
    initialMaze(maze, MAXN);
    createMaze(maze, MAXN);
    Point people;
    createPeople(people,maze,MAXN);
    Point exit;
    createExit(exit,people,maze,MAXN);
    printMaze(maze,MAXN);
    game(people,exit,maze,MAXN);
    return 0;
}
Point getPosition(const int width) {
    int row = 1 + (rand() % (width - 1));
    int column = 1 + (rand() % (width - 1));
    return (Point) {row, column};
}
void initialMaze(char MAZE,const int width) {
    srand(time(0));
    for (int i = 0; i <= width; ++i) {
        for (int j = 0; j <= width; ++j) {
            maze[i][j] = '*';
        }
    }
}
void createMaze(char MAZE,const int width) {
    for (int i = 1; i < width; ++i) {
        for (int j = 1; j < width; ++j) {
            int r = rand() % 3;
            if (r) {
                maze[i][j] = ' ';
            }
        }
    }
}
void printMaze(char MAZE,const int width) {
    system("cls");
    for (int i = 0; i <= width; ++i) {
        for (int j = 0; j <= width; ++j) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}
void createPeople(Point &hero,char MAZE,const int width) {
    hero = getPosition(width);
    maze[hero.x][hero.y] = 'I';
}
void createExit(Point &out,Point &hero,char MAZE,const int width) {
    out = hero;
    while (out == hero)out = getPosition(width);
    maze[out.x][out.y] = 'E';
}
void moveHero(Point &hero,Point &out,char MAZE,int direction) {
    const int directionX[] = {-1, 1, 0, 0};
    const int directionY[] = {0, 0, -1, 1};
    hero.x += directionX[direction];
    hero.y += directionY[direction];
    if (hero == out) {
        system("cls");
        printf("You are Winner!!!\n");
        exit(0);
    }
    if (maze[hero.x][hero.y] == '*') {
        hero.x -= directionX[direction];
        hero.y -= directionY[direction];
        return;
    }
    maze[hero.x][hero.y] = 'I';
    maze[hero.x - directionX[direction]][hero.y - directionY[direction]] = ' ';
}
void game(Point &hero,Point &out,char MAZE,const int width) {
    char op = getche();
    while (op != QIUT) {
        switch (op) {
            case UP :
                moveHero(hero, out, maze, 0);
                break;
            case DOWN :
                moveHero(hero, out, maze, 1);
                break;
            case LETF :
                moveHero(hero, out, maze, 2);
                break;
            case RIGHT :
                moveHero(hero, out, maze, 3);
                break;
            default:
                break;
        }
        printMaze(maze, width);
        op = getche();
    }
}
