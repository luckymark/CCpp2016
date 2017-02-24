#include <stdio.h>
#include <windows.h>
#include <conio.h>
#define  SIZE                        10
const    int                         map[SIZE]={1020,961,989,797,991,799,967,927,831,127};
#define  SEARCH(x,y)                 (map[x]>>(SIZE-y-1))&1
#define  CANMOVE(x,y)                (!(SEARCH(x,y)))&&(x>=0)&&(x<SIZE)&&(y<SIZE)&&(y>=0)

void     refresh                     (const int x,const int y);
void     checkCommand                (int* const x,int* const y,const int command);



int main()
{
    int man_x=9,man_y=0;
    puts("按w s a d移动人物，按q退出游戏");
    system("pause");
    while(man_x!=0||man_y!=9)
    {
        refresh(man_x,man_y);
        checkCommand(&man_x,&man_y,getch()|32);
    }
    puts("游戏结束");
    system("pause");
}


void refresh(const int x,const int y)
{
    system("cls");
    for(int i=0;i<SIZE;i++)
    {
        for(int j=0;j<SIZE;j++)
        {
            if(x==i&&y==j)
            {
                putchar('o');
            }
            else if(SEARCH(i,j)!=0)
            {
                putchar('+');
            }
            else
            {
                putchar(' ');
            }
        }
        putchar('\n');
    }
}


void checkCommand(int* const x,int* const y,const int command)
{
    int tempX=*x,tempY=*y;
    switch (command)
    {
        case 'w':tempX=*x-1;break;
        case 's':tempX=*x+1;break;
        case 'a':tempY=*y-1;break;
        case 'd':tempY=*y+1;break;
        case 'q':*x=0;*y=9;return;//用了return很开心的发现刚好对其了
        default :          return;
    }
    if(CANMOVE(tempX,tempY))
    {
        *x=tempX;
        *y=tempY;
    }
}
