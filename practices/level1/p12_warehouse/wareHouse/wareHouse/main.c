//
//  main.c
//  wareHouse
//
//  Created by 陈浩贤 on 16/3/24.
//  Copyright © 2016年 陈浩贤. All rights reserved.
//

#include <stdio.h>

int finished;


void judgeWhitchToDo(int number);
void displayCargoList();
void depositCargo();
void takeOutCargo();

int main(int argc, const char * argv[]) {
    // insert code here...
    finished=0;
    int whichToDo;
   
    while (finished==0) {
        printf("1.显示存货列表\n");
        printf("2.入库\n");
        printf("3.出库\n");
        printf("\n");
        printf("请输入对应数字进入该功能\n");
        
        scanf("%d",&whichToDo);
        judgeWhitchToDo(whichToDo);
    }
    return 0;
}

void judgeWhitchToDo(int number){
    if (number==1) {
        displayCargoList();
    }else if (number==2){
        depositCargo();
    }else if (number==3){
        takeOutCargo();
    }
}

void displayCargoList(){
    FILE *fp=fopen("cargoList.rtf", "r");
    
}

void depositCargo(){
    
}
void takeOutCargo(){
    
}