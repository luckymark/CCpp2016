//wsad操作
#include<stdio.h>
#include<stdlib.h>
//函数原型
void print();
void commond();
void move(char direction);
//全局变量
int maze[10][12]={
    {1,1,1,1,1,1,1,1,1,1,1,1},
    {3,0,0,0,0,0,0,0,0,0,0,1},
    {1,1,1,1,0,1,1,1,1,1,1,1},
    {1,0,0,0,0,0,0,0,0,0,0,1},
    {1,1,0,1,1,1,1,1,1,1,1,1},
    {1,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,1,1,1,1,1,1,0,1,1,1},
    {1,0,1,1,1,1,1,0,0,1,1,1},
    {1,0,0,0,0,0,1,0,1,1,1,1},
    {1,1,1,1,0,1,1,1,1,1,1,1}
};
int positionX;
int positionY;
//程序主体
int main(){
    while(true){
        print();
        if(positionY==9&&positionX==4){
            printf("you win!\n");
            break;
        }
        commond();
    }
    return 0;
}

void print(){
    system("cls");
    for(int i = 0;i<10;i++){
        for(int j = 0;j<12;j++){
            if(maze[i][j]==1){
                printf("#");
            }else if(maze[i][j]==3){
                printf("@");
                positionX = j;
                positionY = i;
            }else{
                printf(" ");
            }
            if(j==11){
                printf("\n");
            }
        }
    }
}
void commond(){
    char direction = 0;
    scanf("%c",&direction);
    move(direction);
}

void move(char direction){
        if(direction=='w'){
            if(maze[positionY-1][positionX]==0){
                maze[positionY][positionX]=0;
                positionY = positionY-1;
                maze[positionY][positionX]=3;
            }
        }else if(direction=='s'){
            if(maze[positionY+1][positionX]==0){
                maze[positionY][positionX]=0;
                positionY = positionY+1;
                maze[positionY][positionX]=3;
            }
        }else if(direction=='a'){
            if(maze[positionY][positionX-1]==0){
                maze[positionY][positionX]=0;
                positionX = positionX-1;
                maze[positionY][positionX]=3;
            }
        }else if(direction=='d'){
            if(maze[positionY][positionX+1]==0){
                maze[positionY][positionX]=0;
                positionX = positionX+1;
                maze[positionY][positionX]=3;
            }
        }
}
