#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
using namespace std;
#define MAXN 100
#define MAXM 100
#define GOAL 1
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define FN 224
int mazen,mazem,posx,posy;
char maze[MAXN+10][MAXM+10];
void readMaze(int *n,int *m);
void printMaze(int n,int m);
int moveMaze(int ch);
int main(){
    readMaze(&mazen,&mazem);
    while(1){
        printMaze(mazen,mazem);
        int ch = getch() , ret;
        if(ch != FN)continue;
        ch = getch();
        ret = moveMaze(ch);
        if(ret == GOAL){
            system("cls");
            printf("GOAL!!!!!!!!\n");
            break;
        }
    }
    system("pause");
    return 0;
}
void readMaze(int *n,int *m){
    freopen("input.txt","r",stdin);
    int cnt=1;
    scanf("%d%d\n",n,m);
    for(int i=1;i<=*n;++i){
        fgets(maze[i]+1,MAXM,stdin);
        for(int j=1;maze[i][j] != '\0';++j){
            if(maze[i][j] == '*'){
                posx = cnt;
                posy = j;
            }else if(maze[i][j] == '\n'){
                maze[i][j] = '#';
            }
        }
        maze[i][0] = '#';
    }
}
void printMaze(int n,int m){
    system("cls");
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            putchar(maze[i][j]);
        }
        putchar('\n');
    }
}
int moveMaze(int ch){
    const int dx[]={-1,0,1,0},dy[]={0,1,0,-1};
    int dir;
    if(ch == UP){
        dir = 0;
    }else if(ch == RIGHT){
        dir = 1;
    }else if(ch == DOWN){
        dir = 2;
    }else if(ch == LEFT){
        dir = 3;
    }
    if(maze[posx+dx[dir]][posy+dy[dir]] == ' '){//Can move
        maze[posx+dx[dir]][posy+dy[dir]] = '*';
        maze[posx][posy] = ' ';
        posx += dx[dir];
        posy += dy[dir];
        if(posx == mazen || posy == mazem){ // Goal
            return 1;
        }
    }else{
        return -1;
    }
    return 0;
}
