//
//  main.c
//  linkedList
//
//  Created by 陈浩贤 on 16/3/21.
//  Copyright © 2016年 陈浩贤. All rights reserved.
//

#include <stdio.h>



int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
//    struct slist{
//        int info;
//        struct slist*next;
//    };
//    
//    struct slist *head,*p,*q;
//    head=p;
//    p->info=20;
//    p->next=q;
//    q->info=50;
//    q->next='\0';
//    
    
    int a,*p,*q;
    a=10;
    p=&a;
    q=p;
    
    printf("a:%d\n*p:%d\n",a,*p);
    int data[10];
    int *d;
    d=data;
    *d=100;
    *(d+1)=200;
    printf("data1:%d\ndata2:%d\n",data[0],*(d+1));
    
    
    return 0;
}
