#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <conio.h>
using namespace std;
const int maxPoint=1000;
int len[100],maze[100][100],n,x,y,point;
char c;
bool can[100][100];
int xx[4]={0,0,1,-1};
int yy[4]={-1,1,0,0};

void read();
void move(int dir);
bool over();
void getOut(int o);
void play();

int main()
{
    read();
    play();
}

void play()
{
    point=maxPoint;
    while (1)
    {
        c=getch();
        if (c=='l') move(0);
        if (c=='r') move(1);
        if (c=='d') move(2);
        if (c=='u') move(3);
        if (over())
        {
            getOut(1);
            return;
        } else
        {
            getOut(0);
        }
    }
}

void getOut(int o)
{
    int i,j;
    system("cls");
    for (i=1;i<=n;i++)
    {
        for (j=1;j<=len[i];j++)
        {
            if (maze[i][j]==0)
            {
                printf("*");
            }
            if (maze[i][j]==1)
            {
                if (can[i][j])
                {
                    printf("g");
                } else
                {
                    printf(".");
                }
            }
            if (maze[i][j]==2)
            {
                if (can[i][j])
                {
                    printf("B");
                } else
                {
                    printf("b");
                }
            }
            if (maze[i][j]==3)
            {
                if (can[i][j])
                {
                    printf("P");
                } else
                {
                    printf("p");
                }
            }
        }
        printf("\n");
    }

    if (o==1)
    {
        printf("You win!\nThe last step is %d\nThe last grade is %d\n",maxPoint-point,point);
    } else
    {
        printf("step:%d\npoint:%d\n",maxPoint-point,point);
    }
}

bool over()
{
    int i,j;
    for (i=1;i<=n;i++)
    {
        for (j=1;j<=len[i];j++)
        if (maze[i][j]==2 && !can[i][j])
        {
            return false;
        }
    }
    return true;
}

void move(int dir)
{
    int tx,ty,newx,newy;
    newx=x+xx[dir];
    newy=y+yy[dir];
    if (maze[newx][newy]==0)
    {
        return;
    }
    if (maze[newx][newy]==1)
    {
        maze[newx][newy]=3;
        maze[x][y]=1;
        x=newx;
        y=newy;
        point--;
        return;
    }
    if (maze[newx][newy]==2)
    {
        tx=newx+xx[dir];
        ty=newy+yy[dir];
        if (maze[tx][ty]==0 || maze[tx][ty]==2)
        {
            return;
        }
        maze[tx][ty]=2;
        maze[newx][newy]=3;
        maze[x][y]=1;
        x=newx; y=newy;
        point--;
    }
}

void read()
{
    int i,j,l;
    char s[100];
    scanf("%d\n",&n);
    for (i=1;i<=n;i++)
    {
        gets(s);
        l=strlen(s);
        len[i]=l;
        for (j=0;j<l;j++)
        {
            if (s[j]=='.')
            {
                maze[i][j+1]=1;
            }
            if (s[j]=='b')
            {
                maze[i][j+1]=2;
            }
            if (s[j]=='g')
            {
                maze[i][j+1]=1;
                can[i][j+1]=true;
            }
            if (s[j]=='B')
            {
                maze[i][j+1]=2;
                can[i][j+1]=true;
            }
            if (s[j]=='p' || s[j]=='P')
            {
                maze[i][j+1]=3;
                x=i;
                y=j+1;
                if (s[j]=='P')
                {
                    can[i][j+1]=true;
                }
            }
        }
    }
}
