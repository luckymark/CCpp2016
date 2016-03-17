#include <cstdio>
#include <conio.h>
#include <cstdlib>
#include <windows.h>
using namespace std;
#define SleepTime 500
#define GameTimes 3
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
#define NowPoint 'X'
bool Initmap(const int &n,const int &m,char mp[][MAX])
{
    if(scanf("%d%d\n",&n,&m) == 2)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                scanf("%c",&mp[i][j]);
            }
            scanf("\n");
        }
        return true;
    }
    else
    {
        return false;
    }
}
void Dispmap(const int &n,const int &m,const int &NowX,const int &NowY,const char mp[][MAX],const bool isBox[][MAX])
{
    system("cls");
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(i==NowX && j==NowY)
            {
                printf("X");
            }
            else if(mp[i][j]==Bar)
            {
                printf("#");
            }
            else if(isBox[i][j])
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
void FindStartPoint(const int &n,const int &m,char mp[][MAX],int &StartX,int &StartY,bool isBox[][MAX],int &boxNum)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(mp[i][j]==NowPoint)
            {
                StartX=i;
                StartY=j;
            }
            if(mp[i][j]==Boxes)
            {
                ++boxNum;
                mp[i][j]=EmptyBlock;
                isBox[i][j]=true;
            }
        }
    }
}
bool CheckPersonPoint(const int &n,const int &m,const int &x,const int &y,const char mp[][MAX],const bool isBox[][MAX])
{
    return x>0 && x<=n && y>0 && y<=m && mp[x][y]!=Bar;
}
bool CheckBoxPoint(const int &n,const int &m,const int &x,const int &y,const char mp[][MAX],const bool isBox[][MAX])
{
    return x>0 && x<=n && y>0 && y<=m && mp[x][y]!=Bar && !isBox[x][y];
}
void GameStart(int &n,int &m,const int &StartX,const int &StartY,char mp[][MAX],bool isBox[][MAX],const int &boxNum)
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
        if(CheckPersonPoint(n,m,TempX,TempY,mp,isBox))
        {
            if(isBox[TempX][TempY])
            {
                int BoxX=TempX+fx[dir];
                int BoxY=TempY+fy[dir];
                if(CheckBoxPoint(n,m,BoxX,BoxY,mp,isBox))
                {
                    isBox[BoxX][BoxY]=true;
                    isBox[TempX][TempY]=false;
                    if(mp[BoxX][BoxY]==ExceptEntry)
                    {
                        ++CompleteBoxesNum;
                    }
                    if(mp[TempX][TempY]==ExceptEntry)
                    {
                        --CompleteBoxesNum;
                    }
                }
                else
                {
                    continue;
                }
            }
            NowX=TempX,NowY=TempY;
        }
        Dispmap(n,m,NowX,NowY,mp,isBox);
        if(CompleteBoxesNum==boxNum)
        {
            system("cls");
            printf("You Win!\nLoading the next case...\n");
            Sleep(SleepTime);
            return ;
        }
    }
}
int main()
{
        freopen("map.txt","r",stdin);
    int n,m,StartX,StartY,boxNum=0;
    char mp[MAX][MAX];
    bool isBox[MAX][MAX];
    while(Initmap(n,m,mp))
    {
        memset(isBox,false,sizeof(isBox));
        FindStartPoint(n,m,mp,StartX,StartY,isBox,boxNum);
        Dispmap(n,m,StartX,StartY,mp,isBox);
        GameStart(n,m,StartX,StartY,mp,isBox,boxNum);
    }
    return 0;
}
