#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

enum RESULT{
    FINISH,NO
};

enum CAOZUO{
    BEGINNING,UP,DOWN,RIGHT,LEFT,INPUT_ERROR,MOVE_ERROR
};

enum MIGONG{
    HENGX,SHUX,SPACE,PLAYER
};

int painting(int n);
int control(int k);
int judge(int x,int y);
int pointpaint(int a);

int main()
{
    int k=BEGINNING,judged;
    do{
        judged=painting(control(k));
    }while((k=getch())!=0&&(judged!=FINISH));
    printf("You win!");
    return 0;
}

int judge(int x,int y){
    if(x==6&&y==7){
        return FINISH;
    }else{
        return NO;
    }
}

int control(int a){
    int operation;
    switch(a)
    {
       case 72:
        operation=UP;
        break;
       case 80:
        operation=DOWN;
        break;
       case 75:
        operation=LEFT;
        break;
       case 77:
        operation=RIGHT;
        break;
       case BEGINNING:
        operation=BEGINNING;
        break;
       default:
        operation=INPUT_ERROR;
        break;
    }
    return operation;
}

int pointpaint(int a){
    switch(a)
    {
       case SHUX:
        printf("|");
        break;
       case HENGX:
        printf("-");
        break;
       case PLAYER:
        printf("o");
        break;
       case SPACE:
        printf(" ");
        break;
       case -1:
        printf("\n");
        break;
    }
    return 0;
}

int painting(int n){
     static int magic[8][9]={{SHUX,PLAYER,HENGX,HENGX,HENGX,HENGX,HENGX,HENGX,-1},
                              {SHUX,SPACE,SPACE,SPACE,SHUX,SPACE,SHUX,SHUX,-1},
                              {SHUX,HENGX,HENGX,SPACE,SHUX,SPACE,SHUX,SHUX,-1},
                              {SHUX,SPACE,SPACE,SPACE,SPACE,SPACE,SHUX,SHUX,-1},
                              {SHUX,SPACE,SPACE,SHUX,SPACE,HENGX,HENGX,SHUX,-1},
                              {SHUX,SPACE,HENGX,SHUX,SPACE,SPACE,SPACE,SHUX,-1},
                              {SHUX,SPACE,SPACE,SHUX,HENGX,HENGX,SPACE,SPACE,-1},
                              {SHUX,HENGX,HENGX,HENGX,HENGX,HENGX,HENGX,HENGX,-1}};
    static int x=0,y=1;                   //存储玩家位置
    int info=BEGINNING;
    system("cls");
    switch(n)
    {
       case UP:
        if(x!=0&&magic[x-1][y]==SPACE){
           magic[x][y]=SPACE;
           x-=1;
           magic[x][y]=PLAYER;
        }else{
          info=MOVE_ERROR;
        };
        break;
       case DOWN:
        if(x!=7&&magic[x+1][y]==SPACE){
           magic[x][y]=SPACE;
           x+=1;
           magic[x][y]=PLAYER;
        }else{
           info=MOVE_ERROR;
        };
        break;
       case LEFT:
        if(y!=0&&magic[x][y-1]==SPACE){
           magic[x][y]=SPACE;
           y-=1;
           magic[x][y]=PLAYER;
        }else{
           info=MOVE_ERROR;
        };
        break;
       case RIGHT:
        if(y!=7&&magic[x][y+1]==SPACE){
           magic[x][y]=SPACE;
           y+=1;
           magic[x][y]=PLAYER;
        }else{
           info=MOVE_ERROR;
        };
        break;
       case BEGINNING:
        break;
       case INPUT_ERROR:
        info=INPUT_ERROR;
        break;
    }
    int i,j;
    for(i=0;i<8;i++){
        for(j=0;j<9;j++){
            pointpaint(magic[i][j]);
        }
    }
    if(info==INPUT_ERROR){
        printf("请使用方向键进行控制！");
    }else if(info==MOVE_ERROR){
        printf("请勿撞墙！");
    }
    return judge(x,y);
}
