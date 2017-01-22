#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define WALL 1
#define BLANK 0
#define PLAYER 2
#define BOX 3
#define GOAL 4
#define GOAL_BOX 5
#define GOAL_PLAYER 6
#define HEIGHT 10
#define WEIGHT 10
void map_initialize(int i);
void map_printf();
int game(int lev);
char move();
int move_judge(char move);
void goal_restore();
void score_save();
void difficulty_chose();
int map[HEIGHT][WEIGHT];
int player_H,player_W;
int goal_H[10],goal_W[10];
int goal_num;
int level=1;
int score[3]={200,200,200};//初始分数
char level_chose[11]="level1e.txt";
int main()
{
    difficulty_chose();
    while(1)
    {
        map_initialize(level);
        map_printf();
        if(!game(level))//给我自己这种手残增加重置功能
        {
            system("cls");
            continue;
        }
        printf("恭喜过关\n");
        system("pause");
        system("cls");
        level++;
        if(level==4)
        {
            break;
        }
    }
    printf("恭喜你，全部过关！\n");
    score_save();
    return 0;
}
void map_initialize(int i)
{
    FILE *fp;
    level_chose[5]=i+48;
    fp=fopen(level_chose,"r");
    for(int j=0;j<WEIGHT;j++)
    {
        for(int k=0;k<HEIGHT;k++)
        {
            fscanf(fp,"%d",&map[j][k]);
        }
    }
    fscanf(fp,"%d %d",&player_H,&player_W);
    fscanf(fp,"%d",&goal_num);
    for(int j=0;j<goal_num;j++)
    {
        fscanf(fp,"%d %d",&goal_H[j],&goal_W[j]);
    }
    fclose(fp);
}
void map_printf()
{
    for(int i=0;i<HEIGHT;i++)
    {
        for(int j=0;j<WEIGHT;j++)
        {
            switch(map[i][j])
            {
                case WALL: printf("▇");break;
                case BLANK:printf("  ");break;
                case BOX:printf("●"); break;
                case PLAYER:printf("正");break;
                case GOAL:printf("О");break;
                case GOAL_BOX:printf("⊙");break;
                case GOAL_PLAYER:printf("㊣");break;
            }
        }
        printf("\n");
    }
}
int game(int lev)
{
    while(1)
    {
         int judge=move_judge(move());
         if(judge==1)
         {
             score[lev-1]--;
             goal_restore();
             for(int i=0;i<goal_num;i++)
             {
                 if(map[goal_H[i]][goal_W[i]]==BOX)
                 {
                     map[goal_H[i]][goal_W[i]]=GOAL_BOX;
                 }
                 if(map[goal_H[i]][goal_W[i]]==PLAYER)
                 {
                     map[goal_H[i]][goal_W[i]]=GOAL_PLAYER;
                 }
             }
             system("cls");
             map_printf();
         }
         if(judge==2)
         {
             return 0;
         }
         int flag=0;
         for(int i=0;i<goal_num;i++)
         {
             if(map[goal_H[i]][goal_W[i]]==GOAL_BOX)
             {
                 flag++;
             }
         }
         if(flag==goal_num)
         {
             return 1;
         }
    }
}
char move()
{
    char move;
    move=getch();
    return move;
}
int move_judge(char move)
{
    switch(move)
    {
        case 'w':
        {
            if(map[player_H-1][player_W]==WALL)
            {
                return 0;
            }
            if(map[player_H-1][player_W]==BLANK||map[player_H-1][player_W]==GOAL)
            {
                map[player_H][player_W]=BLANK;
                player_H--;
                map[player_H][player_W]=PLAYER;
                return 1;
            }
            if(map[player_H-1][player_W]==BOX||map[player_H-1][player_W]==GOAL_BOX)
            {
                if(map[player_H-2][player_W]==BLANK||map[player_H-2][player_W]==GOAL)
                {
                    map[player_H][player_W]=0;
                    player_H--;
                    map[player_H][player_W]=PLAYER;
                    map[player_H-1][player_W]=BOX;
                    return 1;
                }
                return 0;
            }
            break;
        }
        case 's':
        {
            if(map[player_H+1][player_W]==WALL)
            {
                return 0;
            }
            if(map[player_H+1][player_W]==BLANK||map[player_H+1][player_W]==GOAL)
            {
                map[player_H][player_W]=BLANK;
                player_H++;
                map[player_H][player_W]=PLAYER;
                return 1;
            }
            if(map[player_H+1][player_W]==BOX||map[player_H+1][player_W]==GOAL_BOX)
            {
                if(map[player_H+2][player_W]==BLANK||map[player_H+2][player_W]==GOAL)
                {
                    map[player_H][player_W]=0;
                    player_H++;
                    map[player_H][player_W]=PLAYER;
                    map[player_H+1][player_W]=BOX;
                    return 1;
                }
                return 0;
            }
            break;
        }
        case 'a':
        {
            if(map[player_H][player_W-1]==WALL)
            {
                return 0;
            }
            if(map[player_H][player_W-1]==BLANK||map[player_H][player_W-1]==GOAL)
            {
                map[player_H][player_W]=BLANK;
                player_W--;
                map[player_H][player_W]=PLAYER;
                return 1;
            }
            if(map[player_H][player_W-1]==BOX||map[player_H][player_W-1]==GOAL_BOX)
            {
                if(map[player_H][player_W-2]==BLANK||map[player_H][player_W-2]==GOAL)
                {
                    map[player_H][player_W]=0;
                    player_W--;
                    map[player_H][player_W]=PLAYER;
                    map[player_H][player_W-1]=BOX;
                    return 1;
                }
                return 0;
            }
            break;
        }
        case 'd':
        {
            if(map[player_H][player_W+1]==WALL)
            {
                return 0;
            }
            if(map[player_H][player_W+1]==BLANK||map[player_H][player_W+1]==GOAL)
            {
                map[player_H][player_W]=BLANK;
                player_W++;
                map[player_H][player_W]=PLAYER;
                return 1;
            }
            if(map[player_H][player_W+1]==BOX||map[player_H][player_W+1]==GOAL_BOX)
            {
                if(map[player_H][player_W+2]==BLANK||map[player_H][player_W+2]==GOAL)
                {
                    map[player_H][player_W]=0;
                    player_W++;
                    map[player_H][player_W]=PLAYER;
                    map[player_H][player_W+1]=BOX;
                    return 1;
                }
                return 0;
            }
            break;
        }
        case 'r'://关卡重置
        {
            return 2;
        }
    }
    return 0;
}
void goal_restore()
{
    for(int i=0;i<goal_num;i++)
    {
        if(map[goal_H[i]][goal_W[i]]==BLANK)
        {
            map[goal_H[i]][goal_W[i]]=GOAL;
        }
    }
}
void score_save()
{
    FILE *fp;
    fp=fopen("score.txt","w+");
    fprintf(fp,"%d\n%d\n%d",score[0],score[1],score[2]);
    fclose(fp);
}
void difficulty_chose()
{
    printf("请选择适合你的难度\n输入1:简单\n输入2:困难\n");
    int difficulty;
    scanf("%d",&difficulty);
    switch(difficulty)
    {
        case 1:level_chose[6]='e';break;
        case 2:level_chose[6]='h';break;
    }
    system("cls");
}
