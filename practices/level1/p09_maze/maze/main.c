//
//  main.c
//  maze
//
//  Created by 陈浩贤 on 16/3/14.
//  Copyright © 2016年 陈浩贤. All rights reserved.
//

#include <stdio.h>

#define WIDTH  41
#define HEIGHT 12

char map[HEIGHT][WIDTH]={
    "**************************************** ",
    "**************************************** ",
    "****            *****            ******* ",
    "**** ********** ***** ********** ******* ",
    "**** ********** ***** ********** ******* ",
    "o    **********       **********         ",
    "**** ********** ***** ********** ******* ",
    "**** ********** ***** ********** ******* ",
    "****            *****            ******* ",
    "**************************************** ",
    "**************************************** ",
};

int x,y,finished;

void printWall();
void run(char direction);
int ifHitTheWall(char nextStep);
int ifFinishTheMaze();
void go();
int main(int argc, const char * argv[]) {
    // insert code here...
    printWall();
    printf("请使用wasd＋enter移动\n");
    x=0;
    y=5;
    char step;
    while (finished==0) {
        scanf("%c",&step);
        run(step);
    }
    return 0;
}


void printWall()
{
    for (int i=0; i<HEIGHT; i++) {
        for (int j=0;j<WIDTH ; j++) {
            printf("%c",map[i][j]);
            if (j==WIDTH-1) {
                printf("\n");
            }
        }
    }
   
}

void run(char direction){
    char temp=map[y][x];
    if (direction=='d'||direction=='D') {
        if (ifHitTheWall(map[y][x+1])==1) {
            map[y][x]=map[y][x+1];
            map[y][x+1]=temp;
            x++;
            go();
        }
        
    }else if (direction=='w'||direction=='W'){
        if (ifHitTheWall(map[y-1][x])==1) {
            map[y][x]=map[y-1][x];
            map[y-1][x]=temp;
            y--;
            go();
        }
        
    }else if (direction=='a'||direction=='A'){
        if (ifHitTheWall(map[y][x-1])==1) {
            map[y][x]=map[y][x-1];
            map[y][x-1]=temp;
            x--;
            go();
        }
        
    }else if (direction=='s'||direction=='S'){
        if (ifHitTheWall(map[y+1][x])==1) {
            map[y][x]=map[y+1][x];
            map[y+1][x]=temp;
            y++;
            go();
        }
        
    }
    if (ifFinishTheMaze()==1) {
        finished=1;
    }
}

int ifHitTheWall(char nextStep){
    switch (nextStep) {
        case '*':{
            printf("你药丸啊!\n");
            return 0;
            break;
        }
        case ' ':{
            printf("returned 1\n");
            return 1;
        }
        default:
            return 2;
            break;
    }

}

int ifFinishTheMaze(){
    if (x==WIDTH-1&&y==5) {
        printf("恭喜你跑得比西方记者还快!\n");
        return 1;
    }else {
        return 0;
    };
}

void go(){
    system("clear");
    printWall();
}