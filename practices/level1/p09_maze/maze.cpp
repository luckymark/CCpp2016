#include <iostream>
#include <cstdio>
#include <ctime>
#include <algorithm>
#define Maxn 1100
using namespace std;
int map[Maxn][Maxn],use[Maxn][Maxn],x,y,n,m;
char s[Maxn];
int xx[4]={-1,0,1,0};
int yy[4]={0,1,0,-1};

void read();
bool search(int ,int );

int main()
{
    srand(time(NULL));
    read();
    if (search(x,y))
    {
        printf("YES\n");
    }
    else 
    {
        printf("NO\n")；
    }
}

void read()
{
    //假设迷宫是个n*m的矩阵，0代表墙，1代表空地，2代表出口.
    //x,y分表代表起始点坐标
    scanf("%d%d%d%d\n",&n,&m,&x,&y);
    for (int i=1;i<=n;i++)
    {
        gets(s);
        for (int j=1;j<=m;j++)
        {
            map[i][j]=int(s[j-1])-48;
        }
    }
}

bool search(int x,int y)
{
    int newx,newy,i;
    if (use[x][y]==1) return false;
    use[x][y]=1;
    for (i=0;i<=3;i++)
    {
        newx=x+xx[i];
        newy=y+yy[i];
        if (map[newx][newy]==0)
        {
            continue;
        }
        if (map[newx][newy]==2) 
        {
            return true;
        }
        if (search(newx,newy))
        {
            return true;
        }
    }
    return false;
}
