//
//  main.cpp
//  maze
//
//  Created by iam24 on 16/3/16.
//  Copyright © 2016年 iam24. All rights reserved.
//
#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
int movex[30];
int movey[30];
const int MAXN = 10;
char maze[MAXN][MAXN] = {
    '#','#','#','#','#','P','#','#','#','#',
    '#',' ','#',' ',' ',' ',' ',' ',' ','#',
    '#',' ','#',' ','#','#','#','#','#','#',
    '#',' ','#',' ','#',' ',' ',' ',' ','#',
    '#',' ',' ',' ','#',' ','#','#',' ','#',
    '#',' ','#',' ',' ',' ','#',' ',' ','#',
    '#',' ','#',' ','#',' ','#','#',' ','#',
    '#',' ','#','#','#','#','#','#',' ','#',
    '#',' ',' ',' ','#',' ',' ',' ',' ','#',
    '#','#','#','#','#','W','#','#','#','#' };
void print(int x, int y);
void work();

int main()
{
    work();
    return 0;
}
void work()
{
    printf("请用'w','s','a','d'控制上下左右\n");
    int x = 0, y = MAXN/2;
    char move;
    print(x, y);
    movex['w'-'a']=-1; movex['s'-'a']=1;
    movey['a'-'a']=-1; movey['d'-'a']=1;
    while (true)
    {
        scanf("%c", &move);
        int t = move -'a';
        int nx = x+movex[t];
        int ny = y+movey[t];
        if (ny>=0 && ny<=MAXN-1 && nx>=0 && nx<=MAXN-1 && maze[nx][ny]!='#')
        {
            x = nx;
            y = ny;
            print(x,y);
            if (x == MAXN-1 && y == MAXN/2)
            {
                printf("successful!\n");
                break;
            }
        }
    }
}
void print(int x , int  y)
{
    for (int i = 0 ;i < MAXN ;i++)
    {
        for (int j = 0 ;j < MAXN ;j++)
            if (i == x && j == y)
                printf("P");
            else
                printf("%c",maze[i][j]);
        printf("\n");
    }
}