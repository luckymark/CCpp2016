#include <cstdio>
#include <conio.h>
#include <cstdlib>
#define MAX 110
enum keyboard
{
    KeyW=119,
    KeyS=115,
    KeyA=97,
    KeyD=100,
    KeyUp=72,
    KeyDown=80,
    KeyLeft=75,
    KeyRight=77
};
enum blocks
{
    Start=2,
    End=3,
    EmaptyBlock=0,
    Bar=1
};
void initmap(int &n,int &m,int map[][MAX]);
void dispmap(const int &n,const int &m,const int &NowX,const int &NowY,const int map[][MAX]);
void findStartPoint(const int &n,const int &m,const int map[][MAX],int &StartX,int &StartY);
bool checkPoint(const int &n,const int &m,const int &x,const int &y,const int map[][MAX]);
void gameStart(int &n,int &m,const int &StartX,const int &StartY,int map[][MAX]);
int main()
{
    freopen("map.txt","r",stdin);
    int n,m,StartX,StartY;
    int map[MAX][MAX];
    initmap(n,m,map);
    findStartPoint(n,m,map,StartX,StartY);
    dispmap(n,m,StartX,StartY,map);
    gameStart(n,m,StartX,StartY,map);
    return 0;
}
void initmap(int &n,int &m,int map[][MAX])
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            scanf("%d",&map[i][j]);
        }
        scanf("\n");
    }
}
void dispmap(const int &n,const int &m,const int &NowX,const int &NowY,const int map[][MAX])
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(i==NowX && j==NowY)
            {
                printf("o");
            }
            else 
            {
                switch(map[i][j])
                {
                    case Bar:
                        printf("*");
                        break;
                    case Start:
                        printf("S");
                        break;
                    case End:
                        printf("T");
                        break;
                    case EmaptyBlock:
                        printf(".");     
                }
            }
        }
        printf("\n");
    }
}
void findStartPoint(const int &n,const int &m,const int map[][MAX],int &StartX,int &StartY)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(map[i][j]==Start)
            {
                StartX=i;
                StartY=j;
                break;
            }
        }
    }
}
bool checkPoint(const int &n,const int &m,const int &x,const int &y,const int map[][MAX])
{
    return x>0 && x<=n && y>0 && y<=m && map[x][y]!=Bar;
}
void gameStart(int &n,int &m,const int &StartX,const int &StartY,int map[][MAX])
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
        int TemapX=NowX+fx[dir];
        int TemapY=NowY+fy[dir];
        if(checkPoint(n,m,TemapX,TemapY,map))
        {
            if(map[TemapX][TemapY]==3)
            {
                system("cls");
                printf("You Win!\n");
                return ;
            }
            NowX=TemapX,NowY=TemapY;
        }
        system("cls");
        dispmap(n,m,NowX,NowY,map);
    }
}
