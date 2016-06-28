//
//  main.c
//  test
//
//  Created by 陈浩贤 on 16/5/27.
//  Copyright © 2016年 陈浩贤. All rights reserved.
//

#include <stdio.h>

int a[11]={-1,18,-9,4,-2,0,2,40,16,-8,10};
void printArray();
void build();
void choose();
void insert();
void delete();
int main(int argc, const char * argv[]) {
    printArray();
    
    return 0;
}



void printArray(){
//    printf("请输入几个数\n");
//    int *array=malloc(3*sizeof(int));
//    for (int i=0; i<=2; i++) {
//        scanf("%d",array);
//        array=array+sizeof(int);
//    }
//    for (int j=0; j<=2; j++) {
//        array=array-sizeof(int);
//        printf("%d\n",*array);
//        
//    }
    
    int (*array)[3];
    for (int i=0; i<=2; i++) {
        scanf("%d",array[i]);
    }
    for (int j=0; j<=2; j++) {
        printf("%d\n",*array[j]);
    }
}               