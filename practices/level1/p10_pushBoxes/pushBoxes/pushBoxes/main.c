//
//  main.c
//  pushBoxes
//
//  Created by 陈浩贤 on 16/3/23.
//  Copyright © 2016年 陈浩贤. All rights reserved.
//

#include <stdio.h>

#define WIDTH 40
#define HEIGHT 12

void printMap();
void judgeDirection(char step);
void ifHitSth(int tempX,int tempY);
void run(int nextX,int nextY);
void pushBox(int tempX,int tempY);

int finished,x,y;
char map[HEIGHT][WIDTH]={
    "************************************",
    "************************************",
    "**    *************** x     ********",
    "**    *****************     ********",
    "** o                     ***********",
    "**                       ***********",
    "******    ***********    ***********",
    "******   #**************************",
    "******    **************************",
    "************************************",
    "************************************",
    "************************************",
    
    
};
int main(int argc, const char * argv[]) {
    // insert code here...
    
    
    finished=0;
    printMap();
    printf("请将箱子# 推到指定位置 x\n");
    printf("请输入wasd + enter移动\n");
    char step;
    y=4;
    x=3;
    while (finished==0) {
        
        scanf("%c",&step);
        judgeDirection(step);
        
    }
    
    printf("恭喜你推倒了箱子!\n");
    return 0;
}

void printMap(){
    for (int i=0; i<HEIGHT; i++) {
        for (int j=0; j<WIDTH; j++) {
            if (j==WIDTH-1) {
                printf("\n");
            }
            printf("%c",map[i][j]);
        }
    }
}

void judgeDirection(char step){
    
    if (step=='w'||step=='W') {
        ifHitSth(x, y-1);
    }else if (step=='a'||step=='A'){
        ifHitSth(x-1, y);
    }else if (step=='s'||step=='S'){
        ifHitSth(x, y+1);
    }else if (step=='d'||step=='D'){
        ifHitSth(x+1, y);
    }
}

void ifHitSth(int tempX,int tempY){
    char nextStep=map[tempY][tempX];
    
    
    if (nextStep=='*') {
        
        printf("不知所措\n");
    }else if (nextStep==' '){
        
        run(tempX, tempY);
        
    }else if (nextStep=='#'){

        pushBox(tempX, tempY);
       
    }
}

void run(int nextX,int nextY){
    char temp=map[y][x];
    map[y][x]=map[nextY][nextX];
    map[nextY][nextX]=temp;
    x=nextX;
    y=nextY;
    system("clear");
    printMap();
}

void pushBox(int tempX,int tempY){
    
    int nextX,nextY;
    char nextStep=map[tempY][tempX];
    nextX=2*tempX-x;
    nextY=2*tempY-y;
    char nextOfBox=map[nextY][nextX];

    if (nextOfBox==' ') {
        map[nextY][nextX]=nextStep;
        map[tempY][tempX]=map[y][x];
        map[y][x]=nextOfBox;
        system("clear");
        printMap();
        
        
        y=tempY;
        x=tempX;
        
    }else if (nextOfBox=='*'){
        printf("箱子撞墙啦");
    }else if (nextOfBox=='x'){
        map[nextY][nextX]='@';
        map[tempY][tempX]=map[y][x];
        map[y][x]=' ';
        system("clear");
        printMap();
        finished=1;
    }
}