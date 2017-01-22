#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
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
int manynum=1;
int manxnum=1;
//�˵�λ��
void showMap(void);
//��ʾ��ͼ
void moveJudge(int ynum,int xnum);
//�ж������Ӱ��
void Move(void);
//�����ƶ�
void gameStart(void);
//��Ϸ��ʼ
int main()
{
    gameStart();
    return 0;
}
void gameStart(void)
{
    for (;;)
    {
        system("cls");
        printf("WSAD����@����������ƶ������ڴ���ʤ��\n");
        showMap();
        Move();
        if ((manynum==10)&&(manxnum==11))
        {
            system("cls");
            printf("WSAD����@����������ƶ������ڴ���ʤ��\n");
            showMap();
            break;
        }
    }
    system("pause");
    system("cls");
    printf("congratulations!");
}
void showMap(void)
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
        case 'W':moveJudge(-1,0);
                 break;
        case 's':
        case 'S':moveJudge(1,0);
                 break;
        case 'a':
        case 'A':moveJudge(0,-1);
                 break;
        case 'd':
        case 'D':moveJudge(0,1);
                 break;
    }
}
void moveJudge(int ynum,int xnum)
{
    if (' '==map[manynum+ynum][manxnum+xnum])
    {
        map[manynum+ynum][manxnum+xnum]='@';
        map[manynum][manxnum]=' ';
        manynum=manynum+ynum;
        manxnum=manxnum+xnum;
    }
}
