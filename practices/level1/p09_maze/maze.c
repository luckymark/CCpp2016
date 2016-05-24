#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#define SIZE 11
#define MSIZE SIZE + 40
#define UP 72
#define LEFT 75
#define DOWN 80
#define RIGHT 77
#define START_x 2
#define START_y 1
#define GOAL_x SIZE - 1
#define GOAL_y SIZE
#define RANDOMIZE(); srand((unsigned)time(NULL));

char map[MSIZE][MSIZE];
void buildmaze(char map[][MSIZE]);
void showmaze(int x,int y,char map[][MSIZE]);
void work();
int check_w_build(int x,int y);
void paint(int x,int y);
int check(int x,int y);

int main()
{
    buildmaze(map);
    showmaze(START_x,START_y,map);
    work();
    printf("Finish > < ");
}
void showmaze(int x,int y,char map[][MSIZE])
{
    int i,j;
    system("cls");
    char mapxy;
    mapxy = map[x][y];
    map[x][y] = '*';
    for (int i = 1;i <= SIZE;i++)
        printf("%s\n",map[i]);
    printf("\n");
    map[x][y] = mapxy;
}
void work()
{
    int x = START_x,y = START_y,key;
    while(map[x][y] != '!')
    {
        key = getch();
        switch(key)
        {
        case RIGHT  :
            if (check(x,y + 1) && map[x][y + 1] != '#')  y++;
            break;
        case UP:
            if (check(x - 1,y) && map[x - 1][y] != '#')  x--;
            break;
        case LEFT :
            if (check(x,y - 1) && map[x][y - 1] != '#')  y--;
            break;
        case DOWN:
            if (check(x + 1,y) && map[x + 1][y] != '#')  x++;
            break;
        default:
            continue;
        }
        showmaze(x,y,map);
    }
}
int check(int x,int y)
{
    if (x <= SIZE && x >= 0 && y <= SIZE && y >= 0)
        return 1;
    return 0;
}
void buildmaze(char map[][MSIZE])
{
    int i,j,x,y;
    for (i = 0;i <= SIZE + 1;i++)
    {
        map[0][i] = ' ';map[i][0] = ' ';
        map[SIZE + 1][i] = ' ';map[i][SIZE + 1] = ' ';
    }
    for (i = 1;i <= SIZE;i++)
        for (j = 1;j <= SIZE;j++)
            map[i][j] = '#';
    map[START_x][START_y] = ' ';
    map[GOAL_x][GOAL_y] = '!';
    RANDOMIZE();
    x = rand() % (SIZE - 2) + 1;y = rand() % (SIZE - 2) + 2;
    x += x % 2; y += y % 2;
    paint(x,y);
}
void paint(int x,int y)
{
    int i,n;
    map[x][y] = ' ';
    int directions[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
    int t;
    for (i = 0;i < 4;i++)
    {
        RANDOMIZE();
        n = rand() % 4;
        t = directions[i][0];directions[i][0] = directions[n][0];directions[n][0] = t;
        t = directions[i][1];directions[i][1] = directions[n][1];directions[n][1] = t;
    }
    for (i = 0;i < 4;i++)
    {
        if (check_w_build(x + directions[i][0] * 2,y + directions[i][1] * 2))
        {
            map[x + directions[i][0]][y + directions[i][1]] = ' ';
            paint(x + directions[i][0] * 2,y + directions[i][1] * 2);
        }
    }
}
int check_w_build(int x,int y)
{
    if (x < START_x || x > GOAL_x) return 0;
    if (y < START_y || y > GOAL_y) return 0;
    if (map[x][y] != '#') return 0;
    return 1;
}
