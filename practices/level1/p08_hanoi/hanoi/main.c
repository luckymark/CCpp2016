//
//  main.c
//  hanoi
//
//  Created by 陈浩贤 on 16/3/9.
//  Copyright © 2016年 陈浩贤. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
        int n;
        void honi(int n,char one, char two, char three);
        printf("please enter numbers of disks\n");
        scanf("%d",&n);
        honi(n, 'A', 'B', 'C');
    return 0;
}


void honi(int n,char one, char two, char three)
{
    void steps(char x,char y);
    if (n==1) {
        steps(one, three);
    }else{
    honi(n-1,one, three, two);
    steps(one, three);
    honi(n-1, two, one, three);
    }
}

void steps(char x,char y)
{
    printf("%c->%c\n",x,y);
}