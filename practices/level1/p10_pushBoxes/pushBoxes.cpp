#include <cstdio>
#include <conio.h>
#include <cstdlib>
#include <windows.h>
#define MAX 110
enum gameControl
{
    SleepTime=3000,
    GameTimes=3
};
enum keyboard
{
    KeyR=114,
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
    Boxes='o',
    EmaptyBlock=' ',
    Bar='*',
    ExceptEntry='T',
    NowPoint='X'
};
bool initmap(int &n,int &m,char map[][MAX]);
void dispmap(const int &n,const int &m,const int &NowX,const int &NowY,const char map[][MAX],const bool isBox[][MAX],const int &stepNum);
void findStartPoint(const int &n,const int &m,char map[][MAX],int &StartX,int &StartY,bool isBox[][MAX],int &boxNum);
bool checkPersonPoint(const int &n,const int &m,const int &x,const int &y,const char map[][MAX],const bool isBox[][MAX]);
bool checkBoxPoint(const int &n,const int &m,const int &x,const int &y,const char map[][MAX],const bool isBox[][MAX]);
void gameStart(int &n,int &m,const int &StartX,const int &StartY,char map[][MAX],bool isBox[][MAX],const int &boxNum);
int main()
{
    freopen("map.txt","r",stdin);
    int n,m;
    char map[MAX][MAX];
    bool isBox[MAX][MAX];
    while(initmap(n,m,map))
    {
        int StartX,StartY,boxNum=0;
        memset(isBox,false,sizeof(isBox));
        findStartPoint(n,m,map,StartX,StartY,isBox,boxNum);
        gameStart(n,m,StartX,StartY,map,isBox,boxNum);
    }
    return 0;
}
bool initmap(int &n,int &m,char map[][MAX])
{
    if(scanf("%d%d\n",&n,&m) == 2)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                scanf("%c",&map[i][j]);
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
void dispmap(const int &n,const int &m,const int &NowX,const int &NowY,const char map[][MAX],const bool isBox[][MAX],const int &stepNum)
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
            else if(isBox[i][j])
            {
                printf("o");
            }
            else
            {
                switch(map[i][j])
                {
                    case Bar:
                        printf("#");
                        break;
                    case ExceptEntry:
                        printf("T");
                        break;
                    case EmaptyBlock:
                        printf(" ");
                        break;
                }
            }
            
            // if(map[i][j]==Bar)
            // {
            //     printf("#");
            // }
            // else if(isBox[i][j])
            // {
            //     printf("o");
            // }
            // else if(map[i][j]==ExceptEntry)
            // {
            //     printf("T");
            // }
            // else
            // {
            //     printf(" ");
            // }
        }
        printf("\n");
    }
    printf("Your step: %d\n",stepNum);
    printf("Press 'R' to restart this case.");
}
void findStartPoint(const int &n,const int &m,char map[][MAX],int &StartX,int &StartY,bool isBox[][MAX],int &boxNum)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(map[i][j]==NowPoint)
            {
                StartX=i;
                StartY=j;
            }
            if(map[i][j]==Boxes)
            {
                ++boxNum;
                map[i][j]=EmaptyBlock;
                isBox[i][j]=true;
            }
        }
    }
}
bool checkPersonPoint(const int &n,const int &m,const int &x,const int &y,const char map[][MAX],const bool isBox[][MAX])
{
    return x>0 && x<=n && y>0 && y<=m && map[x][y]!=Bar;
}
bool checkBoxPoint(const int &n,const int &m,const int &x,const int &y,const char map[][MAX],const bool isBox[][MAX])
{
    return x>0 && x<=n && y>0 && y<=m && map[x][y]!=Bar && !isBox[x][y];
}
void gameStart(int &n,int &m,const int &StartX,const int &StartY,char map[][MAX],bool isBox[][MAX],const int &boxNum)
{
    const int fx[]={-1,0,1,0};
    const int fy[]={0,1,0,-1};
    char originMap[MAX][MAX];
    int originisBox[MAX][MAX];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            originMap[i][j]=map[i][j];
            originisBox[i][j]=isBox[i][j];
        }
    }
    reset:
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            map[i][j]=originMap[i][j];
            isBox[i][j]=originisBox[i][j];
        }
    }
    dispmap(n,m,StartX,StartY,map,isBox,0);
    int NowX,NowY,ComapleteBoxesNum=0,stepNum=0;
    NowX=StartX,NowY=StartY;
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
        else if(step==KeyR)
        {
            goto reset;
        }
        else
        {
            continue;
        }
        int TemapX=NowX+fx[dir];
        int TemapY=NowY+fy[dir];
        if(checkPersonPoint(n,m,TemapX,TemapY,map,isBox))
        {
            if(isBox[TemapX][TemapY])
            {
                int BoxX=TemapX+fx[dir];
                int BoxY=TemapY+fy[dir];
                if(checkBoxPoint(n,m,BoxX,BoxY,map,isBox))
                {
                    isBox[BoxX][BoxY]=true;
                    isBox[TemapX][TemapY]=false;
                    if(map[BoxX][BoxY]==ExceptEntry)
                    {
                        ++ComapleteBoxesNum;
                    }
                    if(map[TemapX][TemapY]==ExceptEntry)
                    {
                        --ComapleteBoxesNum;
                    }
                }
                else
                {
                    continue;
                }
            }
            NowX=TemapX,NowY=TemapY;
        }
        ++stepNum;
        dispmap(n,m,NowX,NowY,map,isBox,stepNum);

        if(ComapleteBoxesNum==boxNum)
        {
            system("cls");
            printf("You Win!\nLoading the next case...\n");
            Sleep(SleepTime);
            return ;
        }
    }
}
