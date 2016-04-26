//
//  main.c
//  pushBoxes
//
//  Created by 陈浩贤 on 16/3/23.
//  Copyright © 2016年 陈浩贤. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#define WIDTH 40
#define HEIGHT 12

char path1[120]="/Users/caoxiann/Desktop/c/c\ \&c++lesson/CCpp2016/practices/level1/p10_pushBoxes/pushBoxes/pushBoxes/map1.txt";
char path2[120]="/Users/caoxiann/Desktop/c/c\ \&c++lesson/CCpp2016/practices/level1/p10_pushBoxes/pushBoxes/pushBoxes/map2.txt";

void printMap();
void judgeDirection(char step);
void ifHitSth(int tempX,int tempY);
void run(int nextX,int nextY);
void pushBox(int tempX,int tempY);
void getMap(int index);
int finished,x,y,boxes=0,quit=0;
char map[HEIGHT][WIDTH]={
//    "************************************",
//    "************************************",
//    "**    *************** x     ********",
//    "**    *****************     ********",
//    "** o                     ***********",
//    "**                       ***********",
//    "******    ***********    ***********",
//    "******   #**************************",
//    "******    **************************",
//    "************************************",
//    "************************************",
//    "************************************",
    
    
};

int main(int argc, const char * argv[]) {
    // insert code here...
    int index=0;
    while (quit==0) {
        index++;
        finished=0;
        boxes=0;
        getMap(index);
        printMap();
        printf("请将箱子# 推到指定位置 x\n");
        printf("请输入wasd + enter移动\n");
        char step;
        while (finished!=boxes) {
            
            scanf("%c",&step);
            judgeDirection(step);
            
        }
        
        printf("恭喜你推倒了箱子!\n");
        printf("请问还要玩下一关吗?  y/n  \n");
        char isQuit;
        scanf("%c",&isQuit);
        scanf("%c",&isQuit);
        if (isQuit=='y') {
            quit=0;
        }else{
            quit=1;
        }
    }
    printf("欢迎再次玩耍\n");
    
    return 0;
}
void getMap(int index){
    char path[120];
    if (index==1) {
        strcpy(path, path1);
    }else if (index==2){
        strcpy(path, path2);
    }
    FILE *fr=fopen(path, "r");
    if (fr==NULL) {
        printf("地图打开失败\n");
    }else{
        int i=0,j;
        while (fgets(map[i], 80, fr)) {
            for (j=0; j<WIDTH; j++) {
                if (map[i][j]=='o') {
                    y=i;
                    x=j;
                }
                if (map[i][j]=='#') {
                    boxes++;
                }
            }
            i++;
        }
    }
    
    fclose(fr);
}
void printMap(){
    for (int i=0; i<HEIGHT; i++) {
        for (int j=0; j<WIDTH; j++) {
           
            
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
       
    }else if (nextStep=='@'){
        pushBox(tempX, tempY);
    }
}

void run(int nextX,int nextY){
    char temp=map[y][x];
    if (temp!='^') {
        map[y][x]=map[nextY][nextX];
        map[nextY][nextX]=temp;
    }else{
       
        map[y][x]='x';
        map[nextY][nextX]='o';
        
    }
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
        
        if (map[tempY][tempX]=='@') {
            
            map[nextY][nextX]='#';
            map[tempY][tempX]='^';
            map[y][x]=' ';
            finished--;
            
        }else if (map[y][x]=='^'){
            
            map[y][x]='x';
            map[tempY][tempX]='o';
            map[nextY][nextX]='#';
            
        }else {
            map[nextY][nextX]=nextStep;
            map[tempY][tempX]=map[y][x];
            map[y][x]=nextOfBox;
            
            
        }
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
        y=tempY;
        x=tempX;
        finished++;
    }
}