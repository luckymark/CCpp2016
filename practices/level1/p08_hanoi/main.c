//
//  main.c
//  hanoi
//
//  Created by Ferris on 16/3/10.
//  Copyright © 2016年 Ferris. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

void hanoi(char A,char B,char C,int n);
void Move(int ,char ,char );


int main(int argc, const char * argv[]) {
    int n;
    printf("输入阶数：\n");
    scanf("%d",&n);
    hanoi('A','B','C',n);
    return 0;
}

void hanoi(char A,char B,char C,int n)
{
    if(n==1)
    {
       Move(n,A,C);
    }
    else
    {
        hanoi(A,C,B,n-1);
        Move(n,A,C);
        hanoi(B,A,C,n-1);
    }
}

void Move(int a,char b,char c)
{
    printf("把第 %d 块从 %c 移到 %c\n",a,b,c);
    return;
}


    



