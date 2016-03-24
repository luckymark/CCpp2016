#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
char map[12][12]=
{
    '#','#','#','#','#','#','#','#','#','#','#','#',
    '#','@',' ',' ',' ',' ',' ',' ','#','#','#','#',
    '#','#',' ','#','#','#','#',' ','#','#','#','#',
    '#','#',' ','#','#','#','#','#','#','#','#','#',
    '#',' ',' ','#',' ',' ',' ',' ',' ',' ','#','#',
    '#',' ','#','#',' ','#',' ','#','#',' ','#','#',
    '#',' ',' ','#',' ','#',' ','#','#',' ','#','#',
    '#','#',' ','#',' ','#',' ','#','#',' ','#','#',
    '#','#',' ',' ',' ','#',' ','#','#',' ',' ','#',
    '#','#','#','#','#','#',' ','#','#','#',' ','#',
    '#','#','#','#','#','#','#','#','#','#',' ',' ',
    '#','#','#','#','#','#','#','#','#','#','#','#'
};
int ynum=1;
int xnum=1;
//人的位置
void ShowMap(void);
//显示地图
void Judge(int ymove,int xmove);
//判断输入的影响
void Move(void);
//物体移动
void GameStart(void);
//游戏开始
int main()
{
    GameStart();
    return 0;
}
void GameStart(void)
{
    for (;;)
    {
        system("cls");
        printf("WSAD控制@代表的人物移动至出口处即胜利\n");
        ShowMap();
        Move();
        if ((ynum==10)&&(xnum==11))
        {
            system("cls");
            printf("WSAD控制@代表的人物移动至出口处即胜利\n");
            ShowMap();
            break;
        }
    }
    system("pause");
    system("cls");
    printf("congratulations!");
}
void ShowMap(void)
{
    for (int i=0;i<=11;i++)
    {
        for (int j=0;j<=11;j++)
        {
            printf("%c",map[i][j]);
        }
        printf("\n");
    }
}
void Move(void)
{
    char direction;
    direction=getch();
    switch (direction)
    {
        case 'w':
        case 'W':Judge(-1,0);
                 break;
        case 's':
        case 'S':Judge(1,0);
                 break;
        case 'a':
        case 'A':Judge(0,-1);
                 break;
        case 'd':
        case 'D':Judge(0,1);
                 break;
    }
}
void Judge(int ymove,int xmove)
{
    if (' '==map[ynum+ymove][xnum+xmove])
    {
        map[ynum+ymove][xnum+xmove]='@';
        map[ynum][xnum]=' ';
        ynum=ynum+ymove;
        xnum=xnum+xmove;
    }
}
