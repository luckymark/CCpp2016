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
    HENGX,SHUX,SPACE,PLAYER,MUB,XIANGZ,GREAT
};

int magic[72];

int painting(int n,int *map);
int control(int k);
int judge(int *x);
int pointPaint(int a);

int main()
{
    int k=BEGINNING,judged;
    int steps=0,record=0,i;
    FILE *fp;
    char *s1[2]={"first","second"};
    char *s2[2]={"firstgrade","secondgrade"};
    char *s;
    printf("select the game(input the number):1.first\t2.second\n");
    scanf("%d",&i);
    s=s1[i-1];
    fp=fopen(s,"r");
    fread(magic,4,72,fp);
    fclose(fp);
    s=s2[i-1];
    fp=fopen(s,"r");
    record=(int)getc(fp);
    fclose(fp);
    do{
        steps+=painting(control(k),magic);
        judged=judge(magic);
        printf("record:%d\n",record);
        printf("your steps:%d\n",steps);
    }while((k=getch())!=0&&(judged!=FINISH));
    printf("You win!");
    fp=fopen(s,"w");
    putc(steps,fp);
    fclose(fp);
    return 0;
}

int judge(int *x){
    int i;
    for(i=0;i<72;i++){
        if(x[i]==MUB){
            return NO;
        }
    }
    return FINISH;
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
int pointPaint(int a){
    switch(a)
    {
       case SHUX:
          printf("|");
          break;
       case HENGX:
          printf("-");
          break;
       case PLAYER:
          printf("i");
          break;
       case SPACE:
          printf(" ");
          break;
       case 9:
          printf("\n");
          break;
       case MUB:
          printf("x");
          break;
       case XIANGZ:
          printf("O");
          break;
       case GREAT:
          printf("G");
          break;
    }
    return 0;
}


int painting(int n,int *map){
    static int x=55;
    int step=0;
    system("cls");
    switch(n)
    {
       case UP:
          if((x>=18)&&((map[x-9]==SPACE)||(map[x-9]==MUB))){
              map[x]=SPACE;
              x-=9;
              map[x]=PLAYER;
              step=1;
          }else if((x>=18)&&map[x-9]==XIANGZ){
              if(map[x-18]==SPACE){
                   map[x]=SPACE;
                   x-=9;
                   map[x]=PLAYER;
                   map[x-9]=XIANGZ;
                   step=1;
              }else if(map[x-18]==MUB){
                   map[x]=SPACE;
                   x-=9;
                   map[x]=PLAYER;
                   map[x-9]=GREAT;
                   step=1;
              }else{}
          }else{};
          break;
       case DOWN:
         if((x<=52)&&((map[x+9]==SPACE)||(map[x+9]==MUB))){
              map[x]=SPACE;
              x+=9;
              map[x]=PLAYER;
              step=1;
          }else if((x<=52)&&map[x+9]==XIANGZ){
              if(map[x+18]==SPACE){
                   map[x]=SPACE;
                   x+=9;
                   map[x]=PLAYER;
                   map[x+9]=XIANGZ;
                   step=1;
              }else if(map[x+18]==MUB){
                   map[x]=SPACE;
                   x+=9;
                   map[x]=PLAYER;
                   map[x+9]=GREAT;
                   step=1;
              }else{}
          }else{};
          break;
       case LEFT:
          if(((x%9)>=2)&&((map[x-1]==SPACE)||(map[x-1]==MUB))){
              map[x]=SPACE;
              x-=1;
              map[x]=PLAYER;
              step=1;
          }else if(((x%9)>=2)&&map[x-1]==XIANGZ){
              if(map[x-2]==SPACE){
                   map[x]=SPACE;
                   x-=1;
                   map[x]=PLAYER;
                   map[x-1]=XIANGZ;
                   step=1;
              }else if(map[x-2]==MUB){
                   map[x]=SPACE;
                   x-=1;
                   map[x]=PLAYER;
                   map[x-1]=GREAT;
                   step=1;
              }else{}
          }else{};
          break;
       case RIGHT:
         if(((x%9)<=5)&&((map[x+1]==SPACE)||(map[x+1]==MUB))){
              map[x]=SPACE;
              x+=1;
              map[x]=PLAYER;
              step=1;
          }else if(((x%9)<=5)&&map[x+1]==XIANGZ){
              if(map[x+2]==SPACE){
                   map[x]=SPACE;
                   x+=1;
                   map[x]=PLAYER;
                   map[x+1]=XIANGZ;
                   step=1;
              }else if(map[x+2]==MUB){
                   map[x]=SPACE;
                   x+=1;
                   map[x]=PLAYER;
                   map[x+1]=GREAT;
                   step=1;
              }else{}
          }else{};
          break;
       case BEGINNING:
          break;
       case INPUT_ERROR:
          break;
    }
    int i;
    for(i=0;i<72;i++){
        pointPaint(magic[i]);
    }
    return step;
}
