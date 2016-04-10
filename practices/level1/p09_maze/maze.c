#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <stdlib.h>
#define Wall 1
#define Road 0
#define Start 2
#define End 3
#define Esc 5
#define Up 1
#define Down 2
#define Left 3
#define Right 4
#define Player 6
#define Height 23//迷宫的高度，必须为奇数
#define Width 23 //迷宫的宽度，必须为奇数
int player_x=2,player_y=1;
int map[Height+2][Width+2];
char key;
void create(int x,int y) //随机生成迷宫
{
	int c[4][2]={0,1,1,0,0,-1,-1,0}; //四个方向
	int i,j,t;
		//将方向打乱
	for(i=0;i<4;i++)
	{
		j=rand()%4;
		t=c[i][0];c[i][0]=c[j][0];c[j][0]=t;
		t=c[i][1];c[i][1]=c[j][1];c[j][1]=t;
	}
	map[x][y]=Road;
	for(i=0;i<4;i++)
	if(map[x+2*c[i][0]][y+2*c[i][1]]==Wall)
	{
		map[x+c[i][0]][y+c[i][1]]=Road;
		create(x+2*c[i][0],y+2*c[i][1]);
	}
}
void paint(int x,int y) //画迷宫
{
	switch(map[x][y])
	{
		case Start:
            printf("入");break; //画入口
		case End:
            printf("出");break; //画出口
		case Wall:
            printf("▇");break; //画墙
		case Road:
            printf("  ");break; //画路
		case Player:
            printf("●");break;//画人
	}
	if(y==Width)
    {
        printf("\n");
    }
}
void game()
{
    key=getch();
    while(judge_move())
    {
        system("cls");
        for(int i=1;i<=Height;i++)
        {
            for(int j=1;j<=Width;j++) //画出迷宫
            {
                paint(i,j);
            }
        }
        key=getch();
    }
}
int judge_move()
{
    switch(key)
    {
        case 'w':
            if(map[player_x-1][player_y]==Wall)
            {
                return 1;
            }
            else if(map[player_x-1][player_y]==Road)
            {
                map[player_x-1][player_y]=Player;
                map[player_x][player_y]=Road;
                player_x--;
                return 1;
            }
            else if(map[player_x-1][player_y]==End)
            {
                map[player_x-1][player_y]=Player;
                map[player_x][player_y]=Road;
                player_x--;
                return 0;
            }
            break;
        case 's':
            if(map[player_x+1][player_y]==Wall)
            {
                return 1;
            }
            else if(map[player_x+1][player_y]==Road)
            {
                map[player_x+1][player_y]=Player;
                map[player_x][player_y]=Road;
                player_x++;
                return 1;
            }
            else if(map[player_x+1][player_y]==End)
            {
                map[player_x+1][player_y]=Player;
                map[player_x][player_y]=Road;
                player_x++;
                return 0;
            }
            break;
        case 'd':
            if(map[player_x][player_y+1]==Wall)
            {
                return 1;
            }
            else if(map[player_x][player_y+1]==Road)
            {
                map[player_x][player_y+1]=Player;
                map[player_x][player_y]=Road;
                player_y++;
                return 1;
            }
            else if(map[player_x][player_y+1]==End)
            {
                map[player_x][player_y+1]=Player;
                map[player_x][player_y]=Road;
                player_x++;
                return 0;
            }
            break;
        case 'a':
            if(map[player_x][player_y-1]==Wall)
            {
                return 1;
            }
            else if(map[player_x][player_y-1]==Road)
            {
                map[player_x][player_y-1]=Player;
                map[player_x][player_y]=Road;
                player_y--;
                return 1;
            }
            else if(map[player_x][player_y-1]==End)
            {
                map[player_x][player_y-1]=Player;
                map[player_x][player_y]=Road;
                player_x--;
                return 0;
            }
            break;
    }
    return 1;
}
int main()
{
	int i,j;
	srand((unsigned)time(NULL)); //初始化随即种子
	for(i=0;i<=Height+1;i++)
	for(j=0;j<=Width+1;j++)
	if(i==0||i==Height+1||j==0||j==Width+1) //初始化迷宫
	map[i][j]=Road;
	else map[i][j]=Wall;
	create(2*(rand()%(Height/2)+1),2*(rand()%(Width/2)+1)); //从随机一个点开始生成迷宫，该点行列都为偶数
	for(i=0;i<=Height+1;i++) //边界处理
	{
		map[i][0]=Wall;
		map[i][Width+1]=Wall;
	}
	for(j=0;j<=Width+1;j++) //边界处理
	{
		map[0][j]=Wall;
		map[Height+1][j]=Wall;
	}
	map[2][1]=Player; //给定入口
	map[Height-1][Width]=End; //给定出口
	for(i=1;i<=Height;i++)
	for(j=1;j<=Width;j++) //画出迷宫
	paint(i,j);
	game(); //开始游戏
	printf("\n恭喜过关！\n");
	return 0;
}
