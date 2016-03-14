#include <bits/bits/stdc++.h>
using namespace std;
#define MAXN 100
#define MAXM 100
#define WALL 1
#define BLANK 0
#define POS 2
int mazen,mazem;
int maze[MAXN][MAXM];
void printMaze(int n,int m);
int main(){
    return 0;
}
void printMaze(int n,int m){
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            if(maze[i][j] == WALL)
                putchar('#'); // WALL
            else if(maze[i][j] == BLANK)
                putchar(' ');
            else if(maze[i][j] == POS)
                putchar('*');
            else{
                // Invaild Value
            }
        }
        putchar('\n');
    }
}
