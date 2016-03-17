#include <cstdio>
#include <conio.h>
#include <cstdlib>
using namespace std;
#define MAX 110
#define KeyW 119
#define KeyS 115
#define KeyA 97
#define KeyD 100
#define KeyUp 72
#define KeyDown 80
#define KeyLeft 75
#define KeyRight 77
#define Start 2
#define End 3
#define EmptyBlock 0
#define Bar 1
void Initmap(const int &n,const int &m,int mp[][MAX])
{
    freopen("map.txt","r",stdin);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            scanf("%d",&mp[i][j]);
        }
        scanf("\n");
    }
}
void Dispmap(const int &n,const int &m,const int &NowX,const int &NowY,const int mp[][MAX])
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(i==NowX && j==NowY)
            {
                printf("o");
            }
            else if(mp[i][j]==Bar)
            {
                printf("*");
            }
            else if(mp[i][j]==Start)
            {
                printf("S");
            }
            else if(mp[i][j]==End)
            {
                printf("T");
            }
            else
            {
                printf(".");
            }
        }
        printf("\n");
    }
}
void FindStartPoint(const int &n,const int &m,const int mp[][MAX],int &StartX,int &StartY)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(mp[i][j]==Start)
            {
                StartX=i;
                StartY=j;
                break;
            }
        }
    }
}
bool CheckPoint(const int &n,const int &m,const int &x,const int &y,const int mp[][MAX])
{
    return x>0 && x<=n && y>0 && y<=m && mp[x][y]!=Bar;
}
void GameStart(int &n,int &m,const int &StartX,const int &StartY,int mp[][MAX])
{
    int NowX,NowY;
    NowX=StartX,NowY=StartY;
    const int fx[]={-1,0,1,0};
    const int fy[]={0,1,0,-1};
    while(1)
    {
        int step=getch(),dir;
        if(step==KeyUp || step==KeyW)
        {
            dir=0;
        }
        else if(step==KeyDown || step==KeyS)
        {
            dir=2;
        }
        else if(step==KeyLeft || step==KeyA)
        {
            dir=3;
        }
        else if(step==KeyRight || step==KeyD)
        {
            dir=1;
        }
        else
        {
            continue;
        }
        int TempX=NowX+fx[dir];
        int TempY=NowY+fy[dir];
        if(CheckPoint(n,m,TempX,TempY,mp))
        {
            if(mp[TempX][TempY]==3)
            {
                system("cls");
                printf("You Win!\n");
                return ;
            }
            NowX=TempX,NowY=TempY;
        }
        system("cls");
        Dispmap(n,m,NowX,NowY,mp);
    }
}
int main()
{
    int n,m,StartX,StartY;
    int mp[MAX][MAX];
    Initmap(n,m,mp);
    FindStartPoint(n,m,mp,StartX,StartY);
    Dispmap(n,m,StartX,StartY,mp);
    GameStart(n,m,StartX,StartY,mp);
    return 0;
}
