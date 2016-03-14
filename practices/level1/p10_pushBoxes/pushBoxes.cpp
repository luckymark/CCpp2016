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
#define Boxes 'o'
#define EmptyBlock ' '
#define Bar '*'
#define ExceptEntry 'T'
#define NowPoint '.'
void Initmap(const int &n,const int &m,char mp[][MAX])
{
    freopen("map.txt","r",stdin);
    scanf("%d%d\n",&n,&m);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            scanf("%c",&mp[i][j]);
        }
        scanf("\n");
    }
}
void Dispmap(const int &n,const int &m,const int &NowX,const int &NowY,const char mp[][MAX])
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(i==NowX && j==NowY)
            {
                printf(".");
            }
            else if(mp[i][j]==Bar)
            {
                printf("*");
            }
            else if(mp[i][j]==Boxes)
            {
                printf("o");
            }
            else if(mp[i][j]==ExceptEntry)
            {
                printf("T");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}
void FindStartPoint(const int &n,const int &m,const char mp[][MAX],int &StartX,int &StartY)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(mp[i][j]==NowPoint)
            {
                StartX=i;
                StartY=j;
                break;
            }
        }
    }
}
bool CheckPoint(const int &dir,const int &n,const int &m,const int &x,const int &y)
{
    if(x>0 && x<=n && y>0 && y<=m)
    {

    }
    else
    {
        return false;
    }
}
void GameStart(int &n,int &m,const int &StartX,const int &StartY,char mp[][MAX])
{
    int NowX,NowY,CompleteBoxesNum=0;
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
        if(CheckPoint(n,m,TempX,TempY))
        {
            if(mp[TempX][TempY]==Boxes)
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
    char mp[MAX][MAX];
    Initmap(n,m,mp);
    FindStartPoint(n,m,mp,StartX,StartY);
    Dispmap(n,m,StartX,StartY,mp);
    GameStart(n,m,StartX,StartY,mp);
    return 0;
}
